#ifndef OUTLINE_H
#define OUTLINE_H

#include <QQuickItem>
#include <QtQuick/QQuickPaintedItem>
#include <QPainter>

class Outline : public QQuickPaintedItem
{
    Q_OBJECT

    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)

    private:
        QColor p_color;

    public:
        explicit Outline(QQuickItem *parent = 0);

        void paint(QPainter *painter);

        /*-----Settery a gettery----*/
        QColor color() const;
        void setColor(QColor& color);
        /*--------------------------*/

    signals:
        void colorChanged();
};

#endif // OUTLINE_H
