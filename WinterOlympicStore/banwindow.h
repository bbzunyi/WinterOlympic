#ifndef BANWINDOW_H
#define BANWINDOW_H

#include <QWidget>
#include "datastructure.h"
namespace Ui {
class BanWindow;
}

class BanWindow : public QWidget
{
    Q_OBJECT

public:
    explicit BanWindow(QWidget *parent = nullptr);
    ~BanWindow();

private:
    Ui::BanWindow *ui;
};

#endif // BANWINDOW_H
