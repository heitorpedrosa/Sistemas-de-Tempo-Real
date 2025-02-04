#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <QTimer>

MainWindow::MainWindow ( QWidget *parent )
    : QMainWindow ( parent )
    , ui ( new Ui::MainWindow ),
      resultado ( nullptr ),
      start ( nullptr )
{
    ui -> setupUi ( this ) ;


    /************************************LOAD_IMAGES********************************************/
    QString dir = "";
    QString pix_file;
    QString arquivos [] = { "vermelho.png", "verde.png", "azul.png", "laranja.png" };

    tamanho_arr = sizeof ( arquivos ) / sizeof ( arquivos [ 0 ] );
    for ( int i = 0; i < tamanho_arr; i++ ) {
        pix_file = dir + arquivos [ i ];
        circulo [ i ].load ( pix_file, "PNG" );
    }
    /*******************************************************************************************/

    srand ( time ( NULL ) );

    resultado = new Resultado ( this );
    start = new Start ( this );

    key [ 0 ] = Qt::Key_Z;
    key [ 1 ] = Qt::Key_X;
    key [ 2 ] = Qt::Key_C;
    key [ 3 ] = Qt::Key_V;

    /*************************************CONNECTS**********************************************/
    connect ( resultado, &Resultado::signalStart, this, &MainWindow::slotStart );
    connect ( start, &Start::signalStart, this, &MainWindow::slotStart );
    connect ( this, &MainWindow::signalText, resultado, &Resultado::slotText );
    /*******************************************************************************************/
}

MainWindow::~MainWindow () {
    delete ui;
}

void MainWindow::keyPressEvent ( QKeyEvent *event ) {
    key_pressed ( event -> key () );
}

void MainWindow::exibir_circulo () {
    int position_x = rand () % ( this -> width () - 200 );
    int position_y = rand () % ( this -> height () - 200 );
    index = rand () % tamanho_arr;

    ui -> label -> setGeometry ( position_x, position_y, 100, 100 );
    ui -> label -> setPixmap ( circulo [ index ] );
    gettimeofday ( &image_display_time, NULL );
}

void MainWindow::key_pressed ( int key_value ) {
    //Z -> Vermelho
    //X -> Verde
    //C -> Azul
    //V -> Laranja
    if ( key [ index ] == key_value ) hit++;
    else miss++;

    if ( ( hit + miss ) == qtd_circulos ) {
        emit signalText ( QString::number ( ( tempo_media / qtd_circulos ) / 1000 ), hit, miss );
        resultado -> show ();
        return;
    }
    gettimeofday ( &key_press_time, NULL );
    tempo_media += ( ( key_press_time.tv_sec * 1000000 + key_press_time.tv_usec ) - ( image_display_time.tv_sec * 1000000 + image_display_time.tv_usec ) );
    exibir_circulo ();
}

/******************************************MENU*********************************************/
void MainWindow::on_actionStart_triggered () {
    start -> show ();
}

void MainWindow::on_actionExit_triggered () {
    QCoreApplication::quit ();
}
/*******************************************************************************************/

/***************************************SLOTS***********************************************/
void MainWindow::slotStart () {
    tempo_media = 0;
    hit = 0;
    miss = 0;

    sleep ( 1 );
    exibir_circulo ();
}
/*******************************************************************************************/

