#include "barrels.h"

Barrels::Barrels(QQuickItem *parent): Obstacles(parent) {
    p_spawnTimeLowLimit = 950;
    p_spawnTimeHightLimit = 2000;
    p_maximumAmount = 8;
    p_speed = 21.698;   //kolik zabere milisekund na posunutí o 1 gam pixel
    this->setImageURL(QUrl("../res/images/barrelImage.svg"));
}

void Barrels::handleGamePause() {
    QObject *animation = this->findChild<QObject*>("barrelGenerator");

    if(this->parent()->property("paused")==QVariant(true)) {
        this->pause();
        QMetaObject::invokeMethod(animation, "pause");
    }

    else {
        this->resume();
        QMetaObject::invokeMethod(animation, "resume");
    }
}

