/********************************************************************************
** Form generated from reading UI file 'buywindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUYWINDOW_H
#define UI_BUYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BuyWindow
{
public:
    QPushButton *cancel;
    QLabel *label;
    QLineEdit *number;
    QPushButton *ok;
    QLabel *label_2;
    QLineEdit *ID;

    void setupUi(QWidget *BuyWindow)
    {
        if (BuyWindow->objectName().isEmpty())
            BuyWindow->setObjectName(QString::fromUtf8("BuyWindow"));
        BuyWindow->resize(682, 465);
        cancel = new QPushButton(BuyWindow);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(200, 300, 121, 81));
        label = new QLabel(BuyWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 200, 60, 16));
        number = new QLineEdit(BuyWindow);
        number->setObjectName(QString::fromUtf8("number"));
        number->setGeometry(QRect(230, 180, 211, 51));
        ok = new QPushButton(BuyWindow);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(350, 300, 121, 81));
        label_2 = new QLabel(BuyWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(160, 110, 60, 16));
        ID = new QLineEdit(BuyWindow);
        ID->setObjectName(QString::fromUtf8("ID"));
        ID->setGeometry(QRect(230, 90, 211, 51));

        retranslateUi(BuyWindow);

        QMetaObject::connectSlotsByName(BuyWindow);
    } // setupUi

    void retranslateUi(QWidget *BuyWindow)
    {
        BuyWindow->setWindowTitle(QApplication::translate("BuyWindow", "Form", nullptr));
        cancel->setText(QApplication::translate("BuyWindow", "\345\217\226\346\266\210", nullptr));
        label->setText(QApplication::translate("BuyWindow", "\346\225\260\351\207\217", nullptr));
        ok->setText(QApplication::translate("BuyWindow", "\347\241\256\350\256\244", nullptr));
        label_2->setText(QApplication::translate("BuyWindow", "\345\225\206\345\223\201ID", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BuyWindow: public Ui_BuyWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUYWINDOW_H
