/*|File: backgroundLogic.js
  |Author: Son Hai Nguyen
  |License: LGPL
  |*/

.import "generalLogic.js" as GL

/*|-----------------------------------------------------------------------------------
  |----------------------Inicializuje stromy a jejich vlastnosti----------------------
  |----------------------------------------------------------------------------------*/

function initTrees() {
    var component;

    for(var i = 0; i<trees.maximumAmount; i++) {
        trees.isAvailable[i] = true;

        component = Qt.createComponent("../components_dynamic/tree.qml");
        trees.objects[i] = component.createObject(graphics);
        trees.objects[i].index = i;
    }
}

/*|-----------------------------------------------------------------------------------
  |------------------------Nastaví data a zapne animaci stromu------------------------
  |----------------------------------------------------------------------------------*/

function sendTree() {
    for(var key in trees.objects)
        if(trees.isAvailable[key]) {
            treeGeneratorDelay.duration = Math.floor(Math.random()*(trees.spawnTimeHighLimit-trees.spawnTimeLowLimit)+trees.spawnTimeLowLimit);
            trees.isAvailable[key] = false;
            trees.objects[key].y = (graphics.edgeOfGrass.y+graphics.edgeOfGrass.height+graphics.grass.height) - game.sizeOfPixel*Math.floor(Math.random()*( GL.toNumberOfPixels(graphics.grass.height)+1 )) - 16*game.sizeOfPixel;
            trees.objects[key].visible = true;
            trees.objects[key].start();
            break;
        }
}

/*|-----------------------------------------------------------------------------------
  |--------------------Nastaví data a zapne animaci prvních stromu--------------------
  |----------------------------------------------------------------------------------*/

function initFirstTrees() {
    var component;

    var highLimit = 2*game.sizeOfPixel
    var lowLimit = 0.5*game.sizeOfPixel
    var previousX = 0;
    var numberOfTrees = Math.floor(GL.toNumberOfPixels(root.width)/10.75)

    for(var i = 0; i<numberOfTrees; i++) {
        component = Qt.createComponent("../components_dynamic/tree.qml");

        graphics.firstTrees.objects[i] = component.createObject(graphics.firstTrees);
        graphics.firstTrees.objects[i].x = (i) ?(Math.floor(Math.random()*(highLimit-lowLimit)) + lowLimit + previousX + ((i) ?10*game.sizeOfPixel :0)) :0
        graphics.firstTrees.objects[i].y = (graphics.edgeOfGrass.y+graphics.edgeOfGrass.height+graphics.grass.height) - game.sizeOfPixel*Math.floor(Math.random()*( GL.toNumberOfPixels(graphics.grass.height)+1 )) - 16*game.sizeOfPixel;
        graphics.firstTrees.objects[i].visible = true;

        previousX = graphics.firstTrees.objects[i].x
    }

    graphics.firstTrees.width = graphics.firstTrees.objects[graphics.firstTrees.objects.length-1].x + 10*game.sizeOfPixel
    graphics.treesMoveAnimation.start()  //init animace
    graphics.treesMoveAnimation.pause()
}
