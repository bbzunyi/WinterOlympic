#include "modifywindow.h"
#include "ui_modifywindow.h"
#include "user.h"
bool isLegal1(QString phoneNumber,QString address,QString name){
    int nCount =  name.count();
    if(nCount > 10){
        QErrorMessage *dialog = new QErrorMessage();
        dialog->setWindowTitle("Error");
        dialog->showMessage("用户名不能超过十个字符！");
        return false;
    }
    for(int i = 0 ; i < nCount ; i++)
    {
        QChar cha = name.at(i);
        ushort uni = cha.unicode();
        if((cha>='a' && cha <= 'z') || (cha>='A' && cha <= 'Z') || (uni >= 0x4E00 && uni <= 0x9FA5))
        {

        } else{
            QErrorMessage *dialog = new QErrorMessage();
            dialog->setWindowTitle("Error");
            dialog->showMessage("用户名只能包含中文字符和英文字母！");
            return false;
        }
    }
    nCount = phoneNumber.count();
    if(nCount > 20){
        QErrorMessage *dialog = new QErrorMessage();
        dialog->setWindowTitle("Error");
        dialog->showMessage("联系方式不能超过二十个字符！");
        return false;
    }
    for(int i = 0 ; i < nCount ; i++)
    {
        QChar cha = phoneNumber.at(i);
        if(cha<'0' || cha > '9')
        {
            QErrorMessage *dialog = new QErrorMessage();
            dialog->setWindowTitle("Error");
            dialog->showMessage("联系方式只能为数字！");
            return false;
        }
    }

    nCount = address.count();
    if(nCount > 40){
        QErrorMessage *dialog = new QErrorMessage();
        dialog->setWindowTitle("Error");
        dialog->showMessage("地址不能超过40个字符！");
        return false;
    }
    for(int i = 0 ; i < nCount ; i++)
    {
        QChar cha = address.at(i);
        ushort uni = cha.unicode();
        if((cha>='a' && cha <= 'z') || (cha>='A' && cha <= 'Z') || (uni >= 0x4E00 && uni <= 0x9FA5))
        {

        } else{
            QErrorMessage *dialog = new QErrorMessage();
            dialog->setWindowTitle("Error");
            dialog->showMessage("用户名只能包含中文字符和英文字母！");
            return false;
        }
    }
    return true;

}
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
        if(!isLegal1(ui->phonenumber->text(),ui->address->text(),ui->username->text())){
            return;
        }
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
