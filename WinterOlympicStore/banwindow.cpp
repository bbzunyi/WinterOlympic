#include "banwindow.h"
#include "ui_banwindow.h"
#include "user.h"
BanWindow::BanWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BanWindow)
{
    ui->setupUi(this);
    connect(ui->ok, &QPushButton::clicked, [this](){
        QVector<User> users;
        QString user_id = ui->lineEdit->text();
        QString heading;
        bool flag = false;
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
                 if(user1.get_userID() == user_id){
                     user1.changeState();
                     flag = true;
                 }
                 users.push_back(user1);
             }
             file.close();
        }
        if(flag){
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
             dialog->setText("成功改变用户状态！");
             dialog->show();
             this->close();
        }else{
            QErrorMessage *dialog = new QErrorMessage(this);
            dialog->setWindowTitle("Error");
            dialog->showMessage("用户不存在！");
        }
    });

    connect(ui->cancel, &QPushButton::clicked, [this](){
        this->close();
    });
}

BanWindow::~BanWindow()
{
    delete ui;
}
