#ifndef BUYERWINDOW_H
#define BUYERWINDOW_H

#include <QWidget>

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

private:
    Ui::BuyerWindow *ui;
};

#endif // BUYERWINDOW_H
