#include "modifycommoditywindow.h"
#include "ui_modifycommoditywindow.h"
#include "commodity.h"
bool isLegal(QString name,QString price,QString description){
    if(!is_Num(price)){
        return false;
    }
    int nCount = name.count();
    if(nCount > 20){
        QErrorMessage *dialog = new QErrorMessage();
        dialog->setWindowTitle("Error");
        dialog->showMessage("商品名不能超过二十个字符！");
        return false;
    }
    for(int i = 0 ; i < nCount ; i++)
    {
        QChar cha = name.at(i);
        ushort uni = cha.unicode();
        if((cha>='a' && cha <= 'z') || (cha>='A' && cha <= 'Z') || (uni >= 0x4E00 && uni <= 0x9FA5))
        {

        } else{
            QErrorMessage *dialog = new QErrorMessage();
            dialog->setWindowTitle("Error");
            dialog->showMessage("商品名只能包含中文字符和英文字母！");
            return false;
        }
    }

    nCount = description.count();
    if(nCount > 200){
        QErrorMessage *dialog = new QErrorMessage();
        dialog->setWindowTitle("Error");
        dialog->showMessage("密码不能超过20个字符！");
        return false;
    }

    return true;

}
ModifyCommodityWindow::ModifyCommodityWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModifyCommodityWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("ModifyWindow");
    connect(ui->search, &QPushButton::clicked, [this](){
        QString id = ui->ID->text();
        QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/commodity.txt";
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                 return;
        bool flag = false;
         QTextStream in(&file);
         while (!in.atEnd()) {
             QString line = in.readLine();
             QStringList list = line.split(",");
             if(id == list[0]){
                 flag = true;
                 if(this->user_id == list[5]){
                     ui->price->setText(list[2]);
                     ui->description->setText(list[4]);
                     ui->name->setText(list[1]);
                     file.close();
                     return;
                 }
             }
         }
         file.close();
         if(flag){
             QErrorMessage *dialog = new QErrorMessage(this);
             dialog->setWindowTitle("Error");
             dialog->showMessage("不是你的商品！");
         }
         else{
             QErrorMessage *dialog = new QErrorMessage(this);
             dialog->setWindowTitle("Error");
             dialog->showMessage("商品不存在！");
         }
    });

    connect(ui->ok, &QPushButton::clicked, [this](){
        if(!isLegal(ui->name->text(),ui->price->text(),ui->description->text())){
            return ;
        }
        QString instruction = "UPDATE commodity SET 描述=" + ui->description->text() + ",名称=" + ui->name->text()+",价格=" + ui->price->text()+" WHERE 商品ID = "+ui->ID->text();
        QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
        if(1){
            QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/commands.txt";
            QFile file(path);
            file.open(QIODevice::WriteOnly | QIODevice::Append);
            QTextStream out(&file);
            out << time + ": " + instruction + "\n";
            file.close();
        }
        Commands com;
        com.id = this->user_id;
        com.parse_sql(instruction);
        QMessageBox* dialog = new QMessageBox(this);
        dialog->setWindowTitle("Success");
        dialog->setText("成功修改商品信息！");
        dialog->show();
        this->close();
    });
    connect(ui->cancel, &QPushButton::clicked, [this](){
        this->close();
    });
}

ModifyCommodityWindow::~ModifyCommodityWindow()
{
    delete ui;
}
