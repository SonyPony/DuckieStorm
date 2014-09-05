import QtQuick 2.0
import "../logic/generalLogic.js"as GL

/*---------------------------------*/
/*---Hiearchie obrázků(kvůli Z)----*/
/*---------------------------------*/
Item {

    property alias duckImage: duckImage
    property alias ballImage: ballImage
    property alias scoreText: scoreText
    property alias edgeOfGrass: edgeOfGrass
    property alias grass: grass

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
        sourceSize.width: 1400
        sourceSize.height: 1400
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
        sourceSize.width: 1100
        sourceSize.height: 1100
        /*----------------------------*/
    }
    /*-----------------------------------*/

    /*------------Výpis scóre------------*/
    Text {
        id: scoreText
        z: 1

        text: "0"
        color: "orange"

        font.pixelSize: 7*game.sizeOfPixel
        font.family: pixelFont.name
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
        height: 5*game.sizeOfPixel //+ 3*game.sizeOfPixel
        color: "#b5e61d"

        //anchors.bottom: river.top
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

    /*-Pozadí/přechod mezi řekou a trávou*/
    Repeater {
        model: Math.ceil( root.width/(game.sizeOfPixel*2) ) + 1
        delegate: Image {
            id: image

            source: "../res/background_groundImage.svg"

            x: modelData*width
            y: lineOfRiver.y - height
            z: 0

            width: 2*game.sizeOfPixel
            height: width

            sourceSize.width: 200
            sourceSize.height: 200

            Connections {
                target: game
                onPausedChanged: { (game.paused) ?moveAnimation.pause() :moveAnimation.resume() }
            }

            NumberAnimation { id: moveAnimation; target: image; property: "x"; running: true; loops: Animation.Infinite; from: image.x; to: image.x-width; duration: GL.duration(854, 480, 58); }
        }
    }
    /*-----------------------------------*/
}
