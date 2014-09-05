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
