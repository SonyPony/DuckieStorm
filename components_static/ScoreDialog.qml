import QtQuick 2.0
import "../logic/generalLogic.js" as GL

Item {
    id: scoreDialog

    property bool highScore: true

    x: (root.width-frame.width)/2
    y: (root.height-frame.height)/2 - 4*game.sizeOfPixel

    /*---------------Frame---------------*/
    Image {
        z: 0
        id: frame
        source: "../res/images/scoredialog_frame.svg"

        width: 79*game.sizeOfPixel
        height: 34*game.sizeOfPixel

        /*----Renderovací velikost----*/
        sourceSize.width: 79*game.sizeOfPixel
        sourceSize.height: 34*game.sizeOfPixel
        /*----------------------------*/
    }
    /*-----------------------------------*/

    /*--------(HIGH) SCORE popisek-------*/
    Item {
        id: title

        y: 9*game.sizeOfPixel
        z: 1

        height: 8*game.sizeOfPixel
        width: highTitle.width + scoreTitle.width //+ 2*game.sizeOfPixel

        anchors.horizontalCenter: frame.horizontalCenter

        Rectangle { //červené pozadí za "HIGH"
            id: highBackground

            color: "red"

            x: highTitle.x - 2*game.sizeOfPixel
            y: highTitle.y - 2*game.sizeOfPixel

            width: (highScore) ?27*game.sizeOfPixel :0
            height: 11*game.sizeOfPixel 
        }

        Text {
            id: highTitle

            text: (highScore) ?qsTr("HIGH") :""
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
    /*-----------------------------------*/

    /*------Výpis scóre do dialogu-------*/
    Text {
        id: scoreText

        text: game.score
        color: "black"

        anchors.topMargin: 3*game.sizeOfPixel
        anchors.top: title.bottom
        anchors.horizontalCenter: frame.horizontalCenter

        font.pixelSize: 8*game.sizeOfPixel
        font.family: pixelFont.name
    }
    /*-----------------------------------*/
}
