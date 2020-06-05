#ifndef STAT_SALAIRE_FONCTION_H
#define STAT_SALAIRE_FONCTION_H

#include <QDialog>
#include <iostream>
#include <QApplication>
#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPainter>
#include <QSqlQuery>
namespace Ui {
class stat_salaire_fonction;
}

class stat_salaire_fonction : public QDialog
{
    Q_OBJECT

public:
    explicit stat_salaire_fonction(QWidget *parent = nullptr);
    ~stat_salaire_fonction();

    int Stat_partie2();
    int Stat_partie3();
    int Stat_partie4();
    void paintEvent(QPaintEvent *);
private:
    Ui::stat_salaire_fonction *ui;
};

#endif // STAT_SALAIRE_FONCTION_H
