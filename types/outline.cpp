#include "outline.h"

Outline::Outline(QQuickItem *parent): QQuickPaintedItem(parent) {
}

void Outline::paint(QPainter *painter) {
    QPen pen(p_color, 1);

    painter->setPen(pen);
    painter->setRenderHint(QPainter::Antialiasing, false);
    painter->drawRect(boundingRect().adjusted(1, 1, -1, -1));
}

QColor Outline::color() const {
    return p_color;
}

void Outline::setColor(QColor& color) {
    if(color != p_color) {
        p_color = color;
        emit colorChanged();
    }
}
