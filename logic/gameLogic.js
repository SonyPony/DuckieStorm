function pause() {
    jumpAnimation.pause()
game.paused = true
    barrels.pause()
    clouds.pause()
barrelGenerator.pause()
    cloudGenerator.pause()
    //treeGeneratorDelay.pause()
    if(throwAnimation.running)
        throwAnimation.pause()
    else
        ball.isAvailable = false
    console.log("paused")
}

function resume() {
    jumpAnimation.resume()
    game.paused = false
barrels.resume()
    clouds.resume()
    barrelGenerator.resume()
    //treeGeneratorDelay.resume()
    cloudGenerator.resume()
    //trees.resume()
    console.log("resumed")
    if(ball.image.visible)
        throwAnimation.resume()
    else
        ball.isAvailable = true
}

function end() {
    if(game.highScore<game.score) {
        scoreFile.write(game.score)
        scoreDialog.highScore = true
    }

    pause()
    rootMouseArea.enabled = false
    game.over = true
    scoreDialog.showUp()
}
