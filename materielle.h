#ifndef MATERIELLE_H
#define MATERIELLE_H
#include <QTimer>
#include <QMainWindow>
#include <QMediaPlayer>
#include <QDialog>

namespace Ui {
class materielle;
}

class materielle : public QDialog
{
    Q_OBJECT

public:
    explicit materielle(QWidget *parent = nullptr);
    ~materielle();

void myfunction();
private slots:
//void on_pushButton_clicked();

private:
    Ui::materielle *ui;
      QTimer *timer;
QMediaPlayer *click;
};

#endif // MATERIELLE_H
