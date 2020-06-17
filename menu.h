#ifndef MENU_H
#define MENU_H
#include <QDialog>
#include "stat_productionanimaux.h"
#include "gestion_plante.h"
#include "categorie_materiel.h"
#include "speek/speekajouter.h"
#include "statisqtique_materiel.h"
#include"fournisseurs.h"
#include "materiel.h"
#include "affectation.h"
#include "historique.h"
#include"mahrousplusplus.h"
#include "gestion_affectation.h"
#include"gestion_fournisseur_materiaux.h"
#include"gestion_materiel.h"
#include "gestion_categorie_plante.h"
#include "capture.h"
#include "stat_plante.h"
#include "gestion_besoinanimaux.h"
#include "stat_besoinanimaux.h"
#include "gestion_productionanimaux.h"
#include "gestion_especeanimal.h"
#include "gestion_animaux.h"
#include "stat_animaux.h"
#include "gestion_besoin_plante.h"
#include "stat_besoinplantes.h"
#include "gestion_produit_plante.h"
#include"stat_productionplante.h"
#include"statistique_age_personnels.h"
#include <QTimer>
#include <QMainWindow>
#include <QMediaPlayer>
#include <QDialog>
#include <QSqlQueryModel>
#include <QStateMachine>
#include <QEventTransition>
#include<QPropertyAnimation>
#include<QParallelAnimationGroup>
#include "systeme.h"
#include "rh_fonctions_ops.h"
#include "rh_personnels_ops.h"
#include "stat_salaire_fonction.h"
#include "reclamations.h"
namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();


    void initcm();
bool controleDeSaisiefonction();

    void initm();
    void initf();
    void initaf();
    void initcp();
    void initp();
    void initba();
    void initpa();
    void initea();
    void inita();
    void initbp();
    void initpp();
    bool controleDeSaisiepersonnel();
    int Statistique_partie2();
    int Statistique_partie3();
    int Statistique_partie4();
    void paintEvent1();
    int Statistique_partie5();
    int Statistique_partie6();
    int Statistique_partie7();

    void initmenu();
    void boutonradiocm();
    bool controleDeSaisieCategoerieMateriel();
    bool testnom(QString q);
    bool controleDeSaisieaffectation();
    bool controleDeSaisieFournisseur();
    bool testnomf(QString q);
    bool testprenomf(QString q);
    bool testnomm(QString q);
    bool testmarquem(QString q);
    bool testdescm(QString q);
    bool controleDeSaisieMateriel();
    bool controleDeSaisieCategoeriePlante();
    bool testnomCP(QString q);
    bool controleDeSaisiePlante();
    bool controleDeSaisieAnimal();
    bool testnutrition(QString q);
    bool testabri(QString q);
    bool testvac(QString q);
    bool controleDeSaisieBesoinAnimal();
    bool testproduit(QString q);
    bool controleDeSaisieProductionAnimal();
    bool testnutp(QString q);
    bool controleDeSaisieBesoinPlante();
    bool testproduitp(QString q);
    bool controleDeSaisieProductionPlante();
    void initfonction();
private slots:
    void on_pushButton_28_clicked();
    void on_pushButton_22_clicked();
    void on_pushButton_27_clicked();
    void on_pushButton_25_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_23_clicked();
    void on_AfficherCategorieMateriel_clicked();
    void on_SupprimerCategorieMateriel_clicked();
    void on_ModifierCategorieMaeriel_clicked();
    void on_AjouterCategorieMateriel_clicked();
    void on_afficher_categorie_activated(const QModelIndex &index);
    void on_trieridcroi_clicked();
    void on_trieriddecroi_clicked();
    void on_trierAZ_clicked();
    void on_trierZA_clicked();
    void on_pushButton_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_24_clicked();
    void on_afficher_materiel_activated(const QModelIndex &index);
    void on_radioButton_5_clicked();
    void on_radioButton_7_clicked();
    void on_radioButton_11_clicked();
    void on_radioButton_6_clicked();
    void on_radioButton_8_clicked();
    void on_radioButton_10_clicked();
    void on_radioButton_12_clicked();
    void on_pushButton_21_clicked();
    int on_pushButton_13_clicked();
    void on_pushButton_19_clicked();
    void on_pushButton_20_clicked();
    void on_pushButton_18_clicked();
    void on_pushButton_26_clicked();
    void on_radioButton_9_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_2_clicked();
    void on_afficher_affectation_activated(const QModelIndex &index);
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_radioButton_clicked();
    void on_radioButton_3_clicked();
    void on_radioButton_2_clicked();
    void on_radioButton_4_clicked();
    void on_pushButton_41_clicked();
    void on_pushButton_37_clicked();
    void on_pushButton_33_clicked();
    void on_pushButton_34_clicked();
    void on_radioButton_14_clicked();
    void on_pushButton_30_clicked();
    void on_cx_recherche_textChanged(const QString &arg1);
    void on_pushButton_40_clicked();
    void on_listView2_activated(const QModelIndex &index);
    void on_pushButton_43_clicked();
    void on_pushButton_38_clicked();
    void on_listView_activated(const QModelIndex &index);
    void on_pushButton_35_clicked();
    void on_afficher_fournisseur_activated(const QModelIndex &index);
    void on_pushButton_42_clicked();
    void on_radioButton_17_clicked();
    void on_radioButton_13_clicked();
    void on_radioButton_18_clicked();
    void on_radioButton_16_clicked();
    void on_radioButton_15_clicked();
    void on_pushButton_45_clicked();
    void on_pushButton_46_clicked();
    void on_pushButton_47_clicked();
    void on_pushButton_48_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_29_clicked();
    void on_pushButton_17_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_54_clicked();
    void on_pushButton_39_clicked();
    void on_pushButton_44_clicked();
    void on_pushButton_51_clicked();
    void on_affiche_categorieplante_activated(const QModelIndex &index);
    void on_pushButton_55_clicked();
    void on_radioButton_22_clicked();
    void on_radioButton_19_clicked();
    void on_radioButton_20_clicked();
    void on_radioButton_21_clicked();
    void on_lineEdit_recherchecategorieplante_textChanged(const QString &arg1);
    void on_pushButton_56_clicked();
    void on_pushButton_57_clicked();
    void on_pushButton_49_clicked();
    void on_pushButton_50_clicked();
    void on_pushButton_67_clicked();
    void on_pushButton_59_clicked();
    void on_pushButton_64_clicked();
    void on_afficher_plante_activated(const QModelIndex &index);
    void on_pushButton_63_clicked();
    void on_pushButton_66_clicked();
    void on_pushButton_60_clicked();
    void on_pushButton_61_clicked();
    void on_radioButton_27_clicked();
    void on_radioButton_26_clicked();
    void on_radioButton_28_clicked();
    void on_radioButton_24_clicked();
    void on_radioButton_25_clicked();
    void on_radioButton_23_clicked();
    void on_recherche_2_textChanged(const QString &arg1);
    int on_pushButton_65_clicked();
    void on_pushButton_62_clicked();
    void on_pushButton_53_clicked();
    void on_pushButton_79_clicked();
    void on_pushButton_76_clicked();
    void on_pushButton_71_clicked();
    void on_pushButton_81_clicked();
    void on_pushButton_74_clicked();
    void on_pushButton_78_clicked();
    void on_afficher_besoinanimaux_activated(const QModelIndex &index);
    void on_pushButton_80_clicked();
    void on_pushButton_72_clicked();
    void on_pushButton_82_clicked();
    void on_radioButton_32_clicked();
    void on_radioButton_34_clicked();
    void on_radioButton_33_clicked();
    void on_radioButton_29_clicked();
    void on_radioButton_30_clicked();
    void on_radioButton_31_clicked();
    void on_recherche_3_textChanged(const QString &arg1);
    int on_pushButton_77_clicked();
    void on_pushButton_73_clicked();
    void on_pushButton_68_clicked();
    void on_pushButton_70_clicked();
    void on_pushButton_69_clicked();
    void on_pushButton_92_clicked();
    void on_pushButton_88_clicked();
    void on_afficher_productionanimaux_activated(const QModelIndex &index);
    void on_pushButton_85_clicked();
    void on_pushButton_91_clicked();
    void on_pushButton_89_clicked();
    void on_pushButton_87_clicked();
    void on_pushButton_93_clicked();
    void on_radioButton_36_clicked();
    void on_radioButton_37_clicked();
    void on_radioButton_38_clicked();
    void on_radioButton_35_clicked();
    void on_recherche_4_textChanged(const QString &arg1);
    int on_pushButton_90_clicked();
    void on_pushButton_86_clicked();
    void on_pushButton_83_clicked();
    void on_pushButton_94_clicked();
    void on_pushButton_97_clicked();
    void on_pushButton_101_clicked();
    void on_afficher_especeanimal_activated(const QModelIndex &index);
    void on_pushButton_102_clicked();
    void on_pushButton_99_clicked();
    void on_pushButton_100_clicked();
    void on_lineEdit_recherche_2_textChanged(const QString &arg1);
    void on_radioButton_39_clicked();
    void on_radioButton_42_clicked();
    void on_radioButton_41_clicked();
    void on_radioButton_40_clicked();
    void on_pushButton_96_clicked();
    void on_pushButton_95_clicked();
    void on_pushButton_112_clicked();
    void on_afficher_animaux_activated(const QModelIndex &index);
    void on_pushButton_111_clicked();
    void on_pushButton_113_clicked();
    void on_pushButton_106_clicked();
    void on_pushButton_114_clicked();
    void on_pushButton_107_clicked();
    void on_pushButton_108_clicked();
    void on_radioButton_45_clicked();
    void on_radioButton_48_clicked();
    void on_radioButton_46_clicked();
    void on_radioButton_47_clicked();
    void on_radioButton_43_clicked();
    void on_radioButton_44_clicked();
    void on_recherche_5_textChanged(const QString &arg1);
    int on_pushButton_115_clicked();
    void on_pushButton_110_clicked();
    void on_pushButton_116_clicked();
    void on_pushButton_117_clicked();
    void on_pushButton_120_clicked();
    void on_pushButton_124_clicked();
    void on_afficher_besoin_palnte_activated(const QModelIndex &index);
    void on_pushButton_122_clicked();
    void on_pushButton_123_clicked();
    void on_radioButton_51_clicked();
    void on_radioButton_52_clicked();
    void on_radioButton_50_clicked();
    void on_radioButton_54_clicked();
    void on_radioButton_49_clicked();
    void on_radioButton_53_clicked();
    void on_recherche_6_textChanged(const QString &arg1);
    void on_pushButton_119_clicked();
    void on_pushButton_126_clicked();
    void on_pushButton_127_clicked();
    void on_pushButton_131_clicked();
    void on_pushButton_130_clicked();
    void on_afficher_produitplante_activated(const QModelIndex &index);
    void on_pushButton_132_clicked();
    void on_pushButton_128_clicked();
    void on_radioButton_56_clicked();
    void on_radioButton_58_clicked();
    void on_radioButton_57_clicked();
    void on_radioButton_55_clicked();
    void on_Recherche_2_textChanged(const QString &arg1);
    void on_pushButton_129_clicked();
    int on_pushButton_134_clicked();
    int on_pushButton_135_clicked();
    void on_lineEdit_recherche_textChanged(const QString &arg1);
    void on_recherche_textChanged(const QString &arg1);
    void on_Recherche_textChanged(const QString &arg1);
    void on_pushButton_140_clicked();

    //parametre
    void on_positionChanged(qint64 position );

    void on_durationChanged(qint64 position );
   void on_sliderProgresse_sliderMoved(int position);

   void on_sliderVolume_sliderMoved(int position);
   //void on_pushButton_141_clicked();
   // void on_pushButton_142_clicked();
    void on_pushButton_141_clicked();

    void on_pushButton_142_clicked();

    void on_pushButton_143_clicked();

    void on_pushButton_144_clicked();

    void on_pushButton_145_clicked();

    void on_pushButton_146_clicked();

    void on_pushButton_148_clicked();

    void on_pushButton_147_clicked();

    void on_pushButton_149_clicked();

    void on_pushButton_150_clicked();

    void on_pushButton_151_clicked();

    void on_affichage_activated(const QModelIndex &index);

    void on_AjouterCategorieMateriel_2_clicked();

    void on_ModifierCategorieMaeriel_2_clicked();

    void on_SupprimerCategorieMateriel_2_clicked();

    void on_AjouterPersonnel_clicked();

    void on_affichage_2_activated(const QModelIndex &index);

    void on_ModifierPeronnel_clicked();

    void on_SupprimerPersonnel_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_136_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_137_clicked();

    void on_pushButton_152_clicked();

    void on_pushButton_153_clicked();



    void on_pushButton_155_clicked();

    void on_pushButton_154_clicked();

    void on_trieridcroi_2_clicked();

    void on_trieriddecroi_2_clicked();

    void on_radioButton_59_clicked();

    void on_radioButton_60_clicked();

    void on_trierAZ_2_clicked();

    void on_trierZA_2_clicked();

    void on_lineEdit_recherche_3_textChanged(const QString &arg1);

    void on_pushButton_156_clicked();

int on_pushButton_157_clicked();

void on_pushButton_118_clicked();

void on_pushButton_98_clicked();

void on_pushButton_125_clicked();

void on_pushButton_105_clicked();

int on_pushButton_199_clicked();

void on_pushButton_200_clicked();

void on_pushButton_201_clicked();

void on_pushButton_202_clicked();

void on_pushButton_203_clicked();

void on_pushButton_204_clicked();

void on_pushButton_205_clicked();

void on_pushButton_206_clicked();

void on_pushButton_207_clicked();

void on_pushButton_208_clicked();

void on_pushButton_209_clicked();

void on_pushButton_210_clicked();

void on_pushButton_211_clicked();

void on_pushButton_212_clicked();

void on_checkBox_clicked(bool checked);



void on_pushButton_10_clicked();

void on_pushButton_159_clicked();

void on_comboBox_r_currentIndexChanged();

void on_pushButton_36_clicked();

void on_pushButton_160_clicked();

void on_pushButton_161_clicked();

void on_pushButton_162_clicked();

void on_pushButton_163_clicked();

void on_pushButton_164_clicked();

void on_pushButton_165_clicked();

int on_pushButton_166_clicked();

bool controleDeSaisieEspeceAnimal();
bool testnomEA(QString );

void on_stat_clicked();

private:
    Ui::Menu *ui;
    categorie_materiel *cm;
    fournisseurs *s;
    plante *p;
    materiel *m;
    affectation *af;
    Historique *h;
    gestion_plante tmppl;
    gestion_categorie_materiel tmpcat;
    gestion_affectation tmpaff;
    gestion_categorie_plante tmpcatp;
    gestion_materiel tmpmat;
    gestion_fournisseur_materiaux tmpf;
    gestion_productionanimaux tmppa;
    gestion_besoinanimaux tmpba;
    gestion_especeanimal tmpea;
    gestion_animaux tmpa;
    gestion_besoin_plante tmpbp;
    gestion_produit_plante tmppp;
    rh_fonctions_ops rhf;
    Statisqtique_materiel *sm;
    stat_besoinanimaux *sba;
    Stat_animaux *stata;
    Stat_productionanimaux *spa;
    stat_besoinplantes *sbp;
    stat_productionplante *spp;
    stat_salaire_fonction *stf;
    reclamations r;
    capture *c;
    QString lng;
    Statistique_fournisseur *f;
    SpeekAjouter sa;
    Stat_plante *sp;
    QMediaPlayer *player;
    QMediaPlayer *click;
    QPropertyAnimation *animation;
    QPropertyAnimation *animation1;
    QPropertyAnimation *animation2;
    QParallelAnimationGroup *animationGroup;
    statistique_age_personnels *sap;
    int cl;
    int speek;
    int securite;
    int a;
    systeme sy;


};

#endif // MENU_H
