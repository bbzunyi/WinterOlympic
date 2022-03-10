#ifndef PUBLISHWINDOW_H
#define PUBLISHWINDOW_H

#include <QWidget>
#include "datastructure.h"
#include "commodity.h"
namespace Ui {
class PublishWindow;
}

class PublishWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PublishWindow(QWidget *parent = nullptr);
    ~PublishWindow();
    QString UserId;
private:
    Ui::PublishWindow *ui;
};

#endif // PUBLISHWINDOW_H
