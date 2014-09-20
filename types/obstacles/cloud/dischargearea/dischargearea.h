/*|File: dischargearea.h
  |Author: Son Hai Nguyen
  |License: LGPL
  |*/

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
    Q_PROPERTY(int minWidth READ minWidth WRITE setMinWidth NOTIFY minWidthChanged)
    Q_PROPERTY(int maxWidth READ maxWidth WRITE setMaxWidth NOTIFY maxWidthChanged)
    Q_PROPERTY(int minHeight READ minHeight WRITE setMinHeight NOTIFY minHeightChanged)
    Q_PROPERTY(int maxHeight READ maxHeight WRITE setMaxHeight NOTIFY maxHeightChanged)

    private:
        QColor p_color;
        int p_sizeOfPixel;

        int p_minWidth;
        int p_maxWidth;
        int p_minHeight;
        int p_maxHeight;

    public:
        explicit DischargeArea(QQuickItem *parent = 0);

        void paint(QPainter *painter);
        void setRandomSize();

        /*-----Settery a gettery----*/
        QColor color() const;
        int sizeOfPixel() const;
        int minWidth() const;
        int maxWidth() const;
        int minHeight() const;
        int maxHeight() const;

        void setColor(QColor& value);
        void setSizeOfPixel(int& value);
        void setMinWidth(int& value);
        void setMaxWidth(int& value);
        void setMinHeight(int& value);
        void setMaxHeight(int& value);
        /*--------------------------*/

    signals:
        void colorChanged();
        void sizeOfPixelChanged();
        void minWidthChanged();
        void maxWidthChanged();
        void minHeightChanged();
        void maxHeightChanged();
};

#endif // DISCHARGEAREA_H
