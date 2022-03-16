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
