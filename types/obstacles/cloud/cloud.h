#ifndef CLOUD_H
#define CLOUD_H

#include <QQuickItem>
#include "types/obstacles/obstacle.h"

class Cloud : public Obstacle
{
    Q_OBJECT

    Q_PROPERTY(int chargePiece READ chargePiece WRITE setChargePiece NOTIFY chargePieceChanged)
    Q_PROPERTY(int charge READ charge WRITE setCharge NOTIFY chargeChanged)
    Q_PROPERTY(int debt READ debt WRITE setDebt NOTIFY debtChanged)
    Q_PROPERTY(bool active READ active)

    private:
        int p_charge;
        int p_chargePiece;
        int p_debt;
        bool p_active;

    public:
        explicit Cloud(QQuickItem *parent = 0);
        Q_INVOKABLE void restart(QObject* group);

        /*-----Settery a gettery----*/
        int charge() const;
        int chargePiece() const;
        int debt() const;
        bool active() const;

        void setCharge(int& value);
        void setChargePiece(int& value);
        void setDebt(int& value);
        /*--------------------------*/

    private slots:
        void restore(); //obnoví defaultní hodnoty
        void setActive(); //nastaví interakci s míčem

    signals:
        void chargeChanged();
        void chargePieceChanged();
        void debtChanged();
        void disappear();
};

#endif // CLOUD_H
