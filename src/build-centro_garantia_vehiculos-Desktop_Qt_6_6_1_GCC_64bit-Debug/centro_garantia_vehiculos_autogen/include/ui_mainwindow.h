/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionManual;
    QAction *actionAutomatico;
    QAction *actionAjustes;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuAleatorio;
    QMenu *menuAjustes;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(982, 838);
        MainWindow->setMinimumSize(QSize(982, 838));
        MainWindow->setMaximumSize(QSize(982, 838));
        actionManual = new QAction(MainWindow);
        actionManual->setObjectName("actionManual");
        actionAutomatico = new QAction(MainWindow);
        actionAutomatico->setObjectName("actionAutomatico");
        actionAjustes = new QAction(MainWindow);
        actionAjustes->setObjectName("actionAjustes");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 982, 23));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName("menuMenu");
        menuAleatorio = new QMenu(menubar);
        menuAleatorio->setObjectName("menuAleatorio");
        menuAjustes = new QMenu(menubar);
        menuAjustes->setObjectName("menuAjustes");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menubar->addAction(menuAleatorio->menuAction());
        menubar->addAction(menuAjustes->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Centro de Garantia y Vehiculos", nullptr));
        actionManual->setText(QCoreApplication::translate("MainWindow", "Manual", nullptr));
        actionAutomatico->setText(QCoreApplication::translate("MainWindow", "Aleatorio", nullptr));
        actionAjustes->setText(QCoreApplication::translate("MainWindow", "Ajustes", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("MainWindow", "Manual", nullptr));
        menuAleatorio->setTitle(QCoreApplication::translate("MainWindow", "Aleatorio", nullptr));
        menuAjustes->setTitle(QCoreApplication::translate("MainWindow", "Ajustes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
