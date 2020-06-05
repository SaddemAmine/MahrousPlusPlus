#ifndef ESPECEANIMAL_H
#define ESPECEANIMAL_H
#include "gestion_especeanimal.h"
#include <QDialog>
#include "speek/speekajouter.h"
#include <QtWidgets/qmainwindow.h>
#include <QTextToSpeech>
namespace Ui {
class especeanimal;
}

class especeanimal : public QDialog
{
    Q_OBJECT

public:
    explicit especeanimal(QWidget *parent = nullptr);
    ~especeanimal();

private slots:
    void on_pushButton_clicked();

    void init();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();



    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_afficher_especeanimal_activated(const QModelIndex &index);







private:
    Ui::especeanimal *ui;
    gestion_especeanimal tmpcat;

      QTextToSpeech *m_speech;
      SpeekAjouter  sa;
};

#endif // ESPECEANIMAL_H
