#ifndef VISIBLEITEM_H
#define VISIBLEITEM_H

#include <QQuickItem>

class VisibleItem : public QQuickItem
{
    Q_OBJECT

    Q_PROPERTY(QUrl imageURL READ imageURL WRITE setImageURL NOTIFY imageURLChanged)
    Q_PROPERTY(QObject* image READ image WRITE setImage NOTIFY imageChanged)

    protected:
        QUrl p_imageURL;
        QObject* p_image;

    public:
        explicit VisibleItem(QQuickItem *parent = 0);

        /*-----Settery a gettery----*/
        QUrl imageURL() const;
        QObject* image();

        void setImage(QObject *value);
        void setImageURL(QUrl value);
        /*--------------------------*/
    signals:
        void literaly_nothing(); //jenom kvůli divnému expandování kódu
        void imageChanged();
        void imageURLChanged();
};

#endif // VISIBLEITEM_H
