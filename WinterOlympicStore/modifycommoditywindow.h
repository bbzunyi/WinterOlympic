#ifndef MODIFYCOMMODITYWINDOW_H
#define MODIFYCOMMODITYWINDOW_H

#include <QWidget>
#include "datastructure.h"
namespace Ui {
class ModifyCommodityWindow;
}

class ModifyCommodityWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ModifyCommodityWindow(QWidget *parent = nullptr);
    ~ModifyCommodityWindow();
    QString user_id;
private:
    Ui::ModifyCommodityWindow *ui;
};

#endif // MODIFYCOMMODITYWINDOW_H
