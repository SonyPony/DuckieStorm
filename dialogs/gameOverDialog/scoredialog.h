#ifndef SCOREDIALOG_H
#define SCOREDIALOG_H

#include <QQuickItem>

class ScoreDialog : public QQuickItem
{
    Q_OBJECT

    Q_PROPERTY(bool highScore READ highScore WRITE setHighScore NOTIFY highScoreChanged)

    private:
        int p_highScore;

    public:
        explicit ScoreDialog(QQuickItem *parent = 0);

        /*-----Settery a gettery----*/
        bool highScore() const;

        void setHighScore(bool& value);
        /*--------------------------*/

    signals:
        void highScoreChanged();

        void show();
        void hide();
};

#endif // SCOREDIALOG_H
