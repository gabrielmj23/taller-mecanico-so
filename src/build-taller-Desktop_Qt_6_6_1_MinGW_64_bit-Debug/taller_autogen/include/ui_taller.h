/********************************************************************************
** Form generated from reading UI file 'taller.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TALLER_H
#define UI_TALLER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Taller
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Taller)
    {
        if (Taller->objectName().isEmpty())
            Taller->setObjectName("Taller");
        Taller->resize(800, 600);
        centralwidget = new QWidget(Taller);
        centralwidget->setObjectName("centralwidget");
        Taller->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Taller);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        Taller->setMenuBar(menubar);
        statusbar = new QStatusBar(Taller);
        statusbar->setObjectName("statusbar");
        Taller->setStatusBar(statusbar);

        retranslateUi(Taller);

        QMetaObject::connectSlotsByName(Taller);
    } // setupUi

    void retranslateUi(QMainWindow *Taller)
    {
        Taller->setWindowTitle(QCoreApplication::translate("Taller", "Taller", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Taller: public Ui_Taller {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TALLER_H
