#include "userwindow.h"
#include "ui_userwindow.h"
#include "login.h"
#include "buyerwindow.h"
#include "sellerwindow.h"
#include "personwindow.h"
UserWindow::UserWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("User");
    QPixmap pixmap = QPixmap(":/images/userwindow.jpeg").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this->setPalette(palette);
    ui->buyer->setFont(QFont("黑体",60));
    ui->seller->setFont(QFont("黑体",60));
    ui->person_information->setFont(QFont("黑体",45));
    ui->logout->setFont(QFont("黑体",60));

    ui->buyer->setStyleSheet("background-color: rgb(176, 224, 230);");
    ui->seller->setStyleSheet("background-color: rgb(65, 105, 225);");
    ui->person_information->setStyleSheet("background-color: rgb(106, 90, 205);");
    ui->logout->setStyleSheet("background-color: rgb(135, 206, 235);");

    connect(ui->seller, &QPushButton::clicked, [this]()//seller
    {
        SellerWindow*w = new SellerWindow;
        w->UserID = this->user_id;
        w->show();
        this->close();
    });

    connect(ui->buyer, &QPushButton::clicked, [this]()
    {
        BuyerWindow*w = new BuyerWindow;
        w->UserId = this->user_id;
        w->show();
        this->close();
    });

    connect(ui->person_information, &QPushButton::clicked, [this]()
    {
        PersonWindow*w = new PersonWindow;
        w->show();
        w->UserID = this->user_id;
        this->close();
    });

    connect(ui->logout, &QPushButton::clicked, [this]()//退出程序按钮
    {
        Login* w = new Login;
        w->show();
        this->close();
    });
}

UserWindow::~UserWindow()
{
    delete ui;
}
