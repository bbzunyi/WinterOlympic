#ifndef TOPUPWINDOW_H
#define TOPUPWINDOW_H

#include <QWidget>
#include "datastructure.h"
namespace Ui {
class topupWindow;
}

class topupWindow : public QWidget
{
    Q_OBJECT

public:
    explicit topupWindow(QWidget *parent = nullptr);
    ~topupWindow();
    QString user_id;
private:
    Ui::topupWindow *ui;
};

#endif // TOPUPWINDOW_H
