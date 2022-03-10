#include "calculatorwindow.h"
#include "ui_calculatorwindow.h"

CalculatorWindow::CalculatorWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalculatorWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Calculator");
    QPixmap pixmap = QPixmap(":/images/calculatorwindow.png").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this->setPalette(palette);

    connect(ui->button, &QPushButton::clicked, [this]()
    {
        Calculator cal = Calculator();
        QString formula = ui->lineEdit->text();
        double result = cal.calculate(formula);
        if(!cal.isStandard()){
            QErrorMessage *dialog = new QErrorMessage(this);
            dialog->setWindowTitle("Error");
            dialog->showMessage("表达式格式错误！");
            return ;
        }
        ui->lineEdit->setText(QString::number(result));
    });
}

CalculatorWindow::~CalculatorWindow()
{
    delete ui;
}
