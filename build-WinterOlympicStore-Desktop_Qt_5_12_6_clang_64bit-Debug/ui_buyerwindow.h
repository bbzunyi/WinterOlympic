/********************************************************************************
** Form generated from reading UI file 'buyerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUYERWINDOW_H
#define UI_BUYERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BuyerWindow
{
public:
    QPushButton *CheckCommodity;
    QPushButton *BuyCommodity;
    QPushButton *CheckDetailInformation;
    QPushButton *back;
    QPushButton *Search;
    QPushButton *CheckHistoryOrder;
    QTableView *tableView;
    QLineEdit *lineEdit;

    void setupUi(QWidget *BuyerWindow)
    {
        if (BuyerWindow->objectName().isEmpty())
            BuyerWindow->setObjectName(QString::fromUtf8("BuyerWindow"));
        BuyerWindow->resize(1280, 800);
        CheckCommodity = new QPushButton(BuyerWindow);
        CheckCommodity->setObjectName(QString::fromUtf8("CheckCommodity"));
        CheckCommodity->setGeometry(QRect(150, 10, 161, 71));
        BuyCommodity = new QPushButton(BuyerWindow);
        BuyCommodity->setObjectName(QString::fromUtf8("BuyCommodity"));
        BuyCommodity->setGeometry(QRect(350, 10, 161, 71));
        CheckDetailInformation = new QPushButton(BuyerWindow);
        CheckDetailInformation->setObjectName(QString::fromUtf8("CheckDetailInformation"));
        CheckDetailInformation->setGeometry(QRect(750, 10, 161, 71));
        back = new QPushButton(BuyerWindow);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(950, 10, 161, 71));
        Search = new QPushButton(BuyerWindow);
        Search->setObjectName(QString::fromUtf8("Search"));
        Search->setGeometry(QRect(1110, 110, 111, 51));
        CheckHistoryOrder = new QPushButton(BuyerWindow);
        CheckHistoryOrder->setObjectName(QString::fromUtf8("CheckHistoryOrder"));
        CheckHistoryOrder->setGeometry(QRect(550, 10, 161, 71));
        tableView = new QTableView(BuyerWindow);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(110, 190, 1071, 581));
        lineEdit = new QLineEdit(BuyerWindow);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(110, 110, 961, 51));

        retranslateUi(BuyerWindow);

        QMetaObject::connectSlotsByName(BuyerWindow);
    } // setupUi

    void retranslateUi(QWidget *BuyerWindow)
    {
        BuyerWindow->setWindowTitle(QApplication::translate("BuyerWindow", "Form", nullptr));
        CheckCommodity->setText(QApplication::translate("BuyerWindow", "\346\237\245\347\234\213\345\225\206\345\223\201\345\210\227\350\241\250", nullptr));
        BuyCommodity->setText(QApplication::translate("BuyerWindow", "\350\264\255\344\271\260\345\225\206\345\223\201", nullptr));
        CheckDetailInformation->setText(QApplication::translate("BuyerWindow", "\346\237\245\347\234\213\345\225\206\345\223\201\350\257\246\346\203\205\344\277\241\346\201\257", nullptr));
        back->setText(QApplication::translate("BuyerWindow", "\350\277\224\345\233\236\347\224\250\346\210\267\344\270\273\347\225\214\351\235\242", nullptr));
        Search->setText(QApplication::translate("BuyerWindow", "\346\220\234\347\264\242\345\225\206\345\223\201", nullptr));
        CheckHistoryOrder->setText(QApplication::translate("BuyerWindow", "\346\237\245\347\234\213\345\216\206\345\217\262\350\256\242\345\215\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BuyerWindow: public Ui_BuyerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUYERWINDOW_H
