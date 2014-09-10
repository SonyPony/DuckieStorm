#include "obstacles.h"

Obstacles::Obstacles(QQuickItem *parent): VisibleItem(parent) {}

void Obstacles::handleGamePause() {
    QObject *animation = this->findChild<QObject*>("generator");

    if(this->parent()->property("paused")==QVariant(true)) {
        this->pause();
        QMetaObject::invokeMethod(animation, "pause");
    }

    else {
        this->resume();
        QMetaObject::invokeMethod(animation, "resume");
    }
}

void Obstacles::pause() {
    QVariantList *enable = new QVariantList;
    QObject* animation;
    QObject* object;
    QObject* dischargeAnimation;

    for(int i = 0;  i<p_maximumAmount; i++) {
        enable->append(false);

        object = qvariant_cast<QObject*>(this->property("objects").toList()[i]);
        animation = object->findChild<QObject*>("moveAnimation");
        if(animation->property("running")==QVariant(true)) {
            QMetaObject::invokeMethod(animation, "pause");

            if(object->objectName()=="singleCloud") {
                dischargeAnimation = object->findChild<QObject*>("dischargeAnimationSound");

                if(dischargeAnimation->property("running")==QVariant(true))
                    QMetaObject::invokeMethod(dischargeAnimation, "pause");
            }
        }
    }

    this->setProperty("isAvailable", *enable);

    delete enable;
    enable = 0;
}

void Obstacles::resume() {
    QVariantList *enable = new QVariantList;
    QObject* animation;
    QObject* object;
    QObject* dischargeAnimation;

    for(int i = 0; i<p_maximumAmount; i++) {
        object = qvariant_cast<QObject*>(this->property("objects").toList()[i]);
        animation = object->findChild<QObject*>("moveAnimation");

        if(animation->property("running")==QVariant(true)) {
            enable->append(false);
            QMetaObject::invokeMethod(animation,"resume");

            if(object->objectName()=="singleCloud") {
                dischargeAnimation = object->findChild<QObject*>("dischargeAnimationSound");

                if(dischargeAnimation->property("running")==QVariant(true))
                    QMetaObject::invokeMethod(dischargeAnimation, "resume");
            }
        }

        else
            enable->append(true);
    }

    this->setProperty("isAvailable", *enable);

    delete enable;
    enable = 0;
}

int Obstacles::spawnTimeLowLimit() const {
    return p_spawnTimeLowLimit;
}

int Obstacles::spawnTimeHighLimit() const {
    return p_spawnTimeHightLimit;
}

int Obstacles::maximumAmount() const {
    return p_maximumAmount;
}


qreal Obstacles::speed() const {
    return p_speed;
}

void Obstacles::setSpeed(qreal &value) {
    if(value != p_speed) {
        p_speed = value;
        emit speedChanged();
    }
}
