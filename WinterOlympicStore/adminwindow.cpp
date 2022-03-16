#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "login.h"
AdminWindow::AdminWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Admin");
    QPixmap pixmap = QPixmap(":/images/adminwindow.jpg").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this->setPalette(palette);
    ui->lineEdit->setFont(QFont("黑体",25));

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
        com.id = "admin";
        QStandardItemModel* model = com.parse_sql(instruction);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableView->setModel(model);
        ui->tableView->show();
    });

    connect(ui->CheckOrders, &QPushButton::clicked, [this]()
    {
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
        com.id = "admin";
        QStandardItemModel* model = com.parse_sql(instruction);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableView->setModel(model);
        ui->tableView->show();

    });

    connect(ui->Check_users, &QPushButton::clicked, [this]()
    {
        QString instruction = "SELECT * FROM user";
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
        com.id = "admin";
        QStandardItemModel* model = com.parse_sql(instruction);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableView->setModel(model);
        ui->tableView->show();
    });

    connect(ui->logout, &QPushButton::clicked, [this]()
    {
        Login*w = new Login;
        w->show();
        this->close();
    });

    connect(ui->pull, &QPushButton::clicked, []()
    {
        PullCommodity*w = new PullCommodity();
        w->UserID = "ADMIN";
        w->show();
    });

    connect(ui->BanUser, &QPushButton::clicked, []()
    {
        BanWindow*w = new BanWindow();
        w->show();
    });

    connect(ui->search, &QPushButton::clicked, [this]()
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
        com.id = "admin";
        QStandardItemModel* model = com.parse_sql(instruction);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableView->setModel(model);
        ui->tableView->show();
    });

}

QVector<QString> AdminWindow::search(QString str){
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
         if(list[1] == str){
             vec.push_back(line);
         }
     }
     file.close();
     return vec;
}

AdminWindow::~AdminWindow()
{
    delete ui;
}
