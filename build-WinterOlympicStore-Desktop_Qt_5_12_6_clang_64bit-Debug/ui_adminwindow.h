/********************************************************************************
** Form generated from reading UI file 'adminwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWindow
{
public:
    QPushButton *CheckCommodity;
    QPushButton *pull;
    QPushButton *CheckOrders;
    QPushButton *Check_users;
    QPushButton *BanUser;
    QPushButton *logout;
    QTableView *tableView;
    QPushButton *search;
    QLineEdit *lineEdit;

    void setupUi(QWidget *AdminWindow)
    {
        if (AdminWindow->objectName().isEmpty())
            AdminWindow->setObjectName(QString::fromUtf8("AdminWindow"));
        AdminWindow->resize(1280, 800);
        CheckCommodity = new QPushButton(AdminWindow);
        CheckCommodity->setObjectName(QString::fromUtf8("CheckCommodity"));
        CheckCommodity->setGeometry(QRect(70, 20, 161, 71));
        pull = new QPushButton(AdminWindow);
        pull->setObjectName(QString::fromUtf8("pull"));
        pull->setGeometry(QRect(270, 20, 161, 71));
        CheckOrders = new QPushButton(AdminWindow);
        CheckOrders->setObjectName(QString::fromUtf8("CheckOrders"));
        CheckOrders->setGeometry(QRect(470, 20, 161, 71));
        Check_users = new QPushButton(AdminWindow);
        Check_users->setObjectName(QString::fromUtf8("Check_users"));
        Check_users->setGeometry(QRect(670, 20, 161, 71));
        BanUser = new QPushButton(AdminWindow);
        BanUser->setObjectName(QString::fromUtf8("BanUser"));
        BanUser->setGeometry(QRect(870, 20, 161, 71));
        logout = new QPushButton(AdminWindow);
        logout->setObjectName(QString::fromUtf8("logout"));
        logout->setGeometry(QRect(1070, 20, 155, 71));
        tableView = new QTableView(AdminWindow);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(30, 170, 1221, 601));
        search = new QPushButton(AdminWindow);
        search->setObjectName(QString::fromUtf8("search"));
        search->setGeometry(QRect(1120, 100, 131, 51));
        lineEdit = new QLineEdit(AdminWindow);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(30, 100, 1071, 51));

        retranslateUi(AdminWindow);

        QMetaObject::connectSlotsByName(AdminWindow);
    } // setupUi

    void retranslateUi(QWidget *AdminWindow)
    {
        AdminWindow->setWindowTitle(QApplication::translate("AdminWindow", "Form", nullptr));
        CheckCommodity->setText(QApplication::translate("AdminWindow", "\346\237\245\347\234\213\346\211\200\346\234\211\345\225\206\345\223\201", nullptr));
        pull->setText(QApplication::translate("AdminWindow", "\344\270\213\346\236\266\345\225\206\345\223\201", nullptr));
        CheckOrders->setText(QApplication::translate("AdminWindow", "\346\237\245\347\234\213\346\211\200\346\234\211\350\256\242\345\215\225", nullptr));
        Check_users->setText(QApplication::translate("AdminWindow", "\346\237\245\347\234\213\346\211\200\346\234\211\347\224\250\346\210\267", nullptr));
        BanUser->setText(QApplication::translate("AdminWindow", "\345\260\201\347\246\201\347\224\250\346\210\267", nullptr));
        logout->setText(QApplication::translate("AdminWindow", "\346\263\250\351\224\200", nullptr));
        search->setText(QApplication::translate("AdminWindow", "\346\220\234\347\264\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminWindow: public Ui_AdminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
