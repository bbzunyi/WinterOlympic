/********************************************************************************
** Form generated from reading UI file 'pullcommodity.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PULLCOMMODITY_H
#define UI_PULLCOMMODITY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PullCommodity
{
public:
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *cancel;
    QPushButton *ok;

    void setupUi(QWidget *PullCommodity)
    {
        if (PullCommodity->objectName().isEmpty())
            PullCommodity->setObjectName(QString::fromUtf8("PullCommodity"));
        PullCommodity->resize(603, 452);
        lineEdit = new QLineEdit(PullCommodity);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(170, 150, 211, 51));
        label = new QLabel(PullCommodity);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 170, 60, 16));
        cancel = new QPushButton(PullCommodity);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(140, 270, 121, 81));
        ok = new QPushButton(PullCommodity);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(290, 270, 121, 81));

        retranslateUi(PullCommodity);

        QMetaObject::connectSlotsByName(PullCommodity);
    } // setupUi

    void retranslateUi(QWidget *PullCommodity)
    {
        PullCommodity->setWindowTitle(QApplication::translate("PullCommodity", "Form", nullptr));
        label->setText(QApplication::translate("PullCommodity", "\345\225\206\345\223\201ID", nullptr));
        cancel->setText(QApplication::translate("PullCommodity", "\345\217\226\346\266\210", nullptr));
        ok->setText(QApplication::translate("PullCommodity", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PullCommodity: public Ui_PullCommodity {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PULLCOMMODITY_H
