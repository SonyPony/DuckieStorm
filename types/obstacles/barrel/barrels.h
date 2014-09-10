#ifndef BARRELS_H
#define BARRELS_H

#include <QQuickItem>
#include "types/obstacles/obstacles.h"

class Barrels : public Obstacles
{
    Q_OBJECT

    public:
        explicit Barrels(QQuickItem *parent = 0);

    public slots:
        Q_INVOKABLE void handleGamePause();
};

#endif // BARRELS_H
