/*|File: barrel.h
  |Author: Son Hai Nguyen
  |License: LGPL
  |*/

#ifndef BARREL_H
#define BARREL_H

#include <QQuickItem>
#include "types/obstacles/obstacle.h"

class Barrel : public Obstacle
{
    Q_OBJECT

    public:
        explicit Barrel(QQuickItem *parent = 0);

        Q_INVOKABLE void restart(QObject* group);
};

#endif // BARREL_H
