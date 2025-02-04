/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QSlider *verticalSlider;
    QSlider *verticalSlider_2;
    QSlider *verticalSlider_3;
    QSlider *verticalSlider_4;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 800);
        MainWindow->setMinimumSize(QSize(800, 800));
        MainWindow->setMaximumSize(QSize(800, 800));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalSlider = new QSlider(centralwidget);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setGeometry(QRect(100, 500, 18, 160));
        verticalSlider->setMinimum(3000);
        verticalSlider->setMaximum(50000);
        verticalSlider->setSliderPosition(50000);
        verticalSlider->setOrientation(Qt::Vertical);
        verticalSlider_2 = new QSlider(centralwidget);
        verticalSlider_2->setObjectName(QString::fromUtf8("verticalSlider_2"));
        verticalSlider_2->setGeometry(QRect(300, 500, 18, 160));
        verticalSlider_2->setMinimum(3000);
        verticalSlider_2->setMaximum(50000);
        verticalSlider_2->setSliderPosition(50000);
        verticalSlider_2->setOrientation(Qt::Vertical);
        verticalSlider_3 = new QSlider(centralwidget);
        verticalSlider_3->setObjectName(QString::fromUtf8("verticalSlider_3"));
        verticalSlider_3->setGeometry(QRect(500, 500, 18, 160));
        verticalSlider_3->setMinimum(3000);
        verticalSlider_3->setMaximum(50000);
        verticalSlider_3->setValue(50000);
        verticalSlider_3->setOrientation(Qt::Vertical);
        verticalSlider_4 = new QSlider(centralwidget);
        verticalSlider_4->setObjectName(QString::fromUtf8("verticalSlider_4"));
        verticalSlider_4->setGeometry(QRect(700, 500, 18, 160));
        verticalSlider_4->setMinimum(3000);
        verticalSlider_4->setMaximum(50000);
        verticalSlider_4->setValue(50000);
        verticalSlider_4->setOrientation(Qt::Vertical);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(250, 430, 100, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(95, 700, 55, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(280, 700, 55, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(495, 700, 55, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(680, 700, 55, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Verde", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Amarelo", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Azul", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Vermelho", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
