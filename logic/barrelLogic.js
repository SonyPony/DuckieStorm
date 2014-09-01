.import "../res/shapes.js" as Shapes

/*|-----------------------------------------------------------------------------------
  |------------------------Pausne animaci a nastaví dostupnost------------------------
  |----------------------------------------------------------------------------------*/

function pause() {  //---------------------------------------------------------------------------smazat
    if(game.paused) {
        if(moveAnimation.running)
            moveAnimation.pause()
        else
            singleBarrel.test(barrels)
            //barrels.isAvailable[index] = false
    }
}

/*|-----------------------------------------------------------------------------------
  |----------------------Inicializuje barely a jejich vlastnosti----------------------
  |----------------------------------------------------------------------------------*/

function initBarrels() {
    var component

    for(var i = 0; i<barrels.maximumAmount; i++) {
        barrels.isAvailable[i] = true;

        component = Qt.createComponent("../components_dynamic/barrel.qml");
        barrels.objects[i] = component.createObject(graphics);

        barrels.objects[i].index = i;
    }
}

/*|-----------------------------------------------------------------------------------
  |--------------------------Inicializuje okrajové obdelníky--------------------------
  |----------------------------------------------------------------------------------*/

function initOutlines() {
    var shape = Shapes.getBarrelShape();

     /*------------Zjištění výšky prvního pixelu-------------*/
    var outlinePixels = new Array(Shapes.getBarrelNumberOfPixels());
    var firstPixelHeight = new Array;

    for(var x = 0; x<Shapes.getBarrelNumberOfPixels(); x++) {
        for(var y in shape) {
            if(shape[y][x]=="d" || shape[y][x]=="g" || shape[y][x]=="l") {
                firstPixelHeight[x] = y;
                break;
            }
        }
    }
    /*------------------------------------------------------*/

    /*------------Vytvoření okrajových obdelníků------------*/
    var i = 0;
    var component

    singleBarrel.outlines = [];

    for(var key in firstPixelHeight) {
        if(firstPixelHeight[key-1]==firstPixelHeight[key])
            singleBarrel.outlines[i-1].width += game.sizeOfPixel;

        else {
            component = Qt.createComponent("../components_dynamic/outlineRectangle.qml");
            singleBarrel.outlines[i] = component.createObject(barrelImage)//barrels.objects[i]);

            singleBarrel.outlines[i].x = 1+key*game.sizeOfPixel;
            singleBarrel.outlines[i].y = (parseInt(firstPixelHeight[key]))*game.sizeOfPixel;
            singleBarrel.outlines[i++].width = game.sizeOfPixel;
        }
    }
     /*------------------------------------------------------*/
}

/*|-----------------------------------------------------------------------------------
  |------------------------Najde dostupný barel a pošle signál------------------------
  |----------------------------------------------------------------------------------*/

function sendBarrel() {     //----------------------------------------------------------------------------------
    for(var key in barrels.objects)
        if(barrels.isAvailable[key]) {
            barrelGeneratorDelay.duration = Math.floor(Math.random()*(barrels.spawnTimeHighLimit-barrels.spawnTimeLowLimit)+barrels.spawnTimeLowLimit);
            barrels.isAvailable[key] = false;
            barrels.objects[key].start();
            break;
        }
}

/*|-----------------------------------------------------------------------------------
  |-----------Při změně velikosti okna změní velikost okrajových objedníků------------
  |----------------------------------------------------------------------------------*/

function updateOutlines() {
    var shape = Shapes.getBarrelShape();

    /*------------Zjištění výšky prvního pixelu-------------*/
    var outlinePixels = new Array(Shapes.getBarrelNumberOfPixels());
    var firstPixelHeight = new Array;

    for(var x = 0; x<Shapes.getBarrelNumberOfPixels(); x++) {
        for(var y in shape) {
            if(shape[y][x]=="d" || shape[y][x]=="g" || shape[y][x]=="l") {
                firstPixelHeight[x] = y;
                break;
            }
        }
    }
    /*------------------------------------------------------*/

    /*------------Vytvoření okrajových obdelníků------------*/
    var index;

    for(var i = 0; i<barrels.maximumAmount; i++) {
        index = 0;

        for(var key in firstPixelHeight) {
            if(firstPixelHeight[key-1]==firstPixelHeight[key])
                barrels.objects[i].outlines[index-1].width += game.sizeOfPixel;

            else {
                barrels.objects[i].outlines[index].x = 1+key*game.sizeOfPixel;
                barrels.objects[i].outlines[index].y = (parseInt(firstPixelHeight[key]))*game.sizeOfPixel;
                barrels.objects[i].outlines[index++].width = game.sizeOfPixel;
            }
        }
    }
     /*------------------------------------------------------*/
}
