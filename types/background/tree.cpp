#include "tree.h"

Tree::Tree(QQuickItem *parent): QQuickItem(parent) {
    p_index = 0;
    this->setProperty("visible", false);
}

int Tree::index() const {
    return p_index;
}

void Tree::setIndex(int& value) {
    if(value != p_index) {
        p_index = value;
        emit indexChanged();
    }
}
