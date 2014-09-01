#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QQuickItem>

class Obstacle : public QQuickItem
{
    Q_OBJECT

    Q_PROPERTY(int index READ index WRITE setIndex NOTIFY indexChanged)
    Q_PROPERTY(bool incrementedScore READ incrementedScore WRITE setIncrementedScore NOTIFY incrementedScoreChanged)

    protected:
        /*----Vlasnosti barelu----*/
        int p_index;
        bool p_incrementedScore;
        /*------------------------*/

    public:
        explicit Obstacle(QQuickItem *parent = 0);

        /*-----Settery a gettery----*/
        int index() const;
        bool incrementedScore() const;

        void setIndex(int& value);
        void setIncrementedScore(bool& value);
        /*--------------------------*/

    signals:
        void start();

        void indexChanged();
        void incrementedScoreChanged();
};

#endif // OBSTACLE_H
