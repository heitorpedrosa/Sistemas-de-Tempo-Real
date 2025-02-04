#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QProcess>
#include <QFile>
#include <QDebug>
#include <QTimer>
#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <signal.h>
#include <Windows.h>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void imprimirTabela ();

public slots:
    void lista_processos ();

private slots:
    void on_pushButton_clicked ();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_lineEdit_2_returnPressed();

    void on_lineEdit_3_returnPressed();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
