#include "sellerwindow.h"
#include "ui_sellerwindow.h"
#include "publishwindow.h"
#include "userwindow.h"
#include "modifycommoditywindow.h"
#include "pullcommodity.h"
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

    connect(ui->CheckPublish, &QPushButton::clicked, [this](){
        QString instruction = "SELECT * FROM commodity";
        QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
        if(1){
            QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/commands.txt";
            QFile file(path);
            file.open(QIODevice::WriteOnly | QIODevice::Append);
            QTextStream out(&file);
            out << time + ": " + instruction + "\n";
            file.close();
        }
        Commands com;
        com.id = this->UserID;
        com.user_type = "seller";
        QStandardItemModel* model = com.parse_sql(instruction);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableView->setModel(model);
        ui->tableView->show();
    });

    connect(ui->back, &QPushButton::clicked, [this](){
        this->close();
        UserWindow*w = new UserWindow();
        w->user_id = this->UserID;
        w->show();
    });

    connect(ui->pull, &QPushButton::clicked, [this]()
    {
        PullCommodity*w = new PullCommodity();
        w->UserID = this->UserID;
        w->show();
    });

    connect(ui->modify, &QPushButton::clicked, [this](){
        ModifyCommodityWindow*w = new ModifyCommodityWindow();
        w->user_id = this->UserID;
        w->show();
    });

    connect(ui->CheckOrders, &QPushButton::clicked, [this](){
        QString instruction = "SELECT * FROM order";
        QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
        if(1){
            QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/commands.txt";
            QFile file(path);
            file.open(QIODevice::WriteOnly | QIODevice::Append);
            QTextStream out(&file);
            out << time + ": " + instruction + "\n";
            file.close();
        }
        Commands com;
        com.id = this->UserID;
        com.user_type = "seller";
        QStandardItemModel* model = com.parse_sql(instruction);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableView->setModel(model);
        ui->tableView->show();
    });

}

SellerWindow::~SellerWindow()
{
    delete ui;
}
