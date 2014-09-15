import QtQuick 2.0
import "../logic/generalLogic.js"as GL
import "../logic/backgroundLogic.js" as Logic

/*---------------------------------*/
/*---Hiearchie obrázků(kvůli Z)----*/
/*---------------------------------*/
Item {

    /*------Přenesení id do popředí------*/
    property alias duckImage: duckImage
    property alias ballImage: ballImage
    property alias scoreText: scoreText
    property alias edgeOfGrass: edgeOfGrass
    property alias grass: grass
    /*-----------------------------------*/

    /*-------------Kachnička-------------*/
    Image {
        id: duckImage

        source: duck.imageURL
        x: duck.defaultX
        y: duck.defaultY
        z: 1

        width: duck.size
        height: width

        /*----Renderovací velikost----*/
        sourceSize.width: 14*game.sizeOfPixel
        sourceSize.height: 14*game.sizeOfPixel
        /*----------------------------*/
    }
    /*-----------------------------------*/

    /*---------------Míč-----------------*/
    Image {
        id: ballImage
        objectName: "ballImage"

        source: ball.imageURL
        z: 1

        height: game.sizeOfPixel * 4
        width: height
        visible: false

        /*----Renderovací velikost----*/
        sourceSize.width: 4*game.sizeOfPixel
        sourceSize.height: 4*game.sizeOfPixel
        /*----------------------------*/
    }
    /*-----------------------------------*/

    /*------------Výpis scóre------------*/
    Text {
        id: scoreText

        x: game.sizeOfPixel
        y: game.sizeOfPixel
        z: 1

        text: "0"
        color: "white"

        font.pixelSize: 8*game.sizeOfPixel
        font.family: pixelFont.name

        onTextChanged: {
            if(scoreText.text>game.highScore)
                scoreText.color = "red"

            else if(scoreText.text==game.highScore)
                scoreText.color = "orange"
        }
    }

    /*-----------------------------------*/

    /*-----------Modré pozadí------------*/
    Rectangle {
        id: sky

        z: 0

        width: root.width
        height: edgeOfGrass.y
        color: "#CCF0FF"
    }
    /*-----------------------------------*/

    /*------------Pozadí/řeka------------*/
    Rectangle {
        id: river

        y: duck.defaultY + duck.size - 3*game.sizeOfPixel
        z: 2

        width: root.width
        height: root.height - y
        color: "#64d0ff"
    }
    /*-----------------------------------*/

    /*------------Pozadí/tráva-----------*/
    Rectangle {
        id: grass

        y: lineOfRiver.y - 2*game.sizeOfPixel - height
        z: 0

        width: root.width
        height: 5*game.sizeOfPixel
        color: "#b5e61d"
    }
    /*-----------------------------------*/

    /*---------Tmavý okraj trávy---------*/
    Rectangle {
        id: edgeOfGrass

        z: 0

        width: root.width
        height: game.sizeOfPixel
        color: "#64bd15"

        anchors.bottom: grass.top
    }
    /*-----------------------------------*/

    /*-Kus řeky s nižším Z než kachnička-*/
    Rectangle {
        id: lineOfRiver

        width: root.width
        height: 2*game.sizeOfPixel
        color: "#64d0ff"

        anchors.bottom: river.top
    }
    /*-----------------------------------*/

    /*-----------První stromy------------*/
    Item {
        id: firstTrees

        property var objects: new Array

        Connections {
            target: game
            onPausedChanged: ((game.paused) ?treesMoveAnimation.pause() :treesMoveAnimation.resume())
        }

        Component.onCompleted: Logic.initFirstTrees()

        NumberAnimation { id: treesMoveAnimation; target: firstTrees; property: "x"; to: 0-firstTrees.width; duration: GL.toNumberOfPixels(firstTrees.width)*trees.speed; onRunningChanged: { if(!running && firstTrees.x==0-firstTrees.width) { firstTrees.deleteLater; treesMoveAnimation.deleteLater }}}

    }
    /*-----------------------------------*/

    /*-Pozadí/přechod mezi řekou a trávou*/
    Repeater {
        model: GL.toNumberOfPixels(root.width/2) + 2
        delegate: Image {
            id: image

            source: "../res/images/background_groundImage.svg"

            x: modelData*width
            y: lineOfRiver.y - height
            z: 0

            width: 2*game.sizeOfPixel
            height: width

            sourceSize.width: 2*game.sizeOfPixel
            sourceSize.height: 2*game.sizeOfPixel

            Connections {
                target: root

                onWidthChanged: image.deleteLater
                onHeightChanged: image.deleteLater
            }

            Connections {
                target: game

                onPausedChanged: ((game.paused) ?moveAnimation.pause() :moveAnimation.resume())
            }

            /*-------Animace pohybu dopředu------*/
            NumberAnimation { id: moveAnimation; target: image; property: "x"; loops: Animation.Infinite; from: image.x; to: image.x-width; duration: 29*GL.toNumberOfPixels(image.width) }
            /*-----------------------------------*/

            Component.onCompleted: {    //init animace
                moveAnimation.start()
                moveAnimation.pause()
            }
        }
    }
    /*-----------------------------------*/
}
