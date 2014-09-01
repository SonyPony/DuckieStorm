#include "trees.h"

Trees::Trees(QQuickItem *parent): Obstacles(parent) {
    p_spawnTimeLowLimit = 750;
    p_spawnTimeHightLimit = 1000;
    p_maximumAmount = 15;
    p_imageURL = QUrl("../res/background_treeImage.svg");
}


