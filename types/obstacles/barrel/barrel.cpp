#include "barrel.h"

Barrel::Barrel(QQuickItem *parent): Obstacle(parent) {
    p_index = 0;
    p_incrementedScore = false;
}

/*void Barrel::restart() {
    QObject *animation = this->findChild<QObject*>("moveAnimation");
    QObject *image = this->findChild<QObject*>("image");


}*/


