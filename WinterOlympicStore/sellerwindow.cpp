#include "sellerwindow.h"
#include "ui_sellerwindow.h"
#include "publishwindow.h"
#include "userwindow.h"
SellerWindow::SellerWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SellerWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Seller");
    QPixmap pixmap = QPixmap(":/images/sellerwindow.jpg").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this->setPalette(palette);

    connect(ui->Publish, &QPushButton::clicked, [this]()
    {
        PublishWindow* w = new PublishWindow;
        w->UserId = this->UserID;
        w->show();
    });

    connect(ui->back, &QPushButton::clicked, [this](){
        this->close();
        UserWindow*w = new UserWindow();
        w->user_id = this->UserID;
        w->show();
    });
}

SellerWindow::~SellerWindow()
{
    delete ui;
}
