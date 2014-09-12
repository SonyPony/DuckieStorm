#include "dischargearea.h"
#include <QTime>

DischargeArea::DischargeArea(QQuickItem *parent): QQuickPaintedItem(parent) {
}

void DischargeArea::setRandomSize() {
    qsrand(QTime::currentTime().msec());

    this->setWidth(rand()%(p_maxWidth-p_minWidth+1)+p_minWidth);
    this->setHeight(rand()%(p_maxHeight-p_minHeight+1)+p_minHeight);
}

void DischargeArea::paint(QPainter *painter) {
    int x = boundingRect().x();
    int y = boundingRect().y();
    int width = boundingRect().width();
    int height = boundingRect().height();

    painter->setPen(QPen(p_color));
    painter->setBrush(QBrush(p_color));
    painter->setRenderHint(QPainter::Antialiasing, false);

    //levý horní roh
    painter->drawRect(x, y, 2*p_sizeOfPixel, p_sizeOfPixel);
    painter->drawRect(x, y+p_sizeOfPixel, p_sizeOfPixel, p_sizeOfPixel);

    //levý dolní roh
    painter->drawRect(x, height-2*p_sizeOfPixel, p_sizeOfPixel, p_sizeOfPixel);
    painter->drawRect(x, height-p_sizeOfPixel, 2*p_sizeOfPixel, p_sizeOfPixel);

    //pravý horní roh
    painter->drawRect(width-2*p_sizeOfPixel, y, 2*p_sizeOfPixel, p_sizeOfPixel);
    painter->drawRect(width-p_sizeOfPixel, y+p_sizeOfPixel, p_sizeOfPixel, p_sizeOfPixel);

    //pravý dolní roh
    painter->drawRect(width-p_sizeOfPixel, height-2*p_sizeOfPixel, p_sizeOfPixel, 2*p_sizeOfPixel);
    painter->drawRect(width-2*p_sizeOfPixel, height-p_sizeOfPixel, p_sizeOfPixel, p_sizeOfPixel);
}

QColor DischargeArea::color() const {
    return p_color;
}

int DischargeArea::sizeOfPixel() const {
    return p_sizeOfPixel;
}

int DischargeArea::minWidth() const {
    return p_minWidth;
}

int DischargeArea::maxWidth() const {
    return p_maxWidth;
}

int DischargeArea::minHeight() const {
    return p_minHeight;
}

int DischargeArea::maxHeight() const {
    return p_maxHeight;
}

void DischargeArea::setColor(QColor &value) {
    if(value != p_color) {
        p_color = value;
        emit colorChanged();
    }
}

void DischargeArea::setSizeOfPixel(int &value) {
    if(value != p_sizeOfPixel) {
        p_sizeOfPixel = value;
        emit sizeOfPixelChanged();
    }
}

void DischargeArea::setMinWidth(int &value) {
    if(value != p_minWidth) {
        p_minWidth = value;
        emit minWidthChanged();
    }
}

void DischargeArea::setMaxWidth(int &value) {
    if(value != p_maxWidth) {
        p_maxWidth = value;
        emit maxWidthChanged();
    }
}

void DischargeArea::setMinHeight(int &value) {
    if(value != p_minHeight) {
        p_minHeight = value;
        emit minHeightChanged();
    }
}

void DischargeArea::setMaxHeight(int &value) {
    if(value != p_maxHeight) {
        p_maxHeight = value;
        emit maxHeightChanged();
    }
}
