#ifndef BESOIN_PLANTE_H
#define BESOIN_PLANTE_H
#include "gestion_besoin_plante.h"
#include "speek/speekajouter.h"
#include "speek/speekmodifier.h"
#include "speek/speeksupprimer.h"
#include <QDialog>

namespace Ui {
class besoin_plante;
}

class besoin_plante : public QDialog
{
    Q_OBJECT

public:
    explicit besoin_plante(QWidget *parent = nullptr);
    ~besoin_plante();
    void init();

private slots:
    void on_pushButton_clicked();

    void on_afficher_besoin_palnte_activated(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();



private:
    Ui::besoin_plante *ui;
    gestion_besoin_plante tmpbp;
    SpeekAjouter  sa;
    SpeekModifier sm;
    SpeekSupprimer ss;
};

#endif // BESOIN_PLANTE_H
