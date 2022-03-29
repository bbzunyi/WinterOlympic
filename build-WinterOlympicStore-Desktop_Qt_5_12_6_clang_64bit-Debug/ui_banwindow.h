/********************************************************************************
** Form generated from reading UI file 'banwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BANWINDOW_H
#define UI_BANWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BanWindow
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *cancel;
    QPushButton *ok;

    void setupUi(QWidget *BanWindow)
    {
        if (BanWindow->objectName().isEmpty())
            BanWindow->setObjectName(QString::fromUtf8("BanWindow"));
        BanWindow->resize(689, 480);
        label = new QLabel(BanWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 180, 71, 31));
        lineEdit = new QLineEdit(BanWindow);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(220, 170, 261, 51));
        cancel = new QPushButton(BanWindow);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(160, 270, 171, 81));
        ok = new QPushButton(BanWindow);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(380, 270, 171, 81));

        retranslateUi(BanWindow);

        QMetaObject::connectSlotsByName(BanWindow);
    } // setupUi

    void retranslateUi(QWidget *BanWindow)
    {
        BanWindow->setWindowTitle(QApplication::translate("BanWindow", "Form", nullptr));
        label->setText(QApplication::translate("BanWindow", "\347\224\250\346\210\267ID", nullptr));
        cancel->setText(QApplication::translate("BanWindow", "\345\217\226\346\266\210", nullptr));
        ok->setText(QApplication::translate("BanWindow", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BanWindow: public Ui_BanWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BANWINDOW_H
