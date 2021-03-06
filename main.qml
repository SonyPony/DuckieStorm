/*|File: main.qml
  |Author: Son Hai Nguyen
  |License: LGPL
  |*/

import QtQuick 2.2
import QtQuick.Controls 1.1
import QtMultimedia 5.3
import QtQuick.Window 2.0

import Duck 1.0
import Trees 1.0
import Ball 1.0
import Barrels 1.0
import Clouds 1.0
import Game 1.0
import FileStream 1.0

import "logic/duckLogic.js" as DuckLogic
import "logic/barrelLogic.js" as BarrelLogic
import "logic/cloudLogic.js" as CloudLogic
import "logic/backgroundLogic.js" as BackgroundLogic
import "logic/generalLogic.js" as GL

import "logic/gestures.js" as Gestures
import "res/shapes.js" as Shapes

import "components_static"

ApplicationWindow {
    id: root

    /*--smazat--*/ //možná
    width: 1//854
    height: 1//480
    visible: true
    /*----------*/

    /*---Údaje o kliku myší---*/
    property real touchX
    property real touchY
    property bool mousePressed: false
    /*-----------------------*/

    onVisibilityChanged: {
        if(visibility==3)   //možná ještě 0
            game.paused = true
        console.log(visibility + "------------------------------------------------------------------------")
    }

    onWidthChanged: {
        DuckLogic.updateOutlines()

        if(root.width>0 && graphics.firstTrees.width==0 && game.sizeOfPixel)
            BackgroundLogic.initFirstTrees()
    }

    Game {
        id: game

        /*---------------------------------*/
        /*--------------Font---------------*/
        /*---------------------------------*/
        FontLoader {
            id: pixelFont
            source: "res/fonts/Fleftex_M.ttf"
        }

        /*---------------------------------*/
        /*--------------Zvuky--------------*/
        /*---------------------------------*/
        Sounds { id: sounds }

        /*---------------------------------*/
        /*--------Container grafiky--------*/
        /*---------------------------------*/
        Graphics {
            id: graphics
            objectName: "graphics"
        }

        /*---------------------------------*/
        /*---------Game Over dialog--------*/
        /*---------------------------------*/
        ScoreDialog {
            id: scoreDialog
            objectName: "scoreDialog"
        }

        /*---------------------------------*/
        /*--------Soubor high score--------*/
        /*---------------------------------*/
        FileStream {
            id: scoreFile
            objectName: "scoreFile"

            source: "score.txt"
        }

        /*---------------------------------*/
        /*------------Tutorial-------------*/
        /*---------------------------------*/

        Tutorial { id: tutorial }

        /*----Nastavení vazby----*/
        sizeOfPixel: (root.height * GL.fraction(120, 480))/Shapes.getDuckNumberOfPixels("column")
        /*-----------------------*/
        highScore: scoreFile.read()

        onScoreChanged: {
            graphics.scoreText.text = game.score
        }

        onSizeOfPixelChanged: {
                DuckLogic.updateOutlines()
                BarrelLogic.updateOutlines()
        }

        /*---------------------------------*/
        /*------------Kachnička------------*/
        /*---------------------------------*/
        Duck {
            id: duck
            objectName: "duck"

            /*---Vlasnosti kachničky---*/
            heightOfJump: root.height * GL.fraction(160, 480)
            size: game.sizeOfPixel * 14
            /*-------------------------*/

            /*--Pozicování kachničky--*/
            defaultX: root.width * GL.fraction(150, 850)
            defaultY: root.height-size - 2*game.sizeOfPixel
            /*------------------------*/

            /*---Grafika kachničky---*/
            image: graphics.duckImage
            property var outlines: DuckLogic.initOutlines()
            /*-----------------------*/

            Connections {
                target: game
                onPausedChanged: {
                    if(game.paused) {
                        if(jumpAnimation.running)
                            jumpAnimation.pause()
                    }

                    else
                        jumpAnimation.resume()
                }
            }

            /*--Animace skákání a posunování okrajů kachničky--*/
            onJump: SequentialAnimation {
                id: jumpAnimation
                objectName: "jumpAnimation"

                ScriptAction { script: (function() { if(!duck.canJump) { jumpAnimation.stop() } })() }
                ScriptAction { script: sounds.outWaterSound.play() }
                NumberAnimation { target: duck.image; property: "y"; to: duck.image.y-duck.heightOfJump; duration: 500; easing.type: Easing.OutQuad }
                NumberAnimation { target: duck.image; property: "y"; to: duck.image.y; duration: 500; easing.type: Easing.InQuad }
                ScriptAction { script: sounds.inWaterSound.play() }
            }
            /*-------------------------------------------------*/
        }

        /*---------------------------------*/
        /*------Házený kus kovu(míč)-------*/
        /*---------------------------------*/
        Ball {
            id: ball
            objectName: "ball"

            image: graphics.ballImage

            /*----------------Animace hodu míče----------------*/
            onUpdatePosition: SequentialAnimation {
                id: throwAnimation
                objectName: "throwAnimation"
                loops: Animation.Infinite

                NumberAnimation { duration: 1 }
                ScriptAction { script: ball.updateBallPosition() }
            }
            /*-------------------------------------------------*/
        }

        /*---------------------------------*/
        /*--------Barrely(překážky)--------*/
        /*---------------------------------*/
        Barrels {
            id: barrels

            /*--Objekty a informace--*/
            property var isAvailable: new Array
            property var objects: new Array
            /*-----------------------*/


            Component.onCompleted: {
                BarrelLogic.initBarrels()
            }

            SequentialAnimation {
                id: barrelGenerator
                objectName: "generator"

                running: true

                NumberAnimation { id: barrelGeneratorDelay }
                ScriptAction { script: BarrelLogic.sendBarrel() }
                onRunningChanged: barrelGenerator.start()
            }

        }

        /*---------------------------------*/
        /*--------------Mraky--------------*/
        /*---------------------------------*/

        Clouds {
            id: clouds

            /*---Objekty a informace----*/
            property var objects: new Array
            property var isAvailable: new Array
            /*--------------------------*/

            Component.onCompleted: {
                CloudLogic.initClouds()
            }

            SequentialAnimation {
                id: cloudGenerator
                objectName: "generator"

                running: true

                NumberAnimation { id: cloudGeneratorDelay }
                ScriptAction { script: CloudLogic.sendCloud() }
                onRunningChanged: cloudGenerator.start()
            }
        }

        /*---------------------------------*/
        /*---------Stromy(pozadí)----------*/
        /*---------------------------------*/

        Trees { // není v graphics, protože obsahuje jen data
            id: trees

            /*---Objekty a informace----*/
            property var objects: new Array
            property var isAvailable: new Array
            /*--------------------------*/

            Component.onCompleted: {
                BackgroundLogic.initTrees()
            }

            SequentialAnimation {
                id: treeGenerator
                objectName: "generator"

                running: true

                NumberAnimation { id: treeGeneratorDelay }
                ScriptAction { script: BackgroundLogic.sendTree() }
                onRunningChanged: treeGenerator.start()
            }
        }

        Component.onCompleted: {    //propojení vše se signály game
            game.onPausedChanged.connect(duck.handleGamePause)
            game.onPausedChanged.connect(ball.handleGamePause)
            game.onPausedChanged.connect(barrels.handleGamePause)
            game.onPausedChanged.connect(clouds.handleGamePause)
            game.onPausedChanged.connect(trees.handleGamePause)
            game.onPausedChanged.connect(sounds.soundtrack.handleGamePause)

            game.restart.connect(scoreDialog.hide)
            game.restart.connect(duck.restart)
            game.restart.connect(ball.disable)
        }
    }

    /*---------------------------------*/
    /*----------Pause button-----------*/
    /*---------------------------------*/
    Image {
        id: pauseButton
        source: "res/images/pauseButton.svg"

        x: root.width-(width+2*game.sizeOfPixel)
        y: 2*game.sizeOfPixel
        z: 1

        width: 6*game.sizeOfPixel
        height: 7*game.sizeOfPixel

        /*----Renderovací velikost----*/
        sourceSize.width: 6*game.sizeOfPixel
        sourceSize.height: 7*game.sizeOfPixel
        /*----------------------------*/

        MouseArea {
            anchors.fill: parent
            enabled: false

            onClicked: if(!game.over) { game.paused = (game.paused) ?false :true }
        }
    }

    /*---------------------------------*/
    /*--------------Eventy-------------*/
    /*---------------------------------*/

    MouseArea {
        id: rootMouseArea
        objectName: "rootMouseArea"

        anchors.fill: parent

        onPressed: {
            root.mousePressed = true;
            root.touchX = mouse.x;
            root.touchY = mouse.y ;
        }
        onReleased: {
            root.mousePressed = false;

            if(Gestures.checkClick(root.touchX, root.touchY, mouse.x, mouse.y, GL.pixels(Screen.logicalPixelDensity, 2.5))) //pokud byl proveden klik hodí kachnička míčem
                ball.calculateInfo(mouse.x, mouse.y);

            if(Gestures.checkClick(root.touchX, root.touchY, mouse.x, mouse.y, GL.pixels(Screen.logicalPixelDensity, 2.5)) && tutorial.visible) {   //první klik ve hře
                tutorial.opacity = 0.0
                pauseButton.children[0].enabled = true
                game.paused = false
            }
        }

        onPositionChanged: {
            switch(Gestures.checkSlide(root.touchY, mouse.y, GL.pixels(Screen.logicalPixelDensity, 12))) {
                case "slide up":
                    duck.jump()
                    break;
            }
        }
    }
}
