#ifndef PERSONWINDOW_H
#define PERSONWINDOW_H

#include <QWidget>

namespace Ui {
class PersonWindow;
}

class PersonWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PersonWindow(QWidget *parent = nullptr);
    ~PersonWindow();
    QString UserID;
private:
    Ui::PersonWindow *ui;
};

#endif // PERSONWINDOW_H
