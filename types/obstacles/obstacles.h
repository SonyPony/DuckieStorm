#ifndef OBSTACLES_H
#define OBSTACLES_H

#include <QQuickItem>
#include "types/visibleitem.h"

class Obstacles : public VisibleItem
{
    Q_OBJECT

    Q_PROPERTY(int spawnTimeLowLimit READ spawnTimeLowLimit CONSTANT)
    Q_PROPERTY(int spawnTimeHighLimit READ spawnTimeHighLimit CONSTANT)
    Q_PROPERTY(int maximumAmount READ maximumAmount CONSTANT)
    //Q_PROPERTY(QUrl imageURL READ imageURL CONSTANT)
    Q_PROPERTY(qreal speed READ speed WRITE setSpeed NOTIFY speedChanged)

    protected:
        /*-Mezní hodnoty spawn času-*/
        int p_spawnTimeLowLimit;
        int p_spawnTimeHightLimit;
        /*--------------------------*/

        /*---Informace a cesty---*/
        int p_maximumAmount;
        //QUrl p_imageURL;
        int p_speed;
        /*-----------------------*/

    public:
        explicit Obstacles(QQuickItem *parent = 0);

        Q_INVOKABLE void pause();
        Q_INVOKABLE void resume();

        /*---------Gettery----------*/
        int spawnTimeLowLimit() const;
        int spawnTimeHighLimit() const;
        int maximumAmount() const;
        //QUrl imageURL() const;
        qreal speed() const;

        void setSpeed(qreal& value);
        /*--------------------------*/

    signals:
        void speedChanged();
};

#endif // OBSTACLES_H
