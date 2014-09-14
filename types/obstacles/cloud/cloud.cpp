#include "cloud.h"
#include <QTime>
#include "dischargearea/dischargearea.h"

Cloud::Cloud(QQuickItem *parent): Obstacle(parent) {
    p_index = 0;
    p_incrementedScore = false;
    p_debt = 0;
    p_active = false;
    p_minCharge = 1;
    p_maxCharge = 2;

    this->setOpacity(0);

    QObject::connect(this, SIGNAL(start()), this, SLOT(restore()));
    QObject::connect(this, SIGNAL(start()), this, SLOT(setActive()));
    QObject::connect(this, SIGNAL(disappear()), this, SLOT(setActive()));
}

void Cloud::restart(QObject* group) {
    QObject *animation = this->findChild<QObject*>("moveAnimation");

    if(this->opacity()==QVariant(1.0)) {
        animation->setProperty("running",false);
        this->setProperty("x", group->parent()->parent()->property("width"));
        this->p_incrementedScore = false;

        QString name = "isAvailable["+QString::number(p_index)+"]";
        group->setProperty(name.toUtf8().constData(),true);
    }
}

void Cloud::restore() {
    qsrand(QTime::currentTime().msec());

    QObject *disAnimation = this->findChild<QObject*>("dischargeAnimationSound");
    QObject *lightingImage = this->findChild<QObject*>("lightingImage");
    QObject *chargeBar = this->findChild<QObject*>("chargeBar");
    QObject *image = this->findChild<QObject*>("image");
    DischargeArea *dischargeArea = this->findChild<DischargeArea*>("dischargeArea");

    disAnimation->setProperty("running", false);
    lightingImage->setProperty("visible", false);

    chargeBar->setProperty("x", 0);
    chargeBar->setProperty("width", image->property("width"));

    dischargeArea->setRandomSize();
    dischargeArea->setProperty("x", rand()%(image->property("width").toInt()- dischargeArea->property("width").toInt() +1));

    this->p_fullCharge = rand()%(p_maxCharge-p_minCharge+1)+p_minCharge;
    this->p_charge = this->fullCharge();
    this->p_debt = 0;
    this->setProperty("opacity", 1.0);

    emit fullChargeChanged();
}

int Cloud::minCharge() const {
    return p_minCharge;
}

int Cloud::maxCharge() const {
    return p_maxCharge;
}

int Cloud::fullCharge() const {
    return p_fullCharge;
}

bool Cloud::active() const {
    return p_active;
}

int Cloud::debt() const {
    return p_debt;
}

int Cloud::charge() const {
    return p_charge;
}

int Cloud::chargePiece() const {
    return p_chargePiece;
}

void Cloud::setDebt(int& value) {
    if(value != p_debt) {
        p_debt = value;
        emit debtChanged();
    }
}

void Cloud::setMinCharge(int &value) {
    if(value != p_minCharge) {
        p_minCharge = value;
        emit minChargeChanged();
    }
}

void Cloud::setMaxCharge(int &value) {
    if(value != p_maxCharge) {
        p_maxCharge = value;
        emit maxChargeChanged();
    }
}

void Cloud::setFullCharge(int &value) {
    if(value != p_fullCharge) {
        p_fullCharge = value;
        emit fullChargeChanged();
    }
}

void Cloud::setCharge(int& value) {
    if(value != p_charge) {
        p_charge = value;
        emit chargeChanged();
    }
}

void Cloud::setChargePiece(int& value) {
    if(value != p_chargePiece) {
        p_chargePiece = value;
        emit chargePieceChanged();
    }
}

void Cloud::setActive() {
    p_active = (this->charge()) ?true :false;
}
