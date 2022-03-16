#include "publishwindow.h"
#include "ui_publishwindow.h"
bool isLegal(QString name,QString price,QString number,QString description){
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
    for(int i = 0; i < number.count(); i++){

        if(number[i] < '0' || number[i] > '9'){
            QErrorMessage *dialog = new QErrorMessage();
            dialog->setWindowTitle("Error");
            dialog->showMessage("请输入正确的数字！");
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
PublishWindow::PublishWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PublishWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Publish");

    connect(ui->ok, &QPushButton::clicked, [this]()
    {
        if(!isLegal(ui->Name->text(),ui->Price->text(),ui->Number->text(),ui->Description->text())){
            return ;
        }
        QString instruction = "INSERT INTO commodity VALUES("+ ui->Name->text() + "," + ui->Price->text() + "," +ui->Number->text() + "," + ui->Description->text() + ")";
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
        com.id = this->UserId;
        com.user_type = "seller";
        com.parse_sql(instruction);

       QMessageBox* dialog = new QMessageBox(this);
       dialog->setWindowTitle("Success");
       dialog->setText("成功发布商品！");
       dialog->show();
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
