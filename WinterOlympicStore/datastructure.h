#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H
#include <QString>
#include <QVector>
#include <QStringList>
#include <QMessageBox>
#include <QErrorMessage>
#include <QStack>
#include <QHash>
#include <QChar>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QStandardItemModel>
#include <QDateTime>
#include <QStringListModel>
#include <QTableView>

struct user_account{
    QString id;
    QString password;
};

struct top_up{
    QString UserID;
    double amount;
    QString Date;
};

class Commands{
public:
    QStandardItemModel* select_admin(QString table);
    QStandardItemModel* select_admin(QString table,QString name);
    QStandardItemModel* select(QString table);
    QStandardItemModel* select(QString table,QString name);
    void update(QString type,QString id);
    void insert(QString type,QString information);
    QStandardItemModel* parse_sql(QString instruction);
    QStringListModel* parse_sql(QString instruction,int i);
    QString id;
    QString user_type;

private:

};

#endif // DATASTRUCTURE_H
