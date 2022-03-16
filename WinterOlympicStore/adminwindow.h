#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QWidget>
#include "datastructure.h"
#include "banwindow.h"
#include "pullcommodity.h"
#include "commodity.h"
namespace Ui {
class AdminWindow;
}

class AdminWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();
    QString id;

private:
    QVector<QString> search(QString str);
    Ui::AdminWindow *ui;
};

#endif // ADMINWINDOW_H
