#ifndef GENERATE_TRANSACCTION_H
#define GENERATE_TRANSACCTION_H

#include <QDialog>

namespace Ui {
class Generate_transacction;
}

class Generate_transacction : public QDialog
{
    Q_OBJECT

public:
    explicit Generate_transacction(QWidget *parent = nullptr);
    ~Generate_transacction();
    QString get_data_amount();
    QString get_data_reciever();
    QString get_data_sender();

private slots:

    void on_pushButton_clicked();

private:
    Ui::Generate_transacction *ui;
};

#endif // GENERATE_TRANSACCTION_H
