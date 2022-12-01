#include "generate_transacction.h"
#include "ui_generate_transacction.h"

Generate_transacction::Generate_transacction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Generate_transacction)
{
    ui->setupUi(this);
}

Generate_transacction::~Generate_transacction()
{
    delete ui;
}

void Generate_transacction::on_pushButton_clicked()
{
    close();
}

QString Generate_transacction::get_data_amount(){
    return  QString::number(ui->amount->value());
}

QString Generate_transacction::get_data_reciever(){
    return  ui->reciever->toPlainText();
}

QString Generate_transacction::get_data_sender(){
    return  ui->sender->toPlainText();
}

