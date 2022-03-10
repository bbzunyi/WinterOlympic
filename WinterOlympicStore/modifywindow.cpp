#include "modifywindow.h"
#include "ui_modifywindow.h"
#include "user.h"
ModifyWindow::ModifyWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModifyWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("ModifyWindow");
    QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/user.txt";
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
             return;
     QTextStream in(&file);
     in.readLine();
     User user1;
     while (!in.atEnd()) {
         QString line = in.readLine();
         user1.split(line);
         if(user1.get_userID() == this->user_id){
             break;
         }
     }
     file.close();
    ui->username->setText(user1.get_userName());
    ui->phonenumber->setText(user1.get_phonenumber());
    ui->address->setText(user1.get_address());
    connect(ui->ok, &QPushButton::clicked, [this](){
        QVector<User> users;
        QString heading;
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
                     user1.modify(ui->username->text(),ui->phonenumber->text(),ui->address->text());
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
        this->close();
    });


    connect(ui->cancel, &QPushButton::clicked, [this](){
        this->close();
    });
}

ModifyWindow::~ModifyWindow()
{
    delete ui;
}
