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
    QTableWidget *clienteTableWidget;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_5;
    QPushButton *pushButton_2;
    QWidget *page_2;
    QPushButton *pushButton_3;
    QTableWidget *vehiculosClienteTable;
    QWidget *page_3;
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
        clienteTableWidget = new QTableWidget(page);
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
        clienteTableWidget->setAlternatingRowColors(false);
        clienteTableWidget->setWordWrap(true);
        clienteTableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        clienteTableWidget->horizontalHeader()->setStretchLastSection(false);
        clienteTableWidget->verticalHeader()->setVisible(false);
        lineEdit = new QLineEdit(page);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(20, 20, 231, 41));
        pushButton = new QPushButton(page);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(610, 20, 111, 41));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);"));
        pushButton_5 = new QPushButton(page);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(850, 20, 111, 41));
        pushButton_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        pushButton_2 = new QPushButton(page);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(730, 20, 111, 41));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 0);\n"
"color: rgb(255, 255, 255);"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        pushButton_3 = new QPushButton(page_2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(20, 20, 111, 41));
        vehiculosClienteTable = new QTableWidget(page_2);
        if (vehiculosClienteTable->columnCount() < 3)
            vehiculosClienteTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        vehiculosClienteTable->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        vehiculosClienteTable->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        vehiculosClienteTable->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        vehiculosClienteTable->setObjectName("vehiculosClienteTable");
        vehiculosClienteTable->setGeometry(QRect(20, 90, 941, 600));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(40);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(vehiculosClienteTable->sizePolicy().hasHeightForWidth());
        vehiculosClienteTable->setSizePolicy(sizePolicy3);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        stackedWidget->addWidget(page_3);
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
        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CentroGarantiaVehiculo);
    } // setupUi

    void retranslateUi(QMainWindow *CentroGarantiaVehiculo)
    {
        CentroGarantiaVehiculo->setWindowTitle(QCoreApplication::translate("CentroGarantiaVehiculo", "Centro de Garant\303\255a y Veh\303\255culos", nullptr));
        QTableWidgetItem *___qtablewidgetitem = clienteTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "Nombre", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = clienteTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "Cedula", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = clienteTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "Fecha de Registro", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = clienteTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "N\303\272mero de Carros", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = clienteTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "N\303\272mero de Contacto", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        lineEdit->setPlaceholderText(QCoreApplication::translate("CentroGarantiaVehiculo", "Ingrese el nombre del cliente", nullptr));
        pushButton->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "Seleccionar", nullptr));
        pushButton_5->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "Eliminar", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "Agregar", nullptr));
        pushButton_3->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "< Volver", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = vehiculosClienteTable->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "N\303\272mero de Placa", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = vehiculosClienteTable->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "Ubicaci\303\263n", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = vehiculosClienteTable->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "N\303\272mero de Servicios", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("CentroGarantiaVehiculo", "Manual", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("CentroGarantiaVehiculo", "Otros", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CentroGarantiaVehiculo: public Ui_CentroGarantiaVehiculo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CENTROGARANTIAVEHICULO_H
