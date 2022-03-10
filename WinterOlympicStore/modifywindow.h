#ifndef MODIFYWINDOW_H
#define MODIFYWINDOW_H

#include <QWidget>
#include "datastructure.h"
namespace Ui {
class ModifyWindow;
}

class ModifyWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ModifyWindow(QWidget *parent = nullptr);
    ~ModifyWindow();
    QString user_id;
private:
    Ui::ModifyWindow *ui;
};

#endif // MODIFYWINDOW_H
