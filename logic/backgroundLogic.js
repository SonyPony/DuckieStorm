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
