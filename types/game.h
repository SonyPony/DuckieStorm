#ifndef GAME_H
#define GAME_H

#include <QQuickItem>

class Game : public QQuickItem
{
    Q_OBJECT

    Q_PROPERTY(bool over READ over WRITE setOver NOTIFY overChanged)
    Q_PROPERTY(int score READ score WRITE setScore NOTIFY scoreChanged)
    Q_PROPERTY(int sizeOfPixel READ sizeOfPixel WRITE setSizeOfPixel NOTIFY sizeOfPixelChanged)
    Q_PROPERTY(bool firstChange READ firstChange WRITE setFirstChange NOTIFY firstChangeChanged)
    Q_PROPERTY(bool paused READ paused WRITE setPaused NOTIFY pausedChanged)

    private:
        /*-----Vlastnosti hry-----*/
        bool p_over;
        bool p_paused;
        int p_score;
        /*------------------------*/

        /*Grafické vlastnosti hry-*/
        int p_sizeOfPixel;
        bool p_firstChange;
        /*------------------------*/

    public:
        explicit Game(QQuickItem *parent = 0);

        /*-----Settery a gettery----*/
        bool over() const;
        int score() const;
        int sizeOfPixel() const;
        bool firstChange() const;
        bool paused() const;

        void setOver(bool& value);
        void setScore(int& value);
        void setSizeOfPixel(int& value);
        void setFirstChange(bool& value);
        void setPaused(bool& value);
        /*--------------------------*/

    signals:
        void overChanged();
        void scoreChanged();
        void sizeOfPixelChanged();
        void firstChangeChanged();
        void pausedChanged();
};

#endif // GAME_H
