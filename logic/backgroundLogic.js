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

function sendTree() {       //-----------------------------------------------------------------------
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

function initFirstTrees() {
    var component;

    var highLimit = 2*game.sizeOfPixel
    var lowLimit = 0.5*game.sizeOfPixel
    var previousX = 0;

    for(var i = 0; i<Math.floor(GL.toNumberOfPixels(root.width)*GL.fraction(10, GL.toNumberOfPixels(root.width))); i++) {
        component = Qt.createComponent("../components_dynamic/tree.qml");
        firstTrees.objects[i] = component.createObject(firstTrees);
        firstTrees.objects[i].x = (i) ?(Math.floor(Math.random()*(highLimit-lowLimit)) + lowLimit + previousX + ((i) ?10*game.sizeOfPixel :0)) :0
        previousX = firstTrees.objects[i].x
        firstTrees.objects[i].y = (graphics.edgeOfGrass.y+graphics.edgeOfGrass.height+graphics.grass.height) - game.sizeOfPixel*Math.floor(Math.random()*( GL.toNumberOfPixels(graphics.grass.height)+1 )) - 16*game.sizeOfPixel;
        firstTrees.objects[i].visible = true;
    }

    firstTrees.width = firstTrees.objects[firstTrees.objects.length-1].x + 10*game.sizeOfPixel
    treesMoveAnimation.start()
    treesMoveAnimation.pause()
}
