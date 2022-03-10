#ifndef INVOICE_H
#define INVOICE_H
#include "user.h"
#include "commodity.h"
class invoice
{
public:
    invoice();
    QString join_str();
    void split(QString str);
    void increase_order(User user1,Commodity commodity,int num);//增加订单
private:
    QString orderID;
    QString commodityID;
    double unitPrice;
    QString unitPrice_str;
    QString numberStr;
    int number;
    QString date;
    QString sellerID;
    QString buyerID;
};

#endif // INVOICE_H
