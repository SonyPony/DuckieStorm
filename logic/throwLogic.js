.import "generalLogic.js" as GL

/*|-----------------------------------------------------------------------------------
  |-----------------------Vypočítává dráhu míče na základě času-----------------------
  |----------------------------------------------------------------------------------*/

function changeBallPosition() { //----------------------------------------------------------
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

