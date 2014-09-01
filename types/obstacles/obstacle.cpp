#include "obstacle.h"

Obstacle::Obstacle(QQuickItem *parent): QQuickItem(parent) {}

int Obstacle::index() const {
    return p_index;
}

bool Obstacle::incrementedScore() const {
    return p_incrementedScore;
}

void Obstacle::setIndex(int& value) {
    if(value != p_index) {
        p_index = value;
        emit indexChanged();
    }
}

void Obstacle::setIncrementedScore(bool& value) {
    if(value != p_incrementedScore) {
        p_incrementedScore = value;
        emit incrementedScoreChanged();
    }
}
