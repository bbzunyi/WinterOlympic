#ifndef BUYERWINDOW_H
#define BUYERWINDOW_H

#include <QWidget>
#include "datastructure.h"
#include "commodity.h"
#include "commoditydetailwindow.h"
namespace Ui {
class BuyerWindow;
}

class BuyerWindow : public QWidget
{
    Q_OBJECT

public:
    explicit BuyerWindow(QWidget *parent = nullptr);
    ~BuyerWindow();
    QString UserId;
    QVector<QString> search(QString str);
private:
    Ui::BuyerWindow *ui;
};

#endif // BUYERWINDOW_H
