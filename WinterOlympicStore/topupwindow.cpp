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
