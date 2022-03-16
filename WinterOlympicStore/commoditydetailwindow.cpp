#include "commoditydetailwindow.h"
#include "ui_commoditydetailwindow.h"
#include "datastructure.h"
#include "commodity.h"
CommodityDetailWindow::CommodityDetailWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommodityDetailWindow)
{
    ui->setupUi(this);
    connect(ui->search, &QPushButton::clicked, [this](){
        QString id = ui->ID->text();
        QString instruction = "SELECT * FROM commodity WHERE 商品ID CONTAINS "+ id;
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
        com.user_type = "buyer";
        QStringListModel *model = com.parse_sql(instruction,1);
         ui->listView->setModel(model);
         ui->listView->setFont(QFont("黑体",30));
    });

}

CommodityDetailWindow::~CommodityDetailWindow()
{
    delete ui;
}
