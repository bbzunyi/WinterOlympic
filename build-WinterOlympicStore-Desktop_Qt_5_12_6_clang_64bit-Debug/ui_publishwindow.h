/********************************************************************************
** Form generated from reading UI file 'publishwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PUBLISHWINDOW_H
#define UI_PUBLISHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PublishWindow
{
public:
    QLineEdit *Name;
    QLineEdit *Price;
    QLineEdit *Number;
    QLineEdit *Description;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *cancel;
    QPushButton *ok;

    void setupUi(QWidget *PublishWindow)
    {
        if (PublishWindow->objectName().isEmpty())
            PublishWindow->setObjectName(QString::fromUtf8("PublishWindow"));
        PublishWindow->resize(657, 463);
        Name = new QLineEdit(PublishWindow);
        Name->setObjectName(QString::fromUtf8("Name"));
        Name->setGeometry(QRect(220, 90, 171, 41));
        Price = new QLineEdit(PublishWindow);
        Price->setObjectName(QString::fromUtf8("Price"));
        Price->setGeometry(QRect(220, 160, 171, 41));
        Number = new QLineEdit(PublishWindow);
        Number->setObjectName(QString::fromUtf8("Number"));
        Number->setGeometry(QRect(220, 230, 171, 41));
        Description = new QLineEdit(PublishWindow);
        Description->setObjectName(QString::fromUtf8("Description"));
        Description->setGeometry(QRect(220, 300, 171, 41));
        label = new QLabel(PublishWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 100, 71, 21));
        label_2 = new QLabel(PublishWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(150, 170, 71, 21));
        label_3 = new QLabel(PublishWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(150, 240, 71, 21));
        label_4 = new QLabel(PublishWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(150, 310, 71, 21));
        cancel = new QPushButton(PublishWindow);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(150, 360, 131, 71));
        ok = new QPushButton(PublishWindow);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(320, 360, 131, 71));

        retranslateUi(PublishWindow);

        QMetaObject::connectSlotsByName(PublishWindow);
    } // setupUi

    void retranslateUi(QWidget *PublishWindow)
    {
        PublishWindow->setWindowTitle(QApplication::translate("PublishWindow", "Form", nullptr));
        label->setText(QApplication::translate("PublishWindow", "\345\220\215\347\247\260", nullptr));
        label_2->setText(QApplication::translate("PublishWindow", "\344\273\267\346\240\274", nullptr));
        label_3->setText(QApplication::translate("PublishWindow", "\346\225\260\351\207\217", nullptr));
        label_4->setText(QApplication::translate("PublishWindow", "\346\217\217\350\277\260", nullptr));
        cancel->setText(QApplication::translate("PublishWindow", "\345\217\226\346\266\210\345\217\221\345\270\203", nullptr));
        ok->setText(QApplication::translate("PublishWindow", "\347\241\256\350\256\244\345\217\221\345\270\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PublishWindow: public Ui_PublishWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUBLISHWINDOW_H
