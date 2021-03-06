#include "duck.h"

Duck::Duck(QQuickItem *parent): VisibleItem(parent) {
    p_imageURL = QUrl("../res/images/duckImage.svg");
    p_canJump = true;
}

void Duck::handleGamePause() {
    QObject *game = this->parent();
    QObject *animation = this->findChild<QObject*>("jumpAnimation");

    if(game->property("paused")==QVariant(true)) {
        p_canJump = false;

        if(animation->property("running")==QVariant(true) && animation->property("over")==QVariant(true))
            QMetaObject::invokeMethod(animation, "stop");
    }

    else
        p_canJump = true;

    emit canJumpChanged();
}

void Duck::restart() {
    p_image->setProperty("y", p_defaultY);
}

bool Duck::canJump() const {
    return p_canJump;
}

int Duck::size() const {
    return p_size;
}

int Duck::heightOfJump() const {
    return p_heightOfJump;
}

int Duck::defaultX() const {
    return p_defaultX;
}

int Duck::defaultY() const {
    return p_defaultY;
}

int Duck::horizontalCenterWhenThrowsBall() const {
    return p_horizontalCenterWhenThrowsBall;
}

int Duck::verticalCenterWhenThrowsBall() const {
    return p_verticalCenterWhenThrowsBall;
}


void Duck::setSize(int& value) {
    if(value != p_size) {
        p_size = value;
        emit sizeChanged();
    }
}

void Duck::setHeightOfJump(int& value) {
    if(value != p_heightOfJump) {
        p_heightOfJump = value;
        emit heightOfJumpChanged();
    }
}

void Duck::setDefaultX(int& value) {
    if(value != p_defaultX) {
        p_defaultX = value;
        emit defaultXChanged();
    }
}

void Duck::setDefaultY(int& value) {
    if(value != p_defaultY) {
        p_defaultY = value;
        emit defaultYChanged();
    }
}

void Duck::setHorizontalCenterWhenThrowsBall(int& value) {
    if(value != p_horizontalCenterWhenThrowsBall) {
        p_horizontalCenterWhenThrowsBall = value;
        emit horizontalCenterWhenThrowsBallChanged();
    }
}

void Duck::setVerticalCenterWhenThrowsBall(int& value) {
    if(value != p_verticalCenterWhenThrowsBall) {
        p_verticalCenterWhenThrowsBall = value;
        emit verticalCenterWhenThrowsBallChanged();
    }
}



