/********************************************************************************
** Form generated from reading UI file 'userwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERWINDOW_H
#define UI_USERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserWindow
{
public:
    QPushButton *seller;
    QPushButton *buyer;
    QPushButton *person_information;
    QPushButton *logout;

    void setupUi(QWidget *UserWindow)
    {
        if (UserWindow->objectName().isEmpty())
            UserWindow->setObjectName(QString::fromUtf8("UserWindow"));
        UserWindow->resize(1280, 800);
        seller = new QPushButton(UserWindow);
        seller->setObjectName(QString::fromUtf8("seller"));
        seller->setGeometry(QRect(290, 490, 271, 171));
        buyer = new QPushButton(UserWindow);
        buyer->setObjectName(QString::fromUtf8("buyer"));
        buyer->setGeometry(QRect(770, 490, 271, 171));
        person_information = new QPushButton(UserWindow);
        person_information->setObjectName(QString::fromUtf8("person_information"));
        person_information->setGeometry(QRect(290, 180, 271, 171));
        logout = new QPushButton(UserWindow);
        logout->setObjectName(QString::fromUtf8("logout"));
        logout->setGeometry(QRect(770, 180, 271, 171));

        retranslateUi(UserWindow);

        QMetaObject::connectSlotsByName(UserWindow);
    } // setupUi

    void retranslateUi(QWidget *UserWindow)
    {
        UserWindow->setWindowTitle(QApplication::translate("UserWindow", "Form", nullptr));
        seller->setText(QApplication::translate("UserWindow", "\346\210\221\346\230\257\345\215\226\345\256\266", nullptr));
        buyer->setText(QApplication::translate("UserWindow", "\346\210\221\346\230\257\344\271\260\345\256\266", nullptr));
        person_information->setText(QApplication::translate("UserWindow", "\344\270\252\344\272\272\344\277\241\346\201\257\347\256\241\347\220\206", nullptr));
        logout->setText(QApplication::translate("UserWindow", "\346\263\250\351\224\200\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserWindow: public Ui_UserWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWINDOW_H
