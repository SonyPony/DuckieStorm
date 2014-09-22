/*|File: game.h
  |Author: Son Hai Nguyen
  |License: LGPL
  |*/

#ifndef GAME_H
#define GAME_H

#include <QQuickItem>

class Game : public QQuickItem
{
    Q_OBJECT

    Q_PROPERTY(bool over READ over)
    Q_PROPERTY(int score READ score WRITE setScore NOTIFY scoreChanged)
    Q_PROPERTY(int sizeOfPixel READ sizeOfPixel WRITE setSizeOfPixel NOTIFY sizeOfPixelChanged)
    Q_PROPERTY(bool paused READ paused WRITE setPaused NOTIFY pausedChanged)
    Q_PROPERTY(int highScore READ highScore WRITE setHighScore NOTIFY highScoreChanged)

    private:
        /*-----Vlastnosti hry-----*/
        bool p_over;
        bool p_paused;
        int p_score;
        int p_highScore;
        /*------------------------*/

        /*Grafické vlastnosti hry-*/
        int p_sizeOfPixel;
        /*------------------------*/

    public:
        explicit Game(QQuickItem *parent = 0);

        Q_INVOKABLE void end();

        /*-----Settery a gettery----*/
        bool over() const;
        int score() const;
        int sizeOfPixel() const;
        bool paused() const;
        int highScore() const;

        //void setOver(bool& value);
        void setScore(int& value);
        void setSizeOfPixel(int& value);
        void setPaused(bool& value);
        void setHighScore(int& value);
        /*--------------------------*/

    private slots:
        void gameIsOn();

    signals:
        //void overChanged();
        void scoreChanged();
        void sizeOfPixelChanged();
        void pausedChanged();
        void highScoreChanged();
        void restart();
};

#endif // GAME_H
