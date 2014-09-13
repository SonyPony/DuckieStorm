import QtQuick 2.0

Item {
    Image {
        id: duckImage

        source: duck.imageURL
        opacity: 0.3
        x: duck.defaultX
        y: duck.defaultY-duck.heightOfJump
        z: 1

        width: duck.size
        height: width

        /*----Renderovací velikost----*/
        sourceSize.width: 1400
        sourceSize.height: 1400
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

    Image {
        id: ballImage
        objectName: "ballImage"

        source: ball.imageURL
        opacity: 0.3
        x: 44*game.sizeOfPixel
        y: 12*game.sizeOfPixel
        z: 1

        height: game.sizeOfPixel * 4
        width: height

        /*----Renderovací velikost----*/
        sourceSize.width: 1100
        sourceSize.height: 1100
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

    Text {
        text: qsTr("Tap anywhere to start game.")

        x: (root.width-width)/2
        y: (root.height-height)/2- 4*game.sizeOfPixel

        font.family: pixelFont.name
        font.pixelSize: 2*game.sizeOfPixel
    }
}
