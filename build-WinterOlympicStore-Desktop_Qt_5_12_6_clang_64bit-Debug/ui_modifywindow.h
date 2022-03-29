/********************************************************************************
** Form generated from reading UI file 'modifywindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFYWINDOW_H
#define UI_MODIFYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModifyWindow
{
public:
    QLineEdit *username;
    QLineEdit *phonenumber;
    QLineEdit *address;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *cancel;
    QPushButton *ok;

    void setupUi(QWidget *ModifyWindow)
    {
        if (ModifyWindow->objectName().isEmpty())
            ModifyWindow->setObjectName(QString::fromUtf8("ModifyWindow"));
        ModifyWindow->resize(640, 514);
        username = new QLineEdit(ModifyWindow);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(200, 90, 191, 51));
        phonenumber = new QLineEdit(ModifyWindow);
        phonenumber->setObjectName(QString::fromUtf8("phonenumber"));
        phonenumber->setGeometry(QRect(200, 190, 191, 51));
        address = new QLineEdit(ModifyWindow);
        address->setObjectName(QString::fromUtf8("address"));
        address->setGeometry(QRect(200, 290, 191, 51));
        label = new QLabel(ModifyWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 110, 60, 16));
        label_2 = new QLabel(ModifyWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(130, 210, 60, 16));
        label_3 = new QLabel(ModifyWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(140, 310, 60, 16));
        cancel = new QPushButton(ModifyWindow);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(120, 380, 161, 71));
        ok = new QPushButton(ModifyWindow);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(320, 380, 161, 71));

        retranslateUi(ModifyWindow);

        QMetaObject::connectSlotsByName(ModifyWindow);
    } // setupUi

    void retranslateUi(QWidget *ModifyWindow)
    {
        ModifyWindow->setWindowTitle(QApplication::translate("ModifyWindow", "Form", nullptr));
        label->setText(QApplication::translate("ModifyWindow", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_2->setText(QApplication::translate("ModifyWindow", "\350\201\224\347\263\273\346\226\271\345\274\217", nullptr));
        label_3->setText(QApplication::translate("ModifyWindow", "\345\234\260\345\235\200", nullptr));
        cancel->setText(QApplication::translate("ModifyWindow", "\345\217\226\346\266\210", nullptr));
        ok->setText(QApplication::translate("ModifyWindow", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModifyWindow: public Ui_ModifyWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYWINDOW_H
