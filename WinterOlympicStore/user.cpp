#include "user.h"

User::User()
{

}

QString User::join_str(){
    this->balance_string = QString::number(this->balance,'f',1);
    QStringList list;
    list<<userID<<username<<password<<phoneNumber<<address<<balance_string<<userState;
    QString str = list.join(",");
    str += '\n';
    return str;
}

void User::split(QString str){
    QStringList list = str.split(',');
    this->userID = list[0];
    this->username = list[1];
    this->password = list[2];
    this->phoneNumber = list[3];
    this->address = list[4];
    this->balance_string = list[5];
    this->balance = balance_string.toDouble();
    this->userState = list[6];
}

void User::modify(QString name,QString phonenumber,QString address){
    this->username = name;
    this->phoneNumber = phonenumber;
    this->address = address;
}

QStringList User::check_selfinformation(){
    QStringList list;
    balance_string = QString::number(balance,'f',1);
    QString s1 = "用户名："+this->username;
    QString s2 = "联系方式："+this->phoneNumber;
    QString s3 = "地址："+this->address;
    QString s4 = "钱包余额："+this->balance_string;
    list<<s1<<s2<<s3<<s4;
    return list;
}
