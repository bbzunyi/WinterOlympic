#include "buyerwindow.h"
#include "ui_buyerwindow.h"

BuyerWindow::BuyerWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BuyerWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("buyer");
    QPixmap pixmap = QPixmap(":/images/buyerwindow.jpg").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this->setPalette(palette);
}

BuyerWindow::~BuyerWindow()
{
    delete ui;
}
