#include "login.h"
#include "ui_login.h"
bool isLegal(QString name,QString password){
    int nCount = name.count();
    if(nCount > 10){
        QErrorMessage *dialog = new QErrorMessage();
        dialog->setWindowTitle("Error");
        dialog->showMessage("用户名不能超过十个字符！");
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
            dialog->showMessage("用户名只能包含中文字符和英文字母！");
            return false;
        }
    }

    nCount = password.count();
    if(nCount > 20){
        QErrorMessage *dialog = new QErrorMessage();
        dialog->setWindowTitle("Error");
        dialog->showMessage("密码不能超过20个字符！");
        return false;
    }
    for(int i = 0 ; i < nCount ; i++)
    {
        QChar cha = password.at(i);
        if((cha>='a' && cha <= 'z') || (cha >= '0' && cha <= '9') )
        {

        } else{
            QErrorMessage *dialog = new QErrorMessage();
            dialog->setWindowTitle("Error");
            dialog->showMessage("密码只能包含小写字母和数字");
            return false;
        }
    }
    return true;

}
Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setWindowTitle("LOGIN");
    QPixmap pixmap = QPixmap(":/images/startwindow.jpg").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this->setPalette(palette);
    ui->password->setFont(QFont("黑体",30));
    ui->ID->setFont(QFont("黑体",30));
    ui->title->setFont(QFont("幼圆",50));
    ui->pwInput->setEchoMode(QLineEdit::Password);

    connect(ui->login_button, &QPushButton::clicked, [this]()//用户登陆或管理员登陆
    {

        user_account user1;
        user1.id = ui->ID_input->text();
        user1.password = ui->pwInput->text();
                if(!isLegal(user1.id,user1.password)){
                    return;
                }
        if(isExisted(user1)){
            if(user1.id == "admin" && user1.password == "123456"){
                        AdminWindow*w = new AdminWindow;
                        w->id = "admin";
                        w->show();
                        this->close();
            }else if(isPasswordRight(user1)){
                        UserWindow*w = new UserWindow;
                        w->show();
                        QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/user.txt";
                        QFile file(path);
                        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                                 return;

                         QTextStream in(&file);
                         in.readLine();
                         while (!in.atEnd()) {
                             QString line = in.readLine();
                             QStringList list = line.split(",");
                             if(list[1] == user1.id){
                                 user1.id = list[0];
                                 break;
                             }
                         }
                         file.close();
                        w->user_id = user1.id;
                        this->close();
            }else{//密码错误
              QErrorMessage *dialog = new QErrorMessage(this);
              dialog->setWindowTitle("Error");
              dialog->showMessage("密码错误！");
              ui->pwInput->clear();
            }
        }else{//用户不存在
              QErrorMessage *dialog = new QErrorMessage(this);
              dialog->setWindowTitle("Error");
              dialog->showMessage("用户不存在！");
              ui->pwInput->clear();
              ui->ID_input->clear();
        }
        //this->close();
    });

    connect(ui->calculate, &QPushButton::clicked, []()//计算器
    {
        CalculatorWindow*w = new CalculatorWindow;
        w->show();
    });

    connect(ui->register_button, &QPushButton::clicked, [this]()//用户注册
    {
        user_account user1;
        user1.id = ui->ID_input->text();
        user1.password = ui->pwInput->text();
        if(!isLegal(user1.id,user1.password)){
            return;
        }
        if(user1.id == ""){
            QErrorMessage *dialog = new QErrorMessage(this);
            dialog->setWindowTitle("Error");
            dialog->showMessage("用户名不能为空！");
            return ;
        }
        if(user1.password == ""){
            QErrorMessage *dialog = new QErrorMessage(this);
            dialog->setWindowTitle("Error");
            dialog->showMessage("密码不能为空！");
            return ;
        }
        if(isExisted(user1)){
            QErrorMessage *dialog = new QErrorMessage(this);
            dialog->setWindowTitle("Error");
            dialog->showMessage("用户已存在！");
            ui->pwInput->clear();
            ui->ID_input->clear();
        }else{
            QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/user.txt";
            QFile file(path);
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                     return;
             int max_id = 0;
             QTextStream in(&file);
             in.readLine();
             while (!in.atEnd()) {
                 QString line = in.readLine();
                 QStringList list = line.split(",");
                 QString id = list[0].mid(1);
                 if(id.toInt() > max_id){
                    max_id = id.toInt();
                 }
             }
             file.close();
           file.open(QIODevice::WriteOnly | QIODevice::Append);
           QTextStream out(&file);
           QString user_id = QString::number(max_id+1);
           int len = 3 - user_id.length();
           for(int i = 0; i < len; i++){
                user_id.insert(0,'0');
           }
           user_id.insert(0,'U');
           User user_information = User(user_id,user1.id,user1.password);
           out << user_information.join_str();
           file.close();
           UserWindow*w = new UserWindow;
           w->user_id = user_id;
           w->show();
           this->close();
        }
    });

    connect(ui->exit_button, &QPushButton::clicked, []()//退出程序按钮
    {
        qApp->quit();
    });
}

bool Login::isExisted(user_account user){
    QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/user.txt";//QFileDialog::getOpenFileName(this, "打开文件", "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/users_account.txt");
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return 0;
    }

    QTextStream in(&file);
    //in.setCodec("utf-8");
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList list = line.split(",");
        if(list[1] == user.id || user.id == "admin"){
            file.close();
            return 1;
        }
    }
    file.close();
    return 0;
}

bool Login::isPasswordRight(user_account user){
    QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/user.txt";//QFileDialog::getOpenFileName(this, "打开文件", "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/users_account.txt");
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return 0;
    }

    QTextStream in(&file);
    //in.setCodec("utf-8");
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList list = line.split(",");
        if(list[1] == user.id && list[2] == user.password){
            file.close();
            return 1;
        }
    }
    file.close();
    return 0;
}
Login::~Login()
{
    delete ui;
}
