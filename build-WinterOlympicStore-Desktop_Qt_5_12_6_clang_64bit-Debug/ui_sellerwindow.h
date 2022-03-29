/********************************************************************************
** Form generated from reading UI file 'sellerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELLERWINDOW_H
#define UI_SELLERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SellerWindow
{
public:
    QPushButton *CheckOrders;
    QPushButton *CheckPublish;
    QPushButton *back;
    QPushButton *modify;
    QPushButton *Publish;
    QPushButton *pull;
    QTableView *tableView;

    void setupUi(QWidget *SellerWindow)
    {
        if (SellerWindow->objectName().isEmpty())
            SellerWindow->setObjectName(QString::fromUtf8("SellerWindow"));
        SellerWindow->resize(1280, 800);
        CheckOrders = new QPushButton(SellerWindow);
        CheckOrders->setObjectName(QString::fromUtf8("CheckOrders"));
        CheckOrders->setGeometry(QRect(830, 10, 161, 71));
        CheckPublish = new QPushButton(SellerWindow);
        CheckPublish->setObjectName(QString::fromUtf8("CheckPublish"));
        CheckPublish->setGeometry(QRect(270, 10, 161, 71));
        back = new QPushButton(SellerWindow);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(1020, 10, 161, 71));
        modify = new QPushButton(SellerWindow);
        modify->setObjectName(QString::fromUtf8("modify"));
        modify->setGeometry(QRect(450, 10, 161, 71));
        Publish = new QPushButton(SellerWindow);
        Publish->setObjectName(QString::fromUtf8("Publish"));
        Publish->setGeometry(QRect(90, 10, 161, 71));
        pull = new QPushButton(SellerWindow);
        pull->setObjectName(QString::fromUtf8("pull"));
        pull->setGeometry(QRect(640, 10, 161, 71));
        tableView = new QTableView(SellerWindow);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(90, 120, 1101, 661));

        retranslateUi(SellerWindow);

        QMetaObject::connectSlotsByName(SellerWindow);
    } // setupUi

    void retranslateUi(QWidget *SellerWindow)
    {
        SellerWindow->setWindowTitle(QApplication::translate("SellerWindow", "Form", nullptr));
        CheckOrders->setText(QApplication::translate("SellerWindow", "\346\237\245\347\234\213\345\216\206\345\217\262\350\256\242\345\215\225", nullptr));
        CheckPublish->setText(QApplication::translate("SellerWindow", "\346\237\245\347\234\213\345\217\221\345\270\203\345\225\206\345\223\201", nullptr));
        back->setText(QApplication::translate("SellerWindow", "\350\277\224\345\233\236\347\224\250\346\210\267\344\270\273\347\225\214\351\235\242", nullptr));
        modify->setText(QApplication::translate("SellerWindow", "\344\277\256\346\224\271\345\225\206\345\223\201\344\277\241\346\201\257", nullptr));
        Publish->setText(QApplication::translate("SellerWindow", "\345\217\221\345\270\203\345\225\206\345\223\201", nullptr));
        pull->setText(QApplication::translate("SellerWindow", "\344\270\213\346\236\266\345\225\206\345\223\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SellerWindow: public Ui_SellerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELLERWINDOW_H
