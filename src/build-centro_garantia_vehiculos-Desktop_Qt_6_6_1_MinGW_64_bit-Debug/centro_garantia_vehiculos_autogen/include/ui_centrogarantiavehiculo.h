/********************************************************************************
** Form generated from reading UI file 'centrogarantiavehiculo.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CENTROGARANTIAVEHICULO_H
#define UI_CENTROGARANTIAVEHICULO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CentroGarantiaVehiculo
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QTextEdit *textEdit;
    QWidget *page_2;
    QTableWidget *clienteTableWidget;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_5;
    QPushButton *pushButton_2;
    QWidget *tab_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CentroGarantiaVehiculo)
    {
        if (CentroGarantiaVehiculo->objectName().isEmpty())
            CentroGarantiaVehiculo->setObjectName("CentroGarantiaVehiculo");
        CentroGarantiaVehiculo->resize(983, 738);
        centralwidget = new QWidget(CentroGarantiaVehiculo);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 983, 738));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tab = new QWidget();
        tab->setObjectName("tab");
        stackedWidget = new QStackedWidget(tab);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 981, 701));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy1);
        page = new QWidget();
        page->setObjectName("page");
        textEdit = new QTextEdit(page);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(310, 310, 104, 87));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        clienteTableWidget = new QTableWidget(page_2);
        if (clienteTableWidget->columnCount() < 5)
            clienteTableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        clienteTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        clienteTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        clienteTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        clienteTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        clienteTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        clienteTableWidget->setObjectName("clienteTableWidget");
        clienteTableWidget->setGeometry(QRect(20, 90, 941, 600));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(clienteTableWidget->sizePolicy().hasHeightForWidth());
        clienteTableWidget->setSizePolicy(sizePolicy2);
#if QT_CONFIG(accessibility)
        clienteTableWidget->setAccessibleName(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        clienteTableWidget->setAccessibleDescription(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
        clienteTableWidget->setWordWrap(true);
        clienteTableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        clienteTableWidget->horizontalHeader()->setStretchLastSection(false);
        clienteTableWidget->verticalHeader()->setVisible(false);
        lineEdit = new QLineEdit(page_2);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(20, 20, 231, 41));
        pushButton = new QPushButton(page_2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(610, 20, 111, 41));
        pushButton_5 = new QPushButton(page_2);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(850, 20, 111, 41));
        pushButton_2 = new QPushButton(page_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(730, 20, 111, 41));
        stackedWidget->addWidget(page_2);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tabWidget->addTab(tab_2, QString());
        CentroGarantiaVehiculo->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(CentroGarantiaVehiculo);
        statusbar->setObjectName("statusbar");
        CentroGarantiaVehiculo->setStatusBar(statusbar);

        retranslateUi(CentroGarantiaVehiculo);

        tabWidget->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(CentroGarantiaVehiculo);
    } // setupUi

    void retranslateUi(QMainWindow *CentroGarantiaVehiculo)
    {
        CentroGarantiaVehiculo->setWindowTitle(QCoreApplication::translate("CentroGarantiaVehiculo", "Centro de Garant\303\255a y Veh\303\255culos", nullptr));
        textEdit->setHtml(QCoreApplication::translate("CentroGarantiaVehiculo", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">pruba 1</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        QTableWidgetItem *___qtablewidgetitem = clienteTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "Nombre", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = clienteTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "Cedula", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = clienteTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "N\303\272mero de Carros", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = clienteTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "Fecha de Registro", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = clienteTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "N\303\272mero de Contacto", nullptr));
        pushButton->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "Seleccionar", nullptr));
        pushButton_5->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "Eliminar", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "Agregar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("CentroGarantiaVehiculo", "Manual", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("CentroGarantiaVehiculo", "Otros", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CentroGarantiaVehiculo: public Ui_CentroGarantiaVehiculo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CENTROGARANTIAVEHICULO_H
