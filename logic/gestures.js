/*|File: gestures.js
  |Author: Son Hai Nguyen
  |License: LGPL
  |*/

function checkSlide(y1, y2, lenghtOfSlide) {    //není přítomnost eventů na slide
    if(Math.abs(y1-y2)>=lenghtOfSlide && root.mousePressed) {
        root.touchY = y2;

        if(y1>y2)
            return "slide up";
        else
            return "slide down";
    }

    else
        return 0;
}

function checkClick(pressX, pressY, releaseX, releaseY, tolerance) {    //"onClicked" nemá toleranci
    if( (pressX+tolerance>=releaseX && pressX-tolerance<=releaseX) && (pressY+tolerance>=releaseY && pressY-tolerance<=releaseY))
        return true;
    else
        return false;
}

