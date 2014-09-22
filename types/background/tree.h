/*|File: tree.h
  |Author: Son Hai Nguyen
  |License: LGPL
  |*/

#ifndef TREE_H
#define TREE_H

#include <QQuickItem>

class Tree : public QQuickItem
{
    Q_OBJECT

    Q_PROPERTY(int index READ index WRITE setIndex NOTIFY indexChanged)

    private:
        int p_index;

    public:
        explicit Tree(QQuickItem *parent = 0);

        /*-----Settery a gettery----*/
        int index() const;
        void setIndex(int& value);
        /*--------------------------*/

    signals:
        void start();

        void indexChanged();
};

#endif // TREE_H
