import QtQuick 2.0
import ScoreDialog 1.0
import "../logic/generalLogic.js" as GL

ScoreDialog {
    id: scoreDialog

    x: (root.width-frame.width)/2

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

    /*------Tlačítko na restart hry------*/
    Text {
        id: retryButton

        text: qsTr("RETRY")
        color: "black"

        anchors.bottom: frame.bottom
        anchors.right: frame.right
        anchors.margins: 4*game.sizeOfPixel

        font.pixelSize: 4*game.sizeOfPixel
        font.family: pixelFont.name

        MouseArea {
            propagateComposedEvents: true
            anchors.fill: parent

            onClicked: {
                game.restart()
                rootMouseArea.enabled = true
                game.paused = false
            }
        }
    }
    /*-----------------------------------*/

    /*-----------Tlačítko na FB----------*/
    Image {
        id: facebookButton

        source: "../res/images/scoredialog_FBButton.svg"
        width: 4.5*game.sizeOfPixel
        height: width

        anchors.left: frame.left
        anchors.bottom: frame.bottom
        anchors.margins: 5*game.sizeOfPixel

        /*----Renderovací velikost----*/
        sourceSize.width: 900
        sourceSize.height: 900
        /*----------------------------*/

        MouseArea {
            anchors.fill: parent

            onClicked: Qt.openUrlExternally("https://www.facebook.com/groups/301547260027606/")
        }
    }
    /*-----------------------------------*/

    onHide: SequentialAnimation {
        NumberAnimation { target: scoreDialog; property: "y"; from: scoreDialog.y; to: root.height; duration: 800; easing.type: Easing.InOutCubic }
        ScriptAction { script: (function() { game.score = 0; graphics.scoreText.color = "white" })() }
    }

    onShow: SequentialAnimation {
            ScriptAction { script: scoreDialog.visible = true }
            NumberAnimation { target: scoreDialog; property: "y"; from: root.height; to: (root.height-frame.height)/2 - 4*game.sizeOfPixel; duration: 800; easing.type: Easing.InOutCubic }
        }
}
