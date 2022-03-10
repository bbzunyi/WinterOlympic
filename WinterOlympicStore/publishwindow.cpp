#include "publishwindow.h"
#include "ui_publishwindow.h"

PublishWindow::PublishWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PublishWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Publish");

    connect(ui->ok, &QPushButton::clicked, [this]()
    {
        Commodity commodity = Commodity();
        commodity.set(ui->Name->text(),ui->Price->text(),ui->Number->text().toInt(),ui->Description->text(),this->UserId);
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
       this->close();
    });

    connect(ui->cancel, &QPushButton::clicked, [this](){
        this->close();
    });
}

PublishWindow::~PublishWindow()
{
    delete ui;
}
