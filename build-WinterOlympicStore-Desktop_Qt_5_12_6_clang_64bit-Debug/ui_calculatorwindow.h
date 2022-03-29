/********************************************************************************
** Form generated from reading UI file 'calculatorwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATORWINDOW_H
#define UI_CALCULATORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CalculatorWindow
{
public:
    QLineEdit *lineEdit;
    QPushButton *button;

    void setupUi(QWidget *CalculatorWindow)
    {
        if (CalculatorWindow->objectName().isEmpty())
            CalculatorWindow->setObjectName(QString::fromUtf8("CalculatorWindow"));
        CalculatorWindow->resize(600, 400);
        lineEdit = new QLineEdit(CalculatorWindow);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(50, 90, 491, 81));
        button = new QPushButton(CalculatorWindow);
        button->setObjectName(QString::fromUtf8("button"));
        button->setGeometry(QRect(230, 220, 131, 71));

        retranslateUi(CalculatorWindow);

        QMetaObject::connectSlotsByName(CalculatorWindow);
    } // setupUi

    void retranslateUi(QWidget *CalculatorWindow)
    {
        CalculatorWindow->setWindowTitle(QApplication::translate("CalculatorWindow", "Form", nullptr));
        button->setText(QApplication::translate("CalculatorWindow", "\350\256\241\347\256\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CalculatorWindow: public Ui_CalculatorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATORWINDOW_H
