/********************************************************************************
** Form generated from reading UI file 'modifycommoditywindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFYCOMMODITYWINDOW_H
#define UI_MODIFYCOMMODITYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModifyCommodityWindow
{
public:
    QLineEdit *price;
    QPushButton *cancel;
    QLabel *label_3;
    QPushButton *ok;
    QLineEdit *ID;
    QLabel *label_2;
    QLineEdit *name;
    QLabel *label;
    QLabel *label_4;
    QLineEdit *description;
    QPushButton *search;

    void setupUi(QWidget *ModifyCommodityWindow)
    {
        if (ModifyCommodityWindow->objectName().isEmpty())
            ModifyCommodityWindow->setObjectName(QString::fromUtf8("ModifyCommodityWindow"));
        ModifyCommodityWindow->resize(752, 527);
        price = new QLineEdit(ModifyCommodityWindow);
        price->setObjectName(QString::fromUtf8("price"));
        price->setGeometry(QRect(270, 290, 191, 51));
        cancel = new QPushButton(ModifyCommodityWindow);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(190, 380, 161, 71));
        label_3 = new QLabel(ModifyCommodityWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(200, 310, 60, 16));
        ok = new QPushButton(ModifyCommodityWindow);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(390, 380, 161, 71));
        ID = new QLineEdit(ModifyCommodityWindow);
        ID->setObjectName(QString::fromUtf8("ID"));
        ID->setGeometry(QRect(270, 40, 191, 51));
        label_2 = new QLabel(ModifyCommodityWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(200, 230, 60, 16));
        name = new QLineEdit(ModifyCommodityWindow);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(270, 210, 191, 51));
        label = new QLabel(ModifyCommodityWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 60, 60, 16));
        label_4 = new QLabel(ModifyCommodityWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(200, 140, 60, 16));
        description = new QLineEdit(ModifyCommodityWindow);
        description->setObjectName(QString::fromUtf8("description"));
        description->setGeometry(QRect(270, 120, 191, 51));
        search = new QPushButton(ModifyCommodityWindow);
        search->setObjectName(QString::fromUtf8("search"));
        search->setGeometry(QRect(480, 40, 91, 51));

        retranslateUi(ModifyCommodityWindow);

        QMetaObject::connectSlotsByName(ModifyCommodityWindow);
    } // setupUi

    void retranslateUi(QWidget *ModifyCommodityWindow)
    {
        ModifyCommodityWindow->setWindowTitle(QApplication::translate("ModifyCommodityWindow", "Form", nullptr));
        cancel->setText(QApplication::translate("ModifyCommodityWindow", "\345\217\226\346\266\210", nullptr));
        label_3->setText(QApplication::translate("ModifyCommodityWindow", "\345\225\206\345\223\201\344\273\267\346\240\274", nullptr));
        ok->setText(QApplication::translate("ModifyCommodityWindow", "\347\241\256\350\256\244", nullptr));
        label_2->setText(QApplication::translate("ModifyCommodityWindow", "\345\225\206\345\223\201\345\220\215\347\247\260", nullptr));
        label->setText(QApplication::translate("ModifyCommodityWindow", "\345\225\206\345\223\201ID", nullptr));
        label_4->setText(QApplication::translate("ModifyCommodityWindow", "\345\225\206\345\223\201\346\217\217\350\277\260", nullptr));
        search->setText(QApplication::translate("ModifyCommodityWindow", "\346\220\234\347\264\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModifyCommodityWindow: public Ui_ModifyCommodityWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYCOMMODITYWINDOW_H
