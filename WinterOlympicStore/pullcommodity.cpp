#include "pullcommodity.h"
#include "ui_pullcommodity.h"
#include "commodity.h"
PullCommodity::PullCommodity(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PullCommodity)
{
    ui->setupUi(this);
    connect(ui->ok, &QPushButton::clicked, [this](){
        QVector<Commodity> commodities;
        QString commodity_id = ui->lineEdit->text();
        QString heading;
        bool flag = false;
        if(1){
            QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/commodity.txt";
            QFile file(path);
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                     return;

             QTextStream in(&file);
             heading = in.readLine();
             while (!in.atEnd()) {
                 QString line = in.readLine();
                 Commodity commodity1;
                 commodity1.split(line);
                 if(commodity1.getCommodityID() == commodity_id){
                     commodity1.changeState();
                     flag = true;
                 }
                 commodities.push_back(commodity1);
             }
             file.close();
        }
        if(flag){
            QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/commodity.txt";
            QFile file(path);
            if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
                     return;

             QTextStream out(&file);
             heading += '\n';
             out<<heading;
             for(int i = 0; i < commodities.size(); i++){
                 out<<commodities[i].join_str();
             }
             file.close();
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
