#include "ball.h"

#include <math.h>

Ball::Ball(QQuickItem *parent): VisibleItem(parent) {
    p_speed = 10;
    p_stepsOfThrow = 1;
    p_isAvailable = true;
    p_imageURL = QUrl("../res/ballImage.svg");
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
    p_time = ((p_speed*sin(p_angle)+sqrt(pow(p_speed, 2)*pow(sin(p_angle),2)+2*10*(root->property("height").toInt()-CenterY)))/10); //v sekundách
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

int Ball::speed() const {
    return p_speed;
}

bool Ball::isAvailable() const {
    return p_isAvailable;
}

int Ball::stepsOfThrow() const {
    return p_stepsOfThrow;
}

QUrl Ball::imageURL() const {
    return p_imageURL;

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

