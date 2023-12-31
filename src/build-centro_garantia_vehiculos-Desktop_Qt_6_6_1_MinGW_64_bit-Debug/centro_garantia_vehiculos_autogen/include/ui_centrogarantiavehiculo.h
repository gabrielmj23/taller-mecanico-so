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
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
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
    QDateTimeEdit *dateTimeEdit_3;
    QWidget *page_2;
    QPushButton *pushButton_3;
    QTableWidget *vehiculosClienteTable;
    QLabel *label;
    QDateTimeEdit *dateTimeEdit;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QWidget *page_3;
    QDateTimeEdit *dateTimeEdit_4;
    QPushButton *pushButton_8;
    QTableWidget *vehiculosClienteTable_2;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QLabel *label_2;
    QWidget *tab_2;
    QDateTimeEdit *dateTimeEdit_2;
    QPushButton *pushButton_12;
    QLabel *label_3;
    QLabel *label_4;
    QSlider *horizontalSlider;
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
        tabWidget->setGeometry(QRect(0, -3, 983, 741));
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
        clienteTableWidget->setGeometry(QRect(20, 129, 941, 551));
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
        lineEdit->setGeometry(QRect(20, 70, 231, 41));
        pushButton = new QPushButton(page);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(590, 70, 111, 41));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);"));
        pushButton_5 = new QPushButton(page);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(850, 70, 111, 41));
        pushButton_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        pushButton_2 = new QPushButton(page);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(720, 70, 111, 41));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 0);\n"
"color: rgb(255, 255, 255);"));
        dateTimeEdit_3 = new QDateTimeEdit(page);
        dateTimeEdit_3->setObjectName("dateTimeEdit_3");
        dateTimeEdit_3->setGeometry(QRect(770, 10, 194, 41));
        dateTimeEdit_3->setReadOnly(true);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        pushButton_3 = new QPushButton(page_2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(20, 10, 111, 41));
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
        vehiculosClienteTable->setGeometry(QRect(20, 129, 941, 551));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(40);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(vehiculosClienteTable->sizePolicy().hasHeightForWidth());
        vehiculosClienteTable->setSizePolicy(sizePolicy3);
        vehiculosClienteTable->verticalHeader()->setHighlightSections(false);
        label = new QLabel(page_2);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 70, 531, 41));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label->setFont(font);
        dateTimeEdit = new QDateTimeEdit(page_2);
        dateTimeEdit->setObjectName("dateTimeEdit");
        dateTimeEdit->setGeometry(QRect(770, 10, 194, 41));
        dateTimeEdit->setReadOnly(true);
        pushButton_4 = new QPushButton(page_2);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(590, 70, 111, 41));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);"));
        pushButton_6 = new QPushButton(page_2);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(850, 70, 111, 41));
        pushButton_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        pushButton_7 = new QPushButton(page_2);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(720, 70, 111, 41));
        pushButton_7->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 0);\n"
"color: rgb(255, 255, 255);"));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        dateTimeEdit_4 = new QDateTimeEdit(page_3);
        dateTimeEdit_4->setObjectName("dateTimeEdit_4");
        dateTimeEdit_4->setGeometry(QRect(770, 10, 194, 41));
        dateTimeEdit_4->setReadOnly(true);
        pushButton_8 = new QPushButton(page_3);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(20, 10, 111, 41));
        vehiculosClienteTable_2 = new QTableWidget(page_3);
        if (vehiculosClienteTable_2->columnCount() < 4)
            vehiculosClienteTable_2->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        vehiculosClienteTable_2->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        vehiculosClienteTable_2->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        vehiculosClienteTable_2->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        vehiculosClienteTable_2->setHorizontalHeaderItem(3, __qtablewidgetitem11);
        vehiculosClienteTable_2->setObjectName("vehiculosClienteTable_2");
        vehiculosClienteTable_2->setGeometry(QRect(20, 129, 941, 551));
        sizePolicy3.setHeightForWidth(vehiculosClienteTable_2->sizePolicy().hasHeightForWidth());
        vehiculosClienteTable_2->setSizePolicy(sizePolicy3);
        vehiculosClienteTable_2->verticalHeader()->setHighlightSections(false);
        pushButton_9 = new QPushButton(page_3);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(720, 70, 111, 41));
        pushButton_9->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 0);\n"
"color: rgb(255, 255, 255);"));
        pushButton_10 = new QPushButton(page_3);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(590, 70, 111, 41));
        pushButton_10->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);"));
        pushButton_11 = new QPushButton(page_3);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(850, 70, 111, 41));
        pushButton_11->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        label_2 = new QLabel(page_3);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 70, 531, 41));
        label_2->setFont(font);
        stackedWidget->addWidget(page_3);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        dateTimeEdit_2 = new QDateTimeEdit(tab_2);
        dateTimeEdit_2->setObjectName("dateTimeEdit_2");
        dateTimeEdit_2->setGeometry(QRect(770, 10, 194, 41));
        dateTimeEdit_2->setReadOnly(true);
        pushButton_12 = new QPushButton(tab_2);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(370, 120, 181, 111));
        QPalette palette;
        QBrush brush(QColor(170, 0, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        pushButton_12->setPalette(palette);
        QFont font1;
        font1.setBold(true);
        pushButton_12->setFont(font1);
        pushButton_12->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 0, 255);"));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 70, 621, 41));
        label_3->setFont(font);
        label_4 = new QLabel(tab_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 290, 621, 41));
        label_4->setFont(font);
        horizontalSlider = new QSlider(tab_2);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(370, 360, 160, 42));
        horizontalSlider->setOrientation(Qt::Horizontal);
        tabWidget->addTab(tab_2, QString());
        CentroGarantiaVehiculo->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(CentroGarantiaVehiculo);
        statusbar->setObjectName("statusbar");
        CentroGarantiaVehiculo->setStatusBar(statusbar);

        retranslateUi(CentroGarantiaVehiculo);

        tabWidget->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(2);


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
        dateTimeEdit_3->setDisplayFormat(QCoreApplication::translate("CentroGarantiaVehiculo", "d/M/yyyy h:mm AP", nullptr));
        pushButton_3->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "< Volver", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = vehiculosClienteTable->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "N\303\272mero de Placa", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = vehiculosClienteTable->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "Ubicaci\303\263n", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = vehiculosClienteTable->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "N\303\272mero de Servicios", nullptr));
        label->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "Vehiculos de ", nullptr));
        dateTimeEdit->setDisplayFormat(QCoreApplication::translate("CentroGarantiaVehiculo", "d/M/yyyy h:mm AP", nullptr));
        pushButton_4->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "Seleccionar", nullptr));
        pushButton_6->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "Eliminar", nullptr));
        pushButton_7->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "Agregar", nullptr));
        dateTimeEdit_4->setDisplayFormat(QCoreApplication::translate("CentroGarantiaVehiculo", "d/M/yyyy h:mm AP", nullptr));
        pushButton_8->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "< Volver", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = vehiculosClienteTable_2->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "Fecha de Ingreso", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = vehiculosClienteTable_2->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "Fecha de Egreso", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = vehiculosClienteTable_2->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "Raz\303\263n", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = vehiculosClienteTable_2->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "Kilometraje de Ingreso", nullptr));
        pushButton_9->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "Agregar", nullptr));
        pushButton_10->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "Seleccionar", nullptr));
        pushButton_11->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "Eliminar", nullptr));
        label_2->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "Servicios al Veh\303\255culo de Placa ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("CentroGarantiaVehiculo", "Manual", nullptr));
        dateTimeEdit_2->setDisplayFormat(QCoreApplication::translate("CentroGarantiaVehiculo", "d/M/yyyy h:mm AP", nullptr));
        pushButton_12->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "GENERAR", nullptr));
        label_3->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "Presione el bot\303\263n para generar datos aleatorios", nullptr));
        label_4->setText(QCoreApplication::translate("CentroGarantiaVehiculo", "Velocidad de Tiempo", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("CentroGarantiaVehiculo", "Otros", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CentroGarantiaVehiculo: public Ui_CentroGarantiaVehiculo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CENTROGARANTIAVEHICULO_H
