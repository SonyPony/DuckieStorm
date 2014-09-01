#include "barrel.h"

Barrel::Barrel(QQuickItem *parent): Obstacle(parent) {
    p_index = 0;
    p_incrementedScore = false;
}


