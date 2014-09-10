import QtQuick 2.0
import Cloud 1.0

import "../logic/generalLogic.js" as GL
import "../logic/cloudLogic.js" as Logic

Cloud {
    id: singleCloud
    objectName: "singleCloud"

    chargePiece: cloudImage.width/(2)

    /*----Vyrenderovaný obrázek blesku----*/
    Image {
        id: lightingImage
        source: "../res/images/lightingImage.svg"

        visible: false

        y: cloudImage.y+ cloudImage.height + 15

        width: game.sizeOfPixel*6
        height: game.sizeOfPixel*9

        /*----Renderovací velikost----*/
        sourceSize.width: 600
        sourceSize.height: 900
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
        sourceSize.width: 2600
        sourceSize.height: 1400
        /*----------------------------*/
    }
    /*-----------------------------------*/

    /*--Oblast kam se má trefovat míčem--*/
    Rectangle {
        id: dischargeArea

        color: "yellow"
        opacity: 0.1
        width: root.width*GL.fraction(150, 854)  //změnit
        height: root.height*GL.fraction(80,480)  //změnit
        y: cloudImage.y+20+ cloudImage.height
        anchors.horizontalCenter: cloudImage.horizontalCenter
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
                    objectName: "dischargeAnimationSound"

                    ScriptAction { script: sounds.lightingSound.play() }

                    ParallelAnimation {
                        id: dischargeAnimation

                        NumberAnimation { target: chargeBar; property: "x"; to: chargeBar.x+singleCloud.chargePiece/2; duration: 1500 }
                        NumberAnimation { target: chargeBar; property: "width"; to: chargeBar.width-singleCloud.chargePiece; duration: 1500 }
                        SequentialAnimation {   //blikání blesku
                            loops: 5
                            PropertyAnimation { target: lightingImage; property: "visible"; to: true; duration: 150 }
                            PropertyAnimation { target: lightingImage; property: "visible"; to: false; duration: 150 }
                        }

                        onRunningChanged: { //restart animace, pokud to handler nestihl
                            if(debt>0 && !dischargeAnimation.running) {
                                debt--;
                                dischargeAnimation.running = true;
                            }
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

                    NumberAnimation { target: singleCloud; property: "x"; from: root.width; to: 0-cloudImage.width; duration: GL.toNumberOfPixels(root.width)*clouds.speed }
                    ScriptAction { script: (function() { clouds.isAvailable[index] = true; singleCloud.opacity = 0 })() }
    }
    /*-----------------------------------*/
}
