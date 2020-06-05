#include "historique.h"
#include "ui_historique.h"
#include <QDialog>
#include <QMessageBox>
#include <QDate>
#include <QTime>
#include <QTimer>
#include <QProgressBar>
#include <QStatusBar>
#include <QWidget>
#include <QString>
#include <QDebug>
#include <windows.h>
#include <QFile>
#include <QPrinter>
#include <QPrintDialog>
#include <QFileDialog>
Historique::Historique(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Historique)
{
    ui->setupUi(this);
    QPixmap pix("A:/qt/gestionmateriaux/resources/template.png");
    int w =ui->pic->width();
    int h =ui->pic->height();
    ui->pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ouvrirPlante();
    ouvrirAnimaux();//c bon
    ouvrirMateriel();//c bon
    ouvrirAffectation();//c bon
    ouvrirFournisseur();//c bon
    ouvrirBesoinPlante();
    ouvrirBesoinAnimaux();//c bon
    ouvrirEspeceAnimale();//c bon
    ouvrirCategoriePlante();//c bon
    ouvrirCategorieMateriel();//cbon
    ouvrirproductionanimal();//c bon

}

Historique::~Historique()
{
    delete ui;
}
//affectation
void Historique::ouvrirAffectation()
{
    QFile file ("A:\\integration\\integration final\\2\\mahrousplusplus\\Historique\\HistoriqueAffectation.txt");
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0,"info",file.errorString());
    }
    QTextStream in (&file);
    ui->affectation_Historique->setText(in.readAll());
}
//bouton suivant
void Historique::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
//precedent
void Historique::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

//imprimer
void Historique::on_pushButton_clicked()
{
    QPrinter printer;
    printer.setPrinterName("desierd printer name");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec()== QDialog::Rejected) return;
    ui->affectation_Historique->print(&printer);
}


//ouvrir animaux
void Historique::ouvrirAnimaux()
{
    QFile file ("A:\\integration\\integration final\\2\\mahrousplusplus\\Historique\\Historiqueanimaux.txt");
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0,"info",file.errorString());
    }
    QTextStream in (&file);
    ui->Historique_Animaux->setText(in.readAll());

}

void Historique::on_pushButton_7_clicked()
{
    QPrinter printer;
    printer.setPrinterName("desierd printer name");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec()== QDialog::Rejected) return;
    ui->Historique_Animaux->print(&printer);
}

void Historique::on_pushButton_11_clicked()
{
    QString searchString = ui->Recherche_Historique_2->text();
    QTextDocument *document = ui->Historique_Animaux->document();
   ouvrirAnimaux();
    bool found = false;

    document->undo();

    if (searchString.isEmpty()) {
        QMessageBox::information(this, tr("Empty Search Field"),
                                 tr("The search field is empty. "
                                    "Please enter a word and click Find."));
    } else {
        QTextCursor highlightCursor(document);
        QTextCursor cursor(document);

        cursor.beginEditBlock();


        QTextCharFormat plainFormat(highlightCursor.charFormat());
        QTextCharFormat colorFormat = plainFormat;
        colorFormat.setForeground(Qt::red);

        while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
            highlightCursor = document->find(searchString, highlightCursor,
                                             QTextDocument::FindWholeWords);

            if (!highlightCursor.isNull()) {
                found = true;
                highlightCursor.movePosition(QTextCursor::WordRight,
                                             QTextCursor::KeepAnchor);
                highlightCursor.mergeCharFormat(colorFormat);

            }
        }


        cursor.endEditBlock();

        if (found == false) {
            QMessageBox::information(this, tr("Word Not Found"),
                                     tr("Sorry, the word cannot be found."));
        }
    }

}
//suivant
void Historique::on_pushButton_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}
//presedent
void Historique::on_pushButton_4_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}
//besoin Plante
void Historique::ouvrirBesoinPlante()
{
    QFile file ("A:\\integration\\mahrousplusplus\\Historique\\HistoriqueBesoinPlantes.txt");
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0,"info",file.errorString());
    }
    QTextStream in (&file);
    ui->Historique_besoin_plante->setText(in.readAll());
}

void Historique::on_pushButton_9_clicked()
{
    QPrinter printer;
    printer.setPrinterName("desierd printer name");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec()== QDialog::Rejected) return;
    ui->Historique_besoin_plante->print(&printer);
}

void Historique::on_pushButton_10_clicked()
{
    QString searchString = ui->Recherche_Historique_2->text();
    QTextDocument *document = ui->Historique_Animaux->document();
   ouvrirBesoinPlante();
    bool found = false;

    document->undo();

    if (searchString.isEmpty()) {
        QMessageBox::information(this, tr("Empty Search Field"),
                                 tr("The search field is empty. "
                                    "Please enter a word and click Find."));
    } else {
        QTextCursor highlightCursor(document);
        QTextCursor cursor(document);

        cursor.beginEditBlock();


        QTextCharFormat plainFormat(highlightCursor.charFormat());
        QTextCharFormat colorFormat = plainFormat;
        colorFormat.setForeground(Qt::red);

        while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
            highlightCursor = document->find(searchString, highlightCursor,
                                             QTextDocument::FindWholeWords);

            if (!highlightCursor.isNull()) {
                found = true;
                highlightCursor.movePosition(QTextCursor::WordRight,
                                             QTextCursor::KeepAnchor);
                highlightCursor.mergeCharFormat(colorFormat);

            }
        }


        cursor.endEditBlock();

        if (found == false) {
            QMessageBox::information(this, tr("Word Not Found"),
                                     tr("Sorry, the word cannot be found."));
        }
    }
}
//bouton precedent
void Historique::on_pushButton_28_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}
//bouton suivant
void Historique::on_pushButton_29_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}
//besoin animaux
//ouvrir
void Historique::ouvrirBesoinAnimaux()
{
    QFile file ("A:\\integration\\integration final\\2\\mahrousplusplus\\Historique\\HistoriqueBesoinAnimaux.txt");
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0,"info",file.errorString());
    }
    QTextStream in (&file);
    ui->Historique_Besoin->setText(in.readAll());
}
void Historique::on_pushButton_12_clicked()
{
    QPrinter printer;
    printer.setPrinterName("desierd printer name");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec()== QDialog::Rejected) return;
    ui->Historique_Besoin->print(&printer);
}
void Historique::on_pushButton_13_clicked()
{
    QString searchString = ui->Recherche_Historique_2->text();
    QTextDocument *document = ui->Historique_Animaux->document();
  ouvrirBesoinAnimaux();
    bool found = false;

    document->undo();

    if (searchString.isEmpty()) {
        QMessageBox::information(this, tr("Empty Search Field"),
                                 tr("The search field is empty. "
                                    "Please enter a word and click Find."));
    } else {
        QTextCursor highlightCursor(document);
        QTextCursor cursor(document);

        cursor.beginEditBlock();


        QTextCharFormat plainFormat(highlightCursor.charFormat());
        QTextCharFormat colorFormat = plainFormat;
        colorFormat.setForeground(Qt::red);

        while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
            highlightCursor = document->find(searchString, highlightCursor,
                                             QTextDocument::FindWholeWords);

            if (!highlightCursor.isNull()) {
                found = true;
                highlightCursor.movePosition(QTextCursor::WordRight,
                                             QTextCursor::KeepAnchor);
                highlightCursor.mergeCharFormat(colorFormat);

            }
        }


        cursor.endEditBlock();

        if (found == false) {
            QMessageBox::information(this, tr("Word Not Found"),
                                     tr("Sorry, the word cannot be found."));
        }
    }
}

//bouton suivant
void Historique::on_pushButton_31_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}
//bouton precedent
void Historique::on_pushButton_30_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
//categorie materile
void Historique::ouvrirCategorieMateriel()
{
    QFile file ("A:\\integration\\integration final\\2\\mahrousplusplus\\Historique\\HistoriqueCategorieMateriel.txt");
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0,"info",file.errorString());
    }
    QTextStream in (&file);
    ui->historique_categorie->setText(in.readAll());

}

void Historique::on_ImprimerpdfHistoriqueCategorieMateriel_clicked()
{
    QPrinter printer;
    printer.setPrinterName("desierd printer name");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec()== QDialog::Rejected) return;
    ui->historique_categorie->print(&printer);
}

void Historique::on_RecherhceHistoriqueCategoreMateriel_clicked()
{
    QString searchString = ui->lineEdit_HR->text();
    QTextDocument *document = ui->historique_categorie->document();
  ouvrirCategorieMateriel();
    bool found = false;

    document->undo();

    if (searchString.isEmpty()) {
        QMessageBox::information(this, tr("Empty Search Field"),
                                 tr("The search field is empty. "
                                    "Please enter a word and click Find."));
    } else {
        QTextCursor highlightCursor(document);
        QTextCursor cursor(document);

        cursor.beginEditBlock();


        QTextCharFormat plainFormat(highlightCursor.charFormat());
        QTextCharFormat colorFormat = plainFormat;
        colorFormat.setForeground(Qt::red);

        while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
            highlightCursor = document->find(searchString, highlightCursor,
                                             QTextDocument::FindWholeWords);

            if (!highlightCursor.isNull()) {
                found = true;
                highlightCursor.movePosition(QTextCursor::WordRight,
                                             QTextCursor::KeepAnchor);
                highlightCursor.mergeCharFormat(colorFormat);

            }
        }


        cursor.endEditBlock();

        if (found == false) {
            QMessageBox::information(this, tr("Word Not Found"),
                                     tr("Sorry, the word cannot be found."));
        }
    }
}
//bouron suivant
void Historique::on_pushButton_33_clicked()
{
   ui->stackedWidget->setCurrentIndex(5);
}
//bouton precedent


void Historique::on_pushButton_32_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}
//categorie plante
void Historique::ouvrirCategoriePlante()
{
    QFile file ("A:\\integration\\integration final\\2\\mahrousplusplus\\Historique\\HistoriqueEspecePlante.txt");
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0,"info",file.errorString());
    }
    QTextStream in (&file);
    ui->Hitorique_Espece_plante->setText(in.readAll());

}

void Historique::on_pushButton_16_clicked()
{
    QPrinter printer;
    printer.setPrinterName("desierd printer name");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec()== QDialog::Rejected) return;
    ui->Hitorique_Espece_plante->print(&printer);
}

void Historique::on_pushButton_14_clicked()
{
    QString searchString = ui->Recherche_Historique_3->text();
    QTextDocument *document = ui->Hitorique_Espece_plante->document();
   ouvrirCategoriePlante();
    bool found = false;

    document->undo();

    if (searchString.isEmpty()) {
        QMessageBox::information(this, tr("Empty Search Field"),
                                 tr("The search field is empty. "
                                    "Please enter a word and click Find."));
    } else {
        QTextCursor highlightCursor(document);
        QTextCursor cursor(document);

        cursor.beginEditBlock();


        QTextCharFormat plainFormat(highlightCursor.charFormat());
        QTextCharFormat colorFormat = plainFormat;
        colorFormat.setForeground(Qt::red);

        while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
            highlightCursor = document->find(searchString, highlightCursor,
                                             QTextDocument::FindWholeWords);

            if (!highlightCursor.isNull()) {
                found = true;
                highlightCursor.movePosition(QTextCursor::WordRight,
                                             QTextCursor::KeepAnchor);
                highlightCursor.mergeCharFormat(colorFormat);

            }
        }


        cursor.endEditBlock();

        if (found == false) {
            QMessageBox::information(this, tr("Word Not Found"),
                                     tr("Sorry, the word cannot be found."));
        }
    }
}

//bouton suivant
void Historique::on_pushButton_35_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}
//bouton precedent
void Historique::on_pushButton_34_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}
//espace animale
void Historique::ouvrirEspeceAnimale()
{
    QFile file ("A:\\integration\\integration final\\2\\mahrousplusplus\\Historique\\HistoriqueEspeceAnimal.txt");
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0,"info",file.errorString());
    }
    QTextStream in (&file);
    ui->Historique_Espece->setText(in.readAll());
}

void Historique::on_pushButton_17_clicked()
{
    QPrinter printer;
    printer.setPrinterName("desierd printer name");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec()== QDialog::Rejected) return;
    ui->Historique_Espece->print(&printer);
}

void Historique::on_pushButton_19_clicked()
{
    QString searchString = ui->Find_Historique->text();
    QTextDocument *document = ui->Historique_Espece->document();
   ouvrirEspeceAnimale();
    bool found = false;

    document->undo();

    if (searchString.isEmpty()) {
        QMessageBox::information(this, tr("Empty Search Field"),
                                 tr("The search field is empty. "
                                    "Please enter a word and click Find."));
    } else {
        QTextCursor highlightCursor(document);
        QTextCursor cursor(document);

        cursor.beginEditBlock();


        QTextCharFormat plainFormat(highlightCursor.charFormat());
        QTextCharFormat colorFormat = plainFormat;
        colorFormat.setForeground(Qt::red);

        while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
            highlightCursor = document->find(searchString, highlightCursor,
                                             QTextDocument::FindWholeWords);

            if (!highlightCursor.isNull()) {
                found = true;
                highlightCursor.movePosition(QTextCursor::WordRight,
                                             QTextCursor::KeepAnchor);
                highlightCursor.mergeCharFormat(colorFormat);

            }
        }


        cursor.endEditBlock();

        if (found == false) {
            QMessageBox::information(this, tr("Word Not Found"),
                                     tr("Sorry, the word cannot be found."));
        }
    }
}
//bouton suivant
void Historique::on_pushButton_37_clicked()
{
     ui->stackedWidget->setCurrentIndex(7);
}
//bouton precedent


void Historique::on_pushButton_36_clicked()
{
      ui->stackedWidget->setCurrentIndex(5);
}
//fournissuer
void Historique::ouvrirFournisseur()
{
    QFile file ("A:\\integration\\integration final\\2\\mahrousplusplus\\Historique\\HistoriqueFourniseur.txt");
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0,"info",file.errorString());
    }
    QTextStream in (&file);
    ui->historique_fournisseur->setText(in.readAll());


}
void Historique::on_pushButton_20_clicked()
{

    QPrinter printer;
    printer.setPrinterName("desierd printer name");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec()== QDialog::Rejected) return;
    ui->historique_fournisseur->print(&printer);

}


void Historique::on_pushButton_22_clicked()
{
    QString searchString = ui->Recheche_Historique->text();
    QTextDocument *document = ui->historique_fournisseur->document();
   ouvrirFournisseur();
    bool found = false;

    document->undo();

    if (searchString.isEmpty()) {
        QMessageBox::information(this, tr("Empty Search Field"),
                                 tr("The search field is empty. "
                                    "Please enter a word and click Find."));
    } else {
        QTextCursor highlightCursor(document);
        QTextCursor cursor(document);

        cursor.beginEditBlock();


        QTextCharFormat plainFormat(highlightCursor.charFormat());
        QTextCharFormat colorFormat = plainFormat;
        colorFormat.setForeground(Qt::red);

        while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
            highlightCursor = document->find(searchString, highlightCursor,
                                             QTextDocument::FindWholeWords);

            if (!highlightCursor.isNull()) {
                found = true;
                highlightCursor.movePosition(QTextCursor::WordRight,
                                             QTextCursor::KeepAnchor);
                highlightCursor.mergeCharFormat(colorFormat);

            }
        }


        cursor.endEditBlock();

        if (found == false) {
            QMessageBox::information(this, tr("Word Not Found"),
                                     tr("Sorry, the word cannot be found."));
        }
    }
}

//bouton suivant
void Historique::on_pushButton_39_clicked()
{
 ui->stackedWidget->setCurrentIndex(8);
}
//bouton presedent


void Historique::on_pushButton_38_clicked()
{
     ui->stackedWidget->setCurrentIndex(6);
}
//materiel
void Historique::ouvrirMateriel()
{
    QFile file ("A:\\integration\\integration final\\2\\mahrousplusplus\\Historique\\HistoriqueMateriel.txt");
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0,"info",file.errorString());
    }
    QTextStream in (&file);
    ui->historique_materiel->setText(in.readAll());
}
void Historique::on_pushButton_23_clicked()
{

   QPrinter printer;
   printer.setPrinterName("desierd printer name");
   QPrintDialog dialog(&printer,this);
   if(dialog.exec()== QDialog::Rejected) return;
   ui->historique_materiel->print(&printer);


}

void Historique::on_find_clicked()
{QString searchString = ui->Recherche_Historique_4->text();
    QTextDocument *document = ui->historique_materiel->document();
   ouvrirMateriel();
    bool found = false;

    document->undo();

    if (searchString.isEmpty()) {
        QMessageBox::information(this, tr("Empty Search Field"),
                                 tr("The search field is empty. "
                                    "Please enter a word and click Find."));
    } else {
        QTextCursor highlightCursor(document);
        QTextCursor cursor(document);

        cursor.beginEditBlock();


        QTextCharFormat plainFormat(highlightCursor.charFormat());
        QTextCharFormat colorFormat = plainFormat;
        colorFormat.setForeground(Qt::red);

        while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
            highlightCursor = document->find(searchString, highlightCursor,
                                             QTextDocument::FindWholeWords);

            if (!highlightCursor.isNull()) {
                found = true;
                highlightCursor.movePosition(QTextCursor::WordRight,
                                             QTextCursor::KeepAnchor);
                highlightCursor.mergeCharFormat(colorFormat);

            }
        }


        cursor.endEditBlock();

        if (found == false) {
            QMessageBox::information(this, tr("Word Not Found"),
                                     tr("Sorry, the word cannot be found."));
        }
    }

}
//bouton suivant

void Historique::on_pushButton_41_clicked()
{
     ui->stackedWidget->setCurrentIndex(9);
}
//bouton precedent

void Historique::on_pushButton_40_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}
//plante
//bouton suivant
void Historique::on_pushButton_43_clicked()
{
 ui->stackedWidget->setCurrentIndex(10);
}
//bouton precedent

void Historique::on_pushButton_42_clicked()
{
  ui->stackedWidget->setCurrentIndex(8);
}

void Historique::ouvrirPlante()
{

    QFile file ("A:\\integration\\mahrousplusplus\\Historique\\HistoriquePlante.txt");
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0,"info",file.errorString());
    }
    QTextStream in (&file);
    ui->Historique_plante->setText(in.readAll());

}

void Historique::on_pushButton_27_clicked()
{


   QPrinter printer;
   printer.setPrinterName("desierd printer name");
   QPrintDialog dialog(&printer,this);
   if(dialog.exec()== QDialog::Rejected) return;
   ui->Historique_plante->print(&printer);


}

void Historique::on_pushButton_25_clicked()
{
    QString searchString = ui->recherche_Historique->text();
    QTextDocument *document = ui->Historique_plante->document();
 ouvrirPlante();
    bool found = false;

    document->undo();

    if (searchString.isEmpty()) {
        QMessageBox::information(this, tr("Empty Search Field"),
                                 tr("The search field is empty. "
                                    "Please enter a word and click Find."));
    } else {
        QTextCursor highlightCursor(document);
        QTextCursor cursor(document);

        cursor.beginEditBlock();


        QTextCharFormat plainFormat(highlightCursor.charFormat());
        QTextCharFormat colorFormat = plainFormat;
        colorFormat.setForeground(Qt::red);

        while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
            highlightCursor = document->find(searchString, highlightCursor,
                                             QTextDocument::FindWholeWords);

            if (!highlightCursor.isNull()) {
                found = true;
                highlightCursor.movePosition(QTextCursor::WordRight,
                                             QTextCursor::KeepAnchor);
                highlightCursor.mergeCharFormat(colorFormat);

            }
        }


        cursor.endEditBlock();

        if (found == false) {
            QMessageBox::information(this, tr("Word Not Found"),
                                     tr("Sorry, the word cannot be found."));
        }
    }
}
//production animaux
//ouvrir
void Historique::ouvrirproductionanimal()
{
    QFile file ("A:\\integration\\integration final\\2\\mahrousplusplus\\Historique\\Historiqueproductionanimaux.txt");
      if (!file.open(QIODevice::ReadOnly))
       {
          QMessageBox::information(0,"info",file.errorString());
       }
       QTextStream in (&file);
       ui->Historique_productionAnimaux->setText(in.readAll());
}

void Historique::on_pushButton_15_clicked()
{
    QPrinter printer;
    printer.setPrinterName("desierd printer name");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec()== QDialog::Rejected) return;
    ui->Historique_productionAnimaux->print(&printer);

}

void Historique::on_pushButton_18_clicked()
{
    QString searchString = ui->Recherche_Historique_5->text();
    QTextDocument *document = ui->Historique_productionAnimaux->document();
 ouvrirPlante();
    bool found = false;

    document->undo();

    if (searchString.isEmpty()) {
        QMessageBox::information(this, tr("Empty Search Field"),
                                 tr("The search field is empty. "
                                    "Please enter a word and click Find."));
    } else {
        QTextCursor highlightCursor(document);
        QTextCursor cursor(document);

        cursor.beginEditBlock();


        QTextCharFormat plainFormat(highlightCursor.charFormat());
        QTextCharFormat colorFormat = plainFormat;
        colorFormat.setForeground(Qt::red);

        while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
            highlightCursor = document->find(searchString, highlightCursor,
                                             QTextDocument::FindWholeWords);

            if (!highlightCursor.isNull()) {
                found = true;
                highlightCursor.movePosition(QTextCursor::WordRight,
                                             QTextCursor::KeepAnchor);
                highlightCursor.mergeCharFormat(colorFormat);

            }
        }


        cursor.endEditBlock();

        if (found == false) {
            QMessageBox::information(this, tr("Word Not Found"),
                                     tr("Sorry, the word cannot be found."));
        }
    }
}

void Historique::on_pushButton_44_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void Historique::on_pushButton_45_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//affectation
void Historique::on_pushButton_8_clicked()
{
    QString searchString = ui->Recherche_Historique_affectation->text();
    QTextDocument *document = ui->affectation_Historique->document();
   ouvrirAffectation();
    bool found = false;

    document->undo();

    if (searchString.isEmpty()) {
        QMessageBox::information(this, tr("Empty Search Field"),
                                 tr("The search field is empty. "
                                    "Please enter a word and click Find."));
    } else {
        QTextCursor highlightCursor(document);
        QTextCursor cursor(document);

        cursor.beginEditBlock();


        QTextCharFormat plainFormat(highlightCursor.charFormat());
        QTextCharFormat colorFormat = plainFormat;
        colorFormat.setForeground(Qt::red);

        while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
            highlightCursor = document->find(searchString, highlightCursor,
                                             QTextDocument::FindWholeWords);

            if (!highlightCursor.isNull()) {
                found = true;
                highlightCursor.movePosition(QTextCursor::WordRight,
                                             QTextCursor::KeepAnchor);
                highlightCursor.mergeCharFormat(colorFormat);

            }
        }


        cursor.endEditBlock();

        if (found == false) {
            QMessageBox::information(this, tr("Word Not Found"),
                                     tr("Sorry, the word cannot be found."));
        }
    }
}

