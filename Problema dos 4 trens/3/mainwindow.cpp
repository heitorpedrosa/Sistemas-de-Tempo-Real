#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Iniciar posição dos trens
    trem_verde.first = 90;
    trem_verde.second = 40;

    trem_amarelo.first = 90;
    trem_amarelo.second = 150;

    trem_azul.first = 395;
    trem_azul.second = 150;

    trem_vermelho.first = 90;
    trem_vermelho.second = 260;

    QFont font ( "times", 16, 600 );
    QFontMetrics font_metrics ( font );
    int width, height;

    //Label
    width = 250;
    height = font_metrics.height ();

    ui -> label -> setText ( "Controle de velocidade:" );
    ui -> label -> setFont ( font );
    ui -> label -> setFixedWidth ( width );
    ui -> label -> setFixedHeight ( height );

    start ();
    QTimer *timer = new QTimer ( this );
    connect ( timer, SIGNAL ( timeout() ), this, SLOT ( atualizar_tela() ) );
    timer -> start ( 50 );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent ( QPaintEvent * ) {
    QPainter painter ( this );
    QBrush brush;
    QPen pen;

    pen.setWidth ( 5 );

    //Trilho verde
    pen.setColor ( Qt::green );
    painter.setPen ( pen );
    painter.drawRect ( QRect ( 100, 50, 600, 100 ) );

    //Trilho amarelo
    pen.setColor ( Qt::yellow );
    painter.setPen ( pen );
    painter.drawRect ( QRect ( 100, 160, 295, 100 ) );

    //Trilho azul
    pen.setColor ( Qt::blue );
    painter.setPen ( pen );
    painter.drawRect ( QRect ( 405, 160, 295, 100 ) );

    //Trilho vermelho
    pen.setColor ( Qt::red );
    painter.setPen ( pen );
    painter.drawRect ( QRect ( 100, 270, 600, 100 ) );

    //Trem verde
    brush.setColor ( Qt::darkGreen );
    brush.setStyle ( Qt::SolidPattern );
    painter.setBrush ( brush );
    pen.setColor ( Qt::darkGreen );
    painter.setPen ( pen );
    painter.drawRect ( QRect ( trem_verde.first, trem_verde.second, 20, 20 ) );

    //Trem amarelo
    brush.setColor ( Qt::darkYellow );
    brush.setStyle ( Qt::SolidPattern );
    painter.setBrush ( brush );
    pen.setColor ( Qt::darkYellow );
    painter.setPen ( pen );
    painter.drawRect ( QRect ( trem_amarelo.first, trem_amarelo.second, 20, 20 ) );

    //Trem azul
    brush.setColor ( Qt::darkBlue );
    brush.setStyle ( Qt::SolidPattern );
    painter.setBrush ( brush );
    pen.setColor ( Qt::darkBlue );
    painter.setPen ( pen );
    painter.drawRect ( QRect ( trem_azul.first, trem_azul.second, 20, 20 ) );

    //Trem vermelho
    brush.setColor ( Qt::darkRed );
    brush.setStyle ( Qt::SolidPattern );
    painter.setBrush ( brush );
    pen.setColor ( Qt::darkRed );
    painter.setPen ( pen );
    painter.drawRect ( QRect ( trem_vermelho.first, trem_vermelho.second, 20, 20 ) );
}

pthread_mutex_t work_mutex_1, work_mutex_2, work_mutex_3, work_mutex_4, work_mutex_5;

void *trem_verde_function ( void *arg ) {
    MainWindow *parametros;
    parametros = ( MainWindow* ) arg;
    while ( 1 ) {
        //Direita
        if ( parametros -> trem_verde.first < 690 && parametros -> trem_verde.second == 40 ) {
            parametros -> trem_verde.first += 5;
        }
        //Baixo
        if ( parametros -> trem_verde.first == 690 && parametros -> trem_verde.second < 140 ) {
            parametros -> trem_verde.second += 5;
            if ( parametros -> trem_verde.second == 140 ) {
                pthread_mutex_lock ( &work_mutex_1 );
                pthread_mutex_lock ( &work_mutex_2 );
            }
        }
        //Esquerda
        if ( parametros -> trem_verde.first > 90 && parametros -> trem_verde.second == 140 ) {
            parametros -> trem_verde.first -= 5;
            if ( parametros -> trem_verde.first == 90 ) pthread_mutex_unlock ( &work_mutex_1 );
        }
        //Transição dos trilhos 4 e 5
        if ( parametros -> trem_verde.first == 390 && parametros -> trem_verde.second == 140 ) {
            pthread_mutex_unlock ( &work_mutex_2 );
        }
        //Cima
        if ( parametros -> trem_verde.first == 90 && parametros -> trem_verde.second > 40 ) {
            parametros -> trem_verde.second -= 5;
        }
        usleep ( parametros -> velocidade_trem_verde );
    }
}
void *trem_amarelo_function ( void *arg ) {
    MainWindow *parametros;
    parametros = ( MainWindow* ) arg;
    while ( 1 ) {
        //Direita
        if ( parametros -> trem_amarelo.first < 385 && parametros -> trem_amarelo.second == 150 ) {
            parametros -> trem_amarelo.first += 5;
            if ( parametros -> trem_amarelo.first == 385 ) {
                pthread_mutex_unlock ( &work_mutex_1 );
                pthread_mutex_lock ( &work_mutex_3 );
            }
        }
        //Baixo
        if ( parametros -> trem_amarelo.first == 385 && parametros -> trem_amarelo.second < 250 ) {
            parametros -> trem_amarelo.second += 5;
            if ( parametros -> trem_amarelo.second == 250 ) {
                pthread_mutex_unlock ( &work_mutex_3 );
                pthread_mutex_lock ( &work_mutex_4 );
            }
        }
        //Esquerda
        if ( parametros -> trem_amarelo.first > 90 && parametros -> trem_amarelo.second == 250 ) {
            parametros -> trem_amarelo.first -= 5;
            if ( parametros -> trem_amarelo.first == 90 ) pthread_mutex_unlock ( &work_mutex_4 );
        }
        //Cima
        if ( parametros -> trem_amarelo.first == 90 && parametros -> trem_amarelo.second > 150 ) {
            parametros -> trem_amarelo.second -= 5;
            if ( parametros -> trem_amarelo.second == 150 ) pthread_mutex_lock ( &work_mutex_1 );
        }
        usleep ( parametros -> velocidade_trem_amarelo );
    }
}
void *trem_azul_function ( void *arg ) {
    MainWindow *parametros;
    parametros = ( MainWindow* ) arg;
    while ( 1 ) {
        //Direita
        if ( parametros -> trem_azul.first < 690 && parametros -> trem_azul.second == 150 ) {
            parametros -> trem_azul.first += 5;
            if ( parametros -> trem_azul.first == 690 ) pthread_mutex_unlock ( &work_mutex_2 );
        }
        //Baixo
        if ( parametros -> trem_azul.first == 690 && parametros -> trem_azul.second < 250 ) {
            parametros -> trem_azul.second += 5;
            if ( parametros -> trem_azul.second == 250 ) pthread_mutex_lock ( &work_mutex_5 );
        }
        //Esquerda
        if ( parametros -> trem_azul.first > 395 && parametros -> trem_azul.second == 250 ) {
            parametros -> trem_azul.first -= 5;
            if ( parametros -> trem_azul.first == 395 ) {
                pthread_mutex_lock ( &work_mutex_3 );
                pthread_mutex_unlock ( &work_mutex_5 );
            }
        }
        //Cima
        if ( parametros -> trem_azul.first == 395 && parametros -> trem_azul.second > 150 ) {
            parametros -> trem_azul.second -= 5;
            if ( parametros -> trem_azul.second == 150 ) {
                pthread_mutex_lock ( &work_mutex_2 );
                pthread_mutex_unlock ( &work_mutex_3 );
            }
        }
        usleep ( parametros -> velocidade_trem_azul );
    }
}
void *trem_vermelho_function ( void *arg ) {
    MainWindow *parametros;
    parametros = ( MainWindow* ) arg;
    while ( 1 ) {
        //Direita
        if ( parametros -> trem_vermelho.first < 690 && parametros -> trem_vermelho.second == 260 ) {
            parametros -> trem_vermelho.first += 5;
            if ( parametros -> trem_vermelho.first == 690 ) pthread_mutex_unlock ( &work_mutex_5 );
        }
        //Transição dos trilhos 8 e 10
        if ( parametros -> trem_vermelho.first == 390 && parametros -> trem_vermelho.second == 260 ) {
            pthread_mutex_unlock ( &work_mutex_4 );
        }
        //Baixo
        if ( parametros -> trem_vermelho.first == 690 && parametros -> trem_vermelho.second < 360 ) {
            parametros -> trem_vermelho.second += 5;
        }
        //Esquerda
        if ( parametros -> trem_vermelho.first > 90 && parametros -> trem_vermelho.second == 360 ) {
            parametros -> trem_vermelho.first -= 5;
        }
        //Cima
        if ( parametros -> trem_vermelho.first == 90 && parametros -> trem_vermelho.second > 260 ) {
            parametros -> trem_vermelho.second -= 5;
            if ( parametros -> trem_vermelho.second == 260 ) {
                pthread_mutex_lock ( &work_mutex_4 );
                pthread_mutex_lock ( &work_mutex_5 );
            }
        }
        usleep ( parametros -> velocidade_trem_vermelho );
    }
}

void MainWindow::start () {

    //Mutex
    pthread_mutex_init(&work_mutex_1, NULL);
    pthread_mutex_init(&work_mutex_2, NULL);
    pthread_mutex_init(&work_mutex_3, NULL);
    pthread_mutex_init(&work_mutex_4, NULL);
    pthread_mutex_init(&work_mutex_5, NULL);

    //Threads
    pthread_t thread_verde, thread_amarelo, thread_azul, thread_vermelho;

    pthread_create ( &thread_verde, NULL, trem_verde_function, ( void* ) this );
    pthread_create ( &thread_amarelo, NULL, trem_amarelo_function, ( void* ) this );
    pthread_create ( &thread_azul, NULL, trem_azul_function, ( void* ) this );
    pthread_create ( &thread_vermelho, NULL, trem_vermelho_function, ( void* ) this );

    //Destruix mutex
    pthread_mutex_destroy(&work_mutex_1);
    pthread_mutex_destroy(&work_mutex_2);
    pthread_mutex_destroy(&work_mutex_3);
    pthread_mutex_destroy(&work_mutex_4);
    pthread_mutex_destroy(&work_mutex_5);
}

void MainWindow::atualizar_tela () {
    repaint ();
}

void MainWindow::on_verticalSlider_valueChanged ( int value ) {
    velocidade_trem_verde = value;
}


void MainWindow::on_verticalSlider_2_valueChanged ( int value ) {
    velocidade_trem_amarelo = value;
}


void MainWindow::on_verticalSlider_3_valueChanged ( int value ) {
    velocidade_trem_azul = value;
}


void MainWindow::on_verticalSlider_4_valueChanged ( int value ) {
    velocidade_trem_vermelho = value;
}

