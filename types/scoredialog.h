#ifndef SCOREDIALOG_H
#define SCOREDIALOG_H

#include <QQuickItem>

class scoreDialog : public QQuickItem
{
    Q_OBJECT

    private:
        QColor p_color;
        QFont p_font;
        int p_sizeOfPixel;

    public:
        explicit scoreDialog(QQuickItem *parent = 0);

    signals:

    public slots:

};

#endif // SCOREDIALOG_H
