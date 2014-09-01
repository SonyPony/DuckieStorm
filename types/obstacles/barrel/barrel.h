#ifndef BARREL_H
#define BARREL_H

#include <QQuickItem>
#include "types/obstacles/obstacle.h"

class Barrel : public Obstacle
{
    Q_OBJECT

    public:
        explicit Barrel(QQuickItem *parent = 0);
};

#endif // BARREL_H
