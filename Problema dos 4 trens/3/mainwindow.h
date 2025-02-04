#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <QTimer>
#include <QFont>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    virtual void paintEvent ( QPaintEvent * );

    //pair<x,y>
    std::pair<int,int> trem_verde;
    std::pair<int,int> trem_amarelo;
    std::pair<int,int> trem_azul;
    std::pair<int,int> trem_vermelho;

    int velocidade_trem_verde = 50000;
    int velocidade_trem_amarelo = 50000;
    int velocidade_trem_azul = 50000;
    int velocidade_trem_vermelho = 50000;

    void start ();

public slots:
    void atualizar_tela ();

private slots:
    void on_verticalSlider_valueChanged(int value);

    void on_verticalSlider_2_valueChanged(int value);

    void on_verticalSlider_3_valueChanged(int value);

    void on_verticalSlider_4_valueChanged(int value);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
