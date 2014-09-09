function end() {
    if(game.highScore<game.score) {
        scoreFile.write(game.score)
        scoreDialog.highScore = true
    }

    else {
        scoreDialog.highScore = false
    }

    pause()
    rootMouseArea.enabled = false
    game.over = true
    scoreDialog.show()
}
