#ifndef BUYWINDOW_H
#define BUYWINDOW_H

#include <QWidget>

namespace Ui {
class BuyWindow;
}

class BuyWindow : public QWidget
{
    Q_OBJECT

public:
    explicit BuyWindow(QWidget *parent = nullptr);
    ~BuyWindow();
    QString UserID;
private:
    Ui::BuyWindow *ui;
};

#endif // BUYWINDOW_H
