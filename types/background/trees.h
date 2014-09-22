/*|File: trees.h
  |Author: Son Hai Nguyen
  |License: LGPL
  |*/

#ifndef TREES_H
#define TREES_H

#include <QQuickItem>
#include "types/obstacles/obstacles.h"

class Trees : public Obstacles
{
    Q_OBJECT

    public:
        explicit Trees(QQuickItem *parent = 0);
};

#endif // TREES_H
