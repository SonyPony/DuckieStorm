/*|-----------------------------------------------------------------------------------
  |----------------------Inicializuje mraky a jejich vlastnosti-----------------------
  |----------------------------------------------------------------------------------*/

function initClouds() {
    var component;

    for(var i=0; i<clouds.maximumAmount; i++) {
        clouds.isAvailable[i] = true;

        component = Qt.createComponent("../components_dynamic/cloud.qml");
        clouds.objects[i] = component.createObject(graphics);
        clouds.objects[i].index = i;
    }
}

/*|-----------------------------------------------------------------------------------
  |----------------------Znedostupní mrak a zapne animaci pohybu----------------------
  |----------------------------------------------------------------------------------*/

function sendCloud() {      //------------------------------------------------------------------------
    for(var key in clouds.objects)
        if(clouds.isAvailable[key]) {
            cloudGeneratorDelay.duration = Math.floor(Math.random()*(clouds.spawnTimeHighLimit-clouds.spawnTimeLowLimit)+clouds.spawnTimeLowLimit);
            clouds.isAvailable[key] = false;
            clouds.objects[key].start();
            break;
        }
}

/*|-----------------------------------------------------------------------------------
  |------------------------------Kotrola kolize s míčem-------------------------------
  |----------------------------------------------------------------------------------*/

function checkDischarge_and_Collision() {       //--------------------------------------------------------??????????????????
    if(singleCloud.active && dischargeArea.x+singleCloud.x<=duck.image.x+duck.image.width)
        game.score = 0
    if(singleCloud.active && singleCloud.x+dischargeArea.x <= ball.image.x && singleCloud.x+dischargeArea.x+dischargeArea.width >= ball.image.x+ball.image.width && dischargeArea.y <= ball.image.y+ball.image.y && dischargeArea.y+dischargeArea.height >= ball.image.y && !ball.isAvailable) {
        /*------Zmizení míče------*/
        ball.disable();
        /*------------------------*/

        /*--Ubrání náboje mraku---*/
        if(dischargeAnimation.running)
            debt++;

        singleCloud.charge = (singleCloud.charge-1 > 0) ?singleCloud.charge-1 :0;

        if(singleCloud.charge==0)
            singleCloud.disappear(false);
        /*------------------------*/
    }
}

