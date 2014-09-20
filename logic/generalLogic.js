/*|File: generalLogic.js
  |Author: Son Hai Nguyen
  |License: LGPL
  |*/

/*|-----------------------------------------------------------------------------------
  |------------------------------Vrací podíl dvou čísel-------------------------------
  |----------------------------------------------------------------------------------*/

function fraction(numberOne, numberTwo) {
    return numberOne/numberTwo;
}

/*|-----------------------------------------------------------------------------------
  |---------------------Vrací trvání animace na základě root okna---------------------
  |----------------------------------------------------------------------------------*/

function duration(width, height, pDuration) {
    var ratio = pDuration/(width/height);
    return ratio*(root.width/root.height);
}

/*|-----------------------------------------------------------------------------------
  |------------------------------z pixelů na game pixely------------------------------
  |----------------------------------------------------------------------------------*/

function toNumberOfPixels(value) {
    return Math.floor(value/game.sizeOfPixel);
}

function pixels(density, mm) {
    return density*mm;
}
