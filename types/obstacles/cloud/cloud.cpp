#include "cloud.h"

Cloud::Cloud(QQuickItem *parent): Obstacle(parent) {
    p_index = 0;
    p_incrementedScore = false;
    p_debt = 0;
    p_active = false;

    this->setOpacity(0);

    QObject::connect(this, SIGNAL(start()), this, SLOT(restore()));
    QObject::connect(this, SIGNAL(start()), this, SLOT(setActive()));
    QObject::connect(this, SIGNAL(disappear()), this, SLOT(setActive()));
}

void Cloud::restore() {
    QObject *chargeBar = this->findChild<QObject*>("chargeBar");
    QObject *image = this->findChild<QObject*>("image");

    chargeBar->setProperty("x", 0);
    chargeBar->setProperty("width", image->property("width"));

    this->p_charge = 2;
    this->p_debt = 0;
    this->setProperty("opacity", 1.0);
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
