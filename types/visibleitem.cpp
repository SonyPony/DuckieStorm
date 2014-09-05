#include "visibleitem.h"

VisibleItem::VisibleItem(QQuickItem *parent): QQuickItem(parent) {}

QUrl VisibleItem::imageURL() const {
    return p_imageURL;
}

QObject* VisibleItem::image()  {
    return p_image;
}

void VisibleItem::setImage(QObject *value) {
    p_image = value;
    emit imageChanged();
}

void VisibleItem::setImageURL(QUrl value) {
    if(p_imageURL != value) {
        p_imageURL = value;
        emit imageURLChanged();
    }
}
