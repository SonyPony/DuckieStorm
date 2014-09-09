/*|-----------------------------------------------------------------------------------
  |--------------------------------Kontroluje kolizi----------------------------------
  |----------------------------------------------------------------------------------*/

function checkCollision() {
    var outlineX = outlineRectangle.x + parent.x;
    var outlineY = outlineRectangle.y + parent.y;
    var outlineWidth = outlineRectangle.width;

    var duckX;
    var duckY;
    var duckWidth;

    if(outlineX <= duck.defaultX+duck.size && outlineX >= duck.defaultX && !parent.parent.incrementedScore) {
        for(var key in duck.outlines) {
            duckX = duck.outlines[key].x + duck.defaultX;
            duckY = duck.outlines[key].y + duck.image.y;
            duckWidth = duck.outlines[key].width;

            if(duckX>outlineX+outlineWidth)
                break;

            else if((outlineX <= duckX && outlineX+outlineWidth >= duckX) || (outlineX >= duckX && outlineX <= duckX+duckWidth))
                if(outlineY<=duckY)
                    return true;
        }
    }
    return false;
}

/*|-----------------------------------------------------------------------------------
  |----------------------Kontroluje zda je barel za kachničkou------------------------
  |----------------------------------------------------------------------------------*/

function isBehind() {
    if(parent.x+parent.width < duck.image.x)
        return true;
}

/*|-----------------------------------------------------------------------------------
  |-----------------------------Zvýší skóre a zapne zvuk------------------------------
  |----------------------------------------------------------------------------------*/

function incrementScore() {
    if(isBehind() && !parent.parent.incrementedScore) {
        game.score++;

        if(sounds.scoreSound.isPlaying)
            sounds.scoreSound.stop()
        sounds.scoreSound.play()

        parent.parent.incrementedScore = true;
    }

    else if(checkCollision()) {
        game.end()
        parent.parent.incrementedScore = true;
    }
}

