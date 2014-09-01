.import "../res/shapes.js" as Shapes

/*|-----------------------------------------------------------------------------------
  |--Vytvoří obrys tvořený obdelníky z pole, které obsahuje zomístění pixelů objektu--
  |----------------------------------------------------------------------------------*/

function initOutlines() {
    var shape = Shapes.getDuckShape();

    /*----Zjištění výšky pixelu umístěném v poli(shape)----*/
    var outlinePixels = new Array(Shapes.getDuckNumberOfPixels("row"));
    var lastPixelHeight;

    for(var x = 0; x<Shapes.getDuckNumberOfPixels("row"); x++) {
        for(var y in shape) {
            if( shape[y][x] && shape[y][x] != "0" )
                lastPixelHeight = y;
        }
        outlinePixels[x] = lastPixelHeight;
    }
    /*------------------------------------------------------*/

    /*-------Dynamické vytvoření okrajových obdelníků-------*/
    duck.outlines = [];
    var component;
    var i = 0 ;

    for(var key in outlinePixels) {
        if(outlinePixels[key-1]==outlinePixels[key]) {
            duck.outlines[i-1].width += game.sizeOfPixel;
        }

        else {
            component = Qt.createComponent("../components_dynamic/outlineRectangle.qml");
            duck.outlines[i] = component.createObject(duck.image);

            duck.outlines[i].x = key*game.sizeOfPixel;
            duck.outlines[i].y = (1+parseInt(outlinePixels[key]))*game.sizeOfPixel-1;
            duck.outlines[i++].width = game.sizeOfPixel;
        }
    }
    /*------------------------------------------------------*/
}

/*|-----------------------------------------------------------------------------------
  |------------Mění "y" hodnoty okrajových obdelníků při skoku kachničky--------------
  |---------------------------------------------------------------------------------*/

function updateOutlines() {
    var shape = Shapes.getDuckShape();


    var outlinePixels = new Array(Shapes.getDuckNumberOfPixels("row"));
    var lastPixelHeight;

    for(var x = 0; x<Shapes.getDuckNumberOfPixels("row"); x++) {
        for(var y in shape) {
            if( shape[y][x] && shape[y][x] != "0" )
                lastPixelHeight = y;
        }
        outlinePixels[x] = lastPixelHeight;
    }

    var i = 0 ;

    for(var key in outlinePixels) {
        if(outlinePixels[key-1]==outlinePixels[key]) {
            duck.outlines[i-1].width += game.sizeOfPixel;
        }

        else {
            duck.outlines[i].x = key*game.sizeOfPixel;
            duck.outlines[i].y = (1+parseInt(outlinePixels[key]))*game.sizeOfPixel;
            duck.outlines[i++].width = game.sizeOfPixel;
        }
    }
}
