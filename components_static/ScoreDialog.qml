import QtQuick 2.0
import "../logic/generalLogic.js" as GL

Item {
    id: scoreDialog
    x: 20
    y: 20

    Image {
        z: 0
        id: frame
        source: "../res/images/scoredialog_frame.svg"

        width: 79*game.sizeOfPixel
        height: 34*game.sizeOfPixel

        /*----Renderovací velikost----*/
        sourceSize.width: 790
        sourceSize.height: 340
        /*----------------------------*/
    }

    Item {
        z: 1

        anchors.horizontalCenter: frame.verticalCenter
        anchors.verticalCenter: frame.verticalCenter

        Rectangle {
            id: highBackground

            width: childrenRect.width
            height: childrenRect.height
            color: "red"

            Text {
                id: highTitle

                text: qsTr("HIGH")
                color: "white"

                font.pixelSize: 7*game.sizeOfPixel
                font.family: pixelFont.name
            }
        }

        Text {
            id: scoreTitle

            text: qsTr("SCORE")
            color: "orange"

            anchors.left: highBackground.right

            font.pixelSize: 7*game.sizeOfPixel
            font.family: pixelFont.name
        }
    }
}
