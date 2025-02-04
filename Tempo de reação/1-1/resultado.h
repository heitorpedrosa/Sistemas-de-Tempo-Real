#ifndef RESULTADO_H
#define RESULTADO_H

#include <QDialog>

namespace Ui {
class Resultado;
}

class Resultado : public QDialog
{
    Q_OBJECT

public:
    explicit Resultado(QWidget *parent = nullptr);
    ~Resultado();

private slots:
    void on_buttonBox_accepted ();
    void on_buttonBox_rejected ();

public slots:
    void slotText ( QString str, int hit, int miss );

private:
    Ui::Resultado *ui;

signals:
    void signalStart ();
};

#endif // RESULTADO_H
