#ifndef SELLERWINDOW_H
#define SELLERWINDOW_H

#include <QWidget>
#include "datastructure.h"
namespace Ui {
class SellerWindow;
}

class SellerWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SellerWindow(QWidget *parent = nullptr);
    ~SellerWindow();
    QString UserID;
private:
    Ui::SellerWindow *ui;
};

#endif // SELLERWINDOW_H
