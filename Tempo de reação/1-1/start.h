#ifndef START_H
#define START_H

#include <QDialog>

namespace Ui {
class Start;
}

class Start : public QDialog
{
    Q_OBJECT

public:
    explicit Start(QWidget *parent = nullptr);
    ~Start();

private slots:
    void on_buttonBox_accepted ();

private:
    Ui::Start *ui;

signals:
    void signalStart ();
};

#endif // START_H
