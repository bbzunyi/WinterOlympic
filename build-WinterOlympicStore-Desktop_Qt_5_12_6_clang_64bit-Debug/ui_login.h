/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLineEdit *ID_input;
    QLineEdit *pwInput;
    QLabel *ID;
    QLabel *password;
    QPushButton *login_button;
    QPushButton *register_button;
    QPushButton *exit_button;
    QLabel *title;
    QPushButton *calculate;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(1280, 800);
        ID_input = new QLineEdit(Login);
        ID_input->setObjectName(QString::fromUtf8("ID_input"));
        ID_input->setGeometry(QRect(500, 220, 241, 81));
        pwInput = new QLineEdit(Login);
        pwInput->setObjectName(QString::fromUtf8("pwInput"));
        pwInput->setGeometry(QRect(500, 370, 241, 81));
        ID = new QLabel(Login);
        ID->setObjectName(QString::fromUtf8("ID"));
        ID->setGeometry(QRect(370, 230, 131, 71));
        password = new QLabel(Login);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(370, 370, 141, 91));
        login_button = new QPushButton(Login);
        login_button->setObjectName(QString::fromUtf8("login_button"));
        login_button->setGeometry(QRect(360, 530, 201, 111));
        register_button = new QPushButton(Login);
        register_button->setObjectName(QString::fromUtf8("register_button"));
        register_button->setGeometry(QRect(670, 530, 201, 111));
        exit_button = new QPushButton(Login);
        exit_button->setObjectName(QString::fromUtf8("exit_button"));
        exit_button->setGeometry(QRect(390, 690, 141, 51));
        title = new QLabel(Login);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(390, 80, 481, 101));
        calculate = new QPushButton(Login);
        calculate->setObjectName(QString::fromUtf8("calculate"));
        calculate->setGeometry(QRect(710, 690, 141, 51));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Form", nullptr));
        ID->setText(QApplication::translate("Login", "\347\224\250\346\210\267\345\220\215", nullptr));
        password->setText(QApplication::translate("Login", "\345\257\206\347\240\201", nullptr));
        login_button->setText(QApplication::translate("Login", "\347\231\273\351\231\206", nullptr));
        register_button->setText(QApplication::translate("Login", "\346\263\250\345\206\214", nullptr));
        exit_button->setText(QApplication::translate("Login", "\351\200\200\345\207\272\347\250\213\345\272\217", nullptr));
        title->setText(QApplication::translate("Login", "\345\206\254\345\245\245\347\272\252\345\277\265\345\223\201\344\272\244\346\230\223\345\271\263\345\217\260", nullptr));
        calculate->setText(QApplication::translate("Login", "\350\256\241\347\256\227\345\231\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
