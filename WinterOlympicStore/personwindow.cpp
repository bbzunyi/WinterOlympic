#include "personwindow.h"
#include "ui_personwindow.h"
#include "userwindow.h"
#include "topupwindow.h"
#include "modifywindow.h"
#include "user.h"
#include "calculator.h"
QString PersonWindow::calculate_balance(){
    QString formula = "0";
    QHash<int,QVector<double>> nums;
    if(1){
        QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/topup.txt";
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                 return formula;

         QTextStream in(&file);
         in.readLine();
         int i = 0;
         while (!in.atEnd()) {
             QString line = in.readLine();
             QStringList list = line.split(",");
             if(list[0] == UserID){
                 if(i == 0){
                     formula = list[1];
                     i++;
                 } else{
                     formula += "+" + list[1];
                 }
             }
         }
    }
    if(1){
        QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/order.txt";
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                 return formula;
         QTextStream in(&file);
         in.readLine();
         while (!in.atEnd()) {
             QString line = in.readLine();
             QStringList list = line.split(",");
             if(list[5] == UserID){
                 if(nums.count(list[3].toInt())){
                     nums[list[3].toInt()].push_back(list[2].toDouble());
                 }else{
                     nums[list[3].toInt()] = {list[2].toDouble()};
                 }
             }else if(list[6] == UserID){
                 if(nums.count(list[3].toInt())){
                     nums[list[3].toInt()].push_back(list[2].toDouble()*(-1));
                 }else{
                     nums[list[3].toInt()] = {list[2].toDouble()*(-1)};
                 }
             }
         }
         file.close();
    }
     QHashIterator<int, QVector<double>> iter(nums);
     while(iter.hasNext())
     {
         iter.next();
         QString str = QString::number(iter.key())+"*(";
         for(int i = 0; i < iter.value().size(); i++){
             if(i == 0){
                 str += QString::number(iter.value()[i],'f',1);
             }else{
                 if(iter.value()[i] > 0){
                     str += "+";
                 }
                 str += QString::number(iter.value()[i],'f',1);
             }
         }
         str += ")";
         formula += "+" + str;
     }

    return formula;
}
PersonWindow::PersonWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PersonWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("PersonInformation");
    QPixmap pixmap = QPixmap(":/images/personwindow.png").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this->setPalette(palette);

    connect(ui->top_up, &QPushButton::clicked, [this](){
        topupWindow* w = new topupWindow();
        w->user_id = this->UserID;
        w->show();
    });

    connect(ui->check, &QPushButton::clicked, [this](){
        QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/user.txt";
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                 return;
        User user1;
        QTextStream in(&file);
         while (!in.atEnd()) {
             QString line = in.readLine();
             user1.split(line);
             if(user1.get_userID() == this->UserID){
                 Calculator cal;
                QStringListModel *model = new QStringListModel(user1.check_selfinformation(cal.calculate(calculate_balance())));
                ui->listView->setModel(model);
                ui->listView->setFont(QFont("黑体",30));
                break;
             }
         }
         file.close();
    });

    connect(ui->back, &QPushButton::clicked, [this](){
        this->close();
        UserWindow*w = new UserWindow();
        w->user_id = this->UserID;
        w->show();
    });

    connect(ui->modify, &QPushButton::clicked, [this](){
        ModifyWindow*w = new ModifyWindow();
        w->user_id = this->UserID;
        w->show();
    });
}

PersonWindow::~PersonWindow()
{
    delete ui;
}
