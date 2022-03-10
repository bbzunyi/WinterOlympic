#include "commodity.h"



QString Commodity::join_str(){
    number_str = QString::number(number);
    QStringList list;
    price = QString::number(price.toDouble(),'f',1);
    list<<commodityID<<commodityName<<price<<number_str<<description<<sellerID<<addedDate<<state;
    QString str = list.join(",");
    str += '\n';
    return str;
}

void Commodity::split(QString str){
    QStringList list = str.split(',');
    commodityID = list[0];
    commodityName = list[1];
    price = list[2];
    number = list[3].toInt();
    number_str = list[3];
    description = list[4];
    sellerID = list[5];
    addedDate = list[6];//yyyy-mm-dd
    state = list[7];
}
