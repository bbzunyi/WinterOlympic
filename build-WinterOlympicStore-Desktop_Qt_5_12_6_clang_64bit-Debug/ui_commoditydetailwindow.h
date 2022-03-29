/********************************************************************************
** Form generated from reading UI file 'commoditydetailwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMODITYDETAILWINDOW_H
#define UI_COMMODITYDETAILWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommodityDetailWindow
{
public:
    QPushButton *search;
    QLabel *label;
    QLineEdit *ID;
    QListView *listView;

    void setupUi(QWidget *CommodityDetailWindow)
    {
        if (CommodityDetailWindow->objectName().isEmpty())
            CommodityDetailWindow->setObjectName(QString::fromUtf8("CommodityDetailWindow"));
        CommodityDetailWindow->resize(708, 600);
        search = new QPushButton(CommodityDetailWindow);
        search->setObjectName(QString::fromUtf8("search"));
        search->setGeometry(QRect(450, 20, 91, 51));
        label = new QLabel(CommodityDetailWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 40, 60, 16));
        ID = new QLineEdit(CommodityDetailWindow);
        ID->setObjectName(QString::fromUtf8("ID"));
        ID->setGeometry(QRect(240, 20, 191, 51));
        listView = new QListView(CommodityDetailWindow);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(110, 110, 481, 431));

        retranslateUi(CommodityDetailWindow);

        QMetaObject::connectSlotsByName(CommodityDetailWindow);
    } // setupUi

    void retranslateUi(QWidget *CommodityDetailWindow)
    {
        CommodityDetailWindow->setWindowTitle(QApplication::translate("CommodityDetailWindow", "Form", nullptr));
        search->setText(QApplication::translate("CommodityDetailWindow", "\346\220\234\347\264\242", nullptr));
        label->setText(QApplication::translate("CommodityDetailWindow", "\345\225\206\345\223\201ID", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CommodityDetailWindow: public Ui_CommodityDetailWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMODITYDETAILWINDOW_H
