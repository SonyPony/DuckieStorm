import QtQuick 2.2
import QtQuick.Controls 1.1
import QtMultimedia 5.3

import Duck 1.0
import Trees 1.0
import Ball 1.0
import Barrels 1.0
import Clouds 1.0
import Game 1.0

import "logic/duckLogic.js" as DuckLogic
import "logic/barrelLogic.js" as BarrelLogic
import "logic/cloudLogic.js" as CloudLogic
import "logic/backgroundLogic.js" as BackgroundLogic
import "logic/gameLogic.js" as GameLogic
import "logic/generalLogic.js" as GL

import "logic/gestures.js" as Gestures
import "res/shapes.js" as Shapes

import "components_static"

ApplicationWindow {
    id: root

    /*--smazat--*/ //možná
    width: 854
    height: 480
    visible: true
    /*----------*/

    /*---Údaje o kliku myší---*/
    property real touchX
    property real touchY
    property bool mousePressed: false
    /*-----------------------*/

    onWidthChanged: {
        DuckLogic.updateOutlines()
    }


    Game {
        id: game

        Sounds { id: sounds }
        Graphics {
            id: graphics
            objectName: "graphics"
        }

        /*----Nastavení vazby----*/
        sizeOfPixel: (root.height * GL.fraction(120, 480))/Shapes.getDuckNumberOfPixels("column")
        /*-----------------------*/

        onScoreChanged: graphics.scoreText.text = game.score  //nahradit výpisem na obrazovky

        onSizeOfPixelChanged: { //toto proběhne hned na začátku u Androidu
            if(firstChange) {
                DuckLogic.updateOutlines()
                BarrelLogic.updateOutlines()
            }
            firstChange = true
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
            //Component.onCompleted: duck.setImage(graphics.duckImage)

            /*--Animace skákání a posunování okrajů kachničky--*/
            onJump: SequentialAnimation {
                id: jumpAnimation

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

            Connections {
                target: game
                onPausedChanged: {
                    if(game.paused) {
                        trees.pause()
                        treeGenerator.running = false
                    }

                    else {
                        trees.resume()
                        treeGenerator.running = true
                    }
                }
            }

            Component.onCompleted: {
                BackgroundLogic.initTrees()
            }

            SequentialAnimation {
                id: treeGenerator
                running: true

                NumberAnimation { id: treeGeneratorDelay }
                ScriptAction { script: BackgroundLogic.sendTree() }
                onRunningChanged: treeGenerator.start()
            }
        }
    }



    /*---------------------------------*/
    /*--------------Eventy-------------*/
    /*---------------------------------*/

    MouseArea {
        anchors.fill: parent

        onPressed: {
            root.mousePressed = true;
            root.touchX = mouse.x;
            root.touchY = mouse.y ;
        }
        onReleased: {
            root.mousePressed = false;

            if(Gestures.checkClick(root.touchX, root.touchY, mouse.x, mouse.y, 20)) //pokud byl proveden klik hodí kachnička míčem
                ball.calculateInfo(mouse.x, mouse.y);
        }

        onPositionChanged: {
            switch(Gestures.checkSlide(touchY, mouse.y, root.height*GL.fraction(140, 480))) {
                case "slide up":
                    duck.jump()
                    break;
                case "slide down":
                    (game.paused) ?GameLogic.resume() :GameLogic.pause()    //přidat button na pausu
                    break;
            }
        }
    }
}
