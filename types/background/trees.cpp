#include "trees.h"

Trees::Trees(QQuickItem *parent): Obstacles(parent) {
    p_spawnTimeLowLimit = 750;
    p_spawnTimeHightLimit = 1000;
    p_maximumAmount = 15;
    p_speed = 74.138;
    this->setImageURL(QUrl("../res/images/background_treeImage.svg"));
}



