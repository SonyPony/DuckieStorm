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

        x: 14*game.sizeOfPixel
        y: 9*game.sizeOfPixel
        z: 1

        Rectangle { //červené pozadí za "HIGH"
            x: highTitle.x - 2*game.sizeOfPixel
            y: highTitle.y - 2*game.sizeOfPixel

            width: 27*game.sizeOfPixel
            height: 11*game.sizeOfPixel
            color: "red"
        }

        Text {
            id: highTitle

            text: qsTr("HIGH")
            color: "white"

            font.pixelSize: 8*game.sizeOfPixel
            font.family: pixelFont.name


        }


        Text {
            id: scoreTitle

            text: qsTr("SCORE")
            color: "orange"

            anchors.left: highTitle.right
            anchors.leftMargin: 2*game.sizeOfPixel

            font.pixelSize: 8*game.sizeOfPixel
            font.family: pixelFont.name
        }
    }
}
