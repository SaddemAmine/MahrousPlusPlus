#include "reclamations_rh.h"
#include "ui_reclamations_rh.h"
#include <QDebug>

void reclamations_rh::preplist(){
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery * qry = new QSqlQuery();
    qry->prepare("select objet||', '||nompersonnel||' '||prenompersonnel||', '||reclamations.cin, idreclamation from reclamations, personnels where reclamations.cin = personnels.cin and etat = 0;");
    qry->exec();
    model->setQuery(*qry);
    ui->comboBox->setModel(model);
    //qDebug() << model->data(model->index(0,1));
}

reclamations_rh::reclamations_rh(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reclamations_rh)
{
    ui->setupUi(this);
    preplist();
}

reclamations_rh::~reclamations_rh(){
    delete ui;
}

void reclamations_rh::on_comboBox_currentIndexChanged(){
    QString whereClause = ui->comboBox->model()->data(ui->comboBox->model()->index(ui->comboBox->currentIndex(),1)).toString();
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery * qry = new QSqlQuery();
    qry->prepare("select message, commentaire from reclamations where idreclamation = "+whereClause+";");
    qry->exec();
    model->setQuery(*qry);
    ui->textBrowser->setText(model->data(model->index(0,0)).toString());
    ui->textEdit->setText(model->data(model->index(0,1)).toString());
}

void reclamations_rh::on_pushButton_2_clicked(){
    QString whereClause = ui->comboBox->model()->data(ui->comboBox->model()->index(ui->comboBox->currentIndex(),1)).toString();
    QSqlQuery * qry = new QSqlQuery();
    qry->prepare("update reclamations set commentaire = :commentaire , etat = :etat where idreclamation = "+whereClause+";");
    qry->bindValue(":commentaire",ui->textEdit->toPlainText());
    qry->bindValue(":etat",ui->checkBox->isChecked() ? 1 : 0);
    qry->exec();
    //list refresh if the checkbox is checked
    if(ui->checkBox->isChecked())
        preplist();
}
