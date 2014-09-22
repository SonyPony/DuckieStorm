/*|File: ball.h
  |Author: Son Hai Nguyen
  |License: LGPL
  |*/

#ifndef BALL_H
#define BALL_H

#include <QQuickItem>
#include "types/visibleitem.h"

class Ball : public VisibleItem
{
    Q_OBJECT

    Q_PROPERTY(qreal angle READ angle WRITE setAngle NOTIFY angleChanged)
    Q_PROPERTY(qreal time READ time WRITE setTime NOTIFY timeChanged)
    Q_PROPERTY(int throwSpeed READ throwSpeed CONSTANT)
    Q_PROPERTY(bool isAvailable READ isAvailable WRITE setIsAvailable NOTIFY isAvailableChanged)
    Q_PROPERTY(int stepsOfThrow READ stepsOfThrow WRITE setStepsOfThrow NOTIFY stepsOfThrowChanged)

    private:
        /*----Informace o hodu---*/
        qreal p_angle;
        qreal p_time;
        int p_throwSpeed;
        /*-----------------------*/

        /*--Aktuální stav míče---*/
        bool p_isAvailable;
        int p_stepsOfThrow;
        /*-----------------------*/

        /*--------Metody---------*/
        Q_INVOKABLE void enable();
        /*-----------------------*/

    public:
        explicit Ball(QQuickItem *parent = 0);

        Q_INVOKABLE void disable();
        Q_INVOKABLE void calculateInfo(int x, int y);
        Q_INVOKABLE void updateBallPosition();

        /*-----Settery a gettery----*/
        qreal angle() const;
        qreal time() const;
        int throwSpeed() const;
        bool isAvailable() const;
        int stepsOfThrow() const;

        void setAngle(qreal& value);
        void setTime(qreal& value);
        void setIsAvailable(bool& value);
        void setStepsOfThrow(int& value);
        /*--------------------------*/

    public slots:
        virtual void handleGamePause();

    signals:
        void updatePosition();

        void angleChanged();
        void timeChanged();
        void isAvailableChanged();
        void stepsOfThrowChanged();
};

#endif // BALL_H
