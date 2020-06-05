#ifndef CATEGORIE_MATERIEL_H
#define CATEGORIE_MATERIEL_H
#include "gestion_categorie_materiel.h"
#include <QDialog>
#include "speek/speekajouter.h"
#include <QtWidgets/qmainwindow.h>
#include <QTextToSpeech>
#include <QDialog>

namespace Ui {
class categorie_materiel;
}

class categorie_materiel : public QDialog
{
    Q_OBJECT

public:
    explicit categorie_materiel(QWidget *parent = nullptr);
    ~categorie_materiel();

    void init();

    void test(gestion_categorie_materiel );
private slots:
    void on_AfficherCategorieMateriel_clicked();

    void on_SupprimerCategorieMateriel_clicked();

    void on_ModifierCategorieMaeriel_clicked();

    void on_AjouterCategorieMateriel_clicked();

    void on_afficher_categorie_activated(const QModelIndex &index);

    void on_trieridcroi_clicked();

    void on_trieriddecroi_clicked();

    void on_trierAZ_clicked();

    void on_trierZA_clicked();

    void on_RechercheCategorieMateriel_clicked();


private:
    Ui::categorie_materiel *ui;

    gestion_categorie_materiel tmpcat;

   SpeekAjouter  sa;
};

#endif // CATEGORIE_MATERIEL_H
