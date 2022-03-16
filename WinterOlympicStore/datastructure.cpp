#include "datastructure.h"
#include "commodity.h"
#include "user.h"
#include "invoice.h"
QVector<QString> admin_search(QString str){
    QVector<QString> vec;
    QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/commodity.txt";
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
             return vec;
     QTextStream in(&file);
     in.readLine();
     while (!in.atEnd()) {
         QString line = in.readLine();
         QStringList list = line.split(",");
         if(list[1] == str){
             vec.push_back(line);
         }
     }
     file.close();
     return vec;
}
QVector<QString> buyer_search(QString str,QString userID){
    QVector<QString> vec;
    QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/commodity.txt";
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
             return vec;
     QTextStream in(&file);
     in.readLine();
     while (!in.atEnd()) {
         QString line = in.readLine();
         QStringList list = line.split(",");
         if(list[1] == str && list[7] == "销售中" && list[5] != userID){
             vec.push_back(line);
         }
     }
     file.close();
     return vec;
}
void Commands::update(QString type,QString id){
    if(type == "商品状态"){
        QString heading;
        QVector<Commodity> commodities;
        if(1){
            QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/commodity.txt";
            QFile file(path);
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                     return;

             QTextStream in(&file);
             heading = in.readLine();
             while (!in.atEnd()) {
                 QString line = in.readLine();
                 Commodity commodity1;
                 commodity1.split(line);
                 if(commodity1.getCommodityID() == id){
                     commodity1.changeState();
                 }
                 commodities.push_back(commodity1);
             }
             file.close();
        }
        QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/commodity.txt";
        QFile file(path);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
                 return;

         QTextStream out(&file);
         heading += '\n';
         out<<heading;
         for(int i = 0; i < commodities.size(); i++){
             out<<commodities[i].join_str();
         }
         file.close();
    }else if(type == "用户状态"){
        QString user_id = id;
        QString heading;
        QVector<User> users;
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
                 if(user1.get_userID() == user_id && user1.getstate() == "正常"){
                     user1.changeState();
                 }
                 users.push_back(user1);
             }
             file.close();
        }
        if(1){
            QString heading;
            QVector<Commodity> commodities;
            if(1){
                QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/commodity.txt";
                QFile file(path);
                if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                         return;

                 QTextStream in(&file);
                 heading = in.readLine();
                 while (!in.atEnd()) {
                     QString line = in.readLine();
                     Commodity commodity1;
                     commodity1.split(line);
                     if(commodity1.getSellerID() == id){
                         commodity1.changeState();
                     }
                     commodities.push_back(commodity1);
                 }
                 file.close();
            }
            QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/commodity.txt";
            QFile file(path);
            if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
                     return;

             QTextStream out(&file);
             heading += '\n';
             out<<heading;
             for(int i = 0; i < commodities.size(); i++){
                 out<<commodities[i].join_str();
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
    }else if(type.mid(0,2) == "描述"){
        QVector<Commodity> commodities;
        QString heading;
        if(1){
            QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/commodity.txt";
            QFile file(path);
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                     return;
            QStringList list = type.split(",");

             QTextStream in(&file);
             heading = in.readLine();
             while (!in.atEnd()) {
                 QString line = in.readLine();
                 Commodity commodity1;
                 commodity1.split(line);
                 if(commodity1.getCommodityID() == id){
                     commodity1.modify_commodity_information(list[1].mid(3),list[0].mid(3),list[2].mid(3));
                 }
                 commodities.push_back(commodity1);
             }
             file.close();
        }
        QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/commodity.txt";
        QFile file(path);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
                 return;

         QTextStream out(&file);
         heading += '\n';
         out<<heading;
         for(int i = 0; i < commodities.size(); i++){
             out<<commodities[i].join_str();
         }
         file.close();
    }
}
QStandardItemModel* Commands::select_admin(QString table){
    QStandardItemModel* model = new QStandardItemModel();
    if(table == "commodity"){
        QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/commodity.txt";
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                 return model;
         QTextStream in(&file);
         QString title = in.readLine();
         QStringList title_list = title.split(",");
         model->setHorizontalHeaderLabels(title_list);
         int i = 0;
         while (!in.atEnd()) {
             QString line = in.readLine();
             QStringList list = line.split(",");
             for(int j = 0; j < 8; j++){
                  model->setItem(i, j, new QStandardItem(list[j]));
             }
             i++;
         }
         file.close();
    }else if(table == "order"){
            QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/order.txt";
            QFile file(path);
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                     return model;
             QTextStream in(&file);
             QString title = in.readLine();
             QStringList title_list = title.split(",");
             model->setHorizontalHeaderLabels(title_list);
             int i = 0;
             while (!in.atEnd()) {
                 QString line = in.readLine();
                 QStringList list = line.split(",");
                 for(int j = 0; j < 7; j++){
                      model->setItem(i, j, new QStandardItem(list[j]));
                 }
                 i++;
             }
             file.close();
    }else if(table == "user"){
        QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/user.txt";
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                 return model;
         QTextStream in(&file);
         QString title = in.readLine();
         QStringList title_list = title.split(",");
         model->setHorizontalHeaderLabels(title_list);
         int i = 0;
         while (!in.atEnd()) {
             QString line = in.readLine();
             QStringList list = line.split(",");
             for(int j = 0; j < 7; j++){
                  model->setItem(i, j, new QStandardItem(list[j]));
             }
             i++;
         }
         file.close();
}

     return model;
}

QStandardItemModel* Commands::select_admin(QString table,QString name){
    QStandardItemModel* model = new QStandardItemModel();
    if(table == "commodity"){
        QVector<QString> vec = admin_search(name);
        QString title = "商品ID,名称,价格,数量,描述,卖家ID,上架时间,商品状态";
        QStringList title_list = title.split(",");
        model->setHorizontalHeaderLabels(title_list);
        for(int i = 0; i < vec.size(); i++){
            QString line = vec[i];
            QStringList list = line.split(",");
            for(int j = 0; j < 8; j++){
                 model->setItem(i, j, new QStandardItem(list[j]));
            }
        }

    }

     return model;
}

QStandardItemModel* Commands::select(QString table){
    QStandardItemModel* model = new QStandardItemModel();
    if(table == "commodity"){
        if(user_type == "buyer"){
            QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/commodity.txt";
            QFile file(path);
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                     return model;
             QTextStream in(&file);
             QString title = "商品ID,名称,价格,数量,描述,卖家ID,上架时间";
             in.readLine();
             QStringList title_list = title.split(",");
             model->setHorizontalHeaderLabels(title_list);
             int i = 0;
             while (!in.atEnd()) {
                 QString line = in.readLine();
                 QStringList list = line.split(",");
                 if(list[7] == "销售中" && list[5] != this->id){
                     for(int j = 0; j < 7; j++){
                          model->setItem(i, j, new QStandardItem(list[j]));
                     }
                     i++;
                 }

             }
             file.close();
        }else if(user_type == "seller"){
            QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/commodity.txt";
            QFile file(path);
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                     return model;
             QTextStream in(&file);
             QString title = in.readLine();
             QStringList title_list = title.split(",");
             model->setHorizontalHeaderLabels(title_list);
             int i = 0;
             while (!in.atEnd()) {
                 QString line = in.readLine();
                 QStringList list = line.split(",");
                 if(list[5] == id){
                     for(int j = 0; j < 8; j++){
                          model->setItem(i, j, new QStandardItem(list[j]));
                     }
                     i++;
                 }
             }
             file.close();
        }


    }else if(table == "order"){
            if(user_type == "seller"){
                QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/order.txt";
                QFile file(path);
                if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                         return model;
                 QTextStream in(&file);
                 in.readLine();
                 QString title = "订单ID,商品ID,交易单价,数量,交易时间,买家ID";
                 QStringList title_list = title.split(",");
                 model->setHorizontalHeaderLabels(title_list);
                 int i = 0;
                 while (!in.atEnd()) {
                     QString line = in.readLine();
                     QStringList list = line.split(",");
                     if(list[5] == id){
                         for(int j = 0; j < 5; j++){
                              model->setItem(i, j, new QStandardItem(list[j]));
                         }
                         model->setItem(i, 5, new QStandardItem(list[6]));
                         i++;
                     }
                 }
                 file.close();
            }else if(user_type == "buyer"){
                QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/order.txt";
                QFile file(path);
                if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                         return model;
                 QTextStream in(&file);
                 in.readLine();
                 QString title = "订单ID,商品ID,交易单价,数量,交易时间,卖家ID";
                 QStringList title_list = title.split(",");
                 model->setHorizontalHeaderLabels(title_list);
                 int i = 0;
                 while (!in.atEnd()) {
                     QString line = in.readLine();
                     QStringList list = line.split(",");
                     if(list[6] == id){
                         for(int j = 0; j < 6; j++){
                              model->setItem(i, j, new QStandardItem(list[j]));
                         }
                         i++;
                     }
                 }
                 file.close();
            }


    }else if(table == "user"){
        QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/user.txt";
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                 return model;
         QTextStream in(&file);
         QString title = in.readLine();
         QStringList title_list = title.split(",");
         model->setHorizontalHeaderLabels(title_list);
         int i = 0;
         while (!in.atEnd()) {
             QString line = in.readLine();
             QStringList list = line.split(",");
             for(int j = 0; j < 7; j++){
                  model->setItem(i, j, new QStandardItem(list[j]));
             }
             i++;
         }
         file.close();
}

     return model;
}

QStandardItemModel* Commands::select(QString table, QString name){
    QVector<QString> vec = buyer_search(name,id);
    QStandardItemModel* model = new QStandardItemModel();
    QString title = "商品ID,名称,价格,数量,描述,卖家ID,上架时间";
    QStringList title_list = title.split(",");
    model->setHorizontalHeaderLabels(title_list);
    for(int i = 0; i < vec.size(); i++){
        QString line = vec[i];
        QStringList list = line.split(",");
        for(int j = 0; j < 7; j++){
             model->setItem(i, j, new QStandardItem(list[j]));
        }
    }
    return model;
}
void Commands::insert(QString type,QString information){
    if(type == "commodity" && user_type == "seller"){
        Commodity commodity = Commodity();
        QStringList list = information.split(",");
        QStringList list1 = list[3].split(")");
        commodity.set(list[0].mid(7),list[1],list[2].toInt(),list1[0],id);
        commodity.set_time(QDateTime::currentDateTime().toString("yyyy-MM-dd"));
        QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/commodity.txt";
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                 return;

         QTextStream in(&file);
         in.readLine();
         int max_id = 0;
         while (!in.atEnd()) {
             QString line = in.readLine();
             QStringList list = line.split(",");
             QString commodity_id = list[0].mid(1);
             if(commodity_id.toInt() > max_id){
                 max_id = commodity_id.toInt();
             }
         }
         file.close();
       file.open(QIODevice::WriteOnly | QIODevice::Append);
       QTextStream out(&file);
       QString commodity_id = QString::number(max_id + 1);
       int len = 3 - commodity_id.length();
       for(int i = 0; i < len; i++){
            commodity_id.insert(0,'0');
       }
       commodity_id.insert(0,'M');
       commodity.set_commodityID(commodity_id);
       out << commodity.join_str();
       file.close();
    }else if(type == "order" && user_type == "buyer"){
        QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/order.txt";
        QFile file(path);
        file.open(QIODevice::WriteOnly | QIODevice::Append);
        QTextStream out(&file);
        QString inform = information.mid(7);
        inform[inform.length()-1] = '\0';
        out << inform;
        QStringList list = inform.split(",");
        file.close();
        QString heading;
        QVector<Commodity> commodities;
        if(1){
            QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/commodity.txt";
            QFile file(path);
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                     return;

             QTextStream in(&file);
             heading = in.readLine();
             while (!in.atEnd()) {
                 QString line = in.readLine();
                 Commodity commodity1;
                 commodity1.split(line);
                 if(commodity1.getCommodityID() == list[1] ){
                     commodity1.setnum(commodity1.getNum() - list[3].toInt());
                     if(commodity1.getNum() == 0){
                         commodity1.changeState();
                         QString instruction = "UPDATE commodity SET 商品状态 = 已下架 WHERE 商品ID = "+ list[1];
                         QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
                         if(1){
                             QString path1 = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/commands.txt";
                             QFile file1(path1);
                             file1.open(QIODevice::WriteOnly | QIODevice::Append);
                             QTextStream out1(&file1);
                             out1 << time + ": " + instruction + "\n";
                             file1.close();
                         }
                     }
                 }
                 commodities.push_back(commodity1);
             }
             file.close();
             if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
                      return;

              QTextStream out(&file);
              heading += '\n';
              out<<heading;
              for(int i = 0; i < commodities.size(); i++){
                  out<<commodities[i].join_str();
              }
              file.close();
        }

    }
}

QStringListModel* Commands::parse_sql(QString instruction,int i){
    QStringList list1 = instruction.split(" ");
    QString commodity_id = list1[7];
     QStringListModel *model = new QStringListModel();
    QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/commodity.txt";
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
             return model;
    bool flag = false;
     QTextStream in(&file);
     while (!in.atEnd()) {
         QString line = in.readLine();
         QStringList list = line.split(",");
         if(commodity_id == list[0]){
             flag = true;
             if(this->id != list[5] && list[7] == "销售中"){
                 Commodity commodty1;
                 commodty1.split(line);
                 model = new QStringListModel(commodty1.check_selfinformation());
             }else if(list[7] == "已下架"){
                 QErrorMessage *dialog = new QErrorMessage();
                 dialog->setWindowTitle("Error");
                 dialog->showMessage("商品已下架！");
             }else if(id == list[5]){
                 QErrorMessage *dialog = new QErrorMessage();
                 dialog->setWindowTitle("Error");
                 dialog->showMessage("这是你发布的商品！");
             }
             file.close();
             return model;
         }
     }
     file.close();
     QErrorMessage *dialog = new QErrorMessage();
     dialog->setWindowTitle("Error");
     dialog->showMessage("商品不存在！");

     return model;
}
QStandardItemModel* Commands::parse_sql(QString instruction){
    QStringList list = instruction.split(" ");
    if(list[0] == "SELECT"){
        if(list.size() == 4){
            if(id == "admin"){//admin
                return select_admin(list[3]);
            }else{
                return select(list[3]);
            }
        }else{
            if(id == "admin"){//admin
                return select_admin(list[3],list[7]);
            }else{
                return select(list[3],list[7]);
            }
        }
    }else if(list[0] == "UPDATE"){
        if(list.size() == 8){
             update(list[3],list[7]);
        }else{
             update(list[3],list[9]);
        }
    }else if(list[0] == "INSERT"){
        insert(list[2],list[3]);
    }
    return 0;
}
