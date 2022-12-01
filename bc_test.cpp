#include "bc_test.h"
#include "ui_bc_test.h"

Blockchain *heiderCoin;

bc_test::bc_test(QWidget *parent, Blockchain *_heiderCoin) :
    QDialog(parent),
    ui(new Ui::bc_test)
{
    heiderCoin = _heiderCoin;
    ui->setupUi(this);
}

bc_test::~bc_test()
{
    delete ui;
}

void bc_test::on_show_clicked()
{
    heiderCoin->show_blockchain();
}


void bc_test::on_pushButton_2_clicked()
{
    heiderCoin->test_proof_work(2);
}


void bc_test::on_close_clicked()
{
    heiderCoin->fix_all();
    close();
}


void bc_test::on_pushButton_3_clicked()
{
    heiderCoin->fix_all();
}

