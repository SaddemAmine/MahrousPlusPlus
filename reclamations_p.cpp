#include "reclamations_p.h"
#include "ui_reclamations_p.h"

reclamations_p::reclamations_p(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reclamations_p)
{
    ui->setupUi(this);
}

reclamations_p::~reclamations_p()
{
    delete ui;
}

void reclamations_p::on_pushButton_2_clicked(){
    reclamations r;
    r.ajoutreclamation(ui->lineEdit->text(),ui->lineEdit_2->text(),ui->plainTextEdit->toPlainText());
}
