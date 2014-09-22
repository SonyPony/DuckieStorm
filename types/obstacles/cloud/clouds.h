/*|File: clouds.h
  |Author: Son Hai Nguyen
  |License: LGPL
  |*/

#ifndef CLOUDS_H
#define CLOUDS_H

#include <QQuickItem>
#include "types/obstacles/obstacles.h"

class Clouds : public Obstacles
{
    Q_OBJECT

    Q_PROPERTY(int minCharge READ minCharge CONSTANT)
    Q_PROPERTY(int maxCharge READ maxCharge CONSTANT)

    private:
        static const int p_maxCharge = 2;
        static const int p_minCharge = 1;

    public:
        explicit Clouds(QQuickItem *parent = 0);

        /*-----Settery a gettery----*/
        int minCharge() const;
        int maxCharge() const;
        /*--------------------------*/
};

#endif // CLOUDS_H
