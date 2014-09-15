import QtQuick 2.0
import Cloud 1.0
import DischargeArea 1.0

import "../logic/generalLogic.js" as GL
import "../logic/cloudLogic.js" as Logic

Cloud {
    id: singleCloud
    objectName: "singleCloud"

    chargePiece: cloudImage.width/fullCharge
    minCharge: (game.score>25) ?2 :1
    maxCharge: (game.score>25) ?3 :2

    /*----Vyrenderovaný obrázek blesku----*/
    Image {
        id: lightingImage
        objectName: "lightingImage"

        source: "../res/images/lightingImage.svg"
        visible: false

        y: cloudImage.y+ cloudImage.height + 15

        width: game.sizeOfPixel*6
        height: game.sizeOfPixel*9

        /*----Renderovací velikost----*/
        sourceSize.width: 6*game.sizeOfPixel
        sourceSize.height: 9*game.sizeOfPixel
        /*----------------------------*/

        anchors.horizontalCenter: cloudImage.horizontalCenter
    }
    /*-----------------------------------*/

    /*----Vyrenderovaný obrázek mraku----*/
    Image {

        id: cloudImage
        objectName: "image"

        source: clouds.imageURL

        y: 3*game.sizeOfPixel

        width: game.sizeOfPixel*26
        height: game.sizeOfPixel*14

        /*----Renderovací velikost----*/
        sourceSize.width: 26*game.sizeOfPixel
        sourceSize.height: 14*game.sizeOfPixel
        /*----------------------------*/
    }
    /*-----------------------------------*/

    /*--Oblast kam se má trefovat míčem--*/
    DischargeArea {
        id: dischargeArea
        objectName: "dischargeArea"

        y: cloudImage.y+20+ cloudImage.height

        color: "yellow"
        sizeOfPixel: game.sizeOfPixel

        minWidth: 5*game.sizeOfPixel+((game.score<=20) ?Math.abs(game.score-20)*game.sizeOfPixel :0)
        maxWidth: cloudImage.width-((game.score<=20) ?game.score*game.sizeOfPixel :20*game.sizeOfPixel)
        minHeight: 5*game.sizeOfPixel+((game.score<=12) ?Math.abs(game.score-12)*game.sizeOfPixel :0)
        maxHeight: cloudImage.height-((game.score<=12) ?game.score*game.sizeOfPixel :12*game.sizeOfPixel)

        Behavior on width {
            NumberAnimation { duration: 800; easing.type: Easing.OutCubic }
        }

        Behavior on height {
            NumberAnimation { duration: 400; easing.type: Easing.OutCubic }
        }
    }

    /*-----------------------------------*/

    /*-------Ukazatel životů mraku-------*/
    Rectangle {
        id: chargeBar
        objectName: "chargeBar"

        y: game.sizeOfPixel

        color: "yellow"
        height: game.sizeOfPixel
        width: cloudImage.width
    }
    /*-----------------------------------*/

    onXChanged: Logic.checkDischarge_and_Collision()

    onDisappear: NumberAnimation { target: singleCloud; property: "opacity"; to: 0.0; duration: 1000 }

    /*------Pořešení ubrání života-------*/
    onChargeChanged: SequentialAnimation {
                    id: dischargeAnimationSound
                    objectName: "dischargeAnimationSound"

                    ScriptAction { script: sounds.lightingSound.play() }
                    ScriptAction { script: (function() { dischargeArea.width = dischargeArea.width-((dischargeArea.width/game.sizeOfPixel>=7) ?3*game.sizeOfPixel :0); dischargeArea.height = dischargeArea.height-((dischargeArea.height/game.sizeOfPixel>=7) ?3*game.sizeOfPixel :0) })() }
                    ParallelAnimation {
                        id: dischargeAnimation

                        NumberAnimation { target: chargeBar; property: "x"; to: chargeBar.x+singleCloud.chargePiece/2; duration: 1500 }
                        NumberAnimation { target: chargeBar; property: "width"; to: chargeBar.width-singleCloud.chargePiece; duration: 1500 }
                        SequentialAnimation {   //blikání blesku
                            loops: 5
                            PropertyAnimation { target: lightingImage; property: "visible"; to: true; duration: 150 }
                            PropertyAnimation { target: lightingImage; property: "visible"; to: false; duration: 150 }
                        }
                    }

                    onRunningChanged: { //restart animace, pokud to handler nestihl
                        if(debt>0 && !dischargeAnimationSound.running) {
                            debt--;
                            dischargeAnimationSound.running = true;
                        }
                    }
    }
    /*-----------------------------------*/

    Connections {
        target: game
        onRestart: singleCloud.restart(clouds)
    }

    /*-------Animace pohybu dopředu------*/
    onStart:  SequentialAnimation {
                    id: moveAnimation
                    objectName: "moveAnimation"

                    NumberAnimation { target: singleCloud; property: "x"; from: root.width; to: 0-cloudImage.width; duration: GL.toNumberOfPixels(root.width+cloudImage.width)*clouds.speed }
                    ScriptAction { script: (function() { clouds.isAvailable[index] = true; singleCloud.opacity = 0 })() }
    }
    /*-----------------------------------*/
}
