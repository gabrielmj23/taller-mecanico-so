/********************************************************************************
** Form generated from reading UI file 'taller.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TALLER_H
#define UI_TALLER_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Taller
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QTableWidget *tablaClienteVehiculo;
    QLabel *label_8;
    QWidget *tab_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLineEdit *lineEdit;
    QTableWidget *tablaClientes;
    QPushButton *pushButton;
    QWidget *page_2;
    QPushButton *pushButton_2;
    QLabel *label;
    QTableWidget *tablaVehiculos;
    QPushButton *pushButton_3;
    QWidget *page_3;
    QTableWidget *tablaServicios;
    QPushButton *pushButton_8;
    QLabel *label_9;
    QWidget *tab_3;
    QWidget *tab_4;
    QWidget *tab_5;
    QWidget *tab_6;
    QWidget *tab_7;
    QLabel *label_7;
    QDateTimeEdit *dateTimeEdit;
    QLabel *label_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Taller)
    {
        if (Taller->objectName().isEmpty())
            Taller->setObjectName("Taller");
        Taller->resize(983, 738);
        centralwidget = new QWidget(Taller);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 57, 983, 681));
        tabWidget->setContextMenuPolicy(Qt::DefaultContextMenu);
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tabWidget->setTabPosition(QTabWidget::West);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideLeft);
        tabWidget->setDocumentMode(false);
        tab = new QWidget();
        tab->setObjectName("tab");
        label_3 = new QLabel(tab);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 10, 181, 81));
        QFont font;
        font.setWeight(QFont::Black);
        label_3->setFont(font);
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setAutoFillBackground(false);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(180, 105, 255);\n"
"color: rgb(255, 255, 255);\n"
"border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-radius:10px;\n"
""));
        label_3->setFrameShape(QFrame::Box);
        label_3->setFrameShadow(QFrame::Raised);
        label_3->setAlignment(Qt::AlignCenter);
        label_3->setWordWrap(true);
        label_4 = new QLabel(tab);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(240, 10, 181, 81));
        label_4->setFont(font);
        label_4->setLayoutDirection(Qt::LeftToRight);
        label_4->setAutoFillBackground(false);
        label_4->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);\n"
"border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-radius:10px;\n"
"background-color: rgb(2, 210, 26);\n"
""));
        label_4->setFrameShape(QFrame::Box);
        label_4->setFrameShadow(QFrame::Raised);
        label_4->setAlignment(Qt::AlignCenter);
        label_4->setWordWrap(true);
        label_5 = new QLabel(tab);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(460, 10, 181, 81));
        label_5->setFont(font);
        label_5->setLayoutDirection(Qt::LeftToRight);
        label_5->setAutoFillBackground(false);
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 82, 198);\n"
"color: rgb(255, 255, 255);\n"
"border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-radius:10px;\n"
""));
        label_5->setFrameShape(QFrame::Box);
        label_5->setFrameShadow(QFrame::Raised);
        label_5->setAlignment(Qt::AlignCenter);
        label_5->setWordWrap(true);
        label_6 = new QLabel(tab);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(690, 10, 181, 81));
        label_6->setFont(font);
        label_6->setLayoutDirection(Qt::LeftToRight);
        label_6->setAutoFillBackground(false);
        label_6->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);\n"
"border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-radius:10px;\n"
""));
        label_6->setFrameShape(QFrame::Box);
        label_6->setFrameShadow(QFrame::Raised);
        label_6->setAlignment(Qt::AlignCenter);
        label_6->setWordWrap(true);
        tablaClienteVehiculo = new QTableWidget(tab);
        if (tablaClienteVehiculo->columnCount() < 4)
            tablaClienteVehiculo->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tablaClienteVehiculo->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tablaClienteVehiculo->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tablaClienteVehiculo->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tablaClienteVehiculo->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tablaClienteVehiculo->setObjectName("tablaClienteVehiculo");
        tablaClienteVehiculo->setGeometry(QRect(10, 180, 861, 192));
        label_8 = new QLabel(tab);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 120, 841, 41));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8(""));
        label_8->setLocale(QLocale(QLocale::Spanish, QLocale::Venezuela));
        label_8->setAlignment(Qt::AlignCenter);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        stackedWidget = new QStackedWidget(tab_2);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(-1, -1, 951, 651));
        page = new QWidget();
        page->setObjectName("page");
        lineEdit = new QLineEdit(page);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(10, 10, 231, 41));
        tablaClientes = new QTableWidget(page);
        if (tablaClientes->columnCount() < 5)
            tablaClientes->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tablaClientes->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tablaClientes->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tablaClientes->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tablaClientes->setHorizontalHeaderItem(3, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tablaClientes->setHorizontalHeaderItem(4, __qtablewidgetitem8);
        tablaClientes->setObjectName("tablaClientes");
        tablaClientes->setGeometry(QRect(10, 80, 861, 571));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tablaClientes->sizePolicy().hasHeightForWidth());
        tablaClientes->setSizePolicy(sizePolicy);
#if QT_CONFIG(accessibility)
        tablaClientes->setAccessibleName(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        tablaClientes->setAccessibleDescription(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
        tablaClientes->setAlternatingRowColors(false);
        tablaClientes->setWordWrap(true);
        tablaClientes->horizontalHeader()->setCascadingSectionResizes(false);
        tablaClientes->horizontalHeader()->setStretchLastSection(false);
        tablaClientes->verticalHeader()->setVisible(false);
        pushButton = new QPushButton(page);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(760, 10, 111, 41));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        pushButton_2 = new QPushButton(page_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(760, 10, 111, 41));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);"));
        label = new QLabel(page_2);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 71, 531, 41));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        label->setFont(font2);
        tablaVehiculos = new QTableWidget(page_2);
        if (tablaVehiculos->columnCount() < 3)
            tablaVehiculos->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tablaVehiculos->setHorizontalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tablaVehiculos->setHorizontalHeaderItem(1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tablaVehiculos->setHorizontalHeaderItem(2, __qtablewidgetitem11);
        tablaVehiculos->setObjectName("tablaVehiculos");
        tablaVehiculos->setGeometry(QRect(10, 130, 861, 521));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(40);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tablaVehiculos->sizePolicy().hasHeightForWidth());
        tablaVehiculos->setSizePolicy(sizePolicy1);
        tablaVehiculos->verticalHeader()->setHighlightSections(false);
        pushButton_3 = new QPushButton(page_2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(10, 10, 111, 41));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        tablaServicios = new QTableWidget(page_3);
        if (tablaServicios->columnCount() < 4)
            tablaServicios->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tablaServicios->setHorizontalHeaderItem(0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tablaServicios->setHorizontalHeaderItem(1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tablaServicios->setHorizontalHeaderItem(2, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tablaServicios->setHorizontalHeaderItem(3, __qtablewidgetitem15);
        tablaServicios->setObjectName("tablaServicios");
        tablaServicios->setGeometry(QRect(10, 130, 861, 521));
        sizePolicy1.setHeightForWidth(tablaServicios->sizePolicy().hasHeightForWidth());
        tablaServicios->setSizePolicy(sizePolicy1);
        tablaServicios->verticalHeader()->setHighlightSections(false);
        pushButton_8 = new QPushButton(page_3);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(10, 10, 111, 41));
        label_9 = new QLabel(page_3);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 70, 531, 41));
        label_9->setFont(font2);
        stackedWidget->addWidget(page_3);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        tabWidget->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName("tab_7");
        tabWidget->addTab(tab_7, QString());
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(0, 0, 983, 57));
        label_7->setFont(font);
        label_7->setLayoutDirection(Qt::LeftToRight);
        label_7->setAutoFillBackground(false);
        label_7->setStyleSheet(QString::fromUtf8("background-color: rgb(214, 27, 34);\n"
"\n"
"border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"\n"
""));
        label_7->setFrameShape(QFrame::Box);
        label_7->setFrameShadow(QFrame::Raised);
        label_7->setAlignment(Qt::AlignCenter);
        label_7->setWordWrap(true);
        dateTimeEdit = new QDateTimeEdit(centralwidget);
        dateTimeEdit->setObjectName("dateTimeEdit");
        dateTimeEdit->setGeometry(QRect(780, 10, 194, 41));
        dateTimeEdit->setReadOnly(true);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 10, 981, 41));
        QFont font3;
        font3.setPointSize(22);
        font3.setBold(true);
        label_2->setFont(font3);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_2->setLocale(QLocale(QLocale::Spanish, QLocale::Venezuela));
        label_2->setAlignment(Qt::AlignCenter);
        Taller->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Taller);
        statusbar->setObjectName("statusbar");
        Taller->setStatusBar(statusbar);

        retranslateUi(Taller);

        tabWidget->setCurrentIndex(1);
        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Taller);
    } // setupUi

    void retranslateUi(QMainWindow *Taller)
    {
        Taller->setWindowTitle(QCoreApplication::translate("Taller", "Taller", nullptr));
        label_3->setText(QCoreApplication::translate("Taller", "Clientes 5", nullptr));
        label_4->setText(QCoreApplication::translate("Taller", "Veh\303\255culos en Cola 2", nullptr));
        label_5->setText(QCoreApplication::translate("Taller", "Veh\303\255culos en una de las Estaciones 5", nullptr));
        label_6->setText(QCoreApplication::translate("Taller", "Servicios Completados 20", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tablaClienteVehiculo->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Taller", "Tipo", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tablaClienteVehiculo->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Taller", "Nombre", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tablaClienteVehiculo->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Taller", "Hora", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tablaClienteVehiculo->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Taller", "Placa", nullptr));
        label_8->setText(QCoreApplication::translate("Taller", "\303\232ltimas Entradas y Salidas", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Taller", "Inicio", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        lineEdit->setPlaceholderText(QCoreApplication::translate("Taller", "Ingrese el nombre del cliente", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tablaClientes->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Taller", "Nombre", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tablaClientes->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Taller", "Cedula", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tablaClientes->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Taller", "Fecha de Registro", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tablaClientes->horizontalHeaderItem(3);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Taller", "N\303\272mero de Carros", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tablaClientes->horizontalHeaderItem(4);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("Taller", "N\303\272mero de Contacto", nullptr));
        pushButton->setText(QCoreApplication::translate("Taller", "Seleccionar", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Taller", "Seleccionar", nullptr));
        label->setText(QCoreApplication::translate("Taller", "Vehiculos de ", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tablaVehiculos->horizontalHeaderItem(0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("Taller", "N\303\272mero de Placa", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tablaVehiculos->horizontalHeaderItem(1);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("Taller", "Ubicaci\303\263n", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tablaVehiculos->horizontalHeaderItem(2);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("Taller", "N\303\272mero de Servicios", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Taller", "< Volver", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tablaServicios->horizontalHeaderItem(0);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("Taller", "Fecha de Ingreso", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tablaServicios->horizontalHeaderItem(1);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("Taller", "Fecha de Egreso", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tablaServicios->horizontalHeaderItem(2);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("Taller", "Raz\303\263n", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tablaServicios->horizontalHeaderItem(3);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("Taller", "Kilometraje de Ingreso", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Taller", "< Volver", nullptr));
        label_9->setText(QCoreApplication::translate("Taller", "Servicios al Veh\303\255culo de Placa ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Taller", "Clientes", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("Taller", "Estacionamiento", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("Taller", "Diagn\303\263stico", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("Taller", "Piezas", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("Taller", "Compra de Piezas", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QCoreApplication::translate("Taller", "Estaciones", nullptr));
        label_7->setText(QString());
        label_2->setText(QCoreApplication::translate("Taller", "Inicio", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Taller: public Ui_Taller {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TALLER_H
