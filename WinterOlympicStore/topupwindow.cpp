#include "topupwindow.h"
#include "ui_topupwindow.h"
#include "user.h"
topupWindow::topupWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::topupWindow)
{
    ui->setupUi(this);
    ui->label->setFont(QFont("黑体",30));
    connect(ui->ok, &QPushButton::clicked, [this](){
        double number = ui->lineEdit->text().toDouble();
        QVector<User> users;
        QVector<top_up> records;
        QString heading;
        if(1){
            QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/topup.txt";
            QFile file(path);
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                     return;

             QTextStream in(&file);
             heading = in.readLine();
             while (!in.atEnd()) {
                 QString line = in.readLine();
                 QStringList list = line.split(",");
                 top_up record;
                 record.Date = list[2];
                 record.amount = list[1].toDouble();
                 record.UserID = list[0];
                 records.push_back(record);
             }

             top_up record;
             record.Date = QDateTime::currentDateTime().toString("yyyy-MM-dd");
             record.UserID = user_id;
             record.amount = number;
             records.push_back(record);

             file.close();
             if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
                      return;

              QTextStream out(&file);
              heading += '\n';
              out<<heading;
              for(int i = 0; i < records.size(); i++){
                  out<<records[i].UserID+","+QString::number(records[i].amount,'f',1)+","+records[i].Date+"\n";
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
                 if(user1.get_userID() == this->user_id){
                     user1.AddBalance(number);
                 }
                 users.push_back(user1);
             }
             file.close();
        }
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
         QMessageBox* dialog = new QMessageBox(this);
         dialog->setWindowTitle("Success");
         dialog->setText("充值成功！");
         dialog->show();
        this->close();
    });

    connect(ui->cancel, &QPushButton::clicked, [this](){
        this->close();
    });
}

topupWindow::~topupWindow()
{
    delete ui;
}
