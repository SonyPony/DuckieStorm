#include "barrel.h"

Barrel::Barrel(QQuickItem *parent): Obstacle(parent) {
    p_index = 0;
    p_incrementedScore = false;
}

void Barrel::restart(QObject* group) {
    QObject *animation = this->findChild<QObject*>("moveAnimation");
    QObject *image = this->findChild<QObject*>("image");

    if(image->property("visible")==QVariant(true)) {
        animation->setProperty("running", false);
        image->setProperty("x", this->parent()->parent()->parent()->property("width")); //root šířka
        this->p_incrementedScore = false;

        QString name = "isAvailable["+QString::number(p_index)+"]";
        group->setProperty(name.toUtf8().constData(),true);
    }
}


