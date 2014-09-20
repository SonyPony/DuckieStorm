/*|File: cloud.h
  |Author: Son Hai Nguyen
  |License: LGPL
  |*/

#ifndef CLOUD_H
#define CLOUD_H

#include <QQuickItem>
#include "types/obstacles/obstacle.h"

class Cloud : public Obstacle
{
    Q_OBJECT

    Q_PROPERTY(int chargePiece READ chargePiece WRITE setChargePiece NOTIFY chargePieceChanged)
    Q_PROPERTY(int charge READ charge WRITE setCharge NOTIFY chargeChanged)
    Q_PROPERTY(int fullCharge READ fullCharge WRITE setFullCharge NOTIFY fullChargeChanged)
    Q_PROPERTY(int debt READ debt WRITE setDebt NOTIFY debtChanged)
    Q_PROPERTY(int minCharge READ minCharge WRITE setMinCharge NOTIFY minChargeChanged)
    Q_PROPERTY(int maxCharge READ maxCharge WRITE setMaxCharge NOTIFY maxChargeChanged)
    Q_PROPERTY(bool active READ active)

    private:
        int p_charge;
        int p_chargePiece;
        int p_debt;
        bool p_active;
        int p_fullCharge;

        int p_minCharge;
        int p_maxCharge;

    public:
        explicit Cloud(QQuickItem *parent = 0);
        Q_INVOKABLE void restart(QObject* group);

        /*-----Settery a gettery----*/
        int charge() const;
        int chargePiece() const;
        int debt() const;
        bool active() const;
        int fullCharge() const;
        int minCharge() const;
        int maxCharge() const;

        void setCharge(int& value);
        void setChargePiece(int& value);
        void setDebt(int& value);
        void setFullCharge(int& value);
        void setMinCharge(int& value);
        void setMaxCharge(int& value);
        /*--------------------------*/

    private slots:
        void restore(); //obnoví defaultní hodnoty
        void setActive(); //nastaví interakci s míčem

    signals:
        void chargeChanged();
        void chargePieceChanged();
        void debtChanged();
        void fullChargeChanged();
        void minChargeChanged();
        void maxChargeChanged();
        void disappear();
};

#endif // CLOUD_H
