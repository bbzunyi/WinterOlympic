#ifndef COMMODITYDETAILWINDOW_H
#define COMMODITYDETAILWINDOW_H

#include <QWidget>

namespace Ui {
class CommodityDetailWindow;
}

class CommodityDetailWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CommodityDetailWindow(QWidget *parent = nullptr);
    ~CommodityDetailWindow();
    QString UserID;
private:
    Ui::CommodityDetailWindow *ui;
};

#endif // COMMODITYDETAILWINDOW_H
