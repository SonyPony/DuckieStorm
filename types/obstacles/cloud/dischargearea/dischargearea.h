#ifndef DISCHARGEAREA_H
#define DISCHARGEAREA_H

#include <QQuickItem>
#include <QtQuick/QQuickPaintedItem>
#include <QPainter>

class DischargeArea : public QQuickPaintedItem
{
    Q_OBJECT

    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(int sizeOfPixel READ sizeOfPixel WRITE setSizeOfPixel NOTIFY sizeOfPixelChanged)

    private:
        QColor p_color;
        int p_sizeOfPixel;

    public:
        explicit DischargeArea(QQuickItem *parent = 0);

        void paint(QPainter *painter);

        /*-----Settery a gettery----*/
        QColor color() const;
        int sizeOfPixel() const;

        void setColor(QColor& value);
        void setSizeOfPixel(int& value);
        /*--------------------------*/

    signals:
        void colorChanged();
        void sizeOfPixelChanged();
};

#endif // DISCHARGEAREA_H
