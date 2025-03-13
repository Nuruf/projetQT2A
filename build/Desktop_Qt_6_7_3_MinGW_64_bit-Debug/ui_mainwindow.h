/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_Nom;
    QLineEdit *lineEdit_NbVaccines;
    QLineEdit *lineEdit_Responsable;
    QDateEdit *dateEdit_Debut;
    QDateEdit *dateEdit_Fi;
    QPushButton *pushButton;
    QTableView *tableView;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setEnabled(true);
        label->setGeometry(QRect(40, 90, 61, 21));
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 130, 91, 16));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 170, 63, 20));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 210, 201, 41));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 280, 101, 21));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lineEdit_Nom = new QLineEdit(centralwidget);
        lineEdit_Nom->setObjectName("lineEdit_Nom");
        lineEdit_Nom->setGeometry(QRect(280, 70, 113, 28));
        lineEdit_NbVaccines = new QLineEdit(centralwidget);
        lineEdit_NbVaccines->setObjectName("lineEdit_NbVaccines");
        lineEdit_NbVaccines->setGeometry(QRect(280, 220, 113, 28));
        lineEdit_Responsable = new QLineEdit(centralwidget);
        lineEdit_Responsable->setObjectName("lineEdit_Responsable");
        lineEdit_Responsable->setGeometry(QRect(280, 270, 113, 28));
        dateEdit_Debut = new QDateEdit(centralwidget);
        dateEdit_Debut->setObjectName("dateEdit_Debut");
        dateEdit_Debut->setGeometry(QRect(280, 120, 110, 29));
        dateEdit_Fi = new QDateEdit(centralwidget);
        dateEdit_Fi->setObjectName("dateEdit_Fi");
        dateEdit_Fi->setGeometry(QRect(280, 170, 110, 29));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(190, 380, 131, 41));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(430, 50, 321, 251));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(330, 380, 121, 41));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(460, 380, 141, 41));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(290, 440, 191, 41));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(-170, -130, 1181, 831));
        label_6->setStyleSheet(QString::fromUtf8("image: url(:/Ressources/BackColor.png);"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(-50, 360, 221, 211));
        label_7->setStyleSheet(QString::fromUtf8("image: url(:/Ressources/logoBlancPNG.png);"));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(630, 430, 161, 111));
        label_8->setStyleSheet(QString::fromUtf8("image: url(:/Ressources/iconCOMP.png);"));
        MainWindow->setCentralWidget(centralwidget);
        label_6->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        lineEdit_Nom->raise();
        lineEdit_NbVaccines->raise();
        lineEdit_Responsable->raise();
        dateEdit_Debut->raise();
        dateEdit_Fi->raise();
        pushButton->raise();
        tableView->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        label_7->raise();
        label_8->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Date debut", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Date fin", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Nombre des patients vaccines", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Responsable", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Sauvgarder", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_7->setText(QString());
        label_8->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
