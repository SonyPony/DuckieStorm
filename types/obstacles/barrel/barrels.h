#ifndef BARRELS_H
#define BARRELS_H

#include <QQuickItem>
#include "types/obstacles/obstacles.h"
#include "types/visibleitem.h"

class Barrels : public Obstacles
{
    Q_OBJECT

    public:
        explicit Barrels(QQuickItem *parent = 0);
};

#endif // BARRELS_H
