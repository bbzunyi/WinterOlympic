#ifndef INVOICE_H
#define INVOICE_H
#include "user.h"
#include "commodity.h"
#include "datastructure.h"
class invoice
{
public:
    invoice();
    QString join_str();
    void split(QString str);
    void increase_order(User user1,Commodity commodity,int num);//增加订单
    void set(QString orderID,QString commodityID,QString unitPrice_str,QString numberStr,QString date,QString sellerID,QString buyerID){
        this->orderID = orderID;
        this->commodityID = commodityID;
        this->unitPrice_str = unitPrice_str;
        this->numberStr = numberStr;
        this->date = date;
        this->sellerID = sellerID;
        this->buyerID = buyerID;
    }
private:
    QString orderID;
    QString commodityID;
    QString unitPrice_str;
    QString numberStr;
    QString date;
    QString sellerID;
    QString buyerID;
};

#endif // INVOICE_H
