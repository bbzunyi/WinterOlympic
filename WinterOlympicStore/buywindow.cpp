#include "buywindow.h"
#include "ui_buywindow.h"
#include "datastructure.h"
#include "commodity.h"
#include "user.h"
#include "topupwindow.h"
#include "invoice.h"
BuyWindow::BuyWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BuyWindow)
{
    ui->setupUi(this);
    connect(ui->ok, &QPushButton::clicked, [this](){
        QString num = ui->number->text();
        for(int i = 0; i < num.count(); i++){
            if(num[i] < '0' || num[i] > '9'){
                QErrorMessage *dialog = new QErrorMessage();
                dialog->setWindowTitle("Error");
                dialog->showMessage("请输入正确的数字！");
                return;
            }

        }
        QString commodity_id = ui->ID->text();
        int number = ui->number->text().toInt();
        QString heading;
        double price = 1;
        QString unitprice;
        bool flag = false;
        QString SellerID;
        QVector<User> users;
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
                 if(commodity1.getCommodityID() == commodity_id ){
                     if(commodity1.getState() == "已下架"){
                         QErrorMessage *dialog = new QErrorMessage(this);
                         dialog->setWindowTitle("Error");
                         dialog->showMessage("商品已下架！");
                         return;
                     }
                     if(number > commodity1.getNum()){
                         QErrorMessage *dialog = new QErrorMessage(this);
                         dialog->setWindowTitle("Error");
                         dialog->showMessage("数量超限！");
                         return;
                     }
                     SellerID = commodity1.getSellerID();
                     unitprice = commodity1.getPrice();
                     price = commodity1.getPrice().toDouble()*number;//need to replace
                     flag = true;
                     break;
                 }
             }
             file.close();
        }
        if(flag){
            if(1){
                QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/user.txt";
                QFile file(path);
                if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                         return;

                 QTextStream in(&file);
                 heading = in.readLine();
                 while (!in.atEnd()) {
                     QString line = in.readLine();
                     QStringList list = line.split(",");
                     if(list[0] == this->UserID){
                        if(list[5].toDouble() < price){
                            topupWindow*w = new topupWindow();
                            w->user_id = this->UserID;
                            w->show();
                            file.close();
                            QErrorMessage *dialog = new QErrorMessage(this);
                            dialog->setWindowTitle("Error");
                            dialog->showMessage("余额不足！");
                            return;
                        }
                     }
                 }
                 file.close();
            }

            if(1){
                QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/user.txt";
                QFile file(path);
                if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                         return;

                 QTextStream in(&file);
                 heading = in.readLine();
                 while (!in.atEnd()) {
                     QString line = in.readLine();
                     User user1;
                     user1.split(line);
                     if(user1.get_userID() == this->UserID){
                        user1.AddBalance(-1*price);
                     }else if(user1.get_userID() == SellerID){
                         user1.AddBalance(price);
                     }
                     users.push_back(user1);
                 }
                 file.close();
            }
            if(1){
                QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/user.txt";
                QFile file(path);
                if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
                         return;

                 QTextStream out(&file);
                 heading += '\n';
                 out<<heading;
                 for(int i = 0; i < users.size(); i++){
                     out<<users[i].join_str();
                 }
                 file.close();
            }
            if(1){
                QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/order.txt";
                QFile file(path);
                if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                         return;
                 int max_id = 0;
                 QTextStream in(&file);
                 in.readLine();
                 while (!in.atEnd()) {
                     QString line = in.readLine();
                     QStringList list = line.split(",");
                     QString id = list[0].mid(1);
                     if(id.toInt() > max_id){
                        max_id = id.toInt();
                     }
                 }
                 file.close();
               QString order_id = QString::number(max_id+1);
               int len = 3 - order_id.length();
               for(int i = 0; i < len; i++){
                    order_id.insert(0,'0');
               }
               order_id.insert(0,'T');
               invoice invoice1;
               invoice1.set(order_id,commodity_id,unitprice,QString::number(number),QDateTime::currentDateTime().toString("yyyy-MM-dd"),SellerID,this->UserID);
               QString str = invoice1.join_str();
               str[str.length()-1] = '\0';
               QString instruction = "INSERT INTO order VALUES("+ str + ")";
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
               com.parse_sql(instruction);

               file.close();
            }

             this->close();

             QMessageBox* dialog = new QMessageBox(this);
             dialog->setWindowTitle("Success");
             dialog->setText("成功购买！");
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

BuyWindow::~BuyWindow()
{
    delete ui;
}
