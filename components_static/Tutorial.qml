/*|File: Tutorial.qml
  |Author: Son Hai Nguyen
  |License: LGPL
  |*/

import QtQuick 2.0

Item {
    id: tutorial

    /*-------Kachnička s popiskem--------*/
    Image {
        id: duckImage

        source: duck.imageURL
        opacity: 0.5
        x: duck.defaultX
        y: duck.defaultY-duck.heightOfJump
        z: 1

        width: duck.size
        height: width

        /*----Renderovací velikost----*/
        sourceSize.width: 14*game.sizeOfPixel
        sourceSize.height: 14*game.sizeOfPixel
        /*----------------------------*/

        Text {
            id: duckLabel

            text: qsTr("Slide up to jump.")

            anchors.left: parent.right
            anchors.margins: game.sizeOfPixel
            anchors.verticalCenter: parent.verticalCenter

            font.family: pixelFont.name
            font.pixelSize: 2*game.sizeOfPixel
        }
    }
    /*-----------------------------------*/

    /*----------Míš s popiskem-----------*/
    Image {
        id: ballImage
        objectName: "ballImage"

        source: ball.imageURL
        opacity: 0.5
        x: 44*game.sizeOfPixel
        y: 12*game.sizeOfPixel
        z: 1

        height: game.sizeOfPixel * 4
        width: height

        /*----Renderovací velikost----*/
        sourceSize.width: 4*game.sizeOfPixel
        sourceSize.height: 4*game.sizeOfPixel
        /*----------------------------*/

        Text {
            id: ballLabel

            text: qsTr("Tap to throw ball,\ntargets are clouds.")

            anchors.left: parent.right
            anchors.margins: game.sizeOfPixel
            anchors.verticalCenter: parent.verticalCenter

            font.family: pixelFont.name
            font.pixelSize: 2*game.sizeOfPixel
        }

        Component.onCompleted: game.paused = true
    }
    /*-----------------------------------*/

    /*------Popisek jak začít hru--------*/
    Text {
        text: qsTr("Tap anywhere to start game.")

        x: (root.width-width)/2
        y: (root.height-height)/2- 4*game.sizeOfPixel

        font.family: pixelFont.name
        font.pixelSize: 2*game.sizeOfPixel
    }

    Behavior on opacity {   //animace při mizení
        NumberAnimation { duration: 500 }
    }
    /*------------------------------------*/
}
