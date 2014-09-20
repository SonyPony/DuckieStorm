/*|File: outlineRectangle.qml
  |Author: Son Hai Nguyen
  |License: LGPL
  |*/

import QtQuick 2.0
import Outline 1.0

import "../logic/collisionLogic.js" as Logic

Outline { //okrajový obdelník na kontrolování kolize předmětů
    id: outlineRectangle

    height: 1

    /*---DEBUG---*/
    visible: true
    color: "red"
    z: 10
    /*-----------*/

    Component.onCompleted:
        if(parent.parent.index==0)    //parent.parent = barrel
            parent.onXChanged.connect(Logic.incrementScore)
}
