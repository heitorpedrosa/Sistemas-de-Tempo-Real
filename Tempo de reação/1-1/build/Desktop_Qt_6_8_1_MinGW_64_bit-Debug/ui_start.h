/********************************************************************************
** Form generated from reading UI file 'start.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_START_H
#define UI_START_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Start
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *Start)
    {
        if (Start->objectName().isEmpty())
            Start->setObjectName("Start");
        Start->resize(220, 200);
        Start->setMinimumSize(QSize(220, 200));
        Start->setMaximumSize(QSize(220, 200));
        buttonBox = new QDialogButtonBox(Start);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(-15, 130, 221, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(Start);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 60, 201, 21));

        retranslateUi(Start);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Start, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Start, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Start);
    } // setupUi

    void retranslateUi(QDialog *Start)
    {
        Start->setWindowTitle(QCoreApplication::translate("Start", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Start", "Ap\303\263s clicar em Ok, inicia em 1 seg", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Start: public Ui_Start {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_H
