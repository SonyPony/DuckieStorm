import QtQuick 2.0

import Tree 1.0
import "../logic/generalLogic.js" as GL

Tree {
    id: singleTree

    /*---Vyrenderovaný obrázek stromu----*/
    Image {
        id: image
        objectName: "image"

        source: "../res/images/background_treeImage.svg"
        width: 10*game.sizeOfPixel
        height: 16*game.sizeOfPixel

        sourceSize.width: 10*game.sizeOfPixel
        sourceSize.height: 16*game.sizeOfPixel
    }
    /*-----------------------------------*/

    /*-------Animace pohybu dopředu------*/
    onStart:  SequentialAnimation {
                    objectName: "moveAnimation"

                    NumberAnimation { target: singleTree; property: "x"; from: root.width; to: 0-image.width; duration: GL.toNumberOfPixels(root.width+image.width)*trees.speed }
                    ScriptAction { script: (function() { trees.isAvailable[index] = true; singleTree.visible = false })() }
    }
    /*-----------------------------------*/
}
