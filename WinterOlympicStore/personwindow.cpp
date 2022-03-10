#include "personwindow.h"
#include "ui_personwindow.h"
#include "userwindow.h"
#include "topupwindow.h"
#include "modifywindow.h"
#include "user.h"
PersonWindow::PersonWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PersonWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("PersonInformation");
    QPixmap pixmap = QPixmap(":/images/personwindow.png").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this->setPalette(palette);

    connect(ui->top_up, &QPushButton::clicked, [this](){
        topupWindow* w = new topupWindow();
        w->user_id = this->UserID;
        w->show();
    });

    connect(ui->check, &QPushButton::clicked, [this](){
        QString path = "/Users/mac/Desktop/WinterOlympic/WinterOlympicStore/files/user.txt";
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                 return;
        User user1;
        QTextStream in(&file);
         while (!in.atEnd()) {
             QString line = in.readLine();
             user1.split(line);
             if(user1.get_userID() == this->UserID){
                QStringListModel *model = new QStringListModel(user1.check_selfinformation());
                ui->listView->setModel(model);
                ui->listView->setFont(QFont("黑体",30));
                break;
             }
         }
         file.close();
    });

    connect(ui->back, &QPushButton::clicked, [this](){
        this->close();
        UserWindow*w = new UserWindow();
        w->user_id = this->UserID;
        w->show();
    });

    connect(ui->modify, &QPushButton::clicked, [this](){
        ModifyWindow*w = new ModifyWindow();
        w->user_id = this->UserID;
        w->show();
    });
}

PersonWindow::~PersonWindow()
{
    delete ui;
}
