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
        QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/commodity.txt";
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                 return;
         QTextStream in(&file);
         QStandardItemModel* model = new QStandardItemModel();
         QString title = in.readLine();
         QStringList title_list = title.split(",");
         model->setHorizontalHeaderLabels(title_list);
         ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
         int i = 0;
         while (!in.atEnd()) {
             QString line = in.readLine();
             QStringList list = line.split(",");
             for(int j = 0; j < 8; j++){
                  model->setItem(i, j, new QStandardItem(list[j]));
             }
             i++;
         }
         file.close();
         ui->tableView->setModel(model);
         ui->tableView->show();
    });

    connect(ui->CheckOrders, &QPushButton::clicked, [this]()
    {
        QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/order.txt";
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                 return;
         QTextStream in(&file);
         QStandardItemModel* model = new QStandardItemModel();
         QString title = in.readLine();
         QStringList title_list = title.split(",");
         model->setHorizontalHeaderLabels(title_list);
         ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
         int i = 0;
         while (!in.atEnd()) {
             QString line = in.readLine();
             QStringList list = line.split(",");
             for(int j = 0; j < 7; j++){
                  model->setItem(i, j, new QStandardItem(list[j]));
             }
             i++;
         }
         file.close();
         ui->tableView->setModel(model);
         ui->tableView->show();
    });

    connect(ui->Check_users, &QPushButton::clicked, [this]()
    {
        QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/user.txt";
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                 return;
         QTextStream in(&file);
         QStandardItemModel* model = new QStandardItemModel();
         QString title = in.readLine();
         QStringList title_list = title.split(",");
         model->setHorizontalHeaderLabels(title_list);
         ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
         int i = 0;
         while (!in.atEnd()) {
             QString line = in.readLine();
             QStringList list = line.split(",");
             for(int j = 0; j < 7; j++){
                  model->setItem(i, j, new QStandardItem(list[j]));
             }
             i++;
         }
         file.close();
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
        w->show();
    });

    connect(ui->BanUser, &QPushButton::clicked, []()
    {
        BanWindow*w = new BanWindow();
        w->show();
    });

    connect(ui->search, &QPushButton::clicked, [this]()
    {
        QVector<QString> vec = search(ui->lineEdit->text());
        QStandardItemModel* model = new QStandardItemModel();
        QString title = "商品ID,名称,价格,数量,描述,卖家ID,上架时间,商品状态";
        QStringList title_list = title.split(",");
        model->setHorizontalHeaderLabels(title_list);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        for(int i = 0; i < vec.size(); i++){
            QString line = vec[i];
            QStringList list = line.split(",");
            for(int j = 0; j < 8; j++){
                 model->setItem(i, j, new QStandardItem(list[j]));
            }
        }
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
