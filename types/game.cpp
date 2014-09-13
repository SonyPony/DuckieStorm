#include "game.h"
#include "fileIO/filestream.h"

Game::Game(QQuickItem *parent): QQuickItem(parent) {
    p_over = false;
    p_score = 0;
    p_paused = false;

    QObject::connect(this, SIGNAL(restart()), this, SLOT(gameIsOn()));
}

void Game::end() {
    QObject *scoreDialog = this->findChild<QObject*>("scoreDialog");

    if(p_highScore<p_score) {
        FileStream *file = this->findChild<FileStream*>("scoreFile");
        file->write(QString::number(p_score));
        scoreDialog->setProperty("highScore", true);
        this->p_highScore = p_score;
    }

    else
        scoreDialog->setProperty("highScore", false);

    this->p_over = true;
    this->p_paused = true;
    this->parent()->findChild<QObject*>("rootMouseArea")->setProperty("enabled", false);
    QMetaObject::invokeMethod(scoreDialog, "show");
    emit pausedChanged();
}

void Game::gameIsOn() {
    p_over = false;
}

int Game::highScore() const {
    return p_highScore;
}

bool Game::over() const {
    return p_over;
}

int Game::score() const {
    return p_score;
}

int Game::sizeOfPixel() const {
    return p_sizeOfPixel;
}

bool Game::paused() const {
    return p_paused;
}

void Game::setHighScore(int &value) {
    if(p_highScore != value) {
        p_highScore = value;
        emit highScoreChanged();
    }
}

/*void Game::setOver(bool& value) {
    if(value != p_over) {
        p_over = value;
        emit overChanged();
    }
}*/

void Game::setScore(int& value) {
    if(value != p_score) {
        p_score = value;
        emit scoreChanged();
    }
}

void Game::setSizeOfPixel(int& value) {
    if(value != p_sizeOfPixel) {
        p_sizeOfPixel = value;
        emit sizeOfPixelChanged();
    }
}

void Game::setPaused(bool& value) {
    if(value != p_paused) {
        p_paused = value;
        emit pausedChanged();
    }
}
