/********************************************************************************
** Form generated from reading UI file 'topupwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOPUPWINDOW_H
#define UI_TOPUPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_topupWindow
{
public:
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *cancel;
    QPushButton *ok;

    void setupUi(QWidget *topupWindow)
    {
        if (topupWindow->objectName().isEmpty())
            topupWindow->setObjectName(QString::fromUtf8("topupWindow"));
        topupWindow->resize(536, 379);
        lineEdit = new QLineEdit(topupWindow);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(170, 120, 221, 61));
        label = new QLabel(topupWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 130, 61, 31));
        cancel = new QPushButton(topupWindow);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(150, 240, 111, 71));
        ok = new QPushButton(topupWindow);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(310, 240, 111, 71));

        retranslateUi(topupWindow);

        QMetaObject::connectSlotsByName(topupWindow);
    } // setupUi

    void retranslateUi(QWidget *topupWindow)
    {
        topupWindow->setWindowTitle(QApplication::translate("topupWindow", "Form", nullptr));
        label->setText(QApplication::translate("topupWindow", "\351\207\221\351\242\235", nullptr));
        cancel->setText(QApplication::translate("topupWindow", "\345\217\226\346\266\210", nullptr));
        ok->setText(QApplication::translate("topupWindow", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class topupWindow: public Ui_topupWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOPUPWINDOW_H
