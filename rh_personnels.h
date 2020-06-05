#ifndef RH_PERSONNELS_H
#define RH_PERSONNELS_H

#include <QDialog>

namespace Ui {
class rh_personnels;
}

class rh_personnels : public QDialog
{
    Q_OBJECT

public:
    explicit rh_personnels(QWidget *parent = nullptr);
    ~rh_personnels();

private slots:
    void on_AjouterPersonnel_clicked();

    void on_affichage_doubleClicked(const QModelIndex &index);

    void on_ModifierPeronnel_clicked();

    void on_SupprimerPersonnel_clicked();

private:
    Ui::rh_personnels *ui;
    bool controleDeSaisie();
};

#endif // RH_PERSONNELS_H
