#include "scoredialog.h"

ScoreDialog::ScoreDialog(QQuickItem *parent): QQuickItem(parent) {
    p_highScore = false;
    this->setProperty("visible", false);
}

bool ScoreDialog::highScore() const {
    return p_highScore;
}

void ScoreDialog::setHighScore(bool &value) {
    if(value != p_highScore) {
        p_highScore = value;
        emit highScoreChanged();
    }
}
