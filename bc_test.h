#ifndef BC_TEST_H
#define BC_TEST_H

#include <QDialog>
#include "BlockChain.h"

namespace Ui {
class bc_test;
}

class bc_test : public QDialog
{
    Q_OBJECT

public:
    explicit bc_test(QWidget *parent = nullptr, Blockchain *heiderCoin = nullptr);
    ~bc_test();

private slots:
    void on_show_clicked();

    void on_pushButton_2_clicked();

    void on_close_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::bc_test *ui;
};

#endif // BC_TEST_H
