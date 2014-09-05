#ifndef DUCK_H
#define DUCK_H

#include <QQuickItem>
#include "types/visibleitem.h"


class Duck : public VisibleItem
{
    Q_OBJECT

    Q_PROPERTY(int horizontalCenterWhenThrowsBall READ horizontalCenterWhenThrowsBall WRITE setHorizontalCenterWhenThrowsBall NOTIFY horizontalCenterWhenThrowsBallChanged)
    Q_PROPERTY(int verticalCenterWhenThrowsBall READ verticalCenterWhenThrowsBall WRITE setVerticalCenterWhenThrowsBall NOTIFY verticalCenterWhenThrowsBallChanged)
    Q_PROPERTY(int size READ size WRITE setSize NOTIFY sizeChanged)
    Q_PROPERTY(int heightOfJump READ heightOfJump WRITE setHeightOfJump NOTIFY heightOfJumpChanged)
    Q_PROPERTY(int defaultX READ defaultX WRITE setDefaultX NOTIFY defaultXChanged)
    Q_PROPERTY(int defaultY READ defaultY WRITE setDefaultY NOTIFY defaultYChanged)

    private:
        /*---Vlasnosti kachničky---*/
        int p_size;
        int p_heightOfJump;
        /*-------------------------*/

        /*--Pozicování kachničky--*/
        int p_defaultX;
        int p_defaultY;
        /*------------------------*/

        /*Pozice kachničky při hodu*/
        int p_horizontalCenterWhenThrowsBall;
        int p_verticalCenterWhenThrowsBall;
        /*-------------------------*/


    public:
        explicit Duck(QQuickItem *parent = 0);

        /*-----Settery a gettery----*/
        int size() const;
        int heightOfJump() const;
        int defaultX() const;
        int defaultY() const;
        int horizontalCenterWhenThrowsBall() const;
        int verticalCenterWhenThrowsBall() const;
        //QUrl imageURL() const;

        void setSize(int& value);
        void setHeightOfJump(int& value);
        void setDefaultX(int& value);
        void setDefaultY(int& value);
        void setHorizontalCenterWhenThrowsBall(int& value);
        void setVerticalCenterWhenThrowsBall(int& value);
        /*--------------------------*/

    signals:
        void jump();

        void sizeChanged();
        void heightOfJumpChanged();
        void defaultXChanged();
        void defaultYChanged();
        void horizontalCenterWhenThrowsBallChanged();
        void verticalCenterWhenThrowsBallChanged();
        //void imageURLChanged();
};

#endif // DUCK_H
