#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*********************************************Tabela*******************************************************/
    QTableWidgetItem *newItem;
    QFont boldFont;
    boldFont.setBold(true);

    ui -> tableWidget -> verticalHeader () -> setVisible ( false );
    ui -> tableWidget -> setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOn );

    ui -> tableWidget -> horizontalHeader () -> setSectionResizeMode ( 0, QHeaderView::Stretch );
    ui -> tableWidget -> horizontalHeader () -> setSectionResizeMode ( 1, QHeaderView::ResizeToContents );
    ui -> tableWidget -> horizontalHeader () -> setSectionResizeMode ( 2, QHeaderView::ResizeToContents );
    ui -> tableWidget -> horizontalHeader () -> setSectionResizeMode ( 3, QHeaderView::ResizeToContents );
    ui -> tableWidget -> horizontalHeader () -> setSectionResizeMode ( 4, QHeaderView::ResizeToContents );

    ui -> tableWidget -> setStyleSheet ( "QHeaderView::section { background-color:lightgray }" );

    newItem = new QTableWidgetItem ( " Nome do Processo " );
    newItem -> setTextAlignment ( Qt::AlignCenter );
    newItem -> setFont ( boldFont );
    ui -> tableWidget -> setHorizontalHeaderItem ( 0, newItem );

    newItem = new QTableWidgetItem ( " % CPU " );
    newItem -> setTextAlignment ( Qt::AlignCenter );
    newItem -> setFont ( boldFont );
    ui -> tableWidget -> setHorizontalHeaderItem ( 1, newItem );

    newItem = new QTableWidgetItem ( " PID " );
    newItem -> setTextAlignment ( Qt::AlignCenter );
    newItem -> setFont ( boldFont );
    ui -> tableWidget -> setHorizontalHeaderItem ( 2, newItem );

    newItem = new QTableWidgetItem ( " PPID " );
    newItem -> setTextAlignment ( Qt::AlignCenter );
    newItem -> setFont ( boldFont );
    ui -> tableWidget -> setHorizontalHeaderItem ( 3, newItem );

    newItem = new QTableWidgetItem ( " Prioridade " );
    newItem -> setTextAlignment ( Qt::AlignCenter );
    newItem -> setFont ( boldFont );
    ui -> tableWidget -> setHorizontalHeaderItem ( 4, newItem );

    newItem = new QTableWidgetItem ( " Status " );
    newItem -> setTextAlignment ( Qt::AlignCenter );
    newItem -> setFont ( boldFont );
    ui -> tableWidget -> setHorizontalHeaderItem ( 5, newItem );

    newItem = new QTableWidgetItem ( " Usuário " );
    newItem -> setTextAlignment ( Qt::AlignCenter );
    newItem -> setFont ( boldFont );
    ui -> tableWidget -> setHorizontalHeaderItem ( 6, newItem );
    /**********************************************************************************************************/

    /***************************************************Label**************************************************/
    QFont font ( "times", 16, 600 );
    QFontMetrics font_metrics ( font );
    int width, height;

    //Label
    width = 200;
    height = font_metrics.height ();

    ui -> label -> setText ( "PID do processo:" );
    ui -> label -> setFont ( font );
    ui -> label -> setFixedWidth ( width );
    ui -> label -> setFixedHeight ( height );

    //Label_2
    width = 200;
    height = font_metrics.height ();

    ui -> label_2 -> setText ( "Prioridade:" );
    ui -> label_2 -> setFont ( font );
    ui -> label_2 -> setFixedWidth ( width );
    ui -> label_2 -> setFixedHeight ( height );

    //Label_3
    width = 100;
    height = font_metrics.height ();

    ui -> label_3 -> setText ( "CPU:" );
    ui -> label_3 -> setFont ( font );
    ui -> label_3 -> setFixedWidth ( width );
    ui -> label_3 -> setFixedHeight ( height );

    //Label_4
    width = 100;
    height = font_metrics.height ();

    ui -> label_4 -> setText ( "Filtro:" );
    ui -> label_4 -> setFont ( font );
    ui -> label_4 -> setFixedWidth ( width );
    ui -> label_4 -> setFixedHeight ( height );

    //Label_5
    width = 100;
    height = font_metrics.height ();

    ui -> label_5 -> setText ( "CPU 0:" );
    ui -> label_5 -> setFont ( font );
    ui -> label_5 -> setFixedWidth ( width );
    ui -> label_5 -> setFixedHeight ( height );
    /**********************************************************************************************************/

    /*************************************************LineEdit*************************************************/
    int x, y;

    //LineEdit
    x = ui -> label -> geometry().x();
    y = ui -> label -> geometry().y();
    width = ui -> label -> size().width();
    height = ui -> label -> size().height();
    ui -> lineEdit -> setGeometry ( x + width + 30, y, width, height );

    //LineEdit_2
    x = ui -> label_2 -> geometry().x();
    y = ui -> label_2 -> geometry().y();
    width = ui -> label_2 -> size().width();
    height = ui -> label_2 -> size().height();
    ui -> lineEdit_2 -> setGeometry ( x + width + 30, y, width, height );

    //LineEdit3
    x = ui -> label_3 -> geometry().x();
    y = ui -> label_3 -> geometry().y();
    width = ui -> label_3 -> size().width();
    height = ui -> label_3 -> size().height();
    ui -> lineEdit_3 -> setGeometry ( x + width + 30, y, width, height );

    //LineEdit4
    x = ui -> label_4 -> geometry().x();
    y = ui -> label_4 -> geometry().y();
    width = ui -> label_4 -> size().width();
    height = ui -> label_4 -> size().height();
    ui -> lineEdit_4 -> setGeometry ( x + width + 30, y, width, height );
    /**********************************************************************************************************/

    /************************************************PushButton************************************************/
    //PushButton
    width = 200;
    height = font_metrics.height ();

    ui -> pushButton -> setText ( " Matar " );
    ui -> pushButton -> setFont ( font );
    ui -> pushButton -> setFixedWidth ( width );
    ui -> pushButton -> setFixedHeight ( height );

    x = ui -> lineEdit -> geometry().x() + ui -> lineEdit -> size().width();
    y = ui -> lineEdit -> geometry().y();
    ui -> pushButton -> setGeometry ( x + 30, y - 50, width, height );

    //PushButton_2
    width = 200;
    height = font_metrics.height ();

    ui -> pushButton_2 -> setText ( " Suspender " );
    ui -> pushButton_2 -> setFont ( font );
    ui -> pushButton_2 -> setFixedWidth ( width );
    ui -> pushButton_2 -> setFixedHeight ( height );

    x = ui -> lineEdit -> geometry().x() + ui -> lineEdit -> size().width();
    y = ui -> lineEdit -> geometry().y();
    ui -> pushButton_2 -> setGeometry ( x + 30, y, width, height );

    //PushButton_3
    width = 200;
    height = font_metrics.height ();

    ui -> pushButton_3 -> setText ( " Continuar " );
    ui -> pushButton_3 -> setFont ( font );
    ui -> pushButton_3 -> setFixedWidth ( width );
    ui -> pushButton_3 -> setFixedHeight ( height );

    x = ui -> lineEdit -> geometry().x() + ui -> lineEdit -> size().width();
    y = ui -> lineEdit -> geometry().y();
    ui -> pushButton_3 -> setGeometry ( x + 30, y + 50, width, height );
    /**********************************************************************************************************/

    /***********************************************ProgressBar************************************************/
    x = ui -> label_5 -> geometry().x();
    y = ui -> label_5 -> geometry().y();
    width = ui -> label_5 -> size().width();
    height = ui -> label_5 -> size().height();
    ui -> progressBar -> setGeometry ( x + width + 30, y, width, height );
    /**********************************************************************************************************/

    QTimer *timer = new QTimer ( this );
    connect ( timer, SIGNAL ( timeout () ), this, SLOT ( lista_processos () ) );
    timer -> start ( 1000 );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::imprimirTabela () {
    ifstream inputFile ( "C:\\Users\\Heito\\Desktop\\UFRN\\STR\\Programas\\Gerenciador de processos\\processos.txt" );
    ifstream inputFile2 ( "C:\\Users\\Heito\\Desktop\\UFRN\\STR\\Programas\\Gerenciador de processos\\cpu.txt" );

    if ( !inputFile.is_open () || !inputFile.is_open () ) {
        cerr << "Deu errado para abrir o arquivo";
        exit ( -1 );
    }

    string line;
    int line_count = 0;
    while ( 1 ) {
        getline ( inputFile, line );
        line_count++;
        if ( inputFile.eof () ) break;
    }

    line_count--;

    inputFile.clear ();
    inputFile.seekg ( 0 );
    getline ( inputFile, line );

    string cmd, status, user;
    int pid, ppid, priority, filtro_index;
    float cpu;
    bool flag_lineEdit = false;

    ui -> tableWidget -> setRowCount ( line_count );

    QTableWidgetItem *newItem;
    for ( int i = 0; i < line_count; i++ ) {
        inputFile >> cmd >> cpu >> pid >> ppid >> priority >> status >> user;

        if ( ui -> lineEdit_4 -> text().toStdString () == cmd ) {
            filtro_index = i;
            flag_lineEdit = true;
        }

        newItem = new QTableWidgetItem ( QString::fromStdString ( cmd ) );
        newItem -> setTextAlignment ( Qt::AlignCenter );
        ui -> tableWidget -> setItem ( i, 0, newItem );

        newItem = new QTableWidgetItem ( QString::number ( cpu ) );
        newItem -> setTextAlignment ( Qt::AlignCenter );
        ui -> tableWidget -> setItem ( i, 1, newItem );

        newItem = new QTableWidgetItem ( QString::number ( pid ) );
        newItem -> setTextAlignment ( Qt::AlignCenter );
        ui -> tableWidget -> setItem ( i, 2, newItem );

        newItem = new QTableWidgetItem ( QString::number ( ppid ) );
        newItem -> setTextAlignment ( Qt::AlignCenter );
        ui -> tableWidget -> setItem ( i, 3, newItem );

        newItem = new QTableWidgetItem ( QString::number ( priority ) );
        newItem -> setTextAlignment ( Qt::AlignCenter );
        ui -> tableWidget -> setItem ( i, 4, newItem );

        newItem = new QTableWidgetItem ( QString::fromStdString ( status ) );
        newItem -> setTextAlignment ( Qt::AlignCenter );
        ui -> tableWidget -> setItem ( i, 5, newItem );

        newItem = new QTableWidgetItem ( QString::fromStdString ( user ) );
        newItem -> setTextAlignment ( Qt::AlignCenter );
        ui -> tableWidget -> setItem ( i, 6, newItem );
    }

    if ( flag_lineEdit ) {
        QTableWidgetItem *item = ui -> tableWidget -> item ( filtro_index, 0 );
        ui -> tableWidget -> scrollToItem ( item, QAbstractItemView::PositionAtCenter );
        ui -> tableWidget -> selectRow ( filtro_index );
    }
    else {
        ui -> tableWidget -> scrollToTop ();
        ui -> tableWidget -> selectionModel () -> clearSelection ();
    }

    for ( int i = 0; i < 2; i++ ) inputFile2.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' );
    inputFile2.ignore ( std::numeric_limits<std::streamsize>::max(), ':' );
    inputFile2 >> cpu;

    ui -> progressBar -> setValue ( cpu );
}

void MainWindow::lista_processos () {
    QProcess process;
    process.start ( "cmd", QStringList () << "/c" << "C:\\Windows\\System32\\wsl.exe ps -e -o comm,%cpu,pid,ppid,pri,state,user" );
    process.waitForFinished ();
    QByteArray process_info = process.readAllStandardOutput ();
    process.close ();

    QFile file ( "C:\\Users\\Heito\\Desktop\\UFRN\\STR\\Programas\\Prova_2\\processos.txt" );
    file.open ( QIODevice::WriteOnly );
    file.write ( process_info );
    file.close ();

    process.start ( "cmd", QStringList () << "/c" << "C:\\Windows\\System32\\wsl.exe stdbuf -o0 top 1 -b -n 1" );
    process.waitForFinished ();
    process_info = process.readAllStandardOutput ();
    process.close ();

    QFile file2 ( "C:\\Users\\Heito\\Desktop\\UFRN\\STR\\Programas\\Prova_2\\cpu.txt" );
    file2.open ( QIODevice::WriteOnly );
    file2.write ( process_info );
    file2.close ();

    imprimirTabela ();
}


void MainWindow::on_pushButton_clicked () {
    int PID = ui -> lineEdit -> text().toInt();
    QProcess process;
    process.start ( "cmd", QStringList () << "/c" << "C:\\Windows\\System32\\wsl.exe kill -9" << QString::number ( PID ) );
    process.waitForFinished ();
    process.close ();
    ui -> lineEdit -> clear ();
}


void MainWindow::on_pushButton_2_clicked () {
    int PID = ui -> lineEdit -> text().toInt();
    QProcess process;
    process.start ( "cmd", QStringList () << "/c" << "C:\\Windows\\System32\\wsl.exe kill -STOP" << QString::number ( PID ) );
    process.waitForFinished ();
    process.close ();
    ui -> lineEdit -> clear ();
}


void MainWindow::on_pushButton_3_clicked () {
    int PID = ui -> lineEdit -> text().toInt();
    QProcess process;
    process.start ( "cmd", QStringList () << "/c" << "C:\\Windows\\System32\\wsl.exe kill -CONT" << QString::number ( PID ) );
    process.waitForFinished ();
    process.close ();
    ui -> lineEdit -> clear ();
}


void MainWindow::on_lineEdit_2_returnPressed () {
    int PID = ui -> lineEdit_2 -> text().toInt();
    QProcess process;
    process.start ( "cmd", QStringList () << "/c" << "C:\\Windows\\System32\\wsl.exe renice -n 2 -p" << QString::number ( PID ) );
    process.waitForFinished ();
    process.close ();
    ui -> lineEdit_2 -> clear ();
}


void MainWindow::on_lineEdit_3_returnPressed () {
    int PID = ui -> lineEdit_3 -> text().toInt();
    QProcess process;
    process.start ( "cmd", QStringList () << "/c" << "C:\\Windows\\System32\\wsl.exe taskset -cp 0" << QString::number ( PID ) );
    process.waitForFinished ();
    process.close ();
    ui -> lineEdit_3 -> clear ();
}

