#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <sys/time.h>
#include <QKeyEvent>
#include "resultado.h"
#include <start.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow ( QWidget *parent = nullptr );
    ~MainWindow ();

protected:
    void keyPressEvent ( QKeyEvent *event );

private slots:
    void on_actionStart_triggered ();
    void on_actionExit_triggered ();
    void slotStart ();

private:
    Ui::MainWindow *ui;
    Resultado *resultado;
    Start *start;

    void exibir_circulo ();
    void key_pressed ( int key_value );

    struct timeval image_display_time, key_press_time;
    QPixmap circulo [ 4 ];
    int key [ 4 ];
    int tamanho_arr;
    int index;
    int qtd_circulos = 10;
    int tempo_mili;
    double tempo_media;
    int hit, miss;

signals:
    void signalText ( QString str, int hit, int miss );
};
#endif // MAINWINDOW_H
