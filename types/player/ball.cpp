#include "ball.h"

#include <math.h>

Ball::Ball(QQuickItem *parent): VisibleItem(parent) {
    p_throwSpeed = 10;
    p_stepsOfThrow = 1;
    p_isAvailable = true;
    this->setProperty("imageURL", "../res/images/ballImage.svg");
}

void Ball::handleGamePause() {
    QObject* animation  = this->findChild<QObject*>("throwAnimation");

    if(this->parent()->property("paused")==QVariant(true)) {
        if(p_image->property("visible")==QVariant(true))
            QMetaObject::invokeMethod(animation, "pause");

        else
            p_isAvailable = false;
    }

    else {
        if(p_image->property("visible")==QVariant(true))
            QMetaObject::invokeMethod(animation, "resume");

        else
            p_isAvailable = true;
    }
}

void Ball::updateBallPosition() {
    /*------------------Vyhledání objektů------------------*/
    QObject *root = this->parent()->parent();
    QObject *duck = this->parent()->findChild<QObject*>("duck");
    /*-----------------------------------------------------*/

    /*-------------------Nastavení hodnot------------------*/
    int CenterX = duck->property("horizontalCenterWhenThrowsBall").toInt();
    int CenterY = duck->property("verticalCenterWhenThrowsBall").toInt();
    qreal prescale = root->property("width").toDouble()*(55.0/850.0);
    qreal precission = p_time*70;
    /*-----------------------------------------------------*/

    /*-------------Počítání další pozice míče--------------*/
    p_image->setProperty("x",(float)p_throwSpeed*(p_time/precission*(float)p_stepsOfThrow)*cos(p_angle)*prescale+CenterX);
    p_image->setProperty("y",CenterY-(p_throwSpeed*(p_time/precission*p_stepsOfThrow)*sin(p_angle)-(5*pow(p_time/precission*p_stepsOfThrow,2)))*prescale);
    /*-----------------------------------------------------*/

    /*-Kontrola zda míč přesáhne okraj, pokud ne tak přejde na další pozici-*/
    if(precission<=p_stepsOfThrow || p_image->property("y").toInt()>=root->property("height").toInt())
        this->disable();

    else
        p_stepsOfThrow++;
    /*----------------------------------------------------------------------*/
}

void Ball::calculateInfo(int x, int y) {
    if(!p_isAvailable)  //kontrola zda míč je dostupný
        return;

    /*------------------Vyhledání objektů------------------*/
    QObject *root = this->parent()->parent();
    QObject *duck = this->parent()->findChild<QObject*>("duck");
    QObject *duckImage = qvariant_cast<QObject*>(duck->property("image"));

    duck->setProperty("horizontalCenterWhenThrowsBall",duck->property("defaultX").toInt()+duckImage->property("width").toInt()/2);
    duck->setProperty("verticalCenterWhenThrowsBall",duckImage->property("y").toInt()+duckImage->property("height").toInt()/2);
    /*-----------------------------------------------------*/

    /*---------------Vypočítání hodnot---------------------*/
    int CenterX = duck->property("horizontalCenterWhenThrowsBall").toInt();
    int CenterY = duck->property("verticalCenterWhenThrowsBall").toInt();

    p_angle = asin((CenterY-y)/sqrt(pow(x-CenterX, 2) + pow(CenterY-y, 2)));    //v radiánech
    p_time = ((p_throwSpeed*sin(p_angle)+sqrt(pow(p_throwSpeed, 2)*pow(sin(p_angle),2)+2*10*(root->property("height").toInt()-CenterY)))/10); //v sekundách
    /*-----------------------------------------------------*/

    /*----------Zapnutí animace a zviditelní míč-----------*/
    this->enable();
    /*-----------------------------------------------------*/
}

void Ball::disable() {
    QObject *animation = this->findChild<QObject*>("throwAnimation");

    p_image->setProperty("visible", false);
    p_image->setProperty("x", 0-(p_image->property("width")).toDouble());
    p_image->setProperty("y", 0-(p_image->property("height")).toDouble());

    p_stepsOfThrow = 1;
    p_isAvailable = true;

    animation->setProperty("running", false);
}

void Ball::enable() {
    p_image->setProperty("visible", true);
    this->p_isAvailable = false;
    this->updatePosition();
}

qreal Ball::angle() const {
    return p_angle;
}

qreal Ball::time() const {
    return p_time;
}

int Ball::throwSpeed() const {
    return p_throwSpeed;
}

bool Ball::isAvailable() const {
    return p_isAvailable;
}

int Ball::stepsOfThrow() const {
    return p_stepsOfThrow;
}

void Ball::setAngle(qreal &value) {
    if(value != p_angle) {
        p_angle = value;
        emit angleChanged();
    }
}

void Ball::setTime(qreal &value) {
    if(value != p_time) {
        p_time = value;
        emit timeChanged();
    }
}

void Ball::setIsAvailable(bool &value) {
    if(value != p_isAvailable) {
        p_isAvailable = value;
        emit isAvailableChanged();
    }
}

void Ball::setStepsOfThrow(int &value) {
    if(value != p_stepsOfThrow) {
        p_stepsOfThrow = value;
        emit stepsOfThrowChanged();
    }
}

