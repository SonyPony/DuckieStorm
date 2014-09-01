#include "barrels.h"

Barrels::Barrels(QQuickItem *parent): Obstacles(parent) {
    p_spawnTimeLowLimit = 950;
    p_spawnTimeHightLimit = 2000;
    p_maximumAmount = 8;
    p_speed = 21.698;   //kolik zabere milisekund na posunutí o 1 gam pixel
    p_imageURL = QUrl("../res/barrelImage.svg");
}

/*void Barrels::pause() {
    QVariantList *enable = new QVariantList;
    QObject* animation;

    for(int i = 0;  i<p_maximumAmount; i++) {
        enable->append(false);

        animation = qvariant_cast<QObject*>(this->property("objects").toList()[i])->findChild<QObject*>("moveAnimation");
        if(animation->property("running")==QVariant(true)) {
            QMetaObject::invokeMethod(animation, "pause");
        }
    }

    this->setProperty("isAvailable", *enable);

    delete enable;
    enable = 0;
}*/

/*void Barrels::resume() {
    QVariantList *enable = new QVariantList;
    QObject* animation;

    for(int i = 0; i<p_maximumAmount; i++) {
        animation = qvariant_cast<QObject*>(this->property("objects").toList()[i])->findChild<QObject*>("moveAnimation");

        if(animation->property("running")==QVariant(true)) {
            enable->append(false);
            QMetaObject::invokeMethod(animation,"resume");
        }

        else
            enable->append(true);
    }

    this->setProperty("isAvailable", *enable);

    delete enable;
    enable = 0;
}*/
