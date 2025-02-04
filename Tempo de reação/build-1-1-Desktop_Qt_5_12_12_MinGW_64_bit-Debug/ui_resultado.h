/********************************************************************************
** Form generated from reading UI file 'resultado.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULTADO_H
#define UI_RESULTADO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Resultado
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_tempo;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_hit;
    QLabel *label_miss;

    void setupUi(QDialog *Resultado)
    {
        if (Resultado->objectName().isEmpty())
            Resultado->setObjectName(QString::fromUtf8("Resultado"));
        Resultado->resize(220, 200);
        Resultado->setMinimumSize(QSize(220, 200));
        Resultado->setMaximumSize(QSize(220, 200));
        buttonBox = new QDialogButtonBox(Resultado);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(-15, 130, 221, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(Resultado);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(8, 40, 84, 16));
        label_tempo = new QLabel(Resultado);
        label_tempo->setObjectName(QString::fromUtf8("label_tempo"));
        label_tempo->setGeometry(QRect(94, 40, 150, 16));
        label_2 = new QLabel(Resultado);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(8, 70, 55, 16));
        label_3 = new QLabel(Resultado);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(8, 100, 41, 16));
        label_hit = new QLabel(Resultado);
        label_hit->setObjectName(QString::fromUtf8("label_hit"));
        label_hit->setGeometry(QRect(65, 70, 121, 16));
        label_miss = new QLabel(Resultado);
        label_miss->setObjectName(QString::fromUtf8("label_miss"));
        label_miss->setGeometry(QRect(51, 100, 111, 16));

        retranslateUi(Resultado);
        QObject::connect(buttonBox, SIGNAL(accepted()), Resultado, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Resultado, SLOT(reject()));

        QMetaObject::connectSlotsByName(Resultado);
    } // setupUi

    void retranslateUi(QDialog *Resultado)
    {
        Resultado->setWindowTitle(QApplication::translate("Resultado", "Dialog", nullptr));
        label->setText(QApplication::translate("Resultado", "Tempo m\303\251dio:", nullptr));
        label_tempo->setText(QString());
        label_2->setText(QApplication::translate("Resultado", "Acertos:", nullptr));
        label_3->setText(QApplication::translate("Resultado", "Erros:", nullptr));
        label_hit->setText(QString());
        label_miss->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Resultado: public Ui_Resultado {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTADO_H
