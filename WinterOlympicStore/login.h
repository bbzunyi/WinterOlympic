#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "datastructure.h"
#include "userwindow.h"
#include "adminwindow.h"
#include "user.h"
#include "calculatorwindow.h"
namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private:
    Ui::Login *ui;
    bool isExisted(user_account user);
    bool isPasswordRight(user_account user);
};

#endif // LOGIN_H
