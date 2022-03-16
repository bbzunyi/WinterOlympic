#ifndef USER_H
#define USER_H
#include <QString>
#include <QVector>
#include <QStringList>
#include <QMessageBox>
#include <QErrorMessage>
#include "commodity.h"
class User
{
public:
    User();
    User( QString userID,QString username,QString password){
        this->userID = userID;
        this->username = username;
        this->password = password;
        this->address = "NULL";
        this->phoneNumber = "NULL";
        this->balance = 0;
        this->userState = "正常";
    }
    void changeState(){
        if(userState == "正常"){
            userState = "封禁";
        }else{
            userState = "正常";
        }
    }
    QString getstate(){
        return userState;
    }
    QString join_str();//用成员变量生成QString
    void split(QString str);//用QString给成员变量赋值
    void top_up(double money);//充值
    void modify(QString name,QString phonenumber,QString address);//change personal information
    static void search(QString commodity_name);//搜索商品
    void purchase(QString commodity_id);//购买商品
    void checkHistoryOrder();//查看历史订单
    static void checkCommodityDetails(QString commodity_id);//查看商品详情信息
    static void release_commodity(QString name,QString price,QString number,QString description);
    void check_release_commodity();//查看发布的商品
    void cancel_commodity(QString commodity_id);//下架商品
    QString get_userID(){
        return userID;
    }
    QString get_userName(){
        return username;
    }
    QString get_address(){
        return address;
    }
    QString get_balance(){
        return QString::number(balance,'f',1);
    }
    QString get_phonenumber(){
        return phoneNumber;
    }
    QStringList check_selfinformation(double number);
    void AddBalance(double num){
        this->balance += num;
    }
private:
    QString userID;
    QString username;
    QString password;
    QString address;
    QString phoneNumber;
    QString balance_string;
    double balance;
    QString userState;
};

#endif // USER_H
