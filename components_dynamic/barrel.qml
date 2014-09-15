import QtQuick 2.0
import Barrel 1.0

import "../logic/barrelLogic.js" as Logic
import "../logic/generalLogic.js" as GL

Barrel {   //jeden objekt barelu
    id: singleBarrel

    /*---Okrajové obdelníky---*/
    property var outlines
    /*------------------------*/

    z: 1

    /*---Vyrenderovaný obrázek barelu----*/
    Image {
        id: barrelImage
        objectName: "image"

        source: barrels.imageURL
        visible: false

        y: root.height - game.sizeOfPixel * 11 - game.sizeOfPixel * 2

        width: game.sizeOfPixel * 11
        height: width

        /*----Renderovací velikost----*/
        sourceSize.width: 1100
        sourceSize.height: 1100
        /*----------------------------*/
    }

    Component.onCompleted: {
        Logic.initOutlines()
    }

    Connections {
        target: game
        onRestart: singleBarrel.restart(barrels)
    }

    /*-----------------------------------*/

    /*-------Animace pohybu dopředu------*/
    onStart:  SequentialAnimation {
                    id: moveAnimation
                    objectName: "moveAnimation"

                    ScriptAction { script: (function() { barrelImage.visible = true; singleBarrel.incrementedScore = false })() }
                    NumberAnimation { target: barrelImage; property: "x"; from: root.width; to: 0-barrelImage.width; duration: GL.toNumberOfPixels(root.width+barrelImage.width)*barrels.speed }
                    ScriptAction { script: (function() { barrels.isAvailable[index] = true; barrelImage.visible = false})() }
    }
    /*-----------------------------------*/


}
