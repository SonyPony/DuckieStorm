#include "clouds.h"

Clouds::Clouds(QQuickItem *parent): Obstacles(parent) {
    p_spawnTimeLowLimit = 5000;
    p_spawnTimeHightLimit = 9000;
    p_maximumAmount = 5;
    p_imageURL = QUrl("../res/cloudImage.svg");
}

int Clouds::minCharge() const {
    return p_minCharge;
}

int Clouds::maxCharge() const {
    return p_maxCharge;
}
