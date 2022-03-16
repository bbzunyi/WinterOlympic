#include "pullcommodity.h"
#include "ui_pullcommodity.h"
#include "commodity.h"
PullCommodity::PullCommodity(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PullCommodity)
{
    ui->setupUi(this);
    connect(ui->ok, &QPushButton::clicked, [this](){
        QString commodity_id = ui->lineEdit->text();
        bool flag = false;
        if(1){
            QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/commodity.txt";
            QFile file(path);
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                     return;

             QTextStream in(&file);
             while (!in.atEnd()) {
                 QString line = in.readLine();
                 Commodity commodity1;
                 commodity1.split(line);
                 if(commodity1.getCommodityID() == commodity_id){
                     if(commodity1.getState() == "销售中" && (UserID == "ADMIN" || commodity1.getSellerID() == this->UserID)){
                         commodity1.changeState();
                         flag = true;
                     }
                 }
             }
             file.close();
        }
        if(flag){
            QString instruction = "UPDATE commodity SET 商品状态 = 已下架 WHERE 商品ID = "+ ui->lineEdit->text();
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
            com.parse_sql(instruction);
             QMessageBox* dialog = new QMessageBox(this);
             dialog->setWindowTitle("Success");
             dialog->setText("成功改变商品状态！");
             dialog->show();
             this->close();
        }else{
            QErrorMessage *dialog = new QErrorMessage(this);
            dialog->setWindowTitle("Error");
            dialog->showMessage("商品不存在！");
        }
    });

    connect(ui->cancel, &QPushButton::clicked, [this](){
        this->close();
    });
}

PullCommodity::~PullCommodity()
{
    delete ui;
}
