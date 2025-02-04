#include "resultado.h"
#include "ui_resultado.h"
#include <QPushButton>

Resultado::Resultado(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Resultado)
{
    ui->setupUi(this);

    ui -> buttonBox -> button ( QDialogButtonBox::Ok ) -> setText ( "Restart" );
    ui -> buttonBox -> button ( QDialogButtonBox::Cancel ) -> setText ( "Exit" );
}

Resultado::~Resultado()
{
    delete ui;
}

void Resultado::on_buttonBox_accepted () {
    emit signalStart ();
}


void Resultado::on_buttonBox_rejected() {
    QCoreApplication::quit ();
}

void Resultado::slotText ( QString str, int hit, int miss ) {
    ui -> label_tempo -> setText ( str + " millisec" );
    ui -> label_hit -> setText ( QString::number ( hit ) );
    ui -> label_miss -> setText ( QString::number ( miss ) );
}

