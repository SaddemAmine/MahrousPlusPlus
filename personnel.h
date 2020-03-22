#ifndef PERSONNEL_H
#define PERSONNEL_H
#include <QTimer>
#include <QMainWindow>
#include <QMediaPlayer>
#include <QDialog>
#include <QSqlQueryModel>
namespace Ui {
class personnel;
}

class personnel : public QDialog
{
    Q_OBJECT

public:
    explicit personnel(QWidget *parent = nullptr);
    ~personnel();
    QSqlQueryModel * afficher();

private slots:
    void on_comboBox_currentIndexChanged();



    //void on_pushButton_p_clicked();

    void on_pushButton_p_clicked();

    void on_pushButton_2_f_clicked();

    void on_comboBox_4_currentIndexChanged();

    void on_modifier_f_clicked();

    void on_supprimer_f_clicked();

private:
    Ui::personnel *ui;
    QTimer *timer;
QMediaPlayer *click;
};

#endif // PERSONNEL_H
