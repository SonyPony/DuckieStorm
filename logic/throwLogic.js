.import "generalLogic.js" as GL

function changeBallPosition() {
    /*-------------------Get values-------------------*/
    var CenterOfDuckX = duck.horizontalCenterWhenThrowsBall
    var CenterOfDuckY = duck.verticalCenterWhenThrowsBall

    var angle = ball.angle
    var time = ball.time
    var speed = ball.speed
    var prescale = root.width * GL.fraction(55, 850);
    var precission = time*70;
    /*-----------------------------------------------------*/

    /*-------------Počítání další pozice míče--------------*/
    ball.image.x = speed*(time/precission*ball.stepsOfThrow)*Math.cos(angle)*prescale+CenterOfDuckX;
    ball.image.y = (CenterOfDuckY)-(speed*(time/precission*ball.stepsOfThrow)*Math.sin(angle)-(0.5*10*Math.pow(time/precission*ball.stepsOfThrow,2)))*prescale;
    /*-----------------------------------------------------*/

    /*-Kontrola zda míč přesáhne okraj, pokud ne tak přejde na další pozici-*/
    if(precission<=ball.stepsOfThrow || ball.image.y>=root.height)  {
        ball.disable();
    }

    else
        ball.stepsOfThrow++;
    /*---------------------------------------------------------------------*/
}

/*|-----------------------------------------------------------------------------------
  |------------------Vypočítá informace o hodu ze souřadnic kliknutí------------------
  |----------------------------------------------------------------------------------*/

function calculateThrowInfo(x, y, speed) {  //----------------------------------------------------------
    if(!ball.isAvailable)   //kontrola zda je míč dostupný
        return;
    /*---------------Vypočítání hodnot---------------------*/
    var CenterOfDuckX = duck.defaultX + duck.image.width/2;
    var CenterOfDuckY = duck.image.y + duck.image.height/2;

    ball.angle = Math.asin((CenterOfDuckY-y)/Math.sqrt(Math.pow(x-CenterOfDuckX,2) + Math.pow(CenterOfDuckY-y,2))); //v radiánech
    ball.time = ((speed*Math.sin(ball.angle)+Math.sqrt(Math.pow(speed,2)*Math.pow(Math.sin(ball.angle),2)+2*10*(root.height-CenterOfDuckY)))/10); //v sekundách

    duck.horizontalCenterWhenThrowsBall = CenterOfDuckX;
    duck.verticalCenterWhenThrowsBall = CenterOfDuckY;
    /*-----------------------------------------------------*/

    /--*Nastavení zobrazení míče a vyvolání animace hodu--*/
    ball.enable()  //vyvolá signál na animaci
    /*----------------------------------------------------*/
}

/*|-----------------------------------------------------------------------------------
  |-----------------------Vypočítává dráhu míče na základě času-----------------------
  |----------------------------------------------------------------------------------*/

