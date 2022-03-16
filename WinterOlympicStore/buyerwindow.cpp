#include "buyerwindow.h"
#include "ui_buyerwindow.h"
#include "userwindow.h"
#include "topupwindow.h"
#include "buywindow.h"
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

    connect(ui->back, &QPushButton::clicked, [this](){
        this->close();
        UserWindow*w = new UserWindow();
        w->user_id = this->UserId;
        w->show();
    });

    connect(ui->CheckDetailInformation, &QPushButton::clicked, [this](){
        CommodityDetailWindow*w = new CommodityDetailWindow();
        w->UserID = this->UserId;
        w->show();
    });

    connect(ui->BuyCommodity, &QPushButton::clicked, [this](){
        BuyWindow*w = new BuyWindow();
        w->UserID = this->UserId;
        w->show();
    });

    connect(ui->CheckCommodity, &QPushButton::clicked, [this]()
    {
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
        com.id = this->UserId;
        com.user_type = "buyer";
        QStandardItemModel* model = com.parse_sql(instruction);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableView->setModel(model);
        ui->tableView->show();

    });

    connect(ui->Search, &QPushButton::clicked, [this]()
    {
        QString instruction = "SELECT * FROM commodity WHERE 名称 CONTAINS "+ ui->lineEdit->text();
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
        com.id = this->UserId;
        com.user_type = "buyer";
        QStandardItemModel* model = com.parse_sql(instruction);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableView->setModel(model);
        ui->tableView->show();
    });

    connect(ui->CheckHistoryOrder, &QPushButton::clicked, [this](){
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
        com.id = this->UserId;
        com.user_type = "buyer";
        QStandardItemModel* model = com.parse_sql(instruction);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableView->setModel(model);
        ui->tableView->show();
    });

}

QVector<QString> BuyerWindow::search(QString str){
    QVector<QString> vec;
    QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/commodity.txt";
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
             return vec;
     QTextStream in(&file);
     in.readLine();
     while (!in.atEnd()) {
         QString line = in.readLine();
         QStringList list = line.split(",");
         if(list[1] == str && list[7] == "销售中" && list[5] != this->UserId){
             vec.push_back(line);
         }
     }
     file.close();
     return vec;
}
BuyerWindow::~BuyerWindow()
{
    delete ui;
}
