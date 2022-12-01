#include "widget.h"
#include "./ui_widget.h"

#include "QTime"
#include "generate_transacction.h"
#include "bc_test.h"
#include"./TRANSACTION.h"
#include "./binary_data.h"
#include <vector>


std::string FILENAME = "/home/sebau/Escritorio/Qt_tests/prueba_gui/data";
bool flag = false;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("HeiderCoin");

    // GENERAR BLOCKCHAIN CARGANDO EL ARCHIVO
    if(flag == false){
        VariableRecord *file = new VariableRecord(FILENAME);
        vector<Transaction> loadFile = file->load();
        for (int i = 0; i < loadFile.size(); i++){
            TRANSACTION *tran = new TRANSACTION(loadFile[i].amount, loadFile[i].sender, loadFile[i].reciever, loadFile[i].timestamp);
            this->heiderCoin->addBlock(tran);
        }
        flag = true;
    }
    ui->resultado->setText(QString::number(this->heiderCoin->get_size()));

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{

    Generate_transacction gt;
    gt.setModal(true);
    gt.exec();

    QString amount = gt.get_data_amount();
    QString reciever= gt.get_data_reciever();
    QString sender = gt.get_data_sender();
    QString date = QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss,zzz");

    VariableRecord *file = new VariableRecord(FILENAME);
    Transaction new_transaction = {amount.toStdString(), sender.toStdString(), reciever.toStdString(), date.toStdString()};
    file->add(new_transaction);
    TRANSACTION *tran = new TRANSACTION(amount.toStdString(), sender.toStdString(), reciever.toStdString(), date.toStdString());

    this->heiderCoin->addBlock(tran);
    ui->resultado->clear();
    ui->resultado->setText(QString::number(this->heiderCoin->get_size()));
}


void Widget::on_pushButton_2_clicked()
{
    bc_test bt(nullptr, this->heiderCoin);
    bt.setModal(true);
    bt.exec();
}


void Widget::on_pushButton_3_clicked()
{
    close()
}

