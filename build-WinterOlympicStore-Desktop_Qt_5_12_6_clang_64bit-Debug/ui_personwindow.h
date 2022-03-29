/********************************************************************************
** Form generated from reading UI file 'personwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONWINDOW_H
#define UI_PERSONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PersonWindow
{
public:
    QPushButton *top_up;
    QPushButton *back;
    QPushButton *check;
    QPushButton *modify;
    QListView *listView;

    void setupUi(QWidget *PersonWindow)
    {
        if (PersonWindow->objectName().isEmpty())
            PersonWindow->setObjectName(QString::fromUtf8("PersonWindow"));
        PersonWindow->resize(1280, 800);
        top_up = new QPushButton(PersonWindow);
        top_up->setObjectName(QString::fromUtf8("top_up"));
        top_up->setGeometry(QRect(650, 30, 161, 71));
        back = new QPushButton(PersonWindow);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(840, 30, 161, 71));
        check = new QPushButton(PersonWindow);
        check->setObjectName(QString::fromUtf8("check"));
        check->setGeometry(QRect(290, 30, 161, 71));
        modify = new QPushButton(PersonWindow);
        modify->setObjectName(QString::fromUtf8("modify"));
        modify->setGeometry(QRect(470, 30, 161, 71));
        listView = new QListView(PersonWindow);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(300, 150, 701, 461));

        retranslateUi(PersonWindow);

        QMetaObject::connectSlotsByName(PersonWindow);
    } // setupUi

    void retranslateUi(QWidget *PersonWindow)
    {
        PersonWindow->setWindowTitle(QApplication::translate("PersonWindow", "Form", nullptr));
        top_up->setText(QApplication::translate("PersonWindow", "\345\205\205\345\200\274", nullptr));
        back->setText(QApplication::translate("PersonWindow", "\350\277\224\345\233\236\347\224\250\346\210\267\344\270\273\347\225\214\351\235\242", nullptr));
        check->setText(QApplication::translate("PersonWindow", "\346\237\245\347\234\213\344\277\241\346\201\257", nullptr));
        modify->setText(QApplication::translate("PersonWindow", "\344\277\256\346\224\271\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PersonWindow: public Ui_PersonWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONWINDOW_H
