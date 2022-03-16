#ifndef COMMODITY_H
#define COMMODITY_H
#include "datastructure.h"

class Commodity
{
public:
    Commodity(){
        state = "销售中";
    }
    QString join_str();
    void split(QString str);
    QString getCommodityID(){
        return commodityID;
    }
    QString getSellerID(){
        return sellerID;
    }
    QString getState(){
        return state;
    }
    QString getPrice(){
        return price;
    }
    int getNum(){
        return number;
    }
    void setnum(int num){
        this->number = num;
        if(num == 0){
            state = "已下架";
        }
    }
    void changeState(){
         state = "已下架";
    }
    void modify_information(QString price,QString description);
    void set(QString name,QString price,int number,QString Description,QString SellerID){
        this->commodityName = name;
        this->price = price;
        this->number = number;
        this->description = Description;
        this->sellerID = SellerID;
    }
    void set_time(QString time){
        this->addedDate = time;
    }
    void set_commodityID(QString id){
        commodityID = id;
    }
    void modify_commodity_information(QString name,QString description,QString price){
      commodityName = name;
      this->price = price;
      this->description = description;
    }
    QStringList check_selfinformation();
private:
    QString commodityID;
    QString commodityName;
    QString price;
    int number;
    QString number_str;
    QString description;
    QString sellerID;
    QString addedDate;//yyyy-mm-dd
    QString state;
};

#endif // COMMODITY_H
