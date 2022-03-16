#include "invoice.h"

invoice::invoice()
{

}

QString invoice::join_str(){
    QStringList list;
    list<<orderID<<commodityID<<unitPrice_str<<numberStr<<date<<sellerID<<buyerID;
    QString str = list.join(",");
    str += '\n';
    return str;
}

void invoice::split(QString str){

}
