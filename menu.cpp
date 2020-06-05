#include "menu.h"
#include"image.h"
#include "ui_menu.h"
#include "parametre.h"
#include "gestion_categorie_materiel.h"
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
#include "photo.h"
Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    qDebug () << sy.login("00000002","1234");
    //volume
    QPixmap pix("C:/Users/ASUS/Downloads/speaker.png");
    int w =ui->volume->width();
    int h =ui->volume->height();
    ui->volume->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    lng="";
    cl=1;
    speek=1;
    securite =1;
    a=0;
    ui->stackedWidget->setCurrentIndex(13);

    //animation

    animation1 =new QPropertyAnimation (ui->pushButton_140,"geometry");
    animation1->setDuration(2000);
    animation1->setStartValue(ui->pushButton_140->geometry());
    animation1->setEndValue(QRect(720,430,91,31));
    animation2 =new QPropertyAnimation (ui->pushButton_138,"geometry");
    animation2->setDuration(2000);
    animation2->setStartValue(ui->pushButton_138->geometry());
    animation2->setEndValue(QRect(340,430,91,31));
    animationGroup =new QParallelAnimationGroup;
    animationGroup->addAnimation(animation1);
    animationGroup->addAnimation(animation2);
    animationGroup->start();



    //parametre
    ui->pushButton_150->hide();
    ui->pushButton_144->hide();
    ui->pushButton_154->hide();
    player= new QMediaPlayer();
    player->setMedia(QUrl::fromLocalFile("A:\\integration\\integration final\\2\\mahrousplusplus\\Farma.mp3"));
    player->play();
    connect(player, &QMediaPlayer::positionChanged, this, &Menu::on_positionChanged);
    connect(player, &QMediaPlayer::durationChanged, this, &Menu::on_durationChanged);
    click = new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("A:/integration/integration final/2/mahrousplusplus/click.mp3"));
    //categorie materiel
    ui->afficher_categorie->setModel(tmpcat.afficher_Categorie());
    ui->cx_idcategorie->setEnabled(1);
    //affectation
    ui->afficher_affectation->setModel(tmpaff.afficher_Affectation());
    ui->comboBox_cin->setModel(tmpmat.afficher_CINlist());
    ui->comboBox_materiel->setModel(tmpmat.afficher_Mlist());
    ui->cx_id_affectation->setEnabled(1);
    //materiel
    ui->afficher_materiel->setModel(tmpmat.afficher_materiel());
    ui->comboBox_categorie->setModel(tmpcat.afficher_Clist());
    ui->comboBox_idf->setModel(tmpf.afficher_Flist());
    ui->cx_idm->setEnabled(1);
    ui->count->setStyleSheet("QLabel{min-width: 20px; min-height: 20px;max-width:20px; max-height: 16px;border-radius: 8px;  border:1px solid black;background:red;}");
    ui->count->setNum(tmpmat.afficher_count());
    ui->pushButton_26->hide();
    ui->afficher_materiel_insu->hide();
    //fournisseur
    ui->afficher_fournisseur->setModel(tmpf.afficher_fournisseur());
    ui->cx_idf->setEnabled(1);
    ui->listView->hide();
    ui->listView2->hide();
    ui->pushButton_40->hide();
    ui->pushButton_38->hide();
    //categorie plante
    ui->affiche_categorieplante->setModel(tmpcatp.afficher_Categorie());
    ui->cx_idcategorieplante->setEnabled(1);
    //plante
    ui->afficher_plante->setModel(tmppl.afficher_plante());
    ui->comboBox_categorie_2->setModel(tmpcat.afficher_Clist());
    ui->comboBox_cin_2->setModel(tmppl.afficher_CINlist());
    ui->comboBox_IDBP->setModel(tmppl.afficher_IDBPlist());
    ui->cx_idp->setEnabled(1);
    //besoin animaux
    ui->afficher_besoinanimaux->setModel(tmpba.afficher_besoinanimaux());
    ui->cx_idb->setEnabled(1);
    //production animaux
    ui->afficher_productionanimaux->setModel(tmppa.afficher_productionanimaux());
    ui->comboBox_idespece->setModel(tmpea.afficher_Clist());
    ui->cx_idp->setEnabled(1);
    //espece animal
    ui->afficher_especeanimal->setModel(tmpea.afficher_especeanimal());
    ui->cx_idespeceanimal->setEnabled(1);
    //animal
    ui->afficher_animaux->setModel(tmpa.afficher_animaux());
    ui->comboBox_idespece_2->setModel(tmpea.afficher_Clist());
    ui->comboBox_cin_3->setModel(tmpa.afficher_CINlist());
    ui->comboBox_idba->setModel(tmpa.afficher_IDBAlist());
    ui->cx_ida->setEnabled(1);
    //besoin animaux
    ui->afficher_besoin_palnte->setModel(tmpbp.afficher_besoin_plante());
    ui->cx_idb->setEnabled(1);
    //production animaux
    ui->comboBox_CP->setModel(tmppp.afficher_pplist());
    ui->afficher_produitplante->setModel(tmppp.afficher_produit_plante());
    //fonction
    rh_personnels_ops p;
    rh_fonctions_ops f;
    ui->affichage->setModel(f.afficherFonctions(1));
    //personnel

    ui->affichage_2->setModel(p.afficherPersonnels());
    ui->comboBox->setModel(f.afficherFonctions(0));

}

Menu::~Menu()
{
    delete ui;
}
//fonction initialisation
//categorie materiel
void Menu::initcm()
{
    ui->cx_idcategorie->clear();
    ui->cx_idcategorie->setEnabled(1);
    ui->cx_nomcategorie->clear();
    ui->lineEdit_recherche->clear();
}
//Affectation
void Menu::initaf()
{
    ui->cx_id_affectation->clear();
    ui->cx_id_affectation->setEnabled(1);
    ui->Recherche->clear();
}

//materiel
void Menu::initm()
{
    ui->cx_idm->clear();
    ui->photo->clear();
    ui->chemin->clear();
    ui->cx_idm->setEnabled(1);
    ui->recherche->clear();
    ui->cx_marque->clear();
    ui->cx_desc->clear();
    ui->cx_nomM->clear();
    ui->recherche->clear();
}
//fournisseur
void Menu::initf()
{
    ui->age->clear();
    ui->cx_idf->clear();
    ui->cx_idf->setEnabled(1);
    ui->cx_tel->clear();
    ui->cx_nomf->clear();
    ui->cx_mailf->clear();
    ui->cx_prenomf->clear();
    ui->cx_recherche->clear();
    ui->cx_recherche->clear();

}
//categorie plante
void Menu::initcp()
{
    ui->cx_idcategorie->clear();
    ui->cx_nomcategorie->clear();
    ui->cx_idcategorieplante->setEnabled(1);
    ui->lineEdit_recherchecategorieplante->clear();
}
//plante
void Menu::initp()
{
    ui->cx_idp->clear();
    ui->photo_2->clear();
    ui->chemin_2->clear();
    ui->cx_idp->setEnabled(1);

}
//besoin animal
void Menu::initba()
{
    ui->cx_idb->clear();
    ui->cx_eau->clear();
    ui->cx_nutrition->clear();
    ui->cx_abri->clear();
    ui->cx_vaco->clear();
    ui->cx_idb->setEnabled(1);

}
//production animal
void Menu::initpa()
{
    ui->cx_idpa->clear();
    ui->cx_ppa->clear();
    ui->cx_prix->clear();
    ui->chemin_4->clear();
    ui->cx_idpa->setEnabled(1);
}
//espece animal
void Menu::initea()
{
    ui->cx_idespeceanimal->clear();
    ui->cx_nomespeceanimal->clear();
    ui->cx_idespeceanimal->setEnabled(1);
}
//animal
void Menu::inita()
{
    ui->cx_ida->clear();
    ui->cx_ida->setEnabled(1);
}
//Besoin Plante
void Menu::initbp()
{
    ui->cx_idbp->clear();
    ui->cx_nutp->clear();
    ui->cx_idbp->setEnabled(1);
}
//production plante
void Menu::initpp()
{
    ui->cx_pp->clear();
    ui->cx_produitp->clear();
    ui->cx_prix_2->clear();
    ui->cx_pp->setEnabled(1);
}
//init menu
void Menu::initmenu()
{
    ui->pushButton->setEnabled(1);
    ui->pushButton_16->setEnabled(1);
    ui->pushButton_116->setEnabled(1);
    ui->pushButton_117->setEnabled(1);
    ui->pushButton_68->setEnabled(1);
    ui->pushButton_71->setEnabled(1);
    ui->pushButton_5->setEnabled(1);
    ui->pushButton_14->setEnabled(1);
    ui->pushButton_12->setEnabled(1);
    ui->pushButton_17->setEnabled(1);
    ui->pushButton_6->setEnabled(1);
    ui->pushButton_15->setEnabled(1);
    ui->pushButton_70->setEnabled(1);
    ui->pushButton_69->setEnabled(1);
    ui->pushButton_94->setEnabled(1);
    ui->pushButton_97->setEnabled(1);
    ui->pushButton_39->setEnabled(1);
    ui->pushButton_44->setEnabled(1);
    ui->pushButton_127->setEnabled(1);
    ui->pushButton_126->setEnabled(1);
    ui->pushButton_136->setEnabled(1);
    ui->pushButton_31->setEnabled(1);
    ui->pushButton_49->setEnabled(1);
    ui->pushButton_50->setEnabled(1);
    ui->pushButton_32->setEnabled(1);
    ui->pushButton_137->setEnabled(1);
    ui->pushButton_96->setEnabled(1);
    ui->pushButton_95->setEnabled(1);


}
//bouton categorie materiel
void Menu::on_pushButton_clicked()
{

    if(cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->stackedWidget->setCurrentIndex(1);
    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.categoriematerielen();
        }
        else
        {
            sa.languageSelectedfr();
            sa.categoriematerielfr();
        }
    }else {  sa.stop();}

}
//bouton fournisseur
void Menu::on_pushButton_5_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->stackedWidget->setCurrentIndex(4);
    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.fournisseuren();
        }
        else
        {
            sa.languageSelectedfr();
            sa.fournisseurfr();
        }
    }else {  sa.stop();}
}
//bouton materiel
void Menu::on_pushButton_6_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->stackedWidget->setCurrentIndex(3);


    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.materielen();
        }
        else
        {
            sa.languageSelectedfr();
            sa.materielfr();
        }
    }else {  sa.stop();}
}
//bouton photo fournisseur
void Menu::on_pushButton_14_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->stackedWidget->setCurrentIndex(4);

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.fournisseuren();
        }
        else
        {
            sa.languageSelectedfr();
            sa.fournisseurfr();
        }
    }else {  sa.stop();}
}
//bouton historique
void Menu::on_pushButton_24_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    h = new Historique (this);
    h->show();
    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.historiqueen();
        }
        else
        {
            sa.languageSelectedfr();
            sa.historiquefr();
        }
    }else {  sa.stop();}
}
//categorie materiel
//afficher categorie materiel
void Menu::on_AfficherCategorieMateriel_clicked()
{

    if (cl==1)
    { click->play();}
    else
    { click->stop();}

    ui->afficher_categorie->setModel(tmpcat.afficher_Categorie());//refresh
    initcm();
    ui->cx_idcategorie->setEnabled(1);
    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.affichercmen();
            ui->label_3->setText("Show category");
        }
        else
        {
            sa.languageSelectedfr();
            sa.affichercmfr();
            ui->label_3->setText("Afficher Catégorie");
        }
    }else {  sa.stop();}
}
//supprimer categorie
void Menu::on_SupprimerCategorieMateriel_clicked()
{

    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    if (securite ==0)
    {
        QMessageBox msgBox;
        QString idC = ui->cx_idcategorie->text();
        QString NOMCATEGORIE =ui->cx_nomcategorie->text();
        bool test=tmpcat.supprimer_Categorie(idC);
        if(test)
        {
            ui->afficher_categorie->setModel(tmpcat.afficher_Categorie());
            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();
                    sa.supprimercmen(NOMCATEGORIE);
                    ui->label_3->setText("Remove category");}
                else
                {
                    sa.languageSelectedfr();
                    sa.supprimercmfr(NOMCATEGORIE);
                    ui->label_3->setText("Supprimer Catégorie");
                }
            }else {  sa.stop();}
            ui->cx_idcategorie->setEnabled(1);
            initcm();
        }
        else

        {
            QPixmap pix("A:/LOGO.png");

            msgBox.setText("verifier l'id  !.\n"
                           "Click Cancel to exit.");
            msgBox.setIconPixmap(pix);
            msgBox.exec();
        }
    }
    else
    {
        QMessageBox msgBox;
        QPixmap pix("A:/integration/integration final/danger.png");

        msgBox.setText("Il faut ouvrir cadenas .");
        msgBox.setIconPixmap(pix);
        msgBox.exec();
    }
}
//modifier categorie
void Menu::on_ModifierCategorieMaeriel_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    if (securite==0)
    {

        QString IDCATEGORIE = ui->cx_idcategorie->text();
        QString NOMCATEGORIE= ui->cx_nomcategorie->text();
        gestion_categorie_materiel C(IDCATEGORIE,NOMCATEGORIE);

        bool test=tmpcat.modifier_Categorie(C);
        if(test)
        {
            ui->afficher_categorie->setModel(tmpcat.afficher_Categorie());//refresh
            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();
                    sa.modifiercmen();
                    ui->label_3->setText("Edit category");
                }
                else
                {
                    sa.languageSelectedfr();
                    sa.modifiercmfr();
                    ui->label_3->setText("Modifier Catégorie");
                }
            }else {  sa.stop();}
            initcm();
        }
        else
        {

            QMessageBox msgBox;
            QPixmap pix("A:/LOGO.png");

            msgBox.setText("Catégorie non valide  !.\n"
                           "Click Cancel to exit.");
            msgBox.setIconPixmap(pix);
            msgBox.exec();
        }
    }
    else {
        QMessageBox msgBox;
        QPixmap pix("A:/integration/integration final/danger.png");

        msgBox.setText("Il faut ouvrir cadenas .");
        msgBox.setIconPixmap(pix);
        msgBox.exec();
    }
}
//ajouter categorie
void Menu::on_AjouterCategorieMateriel_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    if (securite==0)
    {
        QString IDCATEGORIE,NOMCATEGORIE;
        IDCATEGORIE=ui->cx_idcategorie->text();
        NOMCATEGORIE=ui->cx_nomcategorie->text();
        gestion_categorie_materiel C(IDCATEGORIE,NOMCATEGORIE);
        bool test=C.ajouter_Categorie();
        if(test)
        {
            QFile file("A:\\integration\\integration final\\2\\mahrousplusplus\\Historique\\HistoriqueCategorieMateriel.txt");
            if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
                return;
            QTextStream cout(&file);
            QString message2="\nCatégorie a été ajoutée sous :\n idC :"+IDCATEGORIE+" \n nomC : "+NOMCATEGORIE+"";
            cout << message2;
            initcm();
            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();
                    sa.ajoutercmen(NOMCATEGORIE);
                    ui->label_3->setText("Add category");
                }
                else
                {
                    sa.languageSelectedfr();
                    sa.ajoutercmfr(NOMCATEGORIE);
                    ui->label_3->setText("Ajouter Catégorie");
                }
            }else {  sa.stop();}
            ui->afficher_categorie->setModel(tmpcat.afficher_Categorie());

        }
        else
        {

            QMessageBox msgBox;
            QPixmap pix("A:/LOGO.png");

            msgBox.setText("Catégorie existe deja  !.\n"
                           "Click Cancel to exit.");
            msgBox.setIconPixmap(pix);
            msgBox.exec();
        }
    }
    else
    {
        QMessageBox msgBox;
        QPixmap pix("A:/integration/integration final/danger.png");

        msgBox.setText("Il faut ouvrir cadenas .");
        msgBox.setIconPixmap(pix);
        msgBox.exec();
    }

}
//table clicked categorie materiel
void Menu::on_afficher_categorie_activated(const QModelIndex &index)
{


    QString val=ui->afficher_categorie->model()->data(index).toString();
    QSqlQuery qry ;

    qry=tmpcat.tableclicked(val);
    if (qry.exec())
    {
        while (qry.next())
        {
            ui->cx_idcategorie->setDisabled(1);
            ui->cx_idcategorie->setText(qry.value(0).toString());
            ui->cx_nomcategorie->setText(qry.value(1).toString());
            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();
                    sa.clicked();
                    ui->label_3->setText("Selected Category");
                }
                else
                {
                    sa.languageSelectedfr();
                    sa.selectionee();
                    ui->label_3->setText("Catégorie Selectionnée");
                }
            }else {  sa.stop();}
        }
    }
}
//Trier Croissant du IdCatégorie materiel
void Menu::on_trieridcroi_clicked()
{

    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_categorie->setModel(tmpcat.afficher_idCroissant());//refresh+

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.trieCroissanten();
            ui->label_3->setText("Sort Ascending from IdCategory");
        }
        else
        {
            sa.languageSelectedfr();
            sa.trieCroissantfr();
            ui->label_3->setText("Trier Croissant du IdCatégorie");
        }
    }else {  sa.stop();}

}
//Trier Décroissant du IdCatégorie materiel
void Menu::on_trieriddecroi_clicked()
{

    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_categorie->setModel(tmpcat.afficher_idDecroissant());//refresh

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.trieDeroissanten();
            ui->label_3->setText("Sort Descending from IdCategory");
        }
        else
        {
            sa.languageSelectedfr();
            sa.trieDeroissantfr();
            ui->label_3->setText("Trier Décroissant du IdCatégorie");
        }
    }else {  sa.stop();}

}
//Trier A-Z nom categorie materiel
void Menu::on_trierAZ_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_categorie->setModel(tmpcat.afficher_nomCroissant());//refresh

    if(speek==1)   {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.trieCroissantena();
            ui->label_3->setText("Sort by A-Z");
        }
        else
        {
            sa.languageSelectedfr();
            sa.trieCroissantfra();
            ui->label_3->setText("Trier A-Z");
        }

    }else {  sa.stop();}

}
//Trier Z-A nom categorie materiel
void Menu::on_trierZA_clicked()
{
    if(cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_categorie->setModel(tmpcat.afficher_nomDecroissant());//refresh

    if(speek==1)   {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.trieDecroissantena();
            ui->label_3->setText("Sort by Z-A");
        }
        else
        {
            sa.languageSelectedfr();
            sa.trieDecroissantfra();
            ui->label_3->setText("Trier Z-A");
        }
    }else {  sa.stop();}

}
//recherche categorie materiel
void Menu::on_lineEdit_recherche_textChanged(const QString &arg1)
{
    QString q = arg1;

    if (q=="")
    {
        ui->afficher_categorie->setModel(tmpcat.afficher_Categorie()) ;

    }
    else {
        ui->afficher_categorie->setModel(tmpcat.rechercher(q)) ;

        if (lng=="en")
        {
            ui->label_3->setText("Research");
        }
        else
        {
            ui->label_3->setText("Recherche");
        }
    }
}
//materiel
//ajouter materiel
void Menu::on_pushButton_22_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    if (securite==0)
    {
        QString IDMATERIEL = ui->cx_idm->text();
        QString NOMMATERIEL= ui->cx_nomM->text();
        QString MARQUEMATERIEL= ui->cx_marque->text();
        int PRIXMATERIEL = ui->prix->text().toInt();
        int STOCKMATERIEL = ui->stock->text().toInt();
        QString DESCMATERIEL= ui->cx_desc->text();
        QString IDCATEGORIE = ui->comboBox_categorie->currentText();
        QString IDFOURNISSUER = ui->comboBox_idf->currentText();
        QString IMAGE =ui->chemin->text();//LABEL CHEMIN
        gestion_materiel M(IDMATERIEL,NOMMATERIEL,MARQUEMATERIEL,PRIXMATERIEL,STOCKMATERIEL,DESCMATERIEL,IDCATEGORIE,IMAGE,IDFOURNISSUER);
        bool test=M.ajouter_materiel();
        if(test)
        {
            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();
                    sa.ajoutermen(NOMMATERIEL);
                    ui->label_22->setText("Add Material");
                }
                else
                {
                    sa.languageSelectedfr();
                    sa.ajoutermfr(NOMMATERIEL);
                    ui->label_22->setText("Ajouter Matériel");
                }

            }else {  sa.stop();}
            QFile file("A:\\integration\\integration final\\2\\mahrousplusplus\\Historique\\HistoriqueMateriel.txt");
            if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
                return;
            QTextStream cout(&file);
            QString message2="\nMaterile  a été ajoutée sous : \nIdM:"+IDMATERIEL+"\nNomM: "+NOMMATERIEL+"\nMarqueM: "+MARQUEMATERIEL+"\nPrixM: "+ui->prix->text()+"\nStockM: "+STOCKMATERIEL+"\nDescriptionM: "+DESCMATERIEL+"\nIdC: "+IDCATEGORIE+"\nCheminImage: "+IMAGE+"\nIdF: "+IDFOURNISSUER ;
            cout << message2;
            ui->afficher_materiel->setModel(tmpmat.afficher_materiel());//refresh
            ui->count->setNum(tmpmat.afficher_count());
            initm();
        }
        else{

            QMessageBox msgBox;
            QPixmap pix("A:/LOGO.png");

            msgBox.setText("Matériel existe deja  !.\n"
                           "Click Cancel to exit.");
            msgBox.setIconPixmap(pix);
            msgBox.exec();

        }
    }
    else
    {
        QMessageBox msgBox;
        QPixmap pix("A:/integration/integration final/danger.png");

        msgBox.setText("Il faut ouvrir cadenas .");
        msgBox.setIconPixmap(pix);
        msgBox.exec();
    }
}
//supprimer materiel
void Menu::on_pushButton_27_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    if (securite==0)
    {
        QString idM = ui->cx_idm->text();
        QString NOMMATERIEL =ui->cx_nomM->text();
        bool test=tmpmat.supprimer_materiel(idM);
        if(test)
        {    ui->afficher_materiel->setModel(tmpmat.afficher_materiel());//refresh


            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();
                    sa.supprimermen(NOMMATERIEL);
                    ui->label_22->setText("Remove Material");
                }
                else
                {
                    sa.languageSelectedfr();
                    sa.supprimermfr(NOMMATERIEL);
                    ui->label_22->setText("Supprimer Matériel");
                }

            }else {  sa.stop();}
            initm();

        }
        else

        {
            QMessageBox msgBox;
            QPixmap pix("A:/LOGO.png");

            msgBox.setText("verifier le id  !.\n"
                           "Click Cancel to exit.");
            msgBox.setIconPixmap(pix);
            msgBox.exec();
        }
    }
    else {
        QMessageBox msgBox;
        QPixmap pix("A:/integration/integration final/danger.png");

        msgBox.setText("Il faut ouvrir cadenas .");
        msgBox.setIconPixmap(pix);
        msgBox.exec();
    }
}
//modifier materiel
void Menu::on_pushButton_28_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}

    if (securite==0)
    {

        QString IDMATERIEL = ui->cx_idm->text();
        QString NOMMATERIEL= ui->cx_nomM->text();
        QString MARQUEMATERIEL= ui->cx_marque->text();
        int PRIXMATERIEL = ui->prix->text().toInt();
        int STOCKMATERIEL = ui->stock->text().toInt();
        QString DESCMATERIEL= ui->cx_desc->text();
        QString IDCATEGORIE = ui->comboBox_categorie->currentText();
        QString IDFOURNISSUER = ui->comboBox_idf->currentText();
        QString IMAGE= ui->chemin->text();//LABEL CHEMIN



        gestion_materiel M(IDMATERIEL,NOMMATERIEL,MARQUEMATERIEL,PRIXMATERIEL,STOCKMATERIEL,DESCMATERIEL,IDCATEGORIE,IMAGE,IDFOURNISSUER);
        bool test=tmpmat.modifier_materiel(M);
        if(test)
        {

            ui->afficher_materiel->setModel(tmpmat.afficher_materiel());//refresh

            if(speek==1)   {
                if (lng=="en")
                {
                    sa.languageSelecteden();
                    sa.modifiermen();
                    ui->label_22->setText("Edit Material");
                }
                else
                {
                    sa.languageSelectedfr();
                    sa.modifiermfr();
                    ui->label_22->setText("Modifier Matériel");
                }

            }else {  sa.stop();}
            initm();
        }
        else
        {

            QMessageBox msgBox;
            QPixmap pix("A:/LOGO.png");
            msgBox.setText("Matériel non valide  !.\n"
                           "Click Cancel to exit.");
            msgBox.setIconPixmap(pix);
            msgBox.exec();
        }
    }
    else {
        QMessageBox msgBox;
        QPixmap pix("A:/integration/integration final/danger.png");

        msgBox.setText("Il faut ouvrir cadenas .");
        msgBox.setIconPixmap(pix);
        msgBox.exec();
    }
}
//ajouter photo materile
void Menu::on_pushButton_25_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    if (securite==0)
    {
        QString filename = QFileDialog::getOpenFileName(this,tr("choose"), "" , tr("image (*.png *.jpg *.jpeg *.bmp *.gif)"));
        if ( QString::compare(filename, QString()) != 0 )
        {
            QImage image;
            bool valid =image.load(filename);
            if (valid)
            {
                ui->chemin->setText(filename);
                image =image.scaledToWidth(ui->photo->width(),Qt::SmoothTransformation);
                ui->photo->setPixmap(QPixmap::fromImage(image));

                if(speek==1)
                {
                    if (lng=="en")
                    {
                        sa.languageSelecteden();
                        sa.ajouterimageen();
                        ui->label_22->setText("Add picture");
                    }
                    else
                    {
                        sa.languageSelectedfr();
                        sa.ajouterimagefr();
                        ui->label_22->setText("Ajouter image");
                    }

                }else {  sa.stop();}
            }

        }
    }
    else
    {
        QMessageBox msgBox;
        QPixmap pix("A:/integration/integration final/danger.png");

        msgBox.setText("Il faut ouvrir cadenas .");
        msgBox.setIconPixmap(pix);
        msgBox.exec();
    }
}
//MODIFIER PHOTO materiel
void Menu::on_pushButton_11_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    if (securite ==0)
    {
        QString filename = QFileDialog::getOpenFileName(this,tr("choose"), "" , tr("image (*.png *.jpg *.jpeg *.bmp *.gif)"));
        if ( QString::compare(filename, QString()) != 0 )
        {
            QImage image;
            bool valid =image.load(filename);
            if (valid)
            {
                ui->chemin->setText(filename);
                image =image.scaledToWidth(ui->photo->width(),Qt::SmoothTransformation);
                ui->photo->setPixmap(QPixmap::fromImage(image));

                if(speek==1)
                {
                    if (lng=="en")
                    {
                        sa.languageSelecteden();
                        sa.modifierimageen();
                        ui->label_22->setText("Edit picture");
                    }
                    else
                    {
                        sa.languageSelectedfr();
                        sa.modifierimagefr();
                        ui->label_22->setText("Modifier image");
                    }

                }else {  sa.stop();}
            }
        }
    }
    else
    {
        QMessageBox msgBox;
        QPixmap pix("A:/integration/integration final/danger.png");

        msgBox.setText("Il faut ouvrir cadenas .");
        msgBox.setIconPixmap(pix);
        msgBox.exec();
    }
}
//option Image materiel
void Menu::on_pushButton_23_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    image p;
    p.setchemin(ui->chemin->text());

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.afficherimageen();
            ui->label_22->setText("Show picture");
        }
        else
        {
            sa.languageSelectedfr();
            sa.afficherimagefr();
            ui->label_22->setText("Afficher image");
        }

    }else {  sa.stop();}
    p.exec();
}
//recherche materiel
void Menu::on_recherche_textChanged(const QString &arg1)
{
    QString q = arg1;

    if (q=="")
    {
        ui->afficher_materiel->setModel(tmpmat.afficher_materiel()) ;

    }
    else {
        ui->afficher_categorie->setModel(tmpmat.rechercher(q)) ;
        if (lng=="en")
        {
            ui->label_22->setText("Research");
        }
        else
        {
            ui->label_22->setText("Recherche");
        }
    }
}
//Tri A-Z nom materiel
void Menu::on_radioButton_9_clicked()
{

    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_materiel->setModel(tmpmat.afficher_nomCroissant());//refresh

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.trieCroissantena();
            ui->label_22->setText("Sort by A-Z");
        }
        else
        {
            sa.languageSelectedfr();
            sa.trieCroissantfra();
            ui->label_22->setText("Trier A-Z");
        }

    }else {  sa.stop();}
}
//Tri Z-A nom materiel
void Menu::on_radioButton_5_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_materiel->setModel(tmpmat.afficher_nomDecroissant());//refresh

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.trieDecroissantena();
            ui->label_22->setText("Sort by Z-A");
        }
        else
        {
            sa.languageSelectedfr();
            sa.trieDecroissantfra();
            ui->label_22->setText("Trier Z-A");
        }

    }else {  sa.stop();}
}
//Tri Croissant du Prix materiel
void Menu::on_radioButton_7_clicked()
{

    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_materiel->setModel(tmpmat.afficher_PrixCroissant());//refresh

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.Croissantprixen();
            ui->label_22->setText("Sort Ascending of Price");
        }
        else
        {
            sa.languageSelectedfr();
            sa.Croissantprixfr();
            ui->label_22->setText("Tri Croissant du Prix");
        }
    }else {  sa.stop();}

}
//Tri Décroissant du Prix materiel
void Menu::on_radioButton_11_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_materiel->setModel(tmpmat.afficher_PrixDecroissant());//refresh

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.Decroissantprixen();
            ui->label_22->setText("Sort Descending  of Price");
        }
        else
        {
            sa.languageSelectedfr();
            sa.Decroissantprixfr();
            ui->label_22->setText("Tri Décroissant du Prix");
        }

    }else {  sa.stop();}
}
//Tri Croissant du Stock materiel
void Menu::on_radioButton_6_clicked()
{


    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_materiel->setModel(tmpmat.afficher_StockCroissant());//refresh

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.Croissantstocken();
            ui->label_22->setText("Sort Ascending of Stock");
        }
        else
        {
            sa.languageSelectedfr();
            sa.Croissantstockfr();
            ui->label_22->setText("Tri Croissant du Stock");
        }

    }else {  sa.stop();}
}
//Tri Décroissant du Stock materiel
void Menu::on_radioButton_8_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_materiel->setModel(tmpmat.afficher_StockDecroissant());//refresh

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.Decroissantstocken();
            ui->label_22->setText("Sort Descending of Stock");
        }
        else
        {
            sa.languageSelectedfr();
            sa.Decroissantstockfr();
            ui->label_22->setText("Tri Décroissant du Stock");
        }

    }else {  sa.stop();}

}
//Trie Croissant d'IdMatériel
void Menu::on_radioButton_10_clicked()
{

    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_materiel->setModel(tmpmat.afficher_idCroissant());//refresh

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.Croissantmen();
            ui->label_22->setText("Sort  Ascending of IdMaterial");
        }
        else
        {
            sa.languageSelectedfr();
            sa.Croissantmfr();
            ui->label_22->setText("Tri Croissant d'IdMatériel");
        }

    }else {  sa.stop();}
}
//Tri Décroissant d'IdMatériel
void Menu::on_radioButton_12_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_materiel->setModel(tmpmat.afficher_idDecroissant());//refresh

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.Decroissantemen();
            ui->label_22->setText("Sort  Descending of IdMaterial");
        }
        else
        {
            sa.languageSelectedfr();
            sa.Decroissantemfr();
            ui->label_22->setText("Tri Décroissant d'IdMatériel");
        }

    }else {  sa.stop();}
}
//statistique Materiel
void Menu::on_pushButton_21_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}


    sm=new Statisqtique_materiel(this);

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.statiquematerielen();
            ui->label_22->setText("Material Statistics");
        }
        else
        {
            sa.languageSelectedfr();
            sa.statiquematerielfr();
            ui->label_22->setText("Statistique matériel");
        }
    }else {  sa.stop();}
    sm->show();
}
//CREATION Pdf materiel
int Menu::on_pushButton_13_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("A:\\integration\\integration final\\2\\mahrousplusplus\\Historique PDF\\Historique Materiel.pdf");//badel i chemin win t7eb t7ot il fichier ya2melek creation
    QPainter painter;

    if (! painter.begin(&printer)) { // failed to open file
        qWarning("failed to open file, is it writable?");
        //return 1;
    }

    QSqlQuery qry ;

    qry=tmpmat.selectdate();
    if (qry.exec())
    {

        QString S= QDate::currentDate().toString();
        painter.drawText(600,50, S);
        QPen penred(Qt::red);

        painter.setFont(QFont("Arial", 60));
        penred.setWidth(1);
        painter.setPen(penred);

        painter.drawText(200,500," La liste des ");
        painter.drawText(200,650,"  materiaux.");
        painter.setFont(QFont("Arial",30));
        painter.setPen(Qt::black);
        painter.drawText(50,100,"Bienvenu");
        painter.setPen(Qt::darkRed);
        painter.drawText(100,200,"Mahrous ++");
        painter.setPen(Qt::black);

    }

    QString id,nom,marque,prix ,stock , desc , idc , image ,idf;
    QSqlQuery   qrry ;
    int i =50;
    int k=0;

    painter.drawPixmap(600,50,100,100,QPixmap::fromImage(QImage("A:/photo/logo.png")));//chemin mta3 il logo
    painter.drawText(400,800, image);

    qrry=tmpmat.selectmateriel();


    if ( qrry.exec() )
    {

        while(qrry.next())
        {

            if ( k % 13 ==0)
            {   i=50;

                if (!printer.newPage())
                {

                    qWarning("failed");
                    return 1;
                }
                painter.setFont(QFont("Arial",10));
                QPen penblack(Qt::red);

                painter.setPen(penblack);
                painter.drawText (0,10,"idM");
                painter.drawText (40,10,"Nom");
                painter.drawText (90,10,"Marque");
                painter.drawText (150,10,"Prix");
                painter.drawText (200,10,"Stock");
                painter.drawText (260,10,"Desc");
                painter.drawText (310,10,"idC");
                painter.drawText (370,10,"URL");
                painter.drawText (590,10,"Photo");
                painter.drawText (650,10,"idF");
            }

            painter.setFont(QFont("Arial",10));
            QPen penblack(Qt::black);

            painter.setPen(penblack);
            int j=0;

            id = qrry.value(0).toString();
            painter.drawText(j*20,i, id);
            j++;

            nom=qrry.value(1).toString();
            painter.drawText(j*40,i, nom);
            j++;
            marque=qrry.value(2).toString();
            painter.drawText(j*50,i, marque);
            j++;
            prix=qrry.value(3).toString();
            painter.drawText(j*49,i, prix);
            j++;
            stock=qrry.value(4).toString();
            painter.drawText(j*51,i, stock);
            j++;
            desc=qrry.value(5).toString();
            painter.drawText(j*52,i, desc);
            j++;
            idc=qrry.value(6).toString();
            painter.drawText(j*53,i, idc);
            j++;
            image=qrry.value(7).toString();
            painter.drawText(j*54,i, image);

            QImage chemin(image);
            painter.drawPixmap(j*80,i,50,50,QPixmap::fromImage(QImage(chemin)));
            j++;
            idf=qrry.value(8).toString();
            painter.drawText(j*83,i, idf);

            i+=80;

            k++;

        }
    }


    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.creationpdfen();
            ui->label_22->setText("PDF creation");
        }
        else
        {
            sa.languageSelectedfr();
            sa.creationpdffr();
            ui->label_22->setText("Création PDF");
        }

    }else {  sa.stop();}
    painter.end();
}
//CAPTURE IMAGE materiel
void Menu::on_pushButton_19_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    c=new capture(this);

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.captureimageen();
            ui->label_22->setText("Capture picture");
        }
        else
        {
            sa.languageSelectedfr();
            sa.captureimagefr();
            ui->label_22->setText("Capture image");
        }

    }else {  sa.stop();}
    c->show();
}
//TABLE CLICKED materiel
void Menu::on_afficher_materiel_activated(const QModelIndex &index)
{

    QString val=ui->afficher_materiel->model()->data(index).toString();
    QSqlQuery qry ;

    qry=tmpmat.tableclicked(val);
    if (qry.exec())
    {
        while (qry.next())
        {

            ui->cx_idm->setDisabled(1);
            ui->cx_idm->setText(qry.value(0).toString());
            ui->cx_nomM->setText(qry.value(1).toString());
            ui->cx_marque->setText(qry.value(2).toString());
            ui->prix->setValue(qry.value(3).toInt());
            ui->stock->setValue(qry.value(4).toInt());
            ui->cx_desc->setText(qry.value(5).toString());
            ui->comboBox_categorie->setCurrentText(qry.value(6).toString());
            ui->chemin->setText(qry.value(7).toString());
            QPixmap pix(ui->chemin->text());
            int w =ui->photo->width();
            int h =ui->photo->height();
            ui->photo->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            ui->comboBox_idf->setCurrentText(qry.value(8).toString());

            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();
                    sa.clickedmen();
                    ui->label_22->setText("Selected Material");
                }
                else
                {
                    sa.languageSelectedfr();
                    sa.clickedmfr();
                    ui->label_22->setText("Matériel Sélectionée");
                }

            }else {  sa.stop();}
        }
    }
}
//notification materiel
void Menu::on_pushButton_20_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_materiel_insu->show();
    ui->afficher_materiel_insu->setModel(tmpmat.afficher_IMlist());

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.affichematerielinsuffisanten();
            ui->label_22->setText("Liste of material insuffisant");
        }
        else
        {
            sa.languageSelectedfr();
            sa.affichematerielinsuffisantfr();
            ui->label_22->setText("La liste des matériel insuffisant");
        }

    }else {  sa.stop();}
    ui->pushButton_26->show();
}
// X notificaation materiel
void Menu::on_pushButton_26_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_materiel_insu->hide();
    ui->pushButton_26->hide();
}
//afficher materiel
void Menu::on_pushButton_18_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}

    if(speek==1)
    {
        if (lng=="en")
        { sa.languageSelecteden();
            sa.affichermen();
            ui->label_22->setText("Show Material");}
        else
        {sa.languageSelectedfr();
            sa.affichermfr();
            ui->label_22->setText("Afficher materiaaux");
        }

    }else {  sa.stop();}

    ui->afficher_materiel->setModel(tmpmat.afficher_materiel());
}
//affectation
//ajouter affectation
void Menu::on_pushButton_8_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    if(securite==0)
    {
        QString IDAFFECTATION,CIN,IDMATERIEL;
        IDAFFECTATION=ui->cx_id_affectation->text();
        CIN=ui->comboBox_cin->currentText();
        IDMATERIEL=ui->comboBox_materiel->currentText();
        QString NOMMATERIEL,MARQUEMATERIEL,DESCMATERIEL,IDCATEGORIE,IMAGE,IDFOURNISSUER;
        int PRIXMATERIEL,STOCKMATERIEL;
        gestion_affectation A(IDAFFECTATION,CIN,IDMATERIEL);
        gestion_materiel M(IDMATERIEL,NOMMATERIEL,MARQUEMATERIEL,PRIXMATERIEL,STOCKMATERIEL,DESCMATERIEL,IDCATEGORIE,IMAGE,IDFOURNISSUER);
        bool test=A.ajouter_Affectation();
        if(test)
        {
            tmpaff.Modifier_Stock(M);
            QFile file("A:\\integration\\integration final\\2\\mahrousplusplus\\Historique\\HistoriqueAffectation.txt");
            if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
                return;
            QTextStream cout(&file);
            QString message2="\nAffectation a été ajoutée sous :\n idA:"+IDAFFECTATION+" \n CIN:"+CIN+" \n idM:"+IDMATERIEL ;
            cout << message2;

            initaf();
            ui->afficher_affectation->setModel(tmpaff.afficher_Affectation());

            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();
                    sa.ajouteraen();
                    ui->label_8->setText("Add Assignment");
                }
                else
                {
                    sa.languageSelectedfr();
                    sa.ajouterafr();
                    ui->label_8->setText("Ajouter Affectation ");
                }

            }else {  sa.stop();}

        }
        else
        {

            QMessageBox msgBox;
            QPixmap pix("A:/LOGO.png");
            msgBox.setText("Affectation existe deja  !.\n"
                           "Click Cancel to exit.");
            msgBox.setIconPixmap(pix);
            msgBox.exec();
        }
    }
    else {
        QMessageBox msgBox;
        QPixmap pix("A:/integration/integration final/danger.png");

        msgBox.setText("Il faut ouvrir cadenas .");
        msgBox.setIconPixmap(pix);
        msgBox.exec();
    }
}
//afficher affectation
void Menu::on_pushButton_2_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_affectation->setModel(tmpaff.afficher_Affectation());

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.afficheraen();
            ui->label_8->setText("Show Assignment");
        }
        else
        {
            sa.languageSelectedfr();
            sa.afficherafr();
            ui->label_8->setText("Afficher Affectation ");
        }

    }else {  sa.stop();}

    initaf();
}
//tableau cliced
void Menu::on_afficher_affectation_activated(const QModelIndex &index)
{
    QString val=ui->afficher_affectation->model()->data(index).toString();
    QSqlQuery qry ;
    qry=tmpaff.tableclicked(val);
    if (qry.exec())
    {
        while (qry.next())
        {

            ui->cx_id_affectation->setDisabled(1);
            ui->cx_id_affectation->setText(qry.value(0).toString());
            ui->comboBox_cin->setCurrentText(qry.value(1).toString());
            ui->comboBox_materiel->setCurrentText(qry.value(2).toString());

            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();
                    sa.clickedena();
                    ui->label_8->setText("Selected Assignment");
                }
                else
                {
                    sa.languageSelectedfr();
                    sa.clickedfra();
                    ui->label_8->setText("Affectation Sélectionnée");
                }

            }else {  sa.stop();}
        }
    }
}
//suprimer affectation
void Menu::on_pushButton_3_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    if (securite==0)
    {
        QString idA = ui->cx_id_affectation->text();

        bool test=tmpaff.supprimer_Affectation(idA);
        if(test)
        {    ui->afficher_affectation->setModel(tmpaff.afficher_Affectation());

            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();
                    sa.supprimeraen();
                    ui->label_8->setText("Remove Assignment");
                }
                else
                {
                    sa.languageSelectedfr();
                    sa.supprimerafr();
                    ui->label_8->setText("Supprimer Affectation");
                }
            }else {  sa.stop();}
            ui->cx_id_affectation->setEnabled(1);

            initaf();

        }
        else
        {

            QMessageBox msgBox;
            QPixmap pix("A:/LOGO.png");
            msgBox.setText("verifier l'id  !.\n"
                           "Click Cancel to exit.");
            msgBox.setIconPixmap(pix);
            msgBox.exec();
        }
    }
    else {
        QMessageBox msgBox;
        QPixmap pix("A:/integration/integration final/danger.png");

        msgBox.setText("Il faut ouvrir cadenas .");
        msgBox.setIconPixmap(pix);
        msgBox.exec();
    }
}
//modifier Affectation
void Menu::on_pushButton_4_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    if (securite ==0)
    {

        QString IDAFFECTATION = ui->cx_id_affectation->text();
        QString CIN = ui->comboBox_cin->currentText();
        QString  IDMATERIEL = ui->comboBox_materiel->currentText();

        gestion_affectation A(IDAFFECTATION,CIN,IDMATERIEL);
        bool test=tmpaff.modifier_Affectation(A);
        if(test)
        {

            ui->afficher_affectation->setModel(tmpaff.afficher_Affectation());

            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();
                    sa.modifieraen();
                    ui->label_8->setText("Edit Assignment");
                }
                else
                {
                    sa.languageSelectedfr();
                    sa.modifierafr();
                    ui->label_8->setText("Modifier Affectation");
                }
            }else {  sa.stop();}
            initaf();
        }
        else
        {

            QMessageBox msgBox;
            QPixmap pix("A:/LOGO.png");
            msgBox.setText("Matériel non valide  !.\n"
                           "Click Cancel to exit.");
            msgBox.setIconPixmap(pix);
            msgBox.exec();
        }
    }
    else {
        QMessageBox msgBox;
        QPixmap pix("A:/integration/integration final/danger.png");

        msgBox.setText("Il faut ouvrir cadenas .");
        msgBox.setIconPixmap(pix);
        msgBox.exec();
    }
}
//trier selon id Affectation  croissant
void Menu::on_radioButton_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_affectation->setModel(tmpaff.afficher_idCroissant());

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.trieCroissantenaff();
            ui->label_8->setText("Sort Ascending by idA");
        }
        else
        {
            sa.languageSelectedfr();
            sa.trieCroissantfraff();
            ui->label_8->setText("Tri Croissant par idA ");
        }

    }else {  sa.stop();}
}
//trier selon id Affectation decroissant
void Menu::on_radioButton_3_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_affectation->setModel(tmpaff.afficher_idDecroissant());

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.trieDecroissantenaff();
            ui->label_8->setText("Sort Descending by idA");
        }
        else
        {
            sa.languageSelectedfr();
            sa.trieDecroissantfraff();
            ui->label_8->setText("Tri Décroissant par idA ");
        }

    }else {  sa.stop();}
}
//trier selon id materiel croissant affectation
void Menu::on_radioButton_2_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_affectation->setModel(tmpaff.afficher_idMaterielCroissant());

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.trieCroissantenm();
            ui->label_8->setText("Sort Ascending by idM");
        }
        else
        {
            sa.languageSelectedfr();
            sa.trieCroissantfrm();
            ui->label_8->setText("Tri Croissant par idM ");
        }
    }else {  sa.stop();}

}
//trier selon id materiel decroissant affectations
void Menu::on_radioButton_4_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_affectation->setModel(tmpaff.afficher_idMaterielDecroissant());

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.trieDecroissantenm();
            ui->label_8->setText("Sort Descending by idM");
        }
        else
        {
            sa.languageSelectedfr();
            sa.trieDecroissantfrm();
            ui->label_8->setText("Tri Décroissant par idM ");
        }

    }else {  sa.stop();}
}
//recherche affectation
void Menu::on_Recherche_textChanged(const QString &arg1)
{
    QString q = arg1;

    if (q=="")
    {
        ui->afficher_affectation->setModel(tmpaff.afficher_Affectation()) ;

    }
    else {
        ui->afficher_affectation->setModel(tmpaff.rechercher(q)) ;

        if(speek==1)
        {
            if (lng=="en")
            {
                ui->label_22->setText("Research");
            }
            else
            {
                ui->label_22->setText("Recherche");
            }
        }
    }
}
//fournisseur
//ajouter fournissuer
void Menu::on_pushButton_41_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    if (securite==0)
    {
        QString IDFOURNISSEUR = ui->cx_idf->text();
        QString NOMFOURNISSEUR = ui->cx_nomf->text();
        QString PRENOMFOURNISSEUR = ui->cx_prenomf->text();
        int NUMTEL = ui->cx_tel->text().toInt();
        QString SEXE;
        int AGE= ui->age->text().toInt();
        if (ui->femme->isChecked())
        { SEXE="femme";}
        if (ui->homme->isChecked())
        {SEXE="homme";}
        QString MAIL = ui->cx_mailf->text();
        gestion_fournisseur_materiaux f(IDFOURNISSEUR,NOMFOURNISSEUR,PRENOMFOURNISSEUR,NUMTEL,AGE,SEXE, MAIL);
        bool test=f.ajouter_fournisseur();
        if(test)
        {
            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();
                    sa.ajouterfen(NOMFOURNISSEUR);
                    ui->label_31->setText("Add supplier");
                }
                else
                {
                    sa.languageSelectedfr();
                    sa.ajouterffr(NOMFOURNISSEUR);
                    ui->label_31->setText("Ajouter Fournisseur");
                }

            }else {  sa.stop();}
            QFile file("A:\\integration\\integration final\\2\\mahrousplusplus\\Historique\\HistoriqueFourniseur.txt");
            if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
                return;
            QTextStream cout(&file);
            QString res1= QString::number(AGE);
            QString res2= QString::number(NUMTEL);
            QString message2="\nFournisseur a été ajoutée sous :\nIdF :"+IDFOURNISSEUR+"\nnomF:"+NOMFOURNISSEUR+"\nprenomF: "+PRENOMFOURNISSEUR+"\nNumTel: "+res2+"\nage: "+res1+"\nsexe:"+SEXE+"\nmail:"+MAIL+ "";
            cout << message2;
            ui->afficher_fournisseur->setModel(tmpf.afficher_fournisseur());//refresh
            initf();
        }
        else{

            QMessageBox msgBox;
            QPixmap pix("A:/LOGO.png");

            msgBox.setText("Fournisseur existe deja  !.\n"
                           "Click Cancel to exit.");
            msgBox.setIconPixmap(pix);
            msgBox.exec();

        }
    }
    else
    {
        QMessageBox msgBox;
        QPixmap pix("A:/integration/integration final/danger.png");

        msgBox.setText("Il faut ouvrir cadenas .");
        msgBox.setIconPixmap(pix);
        msgBox.exec();
    }
}
//supprimer fournissuer
void Menu::on_pushButton_37_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    if (securite==0)
    {
        QString idf = ui->cx_idf->text();
        QString NOMF=ui->cx_nomf->text();
        bool test=tmpf.supprimer_fournisseur(idf);
        if(test)
        {
            ui->afficher_fournisseur->setModel(tmpf.afficher_fournisseur());//refresh
            ui->listView->setModel(tmpf.afficher_Listemail());
            ui->listView2->setModel(tmpf.afficher_Listtel());

            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();
                    sa.supprimerfen(NOMF);
                    ui->label_31->setText("Remove supplier");
                }
                else
                {
                    sa.languageSelectedfr();
                    sa.supprimerffr(NOMF);
                    ui->label_31->setText("Supprimer Fournisseur");
                }

            }else {  sa.stop();}
            initf();
        }
        else
        {
            QMessageBox msgBox;
            QPixmap pix("A:/LOGO.png");

            msgBox.setText("verifier le cin  !.\n"
                           "Click Cancel to exit.");
            msgBox.setIconPixmap(pix);
            msgBox.exec();
        }
    }
    else
    {
        QMessageBox msgBox;
        QPixmap pix("A:/integration/integration final/danger.png");

        msgBox.setText("Il faut ouvrir cadenas .");
        msgBox.setIconPixmap(pix);
        msgBox.exec();
    }
}
//afficher fournissuer
void Menu::on_pushButton_33_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_fournisseur->setModel(tmpf.afficher_fournisseur());//refresh
    ui->listView->setModel(tmpf.afficher_Listemail());
    ui->listView2->setModel(tmpf.afficher_Listtel());

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.afficherfen();
            ui->label_31->setText("Show supplier");
        }
        else
        {
            sa.languageSelectedfr();
            sa.afficherffr();
            ui->label_31->setText("Afficher Fournisseur");
        }

    }else {  sa.stop();}
    initf();
}
//modif fournissuer
void Menu::on_pushButton_34_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    if (securite==0)
    {
        QString IDFOURNISSEUR = ui->cx_idf->text();
        QString NOMFOURNISSEUR = ui->cx_nomf->text();
        QString PRENOMFOURNISSEUR = ui->cx_prenomf->text();
        int NUMTEL = ui->cx_tel->text().toInt();
        int AGE= ui->age->text().toInt();
        QString SEXE;
        if (ui->femme->isChecked())
        {SEXE="femme";}
        if (ui->homme->isChecked())
        {SEXE="homme";}
        QString MAIL = ui->cx_mailf->text();
        gestion_fournisseur_materiaux F(IDFOURNISSEUR,NOMFOURNISSEUR,PRENOMFOURNISSEUR,NUMTEL,AGE,SEXE, MAIL);
        bool test=tmpf.modifier_fournisseur(F);
        if(test)
        {
            ui->afficher_fournisseur->setModel(tmpf.afficher_fournisseur());//refresh
            ui->listView->setModel(tmpf.afficher_Listemail());
            ui->listView2->setModel(tmpf.afficher_Listtel());

            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();
                    sa.modifierfen();
                    ui->label_31->setText("Edit supplier");
                }
                else
                {
                    sa.languageSelectedfr();
                    sa.modifierffr();
                    ui->label_31->setText("Modifier Fournisseur");
                }

            }else {  sa.stop();}
            initf();
        }
        else
        {

            QMessageBox msgBox;
            QPixmap pix("A:/LOGO.png");

            msgBox.setText("Fournisseur non valide  !.\n"
                           "Click Cancel to exit.");
            msgBox.setIconPixmap(pix);
            msgBox.exec();
        }
    }
    else
    {
        QMessageBox msgBox;
        QPixmap pix("A:/integration/integration final/danger.png");

        msgBox.setText("Il faut ouvrir cadenas .");
        msgBox.setIconPixmap(pix);
        msgBox.exec();
    }
}
//Trier Croissant d'IdFournisseur
void Menu::on_radioButton_14_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_fournisseur->setModel(tmpf.afficher_idCroissant());//refresh

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.trieCroissantenf();
            ui->label_31->setText("Sort Ascending by IdSupplier");
        }
        else
        {
            sa.languageSelectedfr();
            sa.trieCroissantfrf();
            ui->label_31->setText("Trier Croissant d'IdFournisseur");
        }

    }else {  sa.stop();}
}
//Trier Decroissant d'IdFournisseur
void Menu::on_radioButton_15_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_fournisseur->setModel(tmpf.afficher_idDecroissant());//refresh

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.Decroissantenf();
            ui->label_31->setText("Sort Descending by IdSupplier");
        }
        else
        {
            sa.languageSelectedfr();
            sa.Decroissantfrf();
            ui->label_31->setText("Trier Decroissant d'IdFournisseur");
        }

    }else {  sa.stop();}
}
//Trier Croissant d'Age Fournisseur
void Menu::on_radioButton_16_clicked()
{


    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_fournisseur->setModel(tmpf.afficher_AgeCroissant());//refresh

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.Coissantageen();
            ui->label_31->setText("Sort Ascending  by Age");
        }
        else
        {
            sa.languageSelectedfr();
            sa.Coissantagefr();
            ui->label_31->setText("Trier Croissant d'Age ");
        }

    }else {  sa.stop();}

}
//Trier Decroissant d'Age Fournisseur
void Menu::on_radioButton_18_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_fournisseur->setModel(tmpf.afficher_AgeDecroissant());//refresh

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.Decroissantageen();
            ui->label_31->setText("Sort Descending  by Age");
        }
        else
        {
            sa.languageSelectedfr();
            sa.Decroissantagefr();
            ui->label_31->setText("Trier Decroissant d'Age ");
        }

    }else {  sa.stop();}
}
//Trier A-Z du Nom Fournisseur
void Menu::on_radioButton_13_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_fournisseur->setModel(tmpf.afficher_NomCroissant());//refresh

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.trieCroissantena();
            ui->label_31->setText("Sort A-Z by name");
        }
        else
        {
            sa.languageSelectedfr();
            sa.trieCroissantfra();
            ui->label_31->setText("Trier A-Z du Nom");
        }

    }else {  sa.stop();}
}
//Trier Z-A du Nom Fournisseur
void Menu::on_radioButton_17_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_fournisseur->setModel(tmpf.afficher_NomDecroissant());//refresh


    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.trieDecroissantena();
            ui->label_31->setText("Sort Z-A by name");
        }
        else
        {
            sa.languageSelectedfr();
            sa.trieDecroissantfra();
            ui->label_31->setText("Trier Z-A du Nom");
        }

    }else {  sa.stop();}
}
//Recherche Fournisseur
void Menu::on_pushButton_30_clicked()
{
    QString q = ui->cx_recherche->text();

    if (q=="")
    {
        ui->afficher_fournisseur->setModel(tmpf.afficher_fournisseur()) ;

    }

    else {
        ui->afficher_fournisseur->setModel(tmpf.rechercher(q)) ;

        if(speek==1)
        {
            if (lng=="en")
            {
                ui->label_31->setText("Search");
            }
            else
            {
                ui->label_31->setText("Chercher");
            }

        }else {  sa.stop();}
    }
}
//Statistique fournissuer
void Menu::on_pushButton_42_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    f=new Statistique_fournisseur(this);
    f->show();

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.statistiqueFen();
            ui->label_31->setText("Supplier Statistics");
        }
        else
        {
            sa.languageSelectedfr();
            sa.statistiqueFfr();
            ui->label_31->setText("Statistique Fournisseur ");
        }


    }else {  sa.stop();}
}
//table clicked Fournisseur
void Menu::on_afficher_fournisseur_activated(const QModelIndex &index)
{
    QString val=ui->afficher_fournisseur->model()->data(index).toString();
    QSqlQuery qry ;

    qry =tmpf.tableclicked(val);
    if (qry.exec())
    {
        while (qry.next())
        {

            ui->cx_idf->setDisabled(1);
            ui->cx_idf->setText(qry.value(0).toString());
            ui->cx_nomf->setText(qry.value(1).toString());
            ui->cx_prenomf->setText(qry.value(2).toString());
            ui->cx_tel->setText(qry.value(3).toString());

            ui->age->setValue(qry.value(4).toInt());
            if (qry.value(5).toString()=="femme")
            {ui->femme->setChecked(true); }
            if (qry.value(5).toString()=="homme")
            {ui->homme->setChecked(true);}
            ui->cx_mailf->setText(qry.value(6).toString());
            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();
                    sa.clickedenf();
                    ui->label_31->setText("Selected supplier");
                }
                else
                {
                    sa.languageSelectedfr();
                    sa.clickedfrf();
                    ui->label_31->setText("Fournisseur Sélectionnée");
                }

            }else {  sa.stop();}
        }
    }
}
//Afficher fournisseur
void Menu::on_pushButton_35_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->listView->show();
    ui->pushButton_38->show();

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.afficherfen();
            ui->label_31->setText("Show Supplier ");
        }
        else
        {
            sa.languageSelectedfr();
            sa.afficherffr();
            ui->label_31->setText("Afficher Fournisseur ");
        }

    }else {  sa.stop();}
    ui->listView->setModel(tmpf.afficher_Listemail());

}
//double click mail fournisseur
void Menu::on_listView_activated(const QModelIndex &index)
{

    QString val = ui->listView->model()->data(index).toString();
    QSqlQuery qry ;

    qry =tmpf.listemailclicked(val);
    if (qry.exec())
    {
        while (qry.next())
        {

            ui->cx_idf->setDisabled(1);
            ui->cx_idf->setText(qry.value(0).toString());
            ui->cx_nomf->setText(qry.value(1).toString());
            ui->cx_prenomf->setText(qry.value(2).toString());
            ui->cx_tel->setText(qry.value(3).toString());

            ui->age->setValue(qry.value(4).toInt());
            if (qry.value(5).toString()=="femme")
            {
                ui->femme->setChecked(true);

            }
            if (qry.value(5).toString()=="homme")
            {
                ui->homme->setChecked(true);
            }

            ui->cx_mailf->setText(qry.value(6).toString());
        }

        if(speek==1)
        {
            if (lng=="en")
            {
                sa.languageSelecteden();
                sa.clickedmailen();
                ui->label_31->setText("Mail Selected  ");
            }
            else
            {
                sa.languageSelectedfr();
                sa.clickedmailfr();
                ui->label_31->setText("Mail Selectionnée");
            }

        }else {  sa.stop();}
    }
}
//X liste mail
void Menu::on_pushButton_38_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->listView->hide();
    //ui->listView2->hide();
    ui->pushButton_38->hide();
    initf();
}
//afficher tel liste fournisseur
void Menu::on_pushButton_43_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->listView2->show();
    ui->pushButton_40->show();

    ui->listView2->setModel(tmpf.afficher_Listtel());

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.phoneaffen();
            ui->label_31->setText("Show Phone Number Supplier ");
        }
        else
        {
            sa.languageSelectedfr();
            sa.phoneafffr();
            ui->label_31->setText("Lister les num tel des fournisseur");
        }

    }else {  sa.stop();}

}
//double click tel
void Menu::on_listView2_activated(const QModelIndex &index)
{
    QString val = ui->listView2->model()->data(index).toString();
    QSqlQuery qry ;
    qry =tmpf.listtelclicked(val);
    if (qry.exec())
    {
        while (qry.next())
        {

            ui->cx_idf->setDisabled(1);
            ui->cx_idf->setText(qry.value(0).toString());
            ui->cx_nomf->setText(qry.value(1).toString());
            ui->cx_prenomf->setText(qry.value(2).toString());
            ui->cx_tel->setText(qry.value(3).toString());

            ui->age->setValue(qry.value(4).toInt());
            if (qry.value(5).toString()=="femme")
            {ui->femme->setChecked(true);}
            if (qry.value(5).toString()=="homme")
            {ui->homme->setChecked(true);}
            ui->cx_mailf->setText(qry.value(6).toString());
            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();
                    sa.clickedtelen();
                    ui->label_31->setText("Phone number Selected  ");
                }
                else
                {
                    sa.languageSelectedfr();
                    sa.clickedtelfr();
                    ui->label_31->setText("Numéro de télèphone Selectionnée");
                }

            }else {  sa.stop();}
        }
    }
}
//X liste tel
void Menu::on_pushButton_40_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->listView2->hide();
    ui->pushButton_40->hide();
    initf();
}
//recherche fournissuer
void Menu::on_cx_recherche_textChanged(const QString &arg1)
{
    QString q = arg1;

    if (q=="")
    {ui->afficher_fournisseur->setModel(tmpf.afficher_fournisseur()) ;}
    else { ui->afficher_fournisseur->setModel(tmpf.rechercher(q)) ;
        if(speek==1)
        {
            if (lng=="en")
            { ui->label_22->setText("Research");}
            else
            {ui->label_22->setText("Recherche");}
        }else {  sa.stop();}
    }
}
//fournissuer vers menu
void Menu::on_pushButton_45_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->stackedWidget->setCurrentIndex(0);
}
//categorie materiel vers menu
void Menu::on_pushButton_46_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->stackedWidget->setCurrentIndex(0);
}
//affectation vers menu
void Menu::on_pushButton_47_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->stackedWidget->setCurrentIndex(0);
}
//materiel vers menu
void Menu::on_pushButton_48_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->stackedWidget->setCurrentIndex(0);
}
//bouton affectation
void Menu::on_pushButton_12_clicked()
{
    if(cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->stackedWidget->setCurrentIndex(2);

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.affectationen();
        }
        else {
            sa.languageSelectedfr();
            sa.affectationfr();
        }

    }else {  sa.stop();}
}
//bouton photo categorie materiel
void Menu::on_pushButton_16_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->stackedWidget->setCurrentIndex(1);

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.categoriematerielen();
        }
        else {
            sa.languageSelectedfr();
            sa.categoriematerielfr();
        }

    }else {  sa.stop();}
}
//bouton photo historique
void Menu::on_pushButton_29_clicked()
{

    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    h = new Historique (this);
    h->show();

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.historiqueen();
        }
        else {
            sa.languageSelectedfr();
            sa.historiquefr();
        }

    }else {  sa.stop();}
}
//bouton photo affectation
void Menu::on_pushButton_17_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->stackedWidget->setCurrentIndex(2);

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.affectationen();
        }
        else {
            sa.languageSelectedfr();
            sa.affectationfr();
        }

    }else {  sa.stop();}
}
//bouton photo materiel
void Menu::on_pushButton_15_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->stackedWidget->setCurrentIndex(3);

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.materielen();
        }
        else {
            sa.languageSelectedfr();
            sa.materielfr();
        }

    }else {  sa.stop();}
}
//categorie plante
//ajouter categorie plante
void Menu::on_pushButton_54_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    if (securite==0)
    {
        QString IDCATEGORIEPLANTE,NOMCATEGORIEPLANTE;
        IDCATEGORIEPLANTE=ui->cx_idcategorieplante->text();
        NOMCATEGORIEPLANTE=ui->cx_nomcategorieplante->text();
        gestion_categorie_plante C(IDCATEGORIEPLANTE,NOMCATEGORIEPLANTE);
        bool test=C.ajouter_Categorie();
        if(test)
        {

            QFile file("A:\\integration\\integration final\\2\\mahrousplusplus\\Historique\\HistoriqueEspecePlante.txt");
            if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
                return;
            QTextStream cout(&file);
            QString message2="\nCatégorie Plante a été ajoutée sous:\nidCP :"+IDCATEGORIEPLANTE+"\nnomCP : "+NOMCATEGORIEPLANTE+"";
            cout << message2;

            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();
                    sa.ajoutercategoriepalnteen();
                    ui->label_48->setText("Add Category plant.");
                }
                else {
                    sa.languageSelectedfr();
                    sa.ajoutercategoriepalntefr();
                    ui->label_48->setText("ajouter Catégorie Plante");
                }

            }else
            {  sa.stop();}
            initcp();
            ui->affiche_categorieplante->setModel(tmpcatp.afficher_Categorie());

        }
        else
        {


            QMessageBox msgBox;
            QPixmap pix("A:/LOGO.png");

            msgBox.setText("Catégorie existe deja  !.\n"
                           "Click Cancel to exit.");
            msgBox.setIconPixmap(pix);
            msgBox.exec();
        }
    }
    else {
        QMessageBox msgBox;
        QPixmap pix("A:/integration/integration final/danger.png");

        msgBox.setText("Il faut ouvrir cadenas .");
        msgBox.setIconPixmap(pix);
        msgBox.exec();
    }
}
//bouton categorie plante
void Menu::on_pushButton_39_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->stackedWidget->setCurrentIndex(5);

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.categorieplanteen();
        }
        else {
            sa.languageSelectedfr();
            sa.categorieplantefr();
        }

    }else {  sa.stop();}
}
//photo bouton categorie palnte
void Menu::on_pushButton_44_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->stackedWidget->setCurrentIndex(5);

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.categorieplanteen();
        }
        else {
            sa.languageSelectedfr();
            sa.categorieplantefr();
        }

    }else {  sa.stop();}
}
//afficher categorie plantes
void Menu::on_pushButton_53_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->affiche_categorieplante->setModel(tmpcatp.afficher_Categorie());

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.affichercategorieplanteen();
            ui->label_48->setText("Show category plant .");
        }
        else {
            sa.languageSelectedfr();
            sa.affichercategorieplantefr();
            ui->label_48->setText("Afficher la liste des catégorie plante .");
        }

    }else {  sa.stop();}
}
//bouton supprimer categorrie plante
void Menu::on_pushButton_51_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    if (securite==0)
    {
        QString idC = ui->cx_idcategorieplante->text();
        QString nomC =ui->cx_nomcategorieplante->text();
        bool test=tmpcatp.supprimer_Categorie(idC);
        if(test)
        {
            ui->affiche_categorieplante->setModel(tmpcatp.afficher_Categorie());
            initcp();
            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();
                    sa.supprimercategorieplanteen(ui->cx_nomcategorieplante->text());
                    ui->label_48->setText("Remove category plant .");
                }
                else {
                    sa.languageSelectedfr();
                    sa.supprimercategorieplantefr(ui->cx_nomcategorieplante->text());
                    ui->label_48->setText("Supprimer catégorie plante .");
                }

            }else {  sa.stop();}
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer Catégorie"),
                                  QObject::tr("verifier l'id  !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
       //bech tbadlou
    }
    else {
        QMessageBox msgBox;
        QPixmap pix("A:/integration/integration final/danger.png");

        msgBox.setText("Il faut ouvrir cadenas .");
        msgBox.setIconPixmap(pix);
        msgBox.exec();
    }
}
//click categorie plante
void Menu::on_affiche_categorieplante_activated(const QModelIndex &index)
{
    QString val=ui->affiche_categorieplante->model()->data(index).toString();
    QSqlQuery qry ;
    qry=tmpcatp.tableclicked(val);

    if (qry.exec())
    {
        while (qry.next())
        {

            ui->cx_idcategorieplante->setDisabled(1);
            ui->cx_idcategorieplante->setText(qry.value(0).toString());
            ui->cx_nomcategorieplante->setText(qry.value(1).toString());
            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();
                    sa.clickedencp();
                    ui->label_48->setText("Selected category plant");
                }
                else
                {
                    sa.languageSelectedfr();
                    sa.clickedfrcp();
                    ui->label_48->setText("Catégorie palnte Sélectionnée");
                }

            }else {  sa.stop();}
        }
    }
}
//bouton modifier
void Menu::on_pushButton_55_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    if (securite==0)
    {
        QString IDCATEGORIEPLANTE = ui->cx_idcategorieplante->text();
        QString NOMCATEGORIEPLANTE= ui->cx_nomcategorieplante->text();
        gestion_categorie_plante C(IDCATEGORIEPLANTE,NOMCATEGORIEPLANTE);
        bool test=tmpcatp.modifier_Categorie(C);
        if(test)
        {

            ui->affiche_categorieplante->setModel(tmpcatp.afficher_Categorie());//refresh

            ui->cx_idcategorieplante->setEnabled(1);
            initcp();

            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();
                    sa.modifiercategorieplanteen();
                    ui->label_48->setText("Edit  category plant .");
                }
                else {
                    sa.languageSelectedfr();
                    sa.modifiercategorieplantefr();
                    ui->label_48->setText("Modifier catégorie plante .");
                }

            }else {  sa.stop();}
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Modifier Catégorie"),
                                  QObject::tr("Catégorie non valide  !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
            //bech tbadlou
        }
    }
    else {  QMessageBox msgBox;
        QPixmap pix("A:/integration/integration final/danger.png");

        msgBox.setText("Il faut ouvrir cadenas .");
        msgBox.setIconPixmap(pix);
        msgBox.exec();
    }
}

//trie id croissant categorie plante
void Menu::on_radioButton_22_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->affiche_categorieplante->setModel(tmpcatp.afficher_idCroissant());//refresh

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.idCroissanten();
            ui->label_48->setText("Sort by id Category .");
        }
        else {
            sa.languageSelectedfr();
            sa.idCroissantfr();
            ui->label_48->setText("Trier Croissant du IdCatégorie .");
        }

    }else {  sa.stop();}
}
//trie id decroissant categorie plante
void Menu::on_radioButton_19_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->affiche_categorieplante->setModel(tmpcatp.afficher_idDecroissant());//refresh
    //ui->label_3->setText("Trier Décroissant du IdCatégorie");

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.idDecroissanten();
           // ui->label_3->setText("Sort descending by id Category .");
        }
        else {
            sa.languageSelectedfr();
            sa.idDecroissantfr();
            //ui->label_3->setText("Trie Decroissant du IdCatégorie .");
        }

    }else {  sa.stop();}
}
//trie nom croissant categorie plante
void Menu::on_radioButton_20_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->affiche_categorieplante->setModel(tmpcatp.afficher_nomCroissant());//refresh

    // ui->label_3->setText("Trier A-Z");

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.tricatCroissantena();
           // ui->label_3->setText("Sort A-Z .");
        }
        else {
            sa.languageSelectedfr();
            sa.tricatCroissantfra();
            //ui->label_3->setText("Trie A-Z .");
        }

    }else {  sa.stop();}
}
//trie nom decroissant categorie plante
void Menu::on_radioButton_21_clicked()
{

    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->affiche_categorieplante->setModel(tmpcatp.afficher_nomDecroissant());//refresh
    //ui->label_3->setText("Trier Z-A");

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.tricatdeCroissantena();
            //ui->label_3->setText("Sort Z-A .");
        }
        else {
            sa.languageSelectedfr();
            sa.tricatdeCroissantfra();
           // ui->label_3->setText("Trie Z-A .");
        }

    }else {  sa.stop();}
}
//recherche categorie plante
void Menu::on_lineEdit_recherchecategorieplante_textChanged(const QString &arg1)
{
    QString q = arg1;

    if (q=="")
    {
        ui->affiche_categorieplante->setModel(tmpcatp.afficher_Categorie()) ;

    }
    else {
        ui->affiche_categorieplante->setModel(tmpcatp.rechercher(q)) ;


        if(speek==1)
        {
            if (lng=="en")
            {
                //ui->label_5->setText("Research");
            }
            else
            {
               // ui->label_5->setText("Recherche");
            }

        }else {  sa.stop();}
    }
}
//categorie plante vers menu
void Menu::on_pushButton_56_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->stackedWidget->setCurrentIndex(0);
}
//plante
//plante vers menu
void Menu::on_pushButton_57_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->stackedWidget->setCurrentIndex(0);
}
//bouton plante
void Menu::on_pushButton_49_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->stackedWidget->setCurrentIndex(6);

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.planteen();
        }
        else {
            sa.languageSelectedfr();
            sa.plantefr();
        }

    }else {  sa.stop();}
}
//bouton photo categorie palnte
void Menu::on_pushButton_50_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->stackedWidget->setCurrentIndex(6);

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.planteen();
        }
        else {
            sa.languageSelectedfr();
            sa.plantefr();
        }

    }else {  sa.stop();}
}
//ajouter plante
void Menu::on_pushButton_67_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    if (securite==0)
    {
        QString IDPLANTE = ui->cx_idp->text();
        QString SECTEUR;
        if (ui->Button_1->isChecked())
        {SECTEUR="1";}
        if (ui->Button_2->isChecked())
        { SECTEUR="2";}
        if (ui->Button_3->isChecked())
        { SECTEUR="3";}
        if (ui->Button_4->isChecked())
        {SECTEUR="4";}

        int QUANTITE = ui->Quantite->text().toInt();
        QString ETAT;
        if (ui->Mauvaise->isChecked())
        {ETAT="Mauvaise";}
        if (ui->Bonne->isChecked())
        {ETAT="Bonne";}
        QString IDCATEGORIEPLANTE = ui->comboBox_categorie_2->currentText();
        QString CIN=ui->comboBox_cin_2->currentText();
        QString IMG =ui->chemin_2->text();//LABEL CHEMIN
        QString IDBP=ui->comboBox_IDBP->currentText();
        gestion_plante P(IDPLANTE,SECTEUR,QUANTITE,ETAT,IDCATEGORIEPLANTE,IMG,CIN,IDBP);
        bool test=P.ajouter_plante();
        if(test)
        {
            QFile file("A:\\integration\\integration final\\2\\mahrousplusplus\\Historique\\HistoriquePlante.txt");
            if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
                return;
            QTextStream cout(&file);
            QString message2="\nPlante a été ajoutée sous :\nidP:"+IDPLANTE+"\nSecteur: "+SECTEUR+"\nQuantite:  "+QUANTITE+"\nEtat: "+ETAT+"\nidCP :"+IDCATEGORIEPLANTE+"\n CheminPhoto: "+IMG+"\nCIN : "+CIN ;
            cout << message2;
            ui->afficher_plante->setModel(tmppl.afficher_plante());//refresh

            initp();

            if(speek==1)
            {
                if (lng=="en")
                {   sa.languageSelecteden();
                    sa.ajouterplanteen();
                    ui->label_57->setText("Add plant .");
                }
                else {
                    sa.languageSelectedfr();
                    sa.ajouterplantefr();
                    ui->label_57->setText("Ajouter plante .");
                }

            }else {  sa.stop();}

        }
        else{
            QMessageBox::critical(nullptr, QObject::tr("Ajouter Plante"),
                                  QObject::tr("Plante existe deja  !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

            //bech tbadlou
        }
    }
    else
    {
        QMessageBox msgBox;
        QPixmap pix("A:/integration/integration final/danger.png");

        msgBox.setText("Il faut ouvrir cadenas .");
        msgBox.setIconPixmap(pix);
        msgBox.exec();
    }
}
//ajouter photo
void Menu::on_pushButton_59_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    QString filename = QFileDialog::getOpenFileName(this,tr("choose"), "" , tr("image (*.png *.jpg *.jpeg *.bmp *.gif)"));
    if ( QString::compare(filename, QString()) != 0 )
    {
        QImage image;
        bool valid =image.load(filename);
        if (valid)
        {
            ui->chemin_2->setText(filename);
            image =image.scaledToWidth(ui->photo_2->width(),Qt::SmoothTransformation);
            ui->photo_2->setPixmap(QPixmap::fromImage(image));


            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();
                    sa.ajouterimageen();
                    ui->label_57->setText("Add picture .");
                }
                else {
                    sa.languageSelectedfr();
                    sa.ajouterimagefr();
                    ui->label_57->setText("Ajouter photo .");
                }

            }else {  sa.stop();}
        }

    }
}
//modifier image
void Menu::on_pushButton_64_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    QString filename = QFileDialog::getOpenFileName(this,tr("choose"), "" , tr("image (*.png *.jpg *.jpeg *.bmp *.gif)"));
    if ( QString::compare(filename, QString()) != 0 )
    {
        QImage image;
        bool valid =image.load(filename);
        if (valid)
        {
            ui->chemin_2->setText(filename);
            image =image.scaledToWidth(ui->photo_2->width(),Qt::SmoothTransformation);
            ui->photo_2->setPixmap(QPixmap::fromImage(image));


            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();
                    sa.modifierimageen();
                    ui->label_57->setText("Edit picture .");

                }
                else {
                    sa.languageSelectedfr();
                    sa.modifierimagefr();
                    ui->label_57->setText("Modifier photo.");
                }

            }else {  sa.stop();}
        }

    }
}
//table clicked plante
void Menu::on_afficher_plante_activated(const QModelIndex &index)
{
    QString val=ui->afficher_plante->model()->data(index).toString();
    QSqlQuery qry ;


    qry=tmppl.tableclicked(val);
    if (qry.exec())
    {
        while (qry.next())
        {

            ui->cx_idp->setDisabled(1);
            ui->cx_idp->setText(qry.value(0).toString());
            if (qry.value(1).toString()=="1")
            {ui->Button_1->setChecked(true);}
            if (qry.value(1).toString()=="2")
            {ui->Button_2->setChecked(true); }
            if (qry.value(1).toString()=="3")
            {ui->Button_3->setChecked(true);}
            if (qry.value(1).toString()=="4")
            {ui->Button_4->setChecked(true); }
            ui->Quantite->setValue(qry.value(3).toInt());
            if (qry.value(2).toString()=="Mauvaise")
            {ui->Mauvaise->setChecked(true);}
            if (qry.value(2).toString()=="Bonne")
            {ui->Bonne->setChecked(true);}
            ui->comboBox_categorie_2->setCurrentText(qry.value(4).toString());
            ui->chemin_2->setText(qry.value(5).toString());
            QPixmap pix(ui->chemin_2->text());
            int w =ui->photo_2->width();
            int h =ui->photo_2->height();
            ui->photo_2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            ui->comboBox_cin_2->setCurrentText(qry.value(6).toString());
            ui->comboBox_IDBP->setCurrentText(qry.value(7).toString());
            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();
                    sa.clickedenp();
                    ui->label_57->setText("Selected plant");
                }
                else
                {
                    sa.languageSelectedfr();
                    sa.clickedfrp();
                    ui->label_57->setText("Plante Sélectionnée");
                }

            }else {  sa.stop();}
        }
    }
}
//supprimer plante
void Menu::on_pushButton_63_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    if (securite==0)
    {
        QString idP = ui->cx_idp->text();
        bool test=tmppl.supprimer_plante(idP);
        if(test)
        {    ui->afficher_plante->setModel(tmppl.afficher_plante());//refresh


            initp();

            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();
                    sa.supprimerplanteen(ui->cx_idp->text());
                    ui->label_57->setText("Remove plant .");
                }
                else {
                    sa.languageSelectedfr();
                    sa.supprimerplantefr(ui->cx_idp->text());
                    ui->label_57->setText("Supprimer plante .");
                }

            }else {  sa.stop();}
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer Plante"),
                                  QObject::tr("verifier le id  !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
    //bech tbadlou
    }
    else
    {
        QMessageBox msgBox;
        QPixmap pix("A:/integration/integration final/danger.png");

        msgBox.setText("Il faut ouvrir cadenas .");
        msgBox.setIconPixmap(pix);
        msgBox.exec();
    }
}
//modifier plante
void Menu::on_pushButton_66_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    if (securite==0)
    {
        QString IDPLANTE = ui->cx_idp->text();
        QString SECTEUR;
        if (ui->Button_1->isChecked())
        {SECTEUR="1"; }
        if (ui->Button_2->isChecked())
        {SECTEUR="2";}
        if (ui->Button_3->isChecked())
        {SECTEUR="3";}
        if (ui->Button_4->isChecked())
        {SECTEUR="4";}
        int QUANTITE = ui->Quantite->text().toInt();
        QString ETAT;
        if (ui->Mauvaise->isChecked())
        {ETAT="Mauvaise";}
        if (ui->Bonne->isChecked())
        {ETAT="Bonne";}
        QString CIN = ui->comboBox_cin_2->currentText();
        QString IDCATEGORIEPLANTE = ui->comboBox_categorie_2->currentText();
        QString IMG= ui->chemin_2->text();//LABEL CHEMIN
        QString IDBP= ui->comboBox_IDBP->currentText();


        gestion_plante P(IDPLANTE,SECTEUR,QUANTITE,ETAT,IDCATEGORIEPLANTE,IMG,CIN,IDBP);
        bool test=tmppl.modifier_plante(P);
        if(test)
        {

            ui->afficher_plante->setModel(tmppl.afficher_plante());//refresh
            initp();

            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();
                    sa.modifierplanteen();
                    ui->label_57->setText("Edit plant .");
                }
                else {
                    sa.languageSelectedfr();
                    sa.modifierplantefr();
                    ui->label_57->setText("Modifier plante .");
                }

            }else {  sa.stop();}
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Modifier plante"),
                                  QObject::tr("plante non valide  !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        //bech tbadlou
        }
    }
    else
    {
        QMessageBox msgBox;
        QPixmap pix("A:/integration/integration final/danger.png");

        msgBox.setText("Il faut ouvrir cadenas .");
        msgBox.setIconPixmap(pix);
        msgBox.exec();
    }
}
//afficher plante
void Menu::on_pushButton_60_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_plante->setModel(tmppl.afficher_plante());//refresh

    initp();

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.afficherplanteen();
            ui->label_57->setText("Show list of plants .");
        }
        else {
            sa.languageSelectedfr();
            sa.afficherplantefr();
            ui->label_57->setText("Afficher la liste des plantes .");
        }

    }else {  sa.stop();}

}
//afficher image
void Menu::on_pushButton_61_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    photo p;
    p.setchemin(ui->chemin_2->text());
    p.exec();
    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.afficherimageen();
            ui->label_57->setText("Show picture");
        }
        else
        {
            sa.languageSelectedfr();
            sa.afficherimagefr();
            ui->label_57->setText("Afficher image");
        }

    }else {  sa.stop();}
}
//trie id croissant plante
void Menu::on_radioButton_27_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_plante->setModel(tmppl.afficher_idCroissant());//refresh

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.idpCroissanten();
            ui->label_57->setText("Sort by id Plant .");
        }
        else {
            sa.languageSelectedfr();
            sa.idpCroissantfr();
            ui->label_57->setText("Trier Croissant du IdPlante .");
        }

    }else {  sa.stop();}
}
//trie id decroissant plante
void Menu::on_radioButton_26_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_plante->setModel(tmppl.afficher_idDecroissant());//refresh

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.idpdeCroissanten();
            ui->label_57->setText("Sort descending by id Plant .");
        }
        else {
            sa.languageSelectedfr();
            sa.idpdeCroissantfr();
            ui->label_57->setText("Trier decroissant du id Plante .");
        }

    }else {  sa.stop();}

}
//trie secteur decroissant
void Menu::on_radioButton_28_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_plante->setModel(tmppl.afficher_SecteurDecroissant());//refresh


    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.tripdeCroissantena();
            ui->label_57->setText("Sort Z-A .");
        }
        else {
            sa.languageSelectedfr();
            sa.tripdeCroissantfra();
            ui->label_8->setText("Tri Z-A .");
        }

    }else {  sa.stop();}
}
//trie secteur croissant
void Menu::on_radioButton_24_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_plante->setModel(tmppl.afficher_SecteurCroissant());//refresh


    if(speek==1)
    {
        if (lng=="en")
        { sa.languageSelecteden();
            sa.tripCroissantena();
            ui->label_57->setText("Sort A-Z .");
        }
        else {
            sa.languageSelectedfr();
            sa.tripCroissantfra();
            ui->label_57->setText("Tri A-Z .");
        }

    }else {  sa.stop();}
}
//trie quantite croissant
void Menu::on_radioButton_25_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_plante->setModel(tmppl.afficher_QuantiteCroissant());//refresh


    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.triQCroissantena();
            ui->label_57->setText("Sort by quantity .");
        }
        else {
            sa.languageSelectedfr();
            sa.triQCroissantfra();
            ui->label_57->setText("Tri croissant du quantite .");
        }

    }else {  sa.stop();}
}
//trie quantit decroissant
void Menu::on_radioButton_23_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_plante->setModel(tmppl.afficher_QuantiteDecroissant());//refresh
    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.triQdeCroissantena();
            ui->label_57->setText("Sort by quantity .");
        }
        else {
            sa.languageSelectedfr();
            sa.triQdeCroissantfra();
            ui->label_57->setText("Tri decroissant du quantite .");
        }

    }else {  sa.stop();}
}
//recherche plante
void Menu::on_recherche_2_textChanged(const QString &arg1)
{
    QString q = arg1;

    if (q=="")
    {
        ui->afficher_plante->setModel(tmppl.afficher_plante()) ;

    }
    else {
        ui->afficher_plante->setModel(tmppl.rechercher(q)) ;

        if(speek==1)
        {
            if (lng=="en")
            {
                // ui->label_5->setText("Research");
            }
            else
            {

                //ui->label_5->setText("Recherche");
            }

        }else {  sa.stop();}
    }
}
//creation pdf plante
int Menu::on_pushButton_65_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("A:\\integration\\integration final\\2\\mahrousplusplus\\Historique PDF\\Liste des Plantes.pdf");//badel i chemin win t7eb t7ot il fichier ya2melek creation
    QPainter painter;

    if (! painter.begin(&printer)) { // failed to open file
        qWarning("failed to open file, is it writable?");
        //return 1;
    }




    QSqlQuery   query ;
    qDebug() << query.prepare("select sysdate from dual  ");//hethi date mta3 systeme d9i9et eli 3melet create pdf (clic 3al bouton )
    if ( query.exec() )
    {

        QString S= QDate::currentDate().toString();
        painter.drawText(600,50, S);
        QPen penred(Qt::red);

        painter.setFont(QFont("Arial", 60));
        penred.setWidth(1);
        painter.setPen(penred);

        painter.drawText(200,500," La liste des ");
        painter.drawText(200,650,"  Plantes.");
        painter.setFont(QFont("Arial",30));
        painter.setPen(Qt::black);
        painter.drawText(50,100,"Bienvenu");
        painter.setPen(Qt::darkRed);
        painter.drawText(100,200,"Mahrous ++");
        painter.setPen(Qt::black);

    }

    QString idP,Secteur,Etat,Quantite, idcp , url ,photo,cin,image;
    QSqlQuery   qry ;
    int i =50;
    int k=0;
    //badel i table w les attribues
    qDebug() << qry.prepare("select * from  PLANTES order by IDPLANTE ");

    painter.drawPixmap(600,50,100,100,QPixmap::fromImage(QImage("A:/photo/logo.png")));//chemin mta3 il logo
    painter.drawText(400,800, image);


    if ( qry.exec() )
    {

        while(qry.next())
        {

            if ( k % 13 ==0)
            {   i=50;

                if (!printer.newPage())
                {

                    qWarning("failed");
                    return 1;
                }
                painter.setFont(QFont("Arial",10));
                QPen penblack(Qt::red);

                painter.setPen(penblack);
                painter.drawText (0,10,"idP");
                painter.drawText (40,10,"Secteur");
                painter.drawText (90,10,"Etat");

                painter.drawText (150,10,"Quantite");
                painter.drawText (210,10,"idCP");
                painter.drawText (260,10,"URL");
                painter.drawText (520,10,"Photo");
                painter.drawText (650,10,"CIN");

            }

            painter.setFont(QFont("Arial",10));
            QPen penblack(Qt::black);

            painter.setPen(penblack);
            int j=0;

            idP = qry.value(0).toString();
            painter.drawText(j*20,i, idP);
            j++;

            Secteur=qry.value(1).toString();
            painter.drawText(j*40,i, Secteur);
            j++;
            Etat=qry.value(2).toString();
            painter.drawText(j*50,i, Etat);
            j++;
            Quantite=qry.value(3).toString();
            painter.drawText(j*49,i,Quantite);
            j++;
            idcp=qry.value(4).toString();
            painter.drawText(j*55,i,idcp);
            j++;
            url=qry.value(5).toString();
            painter.drawText(j*56,i, url);
            j++;

            /*image=qry.value(7).toString();
            painter.drawText(j*54,i, image);*/

            QImage chemin(url);
            painter.drawPixmap(j*88,i,50,50,QPixmap::fromImage(QImage(chemin)));
            j++;
            cin=qry.value(6).toString();
            painter.drawText(j*90,i, cin);
            j++;
            /*idf=qry.value(8).toString();
                        painter.drawText(j*83,i, idf);*/

            i+=80;

            k++;



        }
    }


    painter.end();
    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.creationpdfen();
            ui->label_57->setText("PDF creation");
        }
        else
        {
            sa.languageSelectedfr();
            sa.creationpdffr();
            ui->label_57->setText("Création PDF");
        }

    }else {  sa.stop();}
}
//stat plante
void Menu::on_pushButton_62_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    sp=new Stat_plante(this);
    sp->show();
    //speek
}
//besoin animaux
//ajouter besoin animal
void Menu::on_pushButton_79_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    if(securite==0)
    {
        int IDBESOINANIMAUX = ui->cx_idb->text().toInt();
        int EAUANIMAUX= ui->cx_eau->text().toInt();
        QString NUTRITIONANIMAUX = ui->cx_nutrition->text();
        QString ABRIANIMAUX= ui->cx_abri->text();
        QString VACOANIMAUX=ui->cx_vaco->text();
        QString IMAGEANIMAUX =ui->chemin_3->text();//LABEL CHEMIN

        gestion_besoinanimaux P(IDBESOINANIMAUX,EAUANIMAUX,NUTRITIONANIMAUX,ABRIANIMAUX,VACOANIMAUX,IMAGEANIMAUX);


        bool test=P.ajouter_besoinanimaux();
        if(test)
        {   //ui->label_8->setText("Ajouter Besoin animaux");
            QFile file("A:\\integration\\integration final\\2\\mahrousplusplus\\Historique\\HistoriqueBesoinAnimaux.txt");
            if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
                return;
            QString res1= QString::number(IDBESOINANIMAUX);
            QString res2= QString::number(EAUANIMAUX);
            QTextStream cout(&file);
            QString message2="\nBesoin Animala été ajouter sous  :"+res1+" "+res2+" "+NUTRITIONANIMAUX+" "+ABRIANIMAUX+" "+VACOANIMAUX+" "+IMAGEANIMAUX ;
            cout << message2;
            ui->afficher_besoinanimaux->setModel(tmpba.afficher_besoinanimaux());//refresh

            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();
                    sa.ajouterbesoineen();
                    ui->label_78->setText("Add need animal.");
                }
                else {
                    sa.languageSelectedfr();
                    sa.afficherbesoinefr();
                    ui->label_78->setText("Ajouter besoins animaux.");
                }
            }else {  sa.stop();}

            initba();


        }
        else{
            QMessageBox::critical(nullptr, QObject::tr("Ajouter animaux"),
                                  QObject::tr("animaux existe deja  !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

        }
    }

    else {
        QMessageBox msgBox;
        QPixmap pix("A:/integration/integration final/danger.png");

        msgBox.setText("Il faut ouvrir cadenas .");
        msgBox.setIconPixmap(pix);
        msgBox.exec();
    }
}
//Affiche besoin animal
void Menu::on_pushButton_76_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_besoinanimaux->setModel(tmpba.afficher_besoinanimaux());//refresh
    initba();


    if(speek==1)
    {
        if (lng=="en")
        { sa.languageSelecteden();
            sa.afficherbesoineen();
            ui->label_78->setText("Show list of need animals .");
        }
        else {
            sa.languageSelectedfr();
            sa.afficherbesoinefr();
            ui->label_78->setText("Afficher la liste des besoins animaux.");
        }

    }else {  sa.stop();}
}
//bouton besoin animal
void Menu::on_pushButton_71_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->stackedWidget->setCurrentIndex(7);
}
//besoin animal vers menu
void Menu::on_pushButton_81_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->stackedWidget->setCurrentIndex(0);
}
//ajouter image
void Menu::on_pushButton_74_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    QString filename = QFileDialog::getOpenFileName(this,tr("choose"), "" , tr("image (*.png *.jpg *.jpeg *.bmp *.gif)"));
    if ( QString::compare(filename, QString()) != 0 )
    {
        QImage image;
        bool valid =image.load(filename);
        if (valid)
        {
            ui->chemin_3->setText(filename);
            image =image.scaledToWidth(ui->photo_3->width(),Qt::SmoothTransformation);
            ui->photo_3->setPixmap(QPixmap::fromImage(image));
            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();
                    sa.ajouterimageen();
                    ui->label_78->setText("Add picture .");
                }
                else {
                    sa.languageSelectedfr();
                    sa.ajouterimagefr();
                    ui->label_78->setText("Ajouter photo .");
                }

            }else {  sa.stop();}
        }

    }
}
//modifier image
void Menu::on_pushButton_78_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    QString filename = QFileDialog::getOpenFileName(this,tr("choose"), "" , tr("image (*.png *.jpg *.jpeg *.bmp *.gif)"));
    if ( QString::compare(filename, QString()) != 0 )
    {
        QImage image;
        bool valid =image.load(filename);
        if (valid)
        {
            ui->chemin_3->setText(filename);
            image =image.scaledToWidth(ui->photo_3->width(),Qt::SmoothTransformation);
            ui->photo_3->setPixmap(QPixmap::fromImage(image));
            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();
                    sa.modifierimageen();
                    ui->label_78->setText("Edit picture .");

                }
                else {
                    sa.languageSelectedfr();
                    sa.modifierimagefr();
                    ui->label_78->setText("Modifier photo.");
                }

            }else {  sa.stop();}
        }

    }
}
//selected besoinanimal
void Menu::on_afficher_besoinanimaux_activated(const QModelIndex &index)
{
    QString val=ui->afficher_besoinanimaux->model()->data(index).toString();
    QSqlQuery qry ;

    qry=tmpba.tableclicked(val);

    if (qry.exec())
    {
        while (qry.next())
        {

            ui->cx_idb->setDisabled(1);
            ui->cx_idb->setText(qry.value(0).toString());
            ui->cx_eau->setText(qry.value(1).toString());
            ui->cx_nutrition->setText(qry.value(2).toString());
            ui->cx_abri->setText(qry.value(3).toString());
            ui->cx_vaco->setText(qry.value(4).toString());
            ui->chemin_3->setText(qry.value(5).toString());
            QPixmap pix(ui->chemin_3->text());
            int w =ui->photo_3->width();
            int h =ui->photo_3->height();
            ui->photo_3->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

        }
    }
}
//supprimer besoin animal
void Menu::on_pushButton_80_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    if (securite ==0)
    {
        int idB = ui->cx_idb->text().toInt();

        bool test=tmpba.supprimer_besoinanimaux(idB);
        if(test)
        {    ui->afficher_besoinanimaux->setModel(tmpba.afficher_besoinanimaux());//refresh
            initba();


            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();
                    sa.supprimerbesoinanimeen();
                    ui->label_78->setText("delete animal needs.");
                }
                else {
                    sa.languageSelectedfr();
                    sa.supprimerbesoinanimefr();
                    ui->label_78->setText("supprimer besoins animaux.");
                }

            }else {  sa.stop();}

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer animaux"),
                                  QObject::tr("verifier le id  !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox msgBox;
        QPixmap pix("A:/integration/integration final/danger.png");

        msgBox.setText("Il faut ouvrir cadenas .");
        msgBox.setIconPixmap(pix);
        msgBox.exec();
    }
}
//modifier besoin animal
void Menu::on_pushButton_72_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    if (securite ==0)
    {
        int IDBESOINANIMAUX = ui->cx_idb->text().toInt();
        int EAUANIMAUX= ui->cx_eau->text().toInt();
        QString NUTRITIONANIMAUX = ui->cx_nutrition->text();
        QString ABRIANIMAUX= ui->cx_abri->text();
        QString VACOANIMAUX = ui->cx_vaco->text();
        QString IMAGEANIMAUX= ui->chemin_3->text();//LABEL CHEMIN



        gestion_besoinanimaux P(IDBESOINANIMAUX,EAUANIMAUX,NUTRITIONANIMAUX,ABRIANIMAUX,VACOANIMAUX,IMAGEANIMAUX);
        bool test=tmpba.modifier_besoinanimaux(P);
        if(test)
        {

            ui->afficher_besoinanimaux->setModel(tmpba.afficher_besoinanimaux());//refresh


            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();
                    sa.modifierbesoinanimeen();
                    ui->label_78->setText("modify animal needs.");
                }
                else {
                    sa.languageSelectedfr();
                    sa.modifierbesoinanimefr();
                    ui->label_78->setText("modifier besoins animaux.");
                }

            }else {  sa.stop();}

            initba();

        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Modifier animaux"),
                                  QObject::tr("animaux non valide  !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
    else
    {
        QMessageBox msgBox;
        QPixmap pix("A:/integration/integration final/danger.png");

        msgBox.setText("Il faut ouvrir cadenas .");
        msgBox.setIconPixmap(pix);
        msgBox.exec();
    }
}
//afficher image besoin animal
void Menu::on_pushButton_82_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    photo p;
    p.setchemin(ui->chemin_3->text());
    p.exec();
    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.afficherimageen();
            ui->label_78->setText("Show picture");
        }
        else
        {
            sa.languageSelectedfr();
            sa.afficherimagefr();
            ui->label_78->setText("Afficher image");
        }

    }else {  sa.stop();}
}
//Tri A-Z Nutrition Animaux
void Menu::on_radioButton_32_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_besoinanimaux->setModel(tmpba.afficher_NutCroissant());
    ui->label_78->setText("Tri A-Z Nutrition Animaux ");
}
//Tri Z-A par Nutrition Animaux
void Menu::on_radioButton_34_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_besoinanimaux->setModel(tmpba.afficher_NutDecroissant());
    ui->label_78->setText("Tri Z-A par Nutrition Animaux ");
}
//Tri Croissant de quantite d'eau
void Menu::on_radioButton_33_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_besoinanimaux->setModel(tmpba.afficher_EauCroissant());//refresh
    ui->label_78->setText("Tri Croissant de quantite d'eau");
}
//Tri Décroissant de Qauntite d'eau
void Menu::on_radioButton_29_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_besoinanimaux->setModel(tmpba.afficher_EauDecroissant());//refresh
    ui->label_78->setText("Tri Décroissant de Qauntite d'eau");
}
//Tri Croissant IDBesoin
void Menu::on_radioButton_30_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_besoinanimaux->setModel(tmpba.afficher_idCroissant());//refresh

    ui->label_78->setText("Tri Croissant IDBesoin");
}
//Tri Decroisant IDBesoin
void Menu::on_radioButton_31_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_besoinanimaux->setModel(tmpba.afficher_idDecroissant());//refresh

    ui->label_78->setText("Tri Decroisant IDBesoin");
}
//recherche besoin animal
void Menu::on_recherche_3_textChanged(const QString &arg1)
{
    QString q = arg1;

    if (q=="")
    {
        ui->afficher_besoinanimaux->setModel(tmpba.afficher_besoinanimaux()) ;
        ui->label_78->setText("Liste des besoin animaux ");
    }
    else {
        ui->afficher_besoinanimaux->setModel(tmpba.rechercher(q)) ;
        ui->label_78->setText("Chercher");
    }
}
//pdf besoin animal
int Menu::on_pushButton_77_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("A:\\integration\\integration final\\2\\mahrousplusplus\\Historique PDF\\Liste des Besoin Animaux.pdf");//badel i chemin win t7eb t7ot il fichier ya2melek creation
    QPainter painter;

    if (! painter.begin(&printer)) { // failed to open file
        qWarning("failed to open file, is it writable?");
        //return 1;
    }




    QSqlQuery   query ;
    qDebug() << query.prepare("select sysdate from dual  ");//hethi date mta3 systeme d9i9et eli 3melet create pdf (clic 3al bouton )
    if ( query.exec() )
    {

        QString S= QDate::currentDate().toString();
        painter.drawText(600,50, S);
        QPen penred(Qt::red);

        painter.setFont(QFont("Arial", 60));
        penred.setWidth(1);
        painter.setPen(penred);

        painter.drawText(200,500," La liste des ");
        painter.drawText(180,650,"Besoin Animaux.");
        painter.setFont(QFont("Arial",30));
        painter.setPen(Qt::black);
        painter.drawText(50,100,"Bienvenu");
        painter.setPen(Qt::darkRed);
        painter.drawText(100,200,"Mahrous ++");
        painter.setPen(Qt::black);

    }

    QString idB,eau,nuttrition,ABRI, VAC, url ,photo,image;
    QSqlQuery   qry ;
    int i =50;
    int k=0;
    //badel i table w les attribues
    qDebug() << qry.prepare("select * from  BESOINSANIMAUX  order by IDBESOINANIMAUX ");

    painter.drawPixmap(600,50,100,100,QPixmap::fromImage(QImage("A:/photo/logo.png")));//chemin mta3 il logo
    painter.drawText(400,800, image);


    if ( qry.exec() )
    {

        while(qry.next())
        {

            if ( k % 13 ==0)
            {   i=50;

                if (!printer.newPage())
                {

                    qWarning("failed");
                    return 1;
                }
                painter.setFont(QFont("Arial",10));
                QPen penblack(Qt::red);

                painter.setPen(penblack);

                painter.drawText (0,10,"idB");
                painter.drawText (40,10,"eau");
                painter.drawText (90,10,"nuttrition");

                painter.drawText (150,10,"ABRI");
                painter.drawText (210,10,"VAC");
                painter.drawText (260,10,"url");
                painter.drawText (520,10,"photo");
                //painter.drawText (650,10,"CIN");
                /*painter.drawText (590,10,"");
painter.drawText (650,10,"");*/
            }

            painter.setFont(QFont("Arial",10));
            QPen penblack(Qt::black);

            painter.setPen(penblack);
            int j=0;

            idB = qry.value(0).toString();
            painter.drawText(j*20,i, idB);
            j++;

            eau=qry.value(1).toString();
            painter.drawText(j*40,i, eau);
            j++;
            nuttrition=qry.value(2).toString();
            painter.drawText(j*50,i,nuttrition);
            j++;
            ABRI=qry.value(3).toString();
            painter.drawText(j*49,i,ABRI);
            j++;
            VAC=qry.value(4).toString();
            painter.drawText(j*55,i,VAC);
            j++;
            url=qry.value(5).toString();
            painter.drawText(j*56,i, url);
            j++;

            /*image=qry.value(7).toString();
            painter.drawText(j*54,i, image);*/

            QImage chemin(url);
            painter.drawPixmap(j*88,i,50,50,QPixmap::fromImage(QImage(chemin)));
            j++;

            /*idf=qry.value(8).toString();
                        painter.drawText(j*83,i, idf);*/

            i+=80;

            k++;



        }
    }

    // ui->label_8->setText("Creation PDF");
    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.creationpdfen();
            ui->label_78->setText("PDF creation");
        }
        else
        {
            sa.languageSelectedfr();
            sa.creationpdffr();
            ui->label_78->setText("Création PDF");
        }

    }else {  sa.stop();}
    painter.end();
}
//stat besoin animal
void Menu::on_pushButton_73_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    sba=new stat_besoinanimaux(this);
    sba->show();
}
//bouton photo besoin animal
void Menu::on_pushButton_68_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->stackedWidget->setCurrentIndex(7);
}
//production animal
//bouton production animal
void Menu::on_pushButton_70_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->stackedWidget->setCurrentIndex(8);
}
//bouton photo production animal
void Menu::on_pushButton_69_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->stackedWidget->setCurrentIndex(8);
}
//ajouter production animal
void Menu::on_pushButton_92_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    if (securite ==0)
    {
        int IDPRODUCTIONANIMAUX = ui->cx_idpa->text().toInt();
        int IDESPECE = ui->comboBox_idespece->currentText().toInt();
        QString PRODUITPRODUCTIONANIMAUX = ui->cx_ppa->text();
        int PRIXPRODUCTIONANIMAUX= ui->cx_prix->text().toInt();
        QString IMAGEPRODUCTIONANIMAUX =ui->chemin_4->text();//LABEL CHEMIN

        gestion_productionanimaux P(IDPRODUCTIONANIMAUX,IDESPECE,PRODUITPRODUCTIONANIMAUX,PRIXPRODUCTIONANIMAUX,IMAGEPRODUCTIONANIMAUX);

        bool test=P.ajouter_productionanimaux();
        if(test)
        {
            //ui->label_8->setText("Ajouter productionanimaux");
            QFile file("A:\\integration\\integration final\\2\\mahrousplusplus\\Historique\\Historiqueproductionanimaux.txt");
            if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
                return;
            QTextStream cout(&file);
            QString res1= QString::number(IDPRODUCTIONANIMAUX);
            QString message2="\n L'historique  à ajouter :" +res1+" "+IDESPECE+" "+PRODUITPRODUCTIONANIMAUX+"  "+PRIXPRODUCTIONANIMAUX+" "+IMAGEPRODUCTIONANIMAUX ;
            cout << message2;
            ui->afficher_productionanimaux->setModel(tmppa.afficher_productionanimaux());//refresh
            initpa();
            if(speek==1)
            {
                if (lng=="en")
                { sa.languageSelecteden();
                    sa.ajouterproductionanimalen(ui->cx_ppa->text());

                }
                else {
                    sa.languageSelectedfr();
                    sa.ajouterproductionanimalfr(ui->cx_ppa->text());
                    // ui->label_78->setText("Afficher la liste des besoins animaux.");
                }

            }else {  sa.stop();}

        }
        else{
            QMessageBox::critical(nullptr, QObject::tr("Ajouter productionanimaux"),
                                  QObject::tr("productionanimaux existe deja  !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

        }
    }
    else {
        QMessageBox msgBox;
        QPixmap pix("A:/integration/integration final/danger.png");

        msgBox.setText("Il faut ouvrir cadenas .");
        msgBox.setIconPixmap(pix);
        msgBox.exec();
    }
}
//afficher production animal
void Menu::on_pushButton_88_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_productionanimaux->setModel(tmppa.afficher_productionanimaux());//refresh
    initpa();
    //  ui->comboBox_supp->setModel(tmppl.afficher_Mlist());

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.afficherprodanimen();
            ui->label_78->setText("Show list of animal products .");
        }
        else {
            sa.languageSelecteden();
            sa.afficherprodanimfr();
            ui->label_78->setText("Afficher la liste des produits animaux.");
        }

    }else {  sa.stop();}
}
//clicked production animal
void Menu::on_afficher_productionanimaux_activated(const QModelIndex &index)
{
    QString val=ui->afficher_productionanimaux->model()->data(index).toString();
    QSqlQuery qry ;


    qry=tmppa.tableclicked(val);
    if (qry.exec())
    {
        while (qry.next())
        {

            ui->cx_idpa->setDisabled(1);
            ui->cx_idpa->setText(qry.value(0).toString());
            ui->comboBox_idespece->setCurrentText(qry.value(1).toString());
            ui->cx_ppa->setText(qry.value(2).toString());
            ui->cx_prix->setText(qry.value(3).toString());
            ui->chemin_4->setText(qry.value(4).toString());
            QPixmap pix(ui->chemin_4->text());
            int w =ui->photo_4->width();
            int h =ui->photo_4->height();
            ui->photo_4->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
        }
    }
}
//supprimer production animal
void Menu::on_pushButton_85_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    if (securite ==0)
    {
        int idP = ui->cx_idpa->text().toInt();
        bool test=tmppa.supprimer_productionanimaux(idP);
        if(test)
        {    ui->afficher_productionanimaux->setModel(tmppa.afficher_productionanimaux());//refresh

            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();
                    sa.supprimerprodanimen();
                    ui->label_78->setText("delete list of animal products .");
                }
                else {
                    sa.languageSelecteden();
                    sa.supprimerprodanimfr();
                    ui->label_78->setText("supprimer la liste des produits animaux.");
                }

            }else {  sa.stop();}

            initpa();
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer productionanimaux"),
                                  QObject::tr("verifier le id  !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else {
        QMessageBox msgBox;
        QPixmap pix("A:/integration/integration final/danger.png");

        msgBox.setText("Il faut ouvrir cadenas .");
        msgBox.setIconPixmap(pix);
        msgBox.exec();
    }
}
//modifierproduction animal
void Menu::on_pushButton_91_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    if (securite==0)
    {
        int IDPRODUCTIONANIMAUX = ui->cx_idpa->text().toInt();
        int IDESPECE = ui->comboBox_idespece->currentText().toInt();
        QString PRODUITPRODUCTIONANIMAUX = ui->cx_ppa->text();
        int PRIXPRODUCTIONANIMAUX= ui->cx_prix->text().toInt();
        QString IMAGEPRODUCTIONANIMAUX= ui->chemin->text();//LABEL CHEMIN



        gestion_productionanimaux P(IDPRODUCTIONANIMAUX,IDESPECE,PRODUITPRODUCTIONANIMAUX,PRIXPRODUCTIONANIMAUX,IMAGEPRODUCTIONANIMAUX);
        bool test=tmppa.modifier_productionanimaux(P);
        if(test)
        {

            ui->afficher_productionanimaux->setModel(tmppa.afficher_productionanimaux());//refresh


            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();
                    sa.modifierprodanimen();
                    ui->label_78->setText("modify list of animal products .");
                }
                else {
                    sa.languageSelectedfr();
                    sa.modifierprodanimfr();
                    ui->label_78->setText("modifier la liste des produits animaux.");
                }

            }else {  sa.stop();}
            //sm.speak();//speek modifier
            initpa();
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Modifier animaux"),
                                  QObject::tr("animaux non valide  !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
    else
    {
        QMessageBox msgBox;
        QPixmap pix("A:/integration/integration final/danger.png");

        msgBox.setText("Il faut ouvrir cadenas .");
        msgBox.setIconPixmap(pix);
        msgBox.exec();
    }
}
//ajouter image
void Menu::on_pushButton_89_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    QString filename = QFileDialog::getOpenFileName(this,tr("choose"), "" , tr("image (*.png *.jpg *.jpeg *.bmp *.gif)"));
    if ( QString::compare(filename, QString()) != 0 )
    {
        QImage image;
        bool valid =image.load(filename);
        if (valid)
        {
            ui->chemin_4->setText(filename);
            image =image.scaledToWidth(ui->photo_4->width(),Qt::SmoothTransformation);
            ui->photo_4->setPixmap(QPixmap::fromImage(image));
            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();
                    sa.ajouterimageen();
                    ui->label_78->setText("Add picture .");
                }
                else {
                    sa.languageSelectedfr();
                    sa.ajouterimagefr();
                    ui->label_78->setText("Ajouter photo .");
                }

            }else {  sa.stop();}
        }

    }
}
//modifier image
void Menu::on_pushButton_87_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    QString filename = QFileDialog::getOpenFileName(this,tr("choose"), "" , tr("image (*.png *.jpg *.jpeg *.bmp *.gif)"));
    if ( QString::compare(filename, QString()) != 0 )
    {
        QImage image;
        bool valid =image.load(filename);
        if (valid)
        {
            ui->chemin_4->setText(filename);
            image =image.scaledToWidth(ui->photo_4->width(),Qt::SmoothTransformation);
            ui->photo_4->setPixmap(QPixmap::fromImage(image));
            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();
                    sa.modifierimageen();
                    ui->label_78->setText("Edit picture .");

                }
                else {
                    sa.languageSelectedfr();
                    sa.modifierimagefr();
                    ui->label_78->setText("Modifier photo.");
                }

            }else {  sa.stop();}
        }

    }
}
//afficher image
void Menu::on_pushButton_93_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    photo p;
    p.setchemin(ui->chemin_4->text());
    p.exec();
    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.afficherimageen();
            ui->label_57->setText("Show picture");
        }
        else
        {
            sa.languageSelectedfr();
            sa.afficherimagefr();
            ui->label_57->setText("Afficher image");
        }

    }else {  sa.stop();}
}
//trie produit croissant
void Menu::on_radioButton_36_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_productionanimaux->setModel(tmppa.afficher_ProduitCroissant());//refresh

    //ui->label_8->setText("Tri Croissant d'age");
}
//trie produit decroissant
void Menu::on_radioButton_37_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_productionanimaux->setModel(tmppa.afficher_ProduitDecroissant());//refresh
    //ui->label_8->setText("Tri Croissant d'age");
}
//trie id croissant
void Menu::on_radioButton_38_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_productionanimaux->setModel(tmppa.afficher_IdCroissant());//refresh
    //ui->label_8->setText("Tri Croissant d'age");
}
//trie id decroissant
void Menu::on_radioButton_35_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_productionanimaux->setModel(tmppa.afficher_IdDecroissant());//refresh
    //ui->label_8->setText("Tri Croissant d'age");
}
//recherche production animal
void Menu::on_recherche_4_textChanged(const QString &arg1)
{
    QString q = arg1;

    if (q=="")
    {
        ui->afficher_productionanimaux->setModel(tmppa.afficher_productionanimaux()) ;

    }
    else {
        ui->afficher_productionanimaux->setModel(tmppa.rechercher(q)) ;
        // ui->label_5->setText("Chercher");
    }
}
//creation pdf
int Menu::on_pushButton_90_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("A:\\integration\\integration final\\2\\mahrousplusplus\\Historique PDF\\Liste des productions Animaux.pdf");//badel i chemin win t7eb t7ot il fichier ya2melek creation
    QPainter painter;

    if (! painter.begin(&printer)) { // failed to open file
        qWarning("failed to open file, is it writable?");
        //return 1;
    }




    QSqlQuery   query ;
    qDebug() << query.prepare("select sysdate from dual  ");//hethi date mta3 systeme d9i9et eli 3melet create pdf (clic 3al bouton )
    if ( query.exec() )
    {

        QString S= QDate::currentDate().toString();
        painter.drawText(600,50, S);
        QPen penred(Qt::red);

        painter.setFont(QFont("Arial", 60));
        penred.setWidth(1);
        painter.setPen(penred);

        painter.drawText(200,500," La liste des ");
        painter.drawText(200,650,"  productionAnimaux.");
        painter.setFont(QFont("Arial",30));
        painter.setPen(Qt::black);
        painter.drawText(50,100,"Bienvenu");
        painter.setPen(Qt::darkRed);
        painter.drawText(100,200,"Mahrous ++");
        painter.setPen(Qt::black);

    }

    QString idP,idE,ppa,prix, url ,photo,image;
    QSqlQuery   qry ;
    int i =50;
    int k=0;
    //badel i table w les attribues
    qDebug() << qry.prepare("select * from  PRODUCTIONANIMAUX order by IDPRODUCTIONANIMAUX ");

    painter.drawPixmap(600,50,100,100,QPixmap::fromImage(QImage("A:/photo/logo.png")));//chemin mta3 il logo
    painter.drawText(400,800, image);


    if ( qry.exec() )
    {

        while(qry.next())
        {

            if ( k % 13 ==0)
            {   i=50;

                if (!printer.newPage())
                {

                    qWarning("failed");
                    return 1;
                }
                painter.setFont(QFont("Arial",10));
                QPen penblack(Qt::red);

                painter.setPen(penblack);

                painter.drawText (0,10,"idP");
                painter.drawText (40,10,"idE");
                painter.drawText (90,10,"ppa");

                painter.drawText (150,10,"prix");
                painter.drawText (260,10,"url");
                painter.drawText (520,10,"photo");
                /*painter.drawText (590,10,"");
painter.drawText (650,10,"");*/
            }

            painter.setFont(QFont("Arial",10));
            QPen penblack(Qt::black);

            painter.setPen(penblack);
            int j=0;

            idP = qry.value(0).toString();
            painter.drawText(j*20,i, idP);
            j++;

            idE=qry.value(1).toString();
            painter.drawText(j*40,i, idE);
            j++;
            ppa=qry.value(2).toString();
            painter.drawText(j*50,i,ppa);
            j++;
            prix=qry.value(3).toString();
            painter.drawText(j*49,i,prix);
            j++;
            url=qry.value(4).toString();
            painter.drawText(j*56,i, url);
            j++;

            /*image=qry.value(7).toString();
            painter.drawText(j*54,i, image);*/

            QImage chemin(url);
            painter.drawPixmap(j*88,i,50,50,QPixmap::fromImage(QImage(chemin)));
            j++;

            /*idf=qry.value(8).toString();
                        painter.drawText(j*83,i, idf);*/

            i+=80;

            k++;



        }
    }

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.creationpdfen();
            //ui->label_57->setText("PDF creation");
        }
        else
        {
            sa.languageSelectedfr();
            sa.creationpdffr();
            // ui->label_57->setText("Création PDF");
        }

    }else {  sa.stop();}

    painter.end();
}
//stat production animal
void Menu::on_pushButton_86_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    spa=new Stat_productionanimaux(this);
    spa->show();
}
//production animal vers menu
void Menu::on_pushButton_83_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->stackedWidget->setCurrentIndex(0);
}
//espece animal
//bouton espece animal
void Menu::on_pushButton_94_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->stackedWidget->setCurrentIndex(9);
    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();//fixe
            sa.especeanimalen();

        }
        else
        {
            sa.languageSelectedfr();//fixe
            sa.especeanimalfr();
        }

    }else {  sa.stop();}
}
//bouton image espece animal
void Menu::on_pushButton_97_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->stackedWidget->setCurrentIndex(9);
    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();//fixe
            sa.especeanimalen();

        }
        else
        {
            sa.languageSelectedfr();//fixe
            sa.especeanimalfr();
        }

    }else {  sa.stop();}
}
//ajouter espece animal
void Menu::on_pushButton_101_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    if (securite==0)
    {

        QString IDESPECE,NOMESPECE;
        IDESPECE=ui->cx_idespeceanimal->text();
        NOMESPECE=ui->cx_nomespeceanimal->text();
        gestion_especeanimal C(IDESPECE,NOMESPECE);
        bool test=C.ajouter_especeanimal();
        if(test)
        {
            QFile file("A:\\integration\\integration final\\2\\mahrousplusplus\\Historique\\HistoriqueEspeceAnimal.txt");
            if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
                return;
            QTextStream cout(&file);
            QString message2="\nEspece Animale a été ajoutée sous :\nidEA :"+IDESPECE+"\nnom : "+NOMESPECE+"";
            cout << message2;
            initea();
            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();//fixe
                    sa.ajouterespaceanimalen(ui->cx_nomespeceanimal->text());
                    ui->label_93->setText("Add species animal");
                }
                else
                {
                    sa.languageSelectedfr();//fixe
                    sa.ajouterespaceanimalfr(ui->cx_nomespeceanimal->text());
                    ui->label_93->setText("ajouter espece animal");
                }

            }else {  sa.stop();}
            ui->afficher_especeanimal->setModel(tmpea.afficher_especeanimal());

        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Ajouter Catégorie "),
                                  QObject::tr("Catégorie existe deja  !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
    else {

        QMessageBox msgBox;
        QPixmap pix("A:/integration/integration final/danger.png");

        msgBox.setText("Il faut ouvrir cadenas .");
        msgBox.setIconPixmap(pix);
        msgBox.exec();


    }
}
//selected
void Menu::on_afficher_especeanimal_activated(const QModelIndex &index)
{
    QString val=ui->afficher_especeanimal->model()->data(index).toString();
    QSqlQuery qry ;


    qry=tmpea.tableclicked(val);
    if (qry.exec())
    {
        while (qry.next())
        {

            ui->cx_idespeceanimal->setDisabled(1);
            ui->cx_idespeceanimal->setText(qry.value(0).toString());
            ui->cx_nomespeceanimal->setText(qry.value(1).toString());
            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();//fixe
                    sa.selectedespaceanimalen();
                    ui->label_93->setText("Species animal selected");
                }
                else
                {
                    sa.languageSelectedfr();//fixe
                    sa.selectedespaceanimalfr();
                    ui->label_93->setText("Espece animal selectionée");
                }

            }else {  sa.stop();}

        }
    }

}
//afficher espece animal
void Menu::on_pushButton_102_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_especeanimal->setModel(tmpea.afficher_especeanimal());//refresh
    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();//fixe
            sa.afficherespaceanimalen();
            ui->label_93->setText("List of species animal");
        }
        else
        {
            sa.languageSelectedfr();//fixe
            sa.afficherespaceanimalfr();
            ui->label_93->setText("Liste des espéces animal ");
        }

    }else {  sa.stop();}
}
//supprimer espece animal
void Menu::on_pushButton_99_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    if (securite==0)
    {
        QString idC = ui->cx_idespeceanimal->text();
        bool test=tmpea.supprimer_especeanimal(idC);
        if(test)
        {    ui->afficher_especeanimal->setModel(tmpea.afficher_especeanimal());
            ui->cx_idespeceanimal->setEnabled(1);
            initea();
            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();//fixe
                    sa.supprimerespaceanimalen();
                    ui->label_93->setText("Remove species animal");
                }
                else
                {
                    sa.languageSelectedfr();//fixe
                    sa.afficherespaceanimalfr();
                    ui->label_93->setText("Supprimer espéces animal ");
                }

            }else {  sa.stop();}
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer Catégorie"),
                                  QObject::tr("verifier l'id  !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {

        QMessageBox msgBox;
        QPixmap pix("A:/integration/integration final/danger.png");

        msgBox.setText("Il faut ouvrir cadenas .");
        msgBox.setIconPixmap(pix);
        msgBox.exec();
    }
}
//modifier espece animal
void Menu::on_pushButton_100_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    if (securite==0)
    {
        QString IDESPECE = ui->cx_idespeceanimal->text();
        QString NOMESPECE= ui->cx_nomespeceanimal->text();
        gestion_especeanimal C(IDESPECE,NOMESPECE);
        bool test=tmpea.modifier_especeanimal(C);
        if(test)
        {
            ui->afficher_especeanimal->setModel(tmpea.afficher_especeanimal());//refresh
            ui->cx_idespeceanimal->setEnabled(1);
            initea();
            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();//fixe
                    sa.modifierespaceanimalen();
                    ui->label_93->setText("Edit species animal");
                }
                else
                {
                    sa.languageSelectedfr();//fixe
                    sa.afficherespaceanimalfr();
                    ui->label_93->setText("Modifier espéces animal ");
                }

            }else {  sa.stop();}

        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Modifier Catégorie"),
                                  QObject::tr("Catégorie non valide  !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
    else
    {

        QMessageBox msgBox;
        QPixmap pix("A:/integration/integration final/danger.png");

        msgBox.setText("Il faut ouvrir cadenas .");
        msgBox.setIconPixmap(pix);
        msgBox.exec();
    }
}
//recherche animal
void Menu::on_lineEdit_recherche_2_textChanged(const QString &arg1)
{

    QString q = arg1;

    if (q=="")
    {
        ui->afficher_especeanimal->setModel(tmpea.afficher_especeanimal());//refresh
    }
    else {
        ui->afficher_especeanimal->setModel(tmpea.rechercher(q)) ;
    }
}
//trie id croissant
void Menu::on_radioButton_39_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_especeanimal->setModel(tmpea.afficher_idCroissant());//refresh
}
//trie id decroissant
void Menu::on_radioButton_42_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_especeanimal->setModel(tmpea.afficher_idDecroissant());//refresh
    // ui->label_3->setText("Trier Décroissant du IdCatégorie");
}
//trie nom decroissant
void Menu::on_radioButton_41_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_especeanimal->setModel(tmpea.afficher_nomDecroissant());//refresh
    // ui->label_3->setText("Trier Z-A");
}
//trie nom croissant
void Menu::on_radioButton_40_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_especeanimal->setModel(tmpea.afficher_nomCroissant());//refresh

    // ui->label_3->setText("Trier A-Z");
}
//animal
//bouton animal
void Menu::on_pushButton_96_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->stackedWidget->setCurrentIndex(10);

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();//fixe
            sa.animalen();
        }
        else
        {
            sa.languageSelectedfr();//fixe
            sa.animalfr();
        }

    }else {  sa.stop();}
}
//photo bouton animal
void Menu::on_pushButton_95_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->stackedWidget->setCurrentIndex(10);
    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();//fixe
            sa.animalen();
        }
        else
        {
            sa.languageSelectedfr();//fixe
            sa.animalfr();
        }

    }else {  sa.stop();}
}
//ajouter animal
void Menu::on_pushButton_112_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    if (securite==0)
    {
        QString IDANIMAUX = ui->cx_ida->text();
        int AGEANIMAUX= ui->age_2->text().toInt();
        int IDESPECE = ui->comboBox_idespece_2->currentText().toInt();
        QString SEXEANIMAUX ;
        if (ui->femme_2->isChecked())
        {SEXEANIMAUX="femme";}
        if (ui->homme_2->isChecked())
        { SEXEANIMAUX="homme";}
        QString ETATANIMAUX;
        if (ui->Blesse->isChecked())
        { ETATANIMAUX="Blesse";}
        if (ui->Malade->isChecked())
        {ETATANIMAUX="Malade"; }
        if (ui->Bonne_2->isChecked())
        {ETATANIMAUX="Bonne";}
        QString CIN=ui->comboBox_cin_3->currentText();
        QString IMAGEANIMAUX =ui->chemin_5->text();//LABEL CHEMIN
        QString IDBA=ui->comboBox_idba->currentText();
        gestion_animaux P(IDANIMAUX,IDESPECE,AGEANIMAUX,SEXEANIMAUX,ETATANIMAUX,IMAGEANIMAUX,CIN,IDBA);
        bool test=P.ajouter_animaux();
        if(test)
        {
            QFile file("A:\\integration\\integration final\\2\\mahrousplusplus\\Historique\\Historiqueanimaux.txt");
            if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
                return;
            QTextStream cout(&file);
            QString message2="\n L'historique des Personnels à ajouter :"+IDANIMAUX+" "+IDESPECE+" "+AGEANIMAUX+"  "+SEXEANIMAUX+" "+ETATANIMAUX+" "+IMAGEANIMAUX+" "+CIN+" "+IDBA ;
            cout << message2;
            ui->afficher_animaux->setModel(tmpa.afficher_animaux());//refresh
            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();//fixe
                    sa.ajouteranimalen();
                    ui->label_110->setText("Add animal");
                }
                else
                {
                    sa.languageSelectedfr();//fixe
                    sa.ajouteranimalfr();
                    ui->label_110->setText("Ajouter animal ");
                }

            }else {  sa.stop();}

            inita();


        }
        else{
            QMessageBox::critical(nullptr, QObject::tr("Ajouter animaux"),
                                  QObject::tr("animaux existe deja  !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

        }
    }
    else
    {
        QMessageBox msgBox;
        QPixmap pix("A:/integration/integration final/danger.png");

        msgBox.setText("Il faut ouvrir cadenas .");
        msgBox.setIconPixmap(pix);
        msgBox.exec();
    }
}
//selected
void Menu::on_afficher_animaux_activated(const QModelIndex &index)
{
    QString val=ui->afficher_animaux->model()->data(index).toString();
    QSqlQuery qry ;
    qry=tmpa.tableclicked(val);

    if (qry.exec())
    {
        while (qry.next())
        {

            ui->cx_ida->setDisabled(1);
            ui->cx_ida->setText(qry.value(0).toString());
            ui->comboBox_idespece_2->setCurrentText(qry.value(1).toString());
            ui->age_2->setValue(qry.value(2).toInt());
            //ui->cx_sexe->setText(qry.value(3).toString());
            if (qry.value(3).toString()=="femme")
            {ui->femme_2->setChecked(true);}
            if (qry.value(3).toString()=="homme")
            {ui->homme_2->setChecked(true);}
            if (qry.value(4).toString()=="Blesse")
            { ui->Blesse->setChecked(true);}
            if (qry.value(4).toString()=="Malade")
            { ui->Malade->setChecked(true);}
            if (qry.value(4).toString()=="Bonne")
            {ui->Bonne_2->setChecked(true);}
            ui->chemin_5->setText(qry.value(5).toString());
            QPixmap pix(ui->chemin_5->text());
            int w =ui->photo_5->width();
            int h =ui->photo_5->height();
            ui->photo_5->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            ui->comboBox_cin_3->setCurrentText(qry.value(6).toString());
            ui->comboBox_idba->setCurrentText(qry.value(7).toString());
            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();//fixe
                    sa.selectedanimalen();
                    ui->label_110->setText("animal selected");
                }
                else
                {
                    sa.languageSelectedfr();//fixe
                    sa.selectedanimalfr();
                    ui->label_110->setText("animal selectionnée");
                }

            }else {  sa.stop();}
        }
    }
}
//ajouter image
void Menu::on_pushButton_111_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    QString filename = QFileDialog::getOpenFileName(this,tr("choose"), "" , tr("image (*.png *.jpg *.jpeg *.bmp *.gif)"));
    if ( QString::compare(filename, QString()) != 0 )
    {
        QImage image;
        bool valid =image.load(filename);
        if (valid)
        {
            ui->chemin_5->setText(filename);
            image =image.scaledToWidth(ui->photo_5->width(),Qt::SmoothTransformation);
            ui->photo_5->setPixmap(QPixmap::fromImage(image));
            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();
                    sa.ajouterimageen();
                    ui->label_110->setText("Add picture");
                }
                else
                {
                    sa.languageSelectedfr();
                    sa.ajouterimagefr();
                    ui->label_110->setText("Ajouter image");
                }

            }else {  sa.stop();}
        }

    }
}
//modifier image
void Menu::on_pushButton_113_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    QString filename = QFileDialog::getOpenFileName(this,tr("choose"), "" , tr("image (*.png *.jpg *.jpeg *.bmp *.gif)"));
    if ( QString::compare(filename, QString()) != 0 )
    {
        QImage image;
        bool valid =image.load(filename);
        if (valid)
        {
            ui->chemin_5->setText(filename);
            image =image.scaledToWidth(ui->photo_5->width(),Qt::SmoothTransformation);
            ui->photo_5->setPixmap(QPixmap::fromImage(image));
            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();
                    sa.modifierimageen();
                    ui->label_110->setText("Edit picture");
                }
                else
                {
                    sa.languageSelectedfr();
                    sa.modifierimagefr();
                    ui->label_110->setText("Modifier image");
                }

            }else {  sa.stop();}
        }

    }
}
//supprimer animal
void Menu::on_pushButton_106_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    if (securite==0)
    {
        QString idA = ui->cx_ida->text();
        bool test=tmpa.supprimer_animaux(idA);
        if(test)
        {    ui->afficher_animaux->setModel(tmpa.afficher_animaux());//refresh
            inita();
            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();
                    sa.supprimeranimalen();
                    ui->label_110->setText("Remove animal");
                }
                else
                {
                    sa.languageSelectedfr();
                    sa.supprimeranimalfr();
                    ui->label_110->setText("Supprimer animal");
                }

            }else {  sa.stop();}
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer animaux"),
                                  QObject::tr("verifier le id  !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox msgBox;
        QPixmap pix("A:/integration/integration final/danger.png");

        msgBox.setText("Il faut ouvrir cadenas .");
        msgBox.setIconPixmap(pix);
        msgBox.exec();
    }
}
//modifier animal
void Menu::on_pushButton_114_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    if (securite==0)
    {
        QString IDANIMAUX = ui->cx_ida->text();
        int IDESPECE = ui->comboBox_idespece_2->currentText().toInt();
        int AGEANIMAUX= ui->age_2->text().toInt();
        QString SEXEANIMAUX ;
        if (ui->femme_2->isChecked())
        {SEXEANIMAUX="femme"; }
        if (ui->homme_2->isChecked())
        { SEXEANIMAUX="homme";}
        QString ETATANIMAUX;
        if (ui->Blesse->isChecked())
        {ETATANIMAUX="Blesse"; }
        if (ui->Malade->isChecked())
        {ETATANIMAUX="Malade"; }
        if (ui->Bonne_2->isChecked())
        {ETATANIMAUX="Bonne";}
        QString CIN = ui->comboBox_cin_3->currentText();
        QString IMAGEANIMAUX= ui->chemin_5->text();//LABEL CHEMIN
        QString IDBA = ui->comboBox_idba->currentText();
        gestion_animaux P(IDANIMAUX,IDESPECE,AGEANIMAUX,SEXEANIMAUX,ETATANIMAUX,IMAGEANIMAUX,CIN,IDBA);
        bool test=tmpa.modifier_animaux(P);
        if(test)
        {
            ui->afficher_animaux->setModel(tmpa.afficher_animaux());//refresh
            inita();
            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();
                    sa.modifieranimalen();
                    ui->label_110->setText("Edit animal");
                }
                else
                {
                    sa.languageSelectedfr();
                    sa.modifieranimalfr();
                    ui->label_110->setText("Modifier animal");
                }

            }else {  sa.stop();}
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Modifier animaux"),
                                  QObject::tr("animaux non valide  !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
    else {
        QMessageBox msgBox;
        QPixmap pix("A:/integration/integration final/danger.png");

        msgBox.setText("Il faut ouvrir cadenas .");
        msgBox.setIconPixmap(pix);
        msgBox.exec();
    }
}
//afficher animal
void Menu::on_pushButton_107_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_animaux->setModel(tmpa.afficher_animaux());//refresh
    inita();
    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.afficheranimalen();
            ui->label_110->setText("List of animals");
        }
        else
        {
            sa.languageSelectedfr();
            sa.afficheranimalfr();
            ui->label_110->setText("Liste des animaux");
        }

    }else {  sa.stop();}

}
//afficher image
void Menu::on_pushButton_108_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    photo p;
    p.setchemin(ui->chemin_5->text());
    p.exec();
    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.afficherimageen();
            ui->label_57->setText("Show picture");
        }
        else
        {
            sa.languageSelectedfr();
            sa.afficherimagefr();
            ui->label_57->setText("Afficher image");
        }

    }else {  sa.stop();}
}
//trie id croissant
void Menu::on_radioButton_45_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_animaux->setModel(tmpa.afficher_idCroissant());//refresh
    // ui->label_8->setText("Tri ID");
}
//trie id decroissant
void Menu::on_radioButton_48_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_animaux->setModel(tmpa.afficher_idDecroissant());//refresh
    //ui->label_8->setText("Tri ID DESC");
}
//trie age croissant
void Menu::on_radioButton_46_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_animaux->setModel(tmpa.afficher_AgeCroissant());//refresh
    //ui->label_8->setText("Tri Croissant d'age");
}
//trie age decroisaant
void Menu::on_radioButton_47_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_animaux->setModel(tmpa.afficher_AgeDecroissant());//refresh
    //ui->label_8->setText("Tri Décroissant d'age");
}
//trie id espece animal croissant
void Menu::on_radioButton_43_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_animaux->setModel(tmpa.afficher_IdECroissant());//refresh
    //ui->label_8->setText("Tri Croissant par idE ");
}
//trie id espece animal decroissant
void Menu::on_radioButton_44_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_animaux->setModel(tmpa.afficher_IdEDecroissant());//refresh
    //ui->label_8->setText("Tri Decroissant par idE ");
}
//recherche animal
void Menu::on_recherche_5_textChanged(const QString &arg1)
{
    QString q = arg1;

    if (q=="")
    {
        ui->afficher_animaux->setModel(tmpa.afficher_animaux());//refresh
    }
    else {
        ui->afficher_animaux->setModel(tmpa.rechercher(q)) ;
        // ui->label_5->setText("Chercher");
    }
}
//creation pdf animal
int Menu::on_pushButton_115_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("A:\\integration\\integration final\\2\\mahrousplusplus\\Historique PDF\\Liste des Animaux.pdf");//badel i chemin win t7eb t7ot il fichier ya2melek creation
    QPainter painter;

    if (! painter.begin(&printer)) { // failed to open file
        qWarning("failed to open file, is it writable?");
        //return 1;
    }




    QSqlQuery   query ;
    qDebug() << query.prepare("select sysdate from dual  ");//hethi date mta3 systeme d9i9et eli 3melet create pdf (clic 3al bouton )
    if ( query.exec() )
    {

        QString S= QDate::currentDate().toString();
        painter.drawText(600,50, S);
        QPen penred(Qt::red);

        painter.setFont(QFont("Arial", 60));
        penred.setWidth(1);
        painter.setPen(penred);

        painter.drawText(200,500," La liste des ");
        painter.drawText(200,650,"  Animaux.");
        painter.setFont(QFont("Arial",30));
        painter.setPen(Qt::black);
        painter.drawText(50,100,"Bienvenu");
        painter.setPen(Qt::darkRed);
        painter.drawText(100,200,"Mahrous ++");
        painter.setPen(Qt::black);

    }

    QString idA,idE,Age,sexe, etat, url ,photo,cin,image;
    QSqlQuery   qry ;
    int i =50;
    int k=0;
    //badel i table w les attribues
    qDebug() << qry.prepare("select * from  ANIMAUX order by IDANIMAUX ");

    painter.drawPixmap(600,50,100,100,QPixmap::fromImage(QImage("A:/photo/logo.png")));//chemin mta3 il logo
    painter.drawText(400,800, image);


    if ( qry.exec() )
    {

        while(qry.next())
        {

            if ( k % 13 ==0)
            {   i=50;

                if (!printer.newPage())
                {

                    qWarning("failed");
                    return 1;
                }
                painter.setFont(QFont("Arial",10));
                QPen penblack(Qt::red);

                painter.setPen(penblack);

                painter.drawText (0,10,"idA");
                painter.drawText (40,10,"idE");
                painter.drawText (90,10,"Age");

                painter.drawText (150,10,"sexe");
                painter.drawText (210,10,"etat");
                painter.drawText (260,10,"url");
                painter.drawText (520,10,"photo");
                painter.drawText (650,10,"CIN");
                /*painter.drawText (590,10,"");
painter.drawText (650,10,"");*/
            }

            painter.setFont(QFont("Arial",10));
            QPen penblack(Qt::black);

            painter.setPen(penblack);
            int j=0;

            idA = qry.value(0).toString();
            painter.drawText(j*20,i, idA);
            j++;

            idE=qry.value(1).toString();
            painter.drawText(j*40,i, idE);
            j++;
            Age=qry.value(2).toString();
            painter.drawText(j*50,i,Age);
            j++;
            sexe=qry.value(3).toString();
            painter.drawText(j*49,i,sexe);
            j++;
            etat=qry.value(4).toString();
            painter.drawText(j*55,i,etat);
            j++;
            url=qry.value(5).toString();
            painter.drawText(j*56,i, url);
            j++;

            /*image=qry.value(7).toString();
            painter.drawText(j*54,i, image);*/

            QImage chemin(url);
            painter.drawPixmap(j*88,i,50,50,QPixmap::fromImage(QImage(chemin)));
            j++;
            cin=qry.value(6).toString();
            painter.drawText(j*90,i, cin);
            j++;
            /*idf=qry.value(8).toString();
                        painter.drawText(j*83,i, idf);*/

            i+=80;

            k++;



        }
    }
    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.creationpdfen();
            // ui->label_22->setText("PDF creation");
        }
        else
        {
            sa.languageSelectedfr();
            sa.creationpdffr();
            // ui->label_22->setText("Création PDF");
        }

    }else {  sa.stop();}


    painter.end();
}
//stat animaux
void Menu::on_pushButton_110_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    stata=new Stat_animaux (this);
    stata->show();
    // ui->label_8->setText("Statistique Animaux ");
}
//Besoin Plante
//photo besoin plante
void Menu::on_pushButton_116_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->stackedWidget->setCurrentIndex(11);
    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();//fixe
            sa.besoinplanteen();
        }
        else
        {

            sa.languageSelectedfr();//fixe
            sa.besoinplantefr();
        }

    }else {  sa.stop();}
}
//bouton besoin plante
void Menu::on_pushButton_117_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->stackedWidget->setCurrentIndex(11);

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();//fixe
            sa.besoinplanteen();
        }
        else
        {

            sa.languageSelectedfr();//fixe
            sa.besoinplantefr();
        }

    }else {  sa.stop();}
}
//ajouter besoin plante
void Menu::on_pushButton_120_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    if (securite==0)
    {
        QString idB,np;
        int ep;
        idB=ui->cx_idbp->text();
        np=ui->cx_nutp->text();


        gestion_besoin_plante B(idB,ep,np);

        bool test=B.ajouter_besoin_plante();
        if(test)
        {
            QFile file("A:\\integration\\integration final\\2\\mahrousplusplus\\Historique\\HistoriqueBesoinPlantes.txt");
            if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
                return;
            QTextStream cout(&file);
            QString message2="\nBesoin Plante a été ajoutée sous:\nIdBP:"+idB+"\nNutrition:"+np+"\neau:"+ep ;
            cout << message2;
            ui->afficher_besoin_palnte->setModel(tmpbp.afficher_besoin_plante());//refresh

            initbp();

            if(speek==1)
            {
                if (lng=="en")
                {
                    sa.languageSelecteden();//fixe
                    sa.ajouterbesoinplanteen();
                }
                else
                {
                    sa.languageSelectedfr();//fixe
                    sa.ajouterbesoinplantefr();
                }

            }else {  sa.stop();}

        }
        else{
            QMessageBox::critical(nullptr, QObject::tr("Ajouter Matériel"),
                                  QObject::tr("Matériel existe deja  !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
    else
    {

        QMessageBox msgBox;
        QPixmap pix("A:/integration/integration final/danger.png");

        msgBox.setText("Il faut ouvrir cadenas .");
        msgBox.setIconPixmap(pix);
        msgBox.exec();
    }
}
//afficher bsoin plante
void Menu::on_pushButton_124_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_besoin_palnte->setModel(tmpbp.afficher_besoin_plante());
    // ui->label_5->setText("Afficher Besoin Plante");
    initbp();
    // init ();
}
//cliked besoin plante
void Menu::on_afficher_besoin_palnte_activated(const QModelIndex &index)
{
    QString val=ui->afficher_besoin_palnte->model()->data(index).toString();
    QSqlQuery qry ;

    qry=tmpbp.tableclicked(val);
    if (qry.exec())
    {
        while (qry.next())
        {

            ui->cx_idbp->setDisabled(1);
            ui->cx_idbp->setText(qry.value(0).toString());
            ui->Eau->setValue(qry.value(1).toInt());
            ui->cx_nutp->setText(qry.value(2).toString());
            ui->label_5->setText("Besoin Plante Selectionée");
        }
    }
}
//supprimer besoin plante
void Menu::on_pushButton_122_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    if (securite==0)
    {
        QString idB = ui->cx_idbp->text();

        bool test=tmpbp.supprimer_besoin_plante(idB);
        if(test)
        {    ui->afficher_besoin_palnte->setModel(tmpbp.afficher_besoin_plante());

            ui->label_5->setText("Supprimer Besoin Plante");
            ui->cx_idbp->setEnabled(1);
            //ss.speak();//speak supprimer
            initbp();
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer Catégorie"),
                                  QObject::tr("verifier l'id  !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {

        QMessageBox msgBox;
        QPixmap pix("A:/integration/integration final/danger.png");

        msgBox.setText("Il faut ouvrir cadenas .");
        msgBox.setIconPixmap(pix);
        msgBox.exec();
    }
}
//modifier besoin plante
void Menu::on_pushButton_123_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    if (securite==0)
    {
        QString idB,np;
        int ep;
        idB=ui->cx_idbp->text();
        np=ui->cx_nutp->text();

        ep=ui->Eau->text().toInt();
        gestion_besoin_plante B(idB,ep,np);

        bool test=tmpbp.modifier_besoin_plante(B);
        if(test)
        {

            ui->afficher_besoin_palnte->setModel(tmpbp.afficher_besoin_plante());//refresh


            initbp();
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Modifier Matériel"),
                                  QObject::tr("Matériel non valide  !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
    else
    {

        QMessageBox msgBox;
        QPixmap pix("A:/integration/integration final/danger.png");

        msgBox.setText("Il faut ouvrir cadenas .");
        msgBox.setIconPixmap(pix);
        msgBox.exec();
    }
}
//trie id croissant besoin plante
void Menu::on_radioButton_51_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_besoin_palnte->setModel(tmpbp.afficher_idCroissant());
    // ui->label_5->setText("Tri Croissant par idBP ");
}
//trie id decroissant besoin plante
void Menu::on_radioButton_52_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_besoin_palnte->setModel(tmpbp.afficher_idDecroissant());
    // ui->label_5->setText("Tri Decroissant par idBP ");
}
//Tri Croissant par Quantite de Nutrition
void Menu::on_radioButton_50_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_besoin_palnte->setModel(tmpbp.afficher_NutCroissant());
    // ui->label_5->setText("Tri Croissant par Quantite de Nutrition ");
}
//Tri Decroissant par Quantite de Nutrition
void Menu::on_radioButton_54_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_besoin_palnte->setModel(tmpbp.afficher_NutDecroissant());
    // ui->label_5->setText("Tri Decroissant par Quantite de Nutrition ");
}
//Tri Croissant par Quantite D'eau
void Menu::on_radioButton_49_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_besoin_palnte->setModel(tmpbp.afficher_EauCroissant());
    //ui->label_5->setText("Tri Croissant par Quantite D'eau ");
}
//Tri Decroissant par Quantite D'eau
void Menu::on_radioButton_53_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_besoin_palnte->setModel(tmpbp.afficher_EauDecroissant());
    //ui->label_5->setText("Tri Decroissant par Quantite D'eau ");
}
//recherche besoin plante
void Menu::on_recherche_6_textChanged(const QString &arg1)
{
    QString q = arg1;

    if (q=="")
    {
        ui->afficher_besoin_palnte->setModel(tmpbp.afficher_besoin_plante());//refresh
    }
    else {
        ui->afficher_besoin_palnte->setModel(tmpbp.rechercher(q)) ;
    }
}
//stat besoin plante
void Menu::on_pushButton_119_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    sbp =new stat_besoinplantes (this);
    sbp->show();
}
//production plante
//bouton production plante
void Menu::on_pushButton_126_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->stackedWidget->setCurrentIndex(12);
}
//bouton photo production plante
void Menu::on_pushButton_127_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->stackedWidget->setCurrentIndex(12);
}
//ajouter production plante
void Menu::on_pushButton_131_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    if(securite==0)
    {
        int IDPRODUCTIONPLANTE   = ui->cx_pp->text().toInt();
        QString  IDCATEGORIEPLANTE = ui->comboBox_CP->currentText();

        QString PRODUITPLANTE= ui->cx_produitp->text();
        int PRIXPRODUITPLANTE = ui->cx_prix_2->text().toInt();

        gestion_produit_plante PP(IDPRODUCTIONPLANTE,IDCATEGORIEPLANTE,PRODUITPLANTE,PRIXPRODUITPLANTE);

        bool test=PP.ajouter_produit_plante();
        if(test)
        {   //ui->label_8->setText("Ajouter Matériel");
            QFile file("A:\\integration\\integration final\\2\\mahrousplusplus\\Historique\\HistoriqueProduitPlantes.txt");
            if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
                return;
            QString res1= QString::number(IDPRODUCTIONPLANTE);
            QString res2= QString::number(PRIXPRODUITPLANTE);
            //QString res3= QString::number(PRIXPRODUITPLANTE);

            QTextStream cout(&file);
            QString message2="\n L'historique des Personnels à ajouter :"+res1+" "+IDCATEGORIEPLANTE+" "+PRODUITPLANTE+" "+PRIXPRODUITPLANTE ;
            cout << message2;


            initpp();

            ui->afficher_produitplante->setModel(tmppp.afficher_produit_plante());
        }
        else{
            QMessageBox::critical(nullptr, QObject::tr("Ajouter Matériel"),
                                  QObject::tr("Matériel existe deja  !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
    else
    {
        QMessageBox msgBox;
        QPixmap pix("A:/integration/integration final/danger.png");

        msgBox.setText("Il faut ouvrir cadenas .");
        msgBox.setIconPixmap(pix);
        msgBox.exec();
    }
}
//afficher produit plnate
void Menu::on_pushButton_130_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_produitplante->setModel(tmppp.afficher_produit_plante());//refresh
}
//clicked produit plnate
void Menu::on_afficher_produitplante_activated(const QModelIndex &index)
{
    QString val=ui->afficher_produitplante->model()->data(index).toString();
    QSqlQuery qry ;

    qry.prepare("Select * from PRODUCTIONPLANTE where IDPRODUCTIONPLANTE='"+val+"' ");

    if (qry.exec())
    {
        while (qry.next())
        {

            ui->cx_pp->setDisabled(1);
            ui->cx_pp->setText(qry.value(0).toString());
            ui->comboBox_CP->setCurrentText(qry.value(1).toString());
            ui->cx_produitp->setText(qry.value(2).toString());
            ui->cx_prix_2->setText(qry.value(3).toString());

        }
    }
}
//supprimer produit plante
void Menu::on_pushButton_132_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    if(securite==0)
    {
        int idP = ui->cx_pp->text().toInt();

        bool test=tmppp.supprimer_produit_plante(idP);
        if(test)
        {    ui->afficher_produitplante->setModel(tmppp.afficher_produit_plante());//refresh

            initpp();
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer productionanimaux"),
                                  QObject::tr("verifier le id  !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox msgBox;
        QPixmap pix("A:/integration/integration final/danger.png");

        msgBox.setText("Il faut ouvrir cadenas .");
        msgBox.setIconPixmap(pix);
        msgBox.exec();
    }
}
//modifier produit plante
void Menu::on_pushButton_128_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    if (securite ==0)
    {
        int IDPRODUCTIONPLANTE   = ui->cx_pp->text().toInt();
        QString  IDCATEGORIEPLANTE = ui->comboBox_CP->currentText();

        QString PRODUITPLANTE= ui->cx_produitp->text();
        int PRIXPRODUITPLANTE = ui->cx_prix_2->text().toInt();

        gestion_produit_plante P(IDPRODUCTIONPLANTE,IDCATEGORIEPLANTE,PRODUITPLANTE,PRIXPRODUITPLANTE);
        bool test=tmppp.modifier_produit_palnte(P);
        if(test)
        {

            ui->afficher_produitplante->setModel(tmppp.afficher_produit_plante());//refresh

            initpp();
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Modifier animaux"),
                                  QObject::tr("animaux non valide  !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
    else
    {
        QMessageBox msgBox;
        QPixmap pix("A:/integration/integration final/danger.png");

        msgBox.setText("Il faut ouvrir cadenas .");
        msgBox.setIconPixmap(pix);
        msgBox.exec();
    }
}
//trie prix croissant
void Menu::on_radioButton_56_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_produitplante->setModel(tmppp.afficher_PrixCroissant());//refresh
}
//trie prix decroissant
void Menu::on_radioButton_58_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_produitplante->setModel(tmppp.afficher_PrixDecroissant());//refresh
}
//trie id croissant
void Menu::on_radioButton_57_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_produitplante->setModel(tmppp.afficher_idCroissant());//refresh
}
//trie id decroissant
void Menu::on_radioButton_55_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->afficher_produitplante->setModel(tmppp.afficher_idDecroissant());//refresh
}
//recherche produitnplante
void Menu::on_Recherche_2_textChanged(const QString &arg1)
{
    QString q = arg1;
    if (q=="")
    {
        ui->afficher_produitplante->setModel(tmppp.afficher_produit_plante()) ;

    }
    else {
        ui->afficher_produitplante->setModel(tmppp.rechercher(q)) ;

    }
}
//stat producttion plante
void Menu::on_pushButton_129_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    spp=new stat_productionplante (this);
    spp->show();
}
//pdf besoin plante
int Menu::on_pushButton_134_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("A:\\integration\\integration final\\2\\mahrousplusplus\\Historique PDF\\Besoin Plante.pdf");//badel i chemin win t7eb t7ot il fichier ya2melek creation
    QPainter painter;

    if (! painter.begin(&printer)) { // failed to open file
        qWarning("failed to open file, is it writable?");
        //return 1;
    }




    QSqlQuery   query ;
    qDebug() << query.prepare("select sysdate from dual  ");//hethi date mta3 systeme d9i9et eli 3melet create pdf (clic 3al bouton )
    if ( query.exec() )
    {

        QString S= QDate::currentDate().toString();
        painter.drawText(600,50, S);
        QPen penred(Qt::red);

        painter.setFont(QFont("Arial", 60));
        penred.setWidth(1);
        painter.setPen(penred);

        painter.drawText(200,500," La liste des ");
        painter.drawText(100,650,"Besoins Plantes.");
        painter.setFont(QFont("Arial",30));
        painter.setPen(Qt::black);
        painter.drawText(50,100,"Bienvenu");
        painter.setPen(Qt::darkRed);
        painter.drawText(100,200,"Mahrous ++");
        painter.setPen(Qt::black);

    }

    QString idbp,eau,nutrition, image ;
    QSqlQuery   qry ;
    int i =50;
    int k=0;
    //badel i table w les attribues
    qDebug() << qry.prepare("select * from BESOINSPLANTES order by  IDBESOINSPLANTE ");

    painter.drawPixmap(600,50,100,100,QPixmap::fromImage(QImage("A:/photo/logo.png")));//chemin mta3 il logo
    painter.drawText(400,800, image);


    if ( qry.exec() )
    {

        while(qry.next())
        {

            if ( k % 13 ==0)
            {   i=50;

                if (!printer.newPage())
                {

                    qWarning("failed");
                    return 1;
                }
                painter.setFont(QFont("Arial",10));
                QPen penblack(Qt::red);

                painter.setPen(penblack);
                painter.drawText (0,10,"idb");
                painter.drawText (40,10,"eau");
                painter.drawText (90,10,"nutrition");

            }

            painter.setFont(QFont("Arial",10));
            QPen penblack(Qt::black);

            painter.setPen(penblack);
            int j=0;

            idbp = qry.value(0).toString();
            painter.drawText(j*20,i, idbp);
            j++;

            eau=qry.value(1).toString();
            painter.drawText(j*40,i, eau);
            j++;
            nutrition=qry.value(2).toString();
            painter.drawText(j*50,i, nutrition);
            j++;

            i+=80;

            k++;



        }
    }


    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.creationpdfen();
            // ui->label_22->setText("PDF creation");
        }
        else
        {
            sa.languageSelectedfr();
            sa.creationpdffr();
            //ui->label_22->setText("Création PDF");
        }

    }else {  sa.stop();}
    painter.end();
}
//pdf production plante
int Menu::on_pushButton_135_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("A:\\integration\\integration final\\2\\mahrousplusplus\\Historique PDF\\Production Plante.pdf");//badel i chemin win t7eb t7ot il fichier ya2melek creation
    QPainter painter;

    if (! painter.begin(&printer)) { // failed to open file
        qWarning("failed to open file, is it writable?");
        //return 1;
    }




    QSqlQuery   query ;
    qDebug() << query.prepare("select sysdate from dual  ");//hethi date mta3 systeme d9i9et eli 3melet create pdf (clic 3al bouton )
    if ( query.exec() )
    {

        QString S= QDate::currentDate().toString();
        painter.drawText(600,50, S);
        QPen penred(Qt::red);

        painter.setFont(QFont("Arial", 60));
        penred.setWidth(1);
        painter.setPen(penred);

        painter.drawText(200,500," La liste des ");
        painter.drawText(100,650,"Production Plante.");
        painter.setFont(QFont("Arial",30));
        painter.setPen(Qt::black);
        painter.drawText(50,100,"Bienvenu");
        painter.setPen(Qt::darkRed);
        painter.drawText(100,200,"Mahrous ++");
        painter.setPen(Qt::black);

    }

    QString idPP,idCP,Production,prix , image ;
    QSqlQuery   qry ;
    int i =50;
    int k=0;
    //badel i table w les attribues
    qDebug() << qry.prepare("select * from PRODUCTIONPLANTE order by IDPRODUCTIONPLANTE ");

    painter.drawPixmap(600,50,100,100,QPixmap::fromImage(QImage("A:/photo/logo.png")));//chemin mta3 il logo
    painter.drawText(400,800, image);


    if ( qry.exec() )
    {

        while(qry.next())
        {

            if ( k % 13 ==0)
            {   i=50;

                if (!printer.newPage())
                {

                    qWarning("failed");
                    return 1;
                }
                painter.setFont(QFont("Arial",10));
                QPen penblack(Qt::red);

                painter.setPen(penblack);
                painter.drawText (0,10,"idPP");
                painter.drawText (40,10,"idCP");
                painter.drawText (90,10,"Production");

                painter.drawText (200,10,"Prix");

            }

            painter.setFont(QFont("Arial",10));
            QPen penblack(Qt::black);

            painter.setPen(penblack);
            int j=0;

            idPP = qry.value(0).toString();
            painter.drawText(j*20,i, idPP);
            j++;

            idCP=qry.value(1).toString();
            painter.drawText(j*40,i, idCP);
            j++;
            Production=qry.value(2).toString();
            painter.drawText(j*50,i, Production);
            j++;
            prix=qry.value(3).toString();
            painter.drawText(j*67,i, prix);
            i+=80;

            k++;



        }
    }


    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.creationpdfen();
            // ui->label_22->setText("PDF creation");
        }
        else
        {
            sa.languageSelectedfr();
            sa.creationpdffr();
            //ui->label_22->setText("Création PDF");
        }

    }else {  sa.stop();}
    painter.end();
}
//login vers menu
void Menu::on_pushButton_140_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    qDebug () << ui->cx_nomuser->text();
    qDebug() << ui->cx_password->text();
    if (sy.login(ui->cx_nomuser->text(),ui->cx_password->text())=="admin")
    {
        initmenu();
        ui->stackedWidget->setCurrentIndex(0);
    }
    else
    {
        if((sy.login(ui->cx_nomuser->text(),ui->cx_password->text())=="rh"))
        {
            ui->stackedWidget->setCurrentIndex(0);
            initmenu();
            ui->pushButton->setDisabled(1);
            ui->pushButton_16->setDisabled(1);
            ui->pushButton_116->setDisabled(1);
            ui->pushButton_117->setDisabled(1);
            ui->pushButton_68->setDisabled(1);
            ui->pushButton_71->setDisabled(1);
            ui->pushButton_5->setDisabled(1);
            ui->pushButton_14->setDisabled(1);
            ui->pushButton_12->setDisabled(1);
            ui->pushButton_17->setDisabled(1);
            ui->pushButton_6->setDisabled(1);
            ui->pushButton_16->setDisabled(1);
            ui->pushButton_44->setDisabled(1);
            ui->pushButton_39->setDisabled(1);
            ui->pushButton_97->setDisabled(1);
            ui->pushButton_94->setDisabled(1);
            ui->pushButton_69->setDisabled(1);
            ui->pushButton_70->setDisabled(1);
            ui->pushButton_127->setDisabled(1);
            ui->pushButton_49->setDisabled(1);
            ui->pushButton_50->setDisabled(1);
            ui->pushButton_96->setDisabled(1);
            ui->pushButton_95->setDisabled(1);
            ui->pushButton_126->setDisabled(1);
            ui->pushButton_15->setDisabled(1);

        }
        else
        {
            if (sy.login(ui->cx_nomuser->text(),ui->cx_password->text())=="rm")
            {
                ui->stackedWidget->setCurrentIndex(0);
                initmenu();
                ui->pushButton_116->setDisabled(1);
                ui->pushButton_117->setDisabled(1);
                ui->pushButton_68->setDisabled(1);
                ui->pushButton_71->setDisabled(1);
                ui->pushButton_70->setDisabled(1);
                ui->pushButton_69->setDisabled(1);
                ui->pushButton_94->setDisabled(1);
                ui->pushButton_97->setDisabled(1);
                ui->pushButton_39->setDisabled(1);
                ui->pushButton_44->setDisabled(1);
                ui->pushButton_126->setDisabled(1);
                ui->pushButton_127->setDisabled(1);
                ui->pushButton_136->setDisabled(1);
                ui->pushButton_31->setDisabled(1);
                ui->pushButton_49->setDisabled(1);
                ui->pushButton_50->setDisabled(1);
                ui->pushButton_32->setDisabled(1);
                ui->pushButton_137->setDisabled(1);
                ui->pushButton_96->setDisabled(1);
                ui->pushButton_95->setDisabled(1);
            }
            else
            {
                if (sy.login(ui->cx_nomuser->text(),ui->cx_password->text())=="ra")
                {
                    ui->stackedWidget->setCurrentIndex(0);
                    initmenu();
                    ui->pushButton->setDisabled(1);
                    ui->pushButton_16->setDisabled(1);
                    ui->pushButton_116->setDisabled(1);
                    ui->pushButton_117->setDisabled(1);
                    ui->pushButton_15->setDisabled(1);
                    ui->pushButton_6->setDisabled(1);
                    ui->pushButton_17->setDisabled(1);
                    ui->pushButton_12->setDisabled(1);
                    ui->pushButton_14->setDisabled(1);
                    ui->pushButton_5->setDisabled(1);
                    ui->pushButton_39->setDisabled(1);
                    ui->pushButton_44->setDisabled(1);
                    ui->pushButton_127->setDisabled(1);
                    ui->pushButton_126->setDisabled(1);
                    ui->pushButton_136->setDisabled(1);
                    ui->pushButton_31->setDisabled(1);
                    ui->pushButton_137->setDisabled(1);
                    ui->pushButton_32->setDisabled(1);
                    ui->pushButton_50->setDisabled(1);
                    ui->pushButton_49->setDisabled(1);
                }else {
                    if (sy.login(ui->cx_nomuser->text(),ui->cx_password->text())=="rp")
                    {
                        ui->stackedWidget->setCurrentIndex(0);
                        initmenu();
                        ui->pushButton->setDisabled(1);
                        ui->pushButton_16->setDisabled(1);
                        ui->pushButton_68->setDisabled(1);
                        ui->pushButton_71->setDisabled(1);
                        ui->pushButton_15->setDisabled(1);
                        ui->pushButton_6->setDisabled(1);
                        ui->pushButton_17->setDisabled(1);
                        ui->pushButton_12->setDisabled(1);
                        ui->pushButton_14->setDisabled(1);
                        ui->pushButton_5->setDisabled(1);
                        ui->pushButton_97->setDisabled(1);
                        ui->pushButton_94->setDisabled(1);
                        ui->pushButton_95->setDisabled(1);
                        ui->pushButton_96->setDisabled(1);
                        ui->pushButton_137->setDisabled(1);
                        ui->pushButton_32->setDisabled(1);
                        ui->pushButton_136->setDisabled(1);
                        ui->pushButton_31->setDisabled(1);
                        ui->pushButton_69->setDisabled(1);
                        ui->pushButton_70->setDisabled(1);


                    }
                }
            }

        }
    }


    /* qDebug () << sy.login("12345678","1234");
    ui->stackedWidget->setCurrentIndex(0);*/

}
//parametre
//securite
void Menu::on_pushButton_155_clicked()
{
    securite =0;
    ui->pushButton_155->hide();
    ui->pushButton_154->show();
}
//securite
void Menu::on_pushButton_154_clicked()
{
    securite =1;
    ui->pushButton_155->show();
    ui->pushButton_154->hide();
}
//parametre login vers parametre
void Menu::on_pushButton_139_clicked()
{ if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->stackedWidget->setCurrentIndex(14);
}
//load music
void Menu::on_pushButton_141_clicked()
{
    //Load the file
    player->setMedia(QUrl::fromLocalFile("A:\\integration\\integration final\\2\\mahrousplusplus\\Farma.mp3"));
    player->play();
    qDebug() << player->errorString();
}
//stop music
void Menu::on_pushButton_142_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    player->stop();
}
//sloder progresse
void Menu::on_sliderProgresse_sliderMoved(int position)
{
    player->setPosition(position);
}
//slider volume
void Menu::on_sliderVolume_sliderMoved(int position)
{
    player->setVolume(position);
    if (position == 0)
    {
        QPixmap pix("C:/Users/ASUS/Downloads/mute (1).png");
        int w =ui->volume->width();
        int h =ui->volume->height();
        ui->volume->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
    else {
        QPixmap pix("C:/Users/ASUS/Downloads/speaker.png");
        int w =ui->volume->width();
        int h =ui->volume->height();
        ui->volume->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
}
//position changed slider progresse
void Menu::on_positionChanged(qint64 position)
{
    ui->sliderProgresse->setValue(position);
}
//position changed slider progresse
void Menu::on_durationChanged(qint64 position)
{
    ui->sliderProgresse->setMaximum(position);
}
//click
void Menu::on_pushButton_143_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    cl=0;
    ui->pushButton_143->hide();
    ui->pushButton_144->show();
}
//click
void Menu::on_pushButton_144_clicked()
{
    cl=1;
    ui->pushButton_144->hide();
    ui->pushButton_143->show();
}
//parametre vers login
void Menu::on_pushButton_145_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->stackedWidget->setCurrentIndex(13);
}
//menu vers login
void Menu::on_pushButton_146_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->stackedWidget->setCurrentIndex(13);
}
//english selected
void Menu::on_pushButton_148_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}


    lng="en";
    if(speek==1)
    {
        sa.languageSelecteden();
        sa.english();
    }else {  sa.stop();}
    //interface parametre
    ui->label_137->setText("Music :");
    ui->label_137->setStyleSheet("QLabel{color:#0000ff;}");
    ui->label_134->setText("Progresses :");
    ui->pushButton_141->setText("Start");
    ui->label_139->setText("Language :");
    ui->label_139->setStyleSheet("QLabel{color:#0000ff;}");
    ui->pushButton_147->setText("French");
    ui->label_159->setText("Speek :");
    ui->label_159->setStyleSheet("QLabel{color:#0000ff;}");
    ui->label_160->setText("Security :");
    ui->label_160->setStyleSheet("QLabel{color:#0000ff;}");
    //bouton
    ui->pushButton->setText("Material category");
    ui->pushButton_24->setText("Historical");
    ui->pushButton_5->setText("Supplier");
    ui->pushButton_6->setText("Materials");
    ui->pushButton_12->setText("Assignment");
    ui->pushButton_39->setText("Plant category");
    ui->pushButton_49->setText("Plant");
    ui->pushButton_70->setText("Production animal");
    ui->pushButton_117->setText("Nedd Plant");
    ui->pushButton_32->setText("Personnel");
    ui->pushButton_94->setText("Animal species");
    ui->pushButton_96->setText("Animals");
    //interface Categorie Materiel
    ui->label->setText("Id category:");
    ui->label_2->setText("Name category :");
    ui->label_3->setText("No Action ...");
    ui->AfficherCategorieMateriel->setText("Show category");
    ui->ModifierCategorieMaeriel->setText("Edit category");
    ui->SupprimerCategorieMateriel->setText("Remove category");
    ui->AjouterCategorieMateriel->setText("Add category");
    ui->label_5->setText("Sort by :");
    ui->label_5->setStyleSheet("QLabel{color:#0000ff;}");
    ui->trieridcroi->setText("Id category ↑ ");
    ui->trieriddecroi->setText("Id category ↓");
    ui->label_197->setText("Research :");
    ui->label_197->setStyleSheet("QLabel{color:#0000ff;}");
    //interface affectation
    ui->label_13->setText("Id assignment");
    ui->label_12->setText("CIN");
    ui->label_7->setText("Id material");
    ui->label_8->setText("No Action ...");
    ui->pushButton_3->setText("Remove material");
    ui->pushButton_2->setText("Show material");
    ui->pushButton_4->setText("Edit material");
    ui->pushButton_8->setText("Add material");
    ui->label_9->setText("Sort by :");
    ui->label_9->setStyleSheet("QLabel{color:#0000ff;}");
    ui->radioButton->setText("Id assignment ↑");
    ui->radioButton_3->setText("Id assignment ↓");
    ui->radioButton_2->setText("Id material ↑");
    ui->radioButton_4->setText("Id material ↓");
    ui->label_198->setText("Research :");
    ui->label_198->setStyleSheet("QLabel{color:#0000ff;}");
    //interface materiel
    ui->label_28->setText("Id material :");
    ui->label_18->setText("Name material :");
    ui->label_17->setText("Mark:");
    ui->label_26->setText("Stock :");
    ui->label_25->setText("Price :");
    ui->label_19->setText("Description :");
    ui->label_29->setText("Id category:");
    ui->label_16->setText("Id supplier:");
    ui->label_27->setText("Picture :");
    ui->label_22->setText("No Action ...");
    ui->pushButton_25->setText("Add picture");
    ui->pushButton_11->setText("Edit picture");
    ui->pushButton_23->setText("Show picture");
    ui->pushButton_22->setText("Add material");
    ui->pushButton_28->setText("Edit material");
    ui->pushButton_27->setText("Remove material");
    ui->label_23->setText("Sort by :");
    ui->label_23->setStyleSheet("QLabel{color:#0000ff;}");
    ui->radioButton_6->setText("Stock ↑");
    ui->radioButton_8->setText("Stock ↓");
    ui->radioButton_7->setText("Price ↑");
    ui->radioButton_11->setText("Price ↓");
    ui->label_184->setText("Research :");
    ui->label_184->setStyleSheet("QLabel{color:#0000ff;}");
    //interface fournisseur
    ui->label_40->setText("Id supplier:");
    ui->label_44->setText("Last name :");
    ui->label_34->setText("First name :");
    ui->label_33->setText("Phone number :");
    ui->label_32->setText("Age :");
    ui->label_43->setText("Sex:");
    ui->label_39->setText("Mail supplier");
    ui->label_31->setText("No Action ...");
    ui->pushButton_41->setText("Add supplier");
    ui->pushButton_34->setText("Edit supplier");
    ui->pushButton_33->setText("Show supplier");
    ui->pushButton_37->setText("Remove supplier");
    ui->femme->setText("Women");
    ui->homme->setText("Man");
    ui->label_38->setText("Sort by :");
    ui->label_38->setStyleSheet("QLabel{color:#0000ff;}");
    ui->radioButton_13->setText("Name:A-Z");
    ui->radioButton_17->setText("Name:Z-A");
    ui->radioButton_16->setText("Age ↑");
    ui->radioButton_18->setText("Age ↓");
    ui->label_203->setText("Research :");
    ui->label_203->setStyleSheet("QLabel{color:#0000ff;}");
    //categorie plante
    ui->label_46->setText("Id plant category:");
    ui->label_47->setText("Name plant category:");
    ui->label_48->setText("No Action ...");
    ui->pushButton_53->setText("Show plant category");
    ui->pushButton_51->setText("Remove plant category");
    ui->pushButton_55->setText("Edit plant category");
    ui->pushButton_54->setText("Add plant category");
    ui->label_49->setText("Sort by :");
    ui->radioButton_22->setText("Id plant category ↑");
    ui->radioButton_19->setText("Id plant category ↓");
    ui->radioButton_20->setText("Name:A-Z");
    ui->radioButton_21->setText("Name:Z-A");
    //plante
    ui->label_56->setText("Id plant :");
    ui->label_53->setText("Sector :");
    ui->label_60->setText("Quantity :");
    ui->label_55->setText("State :");
    ui->Mauvaise->setText("Bad");
    ui->Bonne->setText("Good");
    ui->label_64->setText("Id plant category :");
    ui->label_63->setText("CIN");
    ui->label_59->setText("Id need plant :");
    ui->label_54->setText("Picture :");
    ui->label_57->setText("No Action ...");
    ui->pushButton_64->setText("Edit picture");
    ui->pushButton_61->setText("Show picture");
    ui->pushButton_59->setText("Add picture");
    ui->pushButton_66->setText("Edit plant");
    ui->pushButton_63->setText("Remove plant");
    ui->pushButton_67->setText("Add plant");
    ui->pushButton_60->setText("Show plant");
    ui->radioButton_27->setText("Id plant ↑");
    ui->radioButton_26->setText("Id plant ↓");
    ui->radioButton_28->setText("State:A-Z");
    ui->radioButton_24->setText("State:Z-A");
    ui->radioButton_25->setText("Quantity ↑");
    ui->radioButton_23->setText("Quantity ↓");
    ui->label_65->setText("Sort by :");
    //production animal
    //besoin animal(bouton)
    //animal
    ui->label_104->setText("ID Animal :");
    ui->label_105->setText("Age Animal :");
    ui->label_103->setText("Sex Animal :");
    ui->femme_2->setText("Women");
    ui->homme_2->setText("Man");
    ui->label_111->setText("State :");
    ui->Blesse->setText("Injured");
    ui->Malade->setText("Sick");
    ui->Bonne->setText("Good");
    ui->label_113->setText("Id Species :");
    ui->label_108->setText("Id Need :");
    ui->label_100->setText("Picture :");
    ui->label_110->setText("No Action ...");
    ui->pushButton_111->setText("Show picture");
    ui->pushButton_113->setText("Edit picture");
    ui->pushButton_108->setText("Show picture");
    ui->label_102->setText("Sort by :");
    ui->label_102->setStyleSheet("QLabel{color:#0000ff;}");
    ui->radioButton_45->setText("Id Animal ↑");
    ui->radioButton_48->setText("Id Animal ↓");
    ui->radioButton_46->setText("Age ↑");
    ui->radioButton_47->setText("Age ↓");
    ui->radioButton_43->setText("Id Species ↑");
    ui->radioButton_44->setText("Id Species ↓");
    ui->label_214->setText("Research  :");
    ui->label_214->setStyleSheet("QLabel{color:#0000ff;}");
    ui->pushButton_112->setText("Add animal");
    ui->pushButton_114->setText("Edit animal");
    ui->pushButton_106->setText("Remove animal");
    //espece animal(bouton)
    ui->label_94->setText("Id species :");
    ui->label_92->setText("Name species :");
    ui->label_93->setText("No Action ...");
    ui->pushButton_102->setText("Show species");
    ui->pushButton_99->setText("Remove species");
    ui->pushButton_100->setText("Edit species");
    ui->pushButton_101->setText("Add species");
    ui->label_91->setText("Sort by :");
    ui->label_91->setStyleSheet("QLabel{color:#0000ff;}");
    ui->label_213->setText("Research :");
    ui->label_213->setStyleSheet("QLabel{color:#0000ff;}");
    //besoin plante
    ui->label_116->setText("Id nedd plant");
    //interface personnel

}
//francias selected
void Menu::on_pushButton_147_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}

    lng="fr";
    if(speek==1)
    {
        sa.languageSelectedfr();
        sa.francais();
    }else {  sa.stop();}
    //interface parametre
    ui->pushButton_147->setText("Français");
    ui->label_137->setText("Musique :");
    ui->label_137->setStyleSheet("QLabel{color:#0000ff;}");
    ui->label_134->setText("Progresse :");
    ui->pushButton_141->setText("Début");
    ui->label_139->setText("Langue :");
    ui->label_139->setStyleSheet("QLabel{color:#0000ff;}");
    ui->label_159->setText("Parole :");
    ui->label_159->setStyleSheet("QLabel{color:#0000ff;}");
    ui->label_160->setText("Sécurité :");
    ui->label_160->setStyleSheet("QLabel{color:#0000ff;}");
    //bouton
    ui->pushButton->setText("Catégorie Materiel");
    ui->pushButton_24->setText("Historique");
    ui->pushButton_5->setText("Frounisseur");
    ui->pushButton_6->setText("Materiel");
    ui->pushButton_12->setText("Affectation");
    ui->pushButton_39->setText("Catégorie Plante");
    ui->pushButton_49->setText("Plante");
    ui->pushButton_117->setText("Besoin Plante");
    ui->pushButton_94->setText("Espéce Animal");
    ui->pushButton_96->setText("Animaux");
    //interface Categorie Materiel
    ui->label->setText("Id catégorie:");
    ui->label_2->setText("Nom catégorie :");
    ui->label_3->setText("Pas d'action ...");
    ui->AfficherCategorieMateriel->setText("Afficher catégories");
    ui->ModifierCategorieMaeriel->setText("Modifier catégorie");
    ui->SupprimerCategorieMateriel->setText("Supprimer catégorie");
    ui->AjouterCategorieMateriel->setText("Ajouter catégorie");
    ui->label_5->setText("Trier selon : ");
    ui->label_5->setStyleSheet("QLabel{color:#0000ff;}");
    ui->trieridcroi->setText("ID Catégorie ↑ ");
    ui->trieriddecroi->setText("ID Catégorie ↓");
    ui->label_197->setText("Recherche :");
    ui->label_197->setStyleSheet("QLabel{color:#0000ff;}");
    //interface affectation
    ui->label_13->setText("Id affectation");
    ui->label_12->setText("CIN");
    ui->label_7->setText("Id matériel");
    ui->label_8->setText("Pas d'action ...");
    ui->pushButton_3->setText("Supprimer matériel");
    ui->pushButton_2->setText("Afficher matériel");
    ui->pushButton_4->setText("Modifier matériel");
    ui->pushButton_8->setText("Ajouter matériel");
    ui->label_9->setText("Trier selon :");
    ui->label_9->setStyleSheet("QLabel{color:#0000ff;}");
    ui->radioButton->setText("Id affectation ↑");
    ui->radioButton_3->setText("Id affectation ↓");
    ui->radioButton_2->setText("Id matériel ↑");
    ui->radioButton_4->setText("Id matériel ↓");
    ui->label_198->setText("Recherche :");
    ui->label_198->setStyleSheet("QLabel{color:#0000ff;}");
    //interface materiel
    ui->label_28->setText("Id matériel :");
    ui->label_18->setText("Nom Matériel :");
    ui->label_17->setText("Marque :");
    ui->label_26->setText("Stock :");
    ui->label_25->setText("Prix :");
    ui->label_19->setText("Description :");
    ui->label_29->setText("Id Catégotrie :");
    ui->label_16->setText("Id Fournisseur :");
    ui->label_27->setText("Image :");
    ui->label_22->setText("Pas d'Action ...");
    ui->pushButton_25->setText("Ajouter image");
    ui->pushButton_11->setText("Modifier image");
    ui->pushButton_23->setText("Afficehr image");
    ui->pushButton_22->setText("Ajouter matériel");
    ui->pushButton_28->setText("Modifier matériel");
    ui->pushButton_27->setText("Supprimer matériel");
    ui->label_23->setText("Trier selon :");
    ui->label_23->setStyleSheet("QLabel{color:#0000ff;}");
    ui->radioButton_6->setText("Stock ↑");
    ui->radioButton_8->setText("Stock ↓");
    ui->radioButton_7->setText("Prix ↑");
    ui->radioButton_11->setText("Prix ↓");
    ui->label_203->setText("Recherche :");
    ui->label_203->setStyleSheet("QLabel{color:#0000ff;}");
    //interface Fournisseur
    ui->label_40->setText("Id fournisseur:");
    ui->label_44->setText("Nom :");
    ui->label_34->setText("Prenom :");
    ui->label_33->setText("Num telephone :");
    ui->label_32->setText("Age :");
    ui->label_43->setText("Sexe:");
    ui->label_39->setText("Mail fournisseur");
    ui->label_31->setText("Pas d'action  ...");
    ui->pushButton_41->setText("Ajouter fournisseur ");
    ui->pushButton_34->setText("Modifier fournisseur");
    ui->pushButton_33->setText("Afficher fournisseur");
    ui->pushButton_37->setText("Supprimer fournisseur");
    ui->femme->setText("Femme");
    ui->homme->setText("Homme");
    ui->label_38->setText("Trier selon:");
    ui->radioButton_13->setText("Nom:A-Z");
    ui->radioButton_17->setText("Nom:Z-A");
    ui->radioButton_16->setText("Age ↑");
    ui->radioButton_18->setText("Age ↓");
    //categorie plante
    ui->label_46->setText("Id catégorie plante:");
    ui->label_47->setText("Nom catégorie plante:");
    ui->label_48->setText("Pas d'action  ...");
    ui->pushButton_53->setText("Afficher catégorie plante");
    ui->pushButton_51->setText("Supprimer catégorie plante");
    ui->pushButton_55->setText("Modifier catégorie plante");
    ui->pushButton_54->setText("Ajouter catégorie plante");
    ui->label_49->setText("Trier selon:");
    ui->radioButton_22->setText("Id catégorie plante ↑");
    ui->radioButton_19->setText("Id catégorie plante ↓");
    ui->radioButton_20->setText("Nom:A-Z");
    ui->radioButton_21->setText("Nom:Z-A");
    //plante
    ui->label_56->setText("Id plante :");
    ui->label_53->setText("Secteur :");
    ui->label_60->setText("Quantite :");
    ui->label_55->setText("Etat :");
    ui->Mauvaise->setText("Mauvaise");
    ui->Bonne->setText("Bonne");
    ui->label_64->setText("Id catégorie plante :");
    ui->label_63->setText("CIN");
    ui->label_59->setText("Id besoin plante :");
    ui->label_54->setText("Image :");
    ui->label_57->setText("Pas d'action ...");
    ui->pushButton_64->setText("Modifier image");
    ui->pushButton_61->setText("Afficher image");
    ui->pushButton_59->setText("Ajouter image");
    ui->pushButton_66->setText("Modifier plante");
    ui->pushButton_63->setText("Supprimer plante");
    ui->pushButton_67->setText("Ajouter plante");
    ui->pushButton_60->setText("Afficher plante");
    ui->radioButton_27->setText("Id plante ↑");
    ui->radioButton_26->setText("Id plante ↓");
    ui->radioButton_28->setText("Etat:A-Z");
    ui->radioButton_24->setText("Etat:Z-A");
    ui->radioButton_25->setText("Quantite ↑");
    ui->radioButton_23->setText("Quantite ↓");
    ui->label_65->setText("Trier selon :");
    //production animal (bouton)
    //besoin animal (bouton)
    //animal
    ui->label_104->setText("ID Animal :");
    ui->label_105->setText("Age Animal :");
    ui->label_103->setText("Sexe Animal :");
    ui->femme_2->setText("Femme");
    ui->homme_2->setText("Homme");
    ui->label_111->setText("Etat :");
    ui->Blesse->setText("Blesse");
    ui->Malade->setText("Malade");
    ui->Bonne->setText("Bonne");
    ui->label_113->setText("Id Espéce :");
    ui->label_108->setText("Id Besoin :");
    ui->label_100->setText("Image :");
    ui->label_110->setText("Pas d'action ...");
    ui->pushButton_111->setText("Ajouter image");
    ui->pushButton_113->setText("Modifier image");
    ui->pushButton_108->setText("Afficher image");
    ui->label_102->setText("Trier selon :");
    ui->label_102->setStyleSheet("QLabel{color:#0000ff;}");
    ui->radioButton_45->setText("Id Animal ↑");
    ui->radioButton_48->setText("Id Animal ↓");
    ui->radioButton_46->setText("Age ↑");
    ui->radioButton_47->setText("Age ↓");
    ui->radioButton_43->setText("Id Espece ↑");
    ui->radioButton_44->setText("Id Espece ↓");
    ui->label_214->setText("Recherche :");
    ui->label_214->setStyleSheet("QLabel{color:#0000ff;}");
    ui->pushButton_112->setText("Ajouter animal");
    ui->pushButton_114->setText("Modifier animal");
    ui->pushButton_106->setText("Supprimer animal");

    //espece animal
    ui->label_94->setText("Id Espéce :");
    ui->label_92->setText("Nom Espéce :");
    ui->label_93->setText("Pas d'action ...");
    ui->pushButton_102->setText("Afficher les espéces");
    ui->pushButton_99->setText("Supprimer espéce");
    ui->pushButton_100->setText("Modifier espéce");
    ui->pushButton_101->setText("Ajouter espéce");
    ui->label_91->setText("Trier selon :");
    ui->label_91->setStyleSheet("QLabel{color:#0000ff;}");
    ui->label_213->setText("Recherche :");
    ui->label_213->setStyleSheet("QLabel{color:#0000ff;}");
    //besoin plante
    ui->label_116->setText("Id besoin plante");
}
//speek
void Menu::on_pushButton_149_clicked()
{
    //speek off
    speek=0;
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->pushButton_149->hide();
    ui->pushButton_150->show();


}
//speek
void Menu::on_pushButton_150_clicked()
{
    //speek on
    speek=1;
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->pushButton_149->show();
    ui->pushButton_150->hide();
}
//pa&rametre menu vers paramtre
void Menu::on_pushButton_151_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    ui->stackedWidget->setCurrentIndex(14);
}
//fonction
//controle de saisie
bool Menu::controleDeSaisiefonction()
{
    bool result = true;
    bool number = true;
    ui->cx_salaire->text().toInt(&number);

    qDebug() << ui->cx_idFonction->text() << ui->cx_nomFonction->text() << ui->cx_salaire->text() << ui->cx_description->text() << number << endl;

    if(ui->cx_idFonction->text() == ""){
        ui->remarque_id->setText("*");
        ui->text_id->setText("id vide!");
        result = false;
    }
    else{
        ui->remarque_id->setText("");
        ui->text_id->setText("");
    }

    if(ui->cx_nomFonction->text() == ""){
        ui->remarque_nom->setText("*");
        ui->text_nom->setText("nom vide!");
        result = false;
    }
    else{
        ui->remarque_nom->setText("");
        ui->text_nom->setText("");
    }

    if(ui->cx_salaire->text() == ""){
        ui->remarque_salaire->setText("*");
        ui->text_salaire->setText("salaire vide!");
        result = false;
    }
    else
        if(!number){
            ui->remarque_salaire->setText("*");
            ui->text_salaire->setText("salaire non numérique!");
            result = false;
        }
        else{
            ui->remarque_salaire->setText("");
            ui->text_salaire->setText("");
        }

    if(ui->cx_description->text() == ""){
        ui->remarque_desc->setText("*");
        ui->text_desc->setText("description vide!");
        result = false;
    }
    else{
        ui->remarque_desc->setText("");
        ui->text_desc->setText("");
    }

    return result;
}
//selected fonction
void Menu::on_affichage_activated(const QModelIndex &index)
{
    QString val=ui->affichage->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select * from fonctions where idFonction = '"+val+"';");
    if (query.exec())
    {
        while (query.next())
        {

            ui->cx_idFonction->setStyleSheet("color: grey;");
            ui->cx_idFonction->setReadOnly(true);
            ui->cx_idFonction->setText(query.value(0).toString());
            ui->cx_nomFonction->setText(query.value(1).toString());
            ui->cx_salaire->setText(query.value(2).toString());
            ui->cx_description->setText(query.value(3).toString());
        }
    }
    ui->status->setText("Selectionnée!");
}
//ajouter fonction
void Menu::on_AjouterCategorieMateriel_2_clicked()
{
    if(ui->cx_idFonction->isReadOnly()){
        ui->cx_idFonction->setStyleSheet("color:black;");
        ui->cx_idFonction->setReadOnly(false);
    }
    else{
        if(controleDeSaisiefonction()){
            rh_fonctions_ops fOps(ui->cx_idFonction->text(),ui->cx_nomFonction->text(),ui->cx_salaire->text().toInt(),ui->cx_description->text());
            fOps.ajouterFonction();
            QFile file("A:\\integration\\integration final\\2\\mahrousplusplus\\Historique\\HistoriqueFonction.txt");
            if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
                return;
            QTextStream cout(&file);
            QString message2="\nFonction a été ajoutée sous :\n idF :"+ui->cx_idFonction->text()+" \n nomF : "+ui->cx_nomFonction->text()+" \n Salaire : "+ui->cx_salaire->text().toInt()+"\n Salaire : "+ui->cx_description->text()+"";
            cout << message2;
            ui->affichage->setModel(fOps.afficherFonctions(1));
            ui->status->setText("Ajoutée!");
            //sa.speak();
        }
    }
}
//modifier fonction
void Menu::on_ModifierCategorieMaeriel_2_clicked()
{
    if(!ui->cx_idFonction->isReadOnly()){
        ui->status->setText("Veuillez sélectionner d'abord...");
    }
    else{
        if(controleDeSaisiefonction()){
            rh_fonctions_ops fOps(ui->cx_idFonction->text(),ui->cx_nomFonction->text(),ui->cx_salaire->text().toInt(),ui->cx_description->text());
            fOps.modifFonction();
            ui->affichage->setModel(fOps.afficherFonctions(1));
            ui->status->setText("Modifiée!");
            //sm.speak();
        }
    }
}
//supprimer fonction
void Menu::on_SupprimerCategorieMateriel_2_clicked()
{
    if(!ui->cx_idFonction->isReadOnly()){
        ui->status->setText("Veuillez sélectionner d'abord...");
    }
    else{
        if(controleDeSaisiefonction()){
            rh_fonctions_ops fOps(ui->cx_idFonction->text(),ui->cx_nomFonction->text(),ui->cx_salaire->text().toInt(),ui->cx_description->text());
            fOps.suppFonction();
            ui->affichage->setModel(fOps.afficherFonctions(1));
            ui->status->setText("Supprimée!");
            //ss.speak();
        }
    }
}
//personnel
//controle de saisie
bool Menu::controleDeSaisiepersonnel(){
    bool result = true;
    bool number = true;
    ui->cx_cin->text().toInt(&number);

    if(ui->cx_nom->text() == ""){
        ui->remarque_nom->setText("*");
        ui->text_nom->setText("nom vide!");
        result = false;
    }
    else{
        ui->remarque_nom->setText("");
        ui->text_nom->setText("");
    }

    if(ui->cx_prenom->text() == ""){
        ui->remarque_prenom->setText("*");
        ui->text_prenom->setText("prenom vide!");
        result = false;
    }
    else{
        ui->remarque_prenom->setText("");
        ui->text_prenom->setText("");
    }

    if(ui->cx_cin->text() == ""){
        ui->remarque_cin->setText("*");
        ui->text_cin->setText("CIN vide!");
        result = false;
    }
    else
        if(!number || ui->cx_cin->text().length() != 8){
            ui->remarque_cin->setText("*");
            ui->text_cin->setText("Format incorrecte!");
            result = false;
        }
        else{
            ui->remarque_cin->setText("");
            ui->text_cin->setText("");
        }

    if(ui->cx_date->text() == ""){
        ui->remarque_date->setText("*");
        ui->text_date->setText("date vide!");
        result = false;
    }
    else{
        ui->remarque_date->setText("");
        ui->text_date->setText("");
    }

    if(ui->cx_adresse->text() == ""){
        ui->remarque_adresse->setText("*");
        ui->text_adresse->setText("adresse vide!");
        result = false;
    }
    else{
        ui->remarque_adresse->setText("");
        ui->text_adresse->setText("");
    }

    return result;
}
//ajouter  personnel
void Menu::on_AjouterPersonnel_clicked()
{

    if (cl==1)//fi ay evenemenet mta3 click
    { click->play();}
    else
    { click->stop();}
    if(ui->cx_cin->isReadOnly()){
        ui->cx_cin->setStyleSheet("color:black;");
        ui->cx_cin->setReadOnly(false);
    }
    else{
        if(controleDeSaisiepersonnel()){
            QAbstractItemModel * model = ui->comboBox->model();
            QString idF = model->data(model->index(ui->comboBox->currentIndex(),1)).toString();
            rh_personnels_ops pOps(ui->cx_cin->text(),ui->cx_nom->text(),ui->cx_prenom->text(),ui->cx_adresse->text(),ui->cx_date->text(),idF);
            qDebug () << ui->cx_date->text();
            pOps.ajouterPersonnel();
            ui->affichage_2->setModel(pOps.afficherPersonnels());
            ui->status->setText("Ajoutée!");
        }
    }
}
//clicked table personnel
void Menu::on_affichage_2_activated(const QModelIndex &index)
{
    QString val=ui->affichage_2->model()->data(index).toString().trimmed();

    rh_personnels_ops p;
    rh_fonctions_ops f;

    p.chargerPersonnel(val);
    ui->cx_cin->setText(p.getCin());
    ui->cx_nom->setText(p.getNom());
    ui->cx_prenom->setText(p.getPrenom());
    ui->cx_adresse->setText(p.getAdresse());
    ui->cx_date->setDate(QDate::fromString(p.getDateE().left(10),"dd/MM/yy"));

    f.setId(p.getIdFonction());
    QAbstractItemModel * model = f.afficherFonctions(2);

    ui->comboBox->setCurrentIndex(ui->comboBox->findText(model->data(model->index(0,0)).toString()));

    ui->cx_cin->setStyleSheet("color: grey;");
    ui->cx_cin->setReadOnly(true);
    ui->status->setText("Selectionnée!");
}
//moddifier personnel
void Menu::on_ModifierPeronnel_clicked()
{
    if(!ui->cx_cin->isReadOnly()){
        ui->status->setText("Veuillez sélectionner d'abord...");
    }
    else{
        if(controleDeSaisiepersonnel()){
            QAbstractItemModel * model = ui->comboBox->model();
            QString idF = model->data(model->index(ui->comboBox->currentIndex(),1)).toString();
            rh_personnels_ops pOps(ui->cx_cin->text(),ui->cx_nom->text(),ui->cx_prenom->text(),ui->cx_adresse->text(),ui->cx_date->text(),idF);
            pOps.modifPersonnel();
            ui->affichage_2->setModel(pOps.afficherPersonnels());
            ui->status->setText("Modifiée!");
        }
    }
}
//supprimer personnel
void Menu::on_SupprimerPersonnel_clicked()
{
    if(!ui->cx_cin->isReadOnly()){
        ui->status->setText("Veuillez sélectionner d'abord...");
    }
    else{
        if(controleDeSaisiepersonnel()){
            QAbstractItemModel * model = ui->comboBox->model();
            QString idF = model->data(model->index(ui->comboBox->currentIndex(),1)).toString();
            rh_personnels_ops pOps(ui->cx_cin->text(),ui->cx_nom->text(),ui->cx_prenom->text(),ui->cx_adresse->text(),ui->cx_date->text(),idF);
            pOps.suppPersonnel();
            ui->affichage_2->setModel(pOps.afficherPersonnels());
            ui->status->setText("Supprimée!");
        }
    }
}
//bouton fonction
void Menu::on_pushButton_31_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
}
//bouton photo fonction
void Menu::on_pushButton_136_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
}
//bouton personnel
void Menu::on_pushButton_32_clicked()
{

    ui->stackedWidget->setCurrentIndex(16);

    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();//fixe
            sa.personnelen();

        }
        else
        {
            sa.languageSelectedfr();//fixe
            sa.personnelfr();
        }
    }else {  sa.stop();}
}
//bouton photo personnel
void Menu::on_pushButton_137_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);
}
//fonction vers menu
void Menu::on_pushButton_152_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
//personnel vers menu
void Menu::on_pushButton_153_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
//trie id croissant
void Menu::on_trieridcroi_2_clicked()
{
    ui->affichage->setModel(rhf.afficher_idCroissant());
}
//trie id decroissant
void Menu::on_trieriddecroi_2_clicked()
{
    ui->affichage->setModel(rhf.afficher_idDecroissant());
}
//trie salaire croisaant
void Menu::on_radioButton_59_clicked()
{
    ui->affichage->setModel(rhf.afficher_SalaireCroissant());
}
//trie salaire decroisaant
void Menu::on_radioButton_60_clicked()
{
    ui->affichage->setModel(rhf.afficher_SalaireDecroissant());
}
//trie nom croissant
void Menu::on_trierAZ_2_clicked()
{
    ui->affichage->setModel(rhf.afficher_NomCroissant());
}
//trie nom decroissant
void Menu::on_trierZA_2_clicked()
{
    ui->affichage->setModel(rhf.afficher_NomDecroissant());
}
//recherche fonction
void Menu::on_lineEdit_recherche_3_textChanged(const QString &arg1)
{
    QString q = arg1;

    if (q=="")
    {
        rh_fonctions_ops f;
        ui->affichage->setModel(f.afficherFonctions(1));

    }
    else {
        ui->affichage->setModel(rhf.rechercher(q)) ;

        /*if (lng=="en")
        {
            ui->label_3->setText("Research");
        }
        else
        {
            ui->label_3->setText("Recherche");
        }*/
    }
}
//statisur fonction salaire
void Menu::on_pushButton_156_clicked()
{
    stf=new stat_salaire_fonction (this);
    stf->show();
}
//categrie materile vers historique
int  Menu::on_pushButton_157_clicked()
{
    on_pushButton_29_clicked();
}
//besoin plante vers menu
void Menu::on_pushButton_118_clicked()
{

    ui->stackedWidget->setCurrentIndex(0);
}
//espece animal vers menu
void Menu::on_pushButton_98_clicked()
{

    ui->stackedWidget->setCurrentIndex(0);
}
//production plante vers menu
void Menu::on_pushButton_125_clicked()
{

    ui->stackedWidget->setCurrentIndex(0);
}
//animal vers menu
void Menu::on_pushButton_105_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
//pdf fonction
int Menu::on_pushButton_199_clicked()
{
    if (cl==1)
    { click->play();}
    else
    { click->stop();}
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("A:\\integration\\integration final\\2\\mahrousplusplus\\Historique PDF\\Historique Fonction.pdf");//badel i chemin win t7eb t7ot il fichier ya2melek creation
    QPainter painter;

    if (! painter.begin(&printer)) { // failed to open file
        qWarning("failed to open file, is it writable?");
        //return 1;
    }

    QSqlQuery qry ;

    qry=tmpmat.selectdate();
    if (qry.exec())
    {

        QString S= QDate::currentDate().toString();
        painter.drawText(600,50, S);
        QPen penred(Qt::red);

        painter.setFont(QFont("Arial", 60));
        penred.setWidth(1);
        painter.setPen(penred);

        painter.drawText(200,500," La liste des ");
        painter.drawText(200,650,"  fonctions.");
        painter.setFont(QFont("Arial",30));
        painter.setPen(Qt::black);
        painter.drawText(50,100,"Bienvenu");
        painter.setPen(Qt::darkRed);
        painter.drawText(100,200,"Mahrous ++");
        painter.setPen(Qt::black);

    }

    QString id,nom,salaire,prix ,stock , desc , idc , image ,idf;
    QSqlQuery   qrry ;
    int i =50;
    int k=0;

    painter.drawPixmap(600,50,100,100,QPixmap::fromImage(QImage("A:/photo/logo.png")));//chemin mta3 il logo
    painter.drawText(400,800, image);

    qDebug() << qrry.prepare("select * from  FONCTIONS order by IDFONCTION ");


    if ( qrry.exec() )
    {

        while(qrry.next())
        {

            if ( k % 13 ==0)
            {   i=50;

                if (!printer.newPage())
                {

                    qWarning("failed");
                    return 1;
                }
                painter.setFont(QFont("Arial",10));
                QPen penblack(Qt::red);

                painter.setPen(penblack);
                painter.drawText (0,10,"idF");
                painter.drawText (40,10,"NomF");
                painter.drawText (260,10,"Salaire");
                painter.drawText (340,10,"Description");

            }

            painter.setFont(QFont("Arial",10));
            QPen penblack(Qt::black);

            painter.setPen(penblack);
            int j=0;

            id = qrry.value(0).toString();
            painter.drawText(j*20,i, id);
            j++;

            nom=qrry.value(1).toString();
            painter.drawText(j*40,i, nom);
            j++;
            salaire=qrry.value(2).toString();
            painter.drawText(j*130,i, salaire);
            j++;
            desc=qrry.value(3).toString();
            painter.drawText(j*120,i, desc);
            j++;


            i+=80;

            k++;

        }
    }


    if(speek==1)
    {
        if (lng=="en")
        {
            sa.languageSelecteden();
            sa.creationpdfen();
            // ui->label_22->setText("PDF creation");
        }
        else
        {
            sa.languageSelectedfr();
            sa.creationpdffr();
            //ui->label_22->setText("Création PDF");
        }

    }else {  sa.stop();}
    painter.end();
}
//affectation vers historique
void Menu::on_pushButton_200_clicked()
{
    on_pushButton_29_clicked();
}
//materiel vers historique
void Menu::on_pushButton_201_clicked()
{
    on_pushButton_29_clicked();
}
//fournissuer vers hiqtorique
void Menu::on_pushButton_202_clicked()
{
    on_pushButton_29_clicked();
}
//categorie plante vers historique
void Menu::on_pushButton_203_clicked()
{
    on_pushButton_29_clicked();
}
//plante vers historique
void Menu::on_pushButton_204_clicked()
{
    on_pushButton_29_clicked();
}
//besoin animal vers historique
void Menu::on_pushButton_205_clicked()
{
    on_pushButton_29_clicked();
}
//produit animal vers historique
void Menu::on_pushButton_206_clicked()
{
    on_pushButton_29_clicked();
}
//espece animel vers historique
void Menu::on_pushButton_207_clicked()
{
    on_pushButton_29_clicked();
}
//animal vers historique
void Menu::on_pushButton_208_clicked()
{
    on_pushButton_29_clicked();
}
//besoin plante vers historique
void Menu::on_pushButton_209_clicked()
{
    on_pushButton_29_clicked();
}
//peoduction plante vers historique
void Menu::on_pushButton_210_clicked()
{
    on_pushButton_29_clicked();
}
//fronction vers  historique
void Menu::on_pushButton_211_clicked()
{
    on_pushButton_29_clicked();
}
//personnels vers historique
void Menu::on_pushButton_212_clicked()
{
    on_pushButton_29_clicked();
}
