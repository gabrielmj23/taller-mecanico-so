#include <QHeaderView>
#include <QLineEdit>
#include <QDialog>
#include <QComboBox>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QTableWidgetItem>
#include <QDebug>
#include <QDate>
#include <QString>
#include <vector>
#include <string>
#include <ctime>
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "centrogarantiavehiculo.h"
#include "./ui_centrogarantiavehiculo.h"
#include "Servicio.h"
#include "Cliente.h"
#include "Vehiculo.h"
#include "clientUtils.h"
using namespace std;

#define NUM_RANDOMS 10

// Variables globales
string cedulaActual = "";
string placaActual = "";

// Actualiza las propiedades de los items de la tabla (centrar y no editable)
void actItemsTabla(QTableWidget *tableWidget)
{
    // Los items no son editables y están centrados
    for (int i = 0; i < tableWidget->rowCount(); i++)
    {
        for (int j = 0; j < tableWidget->columnCount(); j++)
        {
            QTableWidgetItem *item = tableWidget->item(i, j);
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            item->setTextAlignment(Qt::AlignCenter);
        }
    }
}

// Rellena la tabla de clientes basado en los contenidos del archivo de clientes
void rellenarTablaClientes(QTableWidget *tableWidget)
{
    // Limpiar la tabla de clientes
    tableWidget->clearContents();
    tableWidget->setRowCount(0);

    // Agregar clientes a la tabla
    vector<Cliente> clientes = Cliente::cargarClientesDesdeArchivo();
    vector<Vehiculo> vehiculos = Vehiculo::cargarVehiculosDesdeArchivo();
    for (int i = 0; i < clientes.size(); i++)
    {
        tableWidget->insertRow(i);
        tableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(clientes[i].getNombre())));
        tableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(clientes[i].getCedula())));
        tableWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(clientes[i].getFechaRegistro())));
        tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(clientes[i].getNumVehiculos(vehiculos))));
        tableWidget->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(clientes[i].getNumContacto())));
    }
    actItemsTabla(tableWidget);
}

// Rellena la tabla de vehiculos basado en los contenidos del archivo de vehiculos
void rellenarTablaVehiculos(QTableWidget *tableWidget)
{
    // Limpiar la tabla de vehículos
    tableWidget->clearContents();
    tableWidget->setRowCount(0);

    // Agregar vehículos
    vector<Vehiculo> vehiculos = Vehiculo::cargarVehiculosDesdeArchivo();
    for (Vehiculo vehiculo : vehiculos)
    {
        // Verificar si el vehículo tiene la misma cédula del cliente
        if (vehiculo.getCedulaCliente().compare(cedulaActual) == 0)
        {
            // Obtener la información del vehículo
            string placa = vehiculo.getPlaca();
            string dentroTaller = vehiculo.getEnTaller() ? "Sí" : "No";

            // Agregar una nueva fila a la tabla de vehículos del cliente
            int numRows = tableWidget->rowCount();
            tableWidget->insertRow(numRows);

            // Mostrar la información del vehículo en la tabla
            QTableWidgetItem *itemPlaca = new QTableWidgetItem(QString::fromStdString(placa));
            QTableWidgetItem *itemDentroTaller = new QTableWidgetItem(QString::fromStdString(dentroTaller));
            QTableWidgetItem *itemNumServicios = new QTableWidgetItem(QString::number(vehiculo.getNumServicios()));

            tableWidget->setItem(numRows, 0, itemPlaca);
            tableWidget->setItem(numRows, 1, itemDentroTaller);
            tableWidget->setItem(numRows, 2, itemNumServicios);
        }
    }
    actItemsTabla(tableWidget);
    tableWidget->verticalHeader()->setVisible(false);
}

CentroGarantiaVehiculo::CentroGarantiaVehiculo(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::CentroGarantiaVehiculo)
{
    ui->setupUi(this);

    /*
     * Página 1 de stacked widget
     */
    // Tabla de clientes
    ui->clienteTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Agregar clientes a la tabla
    rellenarTablaClientes(ui->clienteTableWidget);
    actItemsTabla(ui->clienteTableWidget);

    /*
     * Página 2 de stacked widget
     */
    // Tabla de vehiculos por cliente
    ui->vehiculosClienteTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->serviciosTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

CentroGarantiaVehiculo::~CentroGarantiaVehiculo()
{
    delete ui;
}

/*
 *
 * Botón para agregar clientes a la tabla
 *
 */
void CentroGarantiaVehiculo::on_pushButton_2_clicked()
{
    QDialog dialog(nullptr);
    QFormLayout form(&dialog);

    QLineEdit *lineEditName = new QLineEdit(&dialog);
    QLineEdit *lineEditCedula = new QLineEdit(&dialog);
    QLineEdit *lineEditNumContacto = new QLineEdit(&dialog);
    form.addRow("Nombre y Apellido:", lineEditName);
    form.addRow("Cedula:", lineEditCedula);
    form.addRow("Numero de Contacto:", lineEditNumContacto);

    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);

    QObject::connect(&buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    QObject::connect(&buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    if (dialog.exec() == QDialog::Accepted)
    {
        QString name = lineEditName->text();
        QString cedula = lineEditCedula->text();
        QString numContacto = lineEditNumContacto->text();
        if (name == "" || cedula == "" || numContacto == "")
        {
            qDebug() << "Error: No se puede dejar campos vacios";
            return;
        }

        // Create a new Cliente object
        Cliente newCliente(name.toStdString(), cedula.toStdString(), QDate::currentDate().toString("dd-MM-yyyy").toStdString(), numContacto.toStdString());
        Cliente::guardarClienteEnArchivo(newCliente);
        rellenarTablaClientes(ui->clienteTableWidget);
        actItemsTabla(ui->clienteTableWidget);
        informarClienteNuevo();
    }
}

/**
 * @brief ** Funcion para buscar clientes en la tabla
 *
 * @param arg1
 * @return ** void
 */
void CentroGarantiaVehiculo::on_lineEdit_textChanged(const QString &arg1)
{
    for (int row = 0; row < ui->clienteTableWidget->rowCount(); row++)
    {
        QTableWidgetItem *item = ui->clienteTableWidget->item(row, 0);
        bool match = item && item->text().contains(arg1, Qt::CaseInsensitive);
        ui->clienteTableWidget->setRowHidden(row, !match);
    }
}

/*
 *
 * Botón para eliminar clientes de la tabla
 *
 */
void CentroGarantiaVehiculo::on_pushButton_5_clicked()
{
    // Get the current row
    int row = ui->clienteTableWidget->currentRow();
    // If there is no row selected, return
    if (row == -1)
    {
        qDebug() << "Error: No se ha seleccionado una fila";
        return;
    }
    // Remove the row from the table
    ui->clienteTableWidget->removeRow(row);
}

/*
 *
 * Botón que permite seleccionar un cliente de la tabla y ver sus vehiculos
 *
 */
void CentroGarantiaVehiculo::on_pushButton_clicked()
{
    // Get the current row
    int row = ui->clienteTableWidget->currentRow();
    // If there is no row selected, return
    if (row == -1)
    {
        qDebug() << "Error: No se ha seleccionado una fila";
        return;
    }
    ui->stackedWidget->setCurrentWidget(ui->page_2);

    // Get the cliente's cedula from the selected row
    QTableWidgetItem *cedulaItem = ui->clienteTableWidget->item(row, 1);
    QString cedula = cedulaItem->text();
    cedulaActual = cedula.toStdString();
    QTableWidgetItem *nombreItem = ui->clienteTableWidget->item(row, 0);
    QString nombre = nombreItem->text();

    // Set the label to the cliente's name
    ui->label->setText("Vehiculos de " + nombre);

    // Limpiar la tabla de vehículos del cliente
    ui->vehiculosClienteTable->clearContents();
    ui->vehiculosClienteTable->setRowCount(0);

    // Iterar en el arreglo de vehículos
    vector<Vehiculo> vehiculosVector = Vehiculo::cargarVehiculosDesdeArchivo();
    for (Vehiculo vehiculo : vehiculosVector)
    {
        // Verificar si el vehículo tiene la misma cédula del cliente
        if (vehiculo.getCedulaCliente().compare(cedula.toStdString()) == 0)
        {
            // Obtener la información del vehículo
            string placa = vehiculo.getPlaca();
            string dentroTaller = vehiculo.getEnTaller() ? "Sí" : "No";

            // Agregar una nueva fila a la tabla de vehículos del cliente
            int numRows = ui->vehiculosClienteTable->rowCount();
            ui->vehiculosClienteTable->insertRow(numRows);

            // Mostrar la información del vehículo en la tabla
            QTableWidgetItem *itemPlaca = new QTableWidgetItem(QString::fromStdString(placa));
            QTableWidgetItem *itemDentroTaller = new QTableWidgetItem(QString::fromStdString(dentroTaller));
            QTableWidgetItem *itemNumServicios = new QTableWidgetItem(QString::number(vehiculo.getNumServicios()));

            ui->vehiculosClienteTable->setItem(numRows, 0, itemPlaca);
            ui->vehiculosClienteTable->setItem(numRows, 1, itemDentroTaller);
            ui->vehiculosClienteTable->setItem(numRows, 2, itemNumServicios);

            actItemsTabla(ui->vehiculosClienteTable);
        }
    }
    ui->vehiculosClienteTable->verticalHeader()->setVisible(false);
}

/*
 *
 * Botón para regresar a stacked widget clientes
 *
 */
void CentroGarantiaVehiculo::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page);
}

// Botón para registrar vehículo
void CentroGarantiaVehiculo::on_pushButton_7_clicked()
{

    QDialog dialog(nullptr);
    QFormLayout form(&dialog);

    QLineEdit *lineEditPlaca = new QLineEdit(&dialog);
    form.addRow("Numero de Placa:", lineEditPlaca);

    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);

    QObject::connect(&buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    QObject::connect(&buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    if (dialog.exec() == QDialog::Accepted)
    {
        QString placa = lineEditPlaca->text();

        if (placa == "")
        {
            qDebug() << "Error: No se puede dejar campos vacios";
            return;
        }

        // Create a new Vehiculo object
        Vehiculo newVehiculo(cedulaActual, placa.toStdString());
        Vehiculo::guardarVehiculoEnArchivo(newVehiculo);

        // Get the current number of rows in the table
        int numRows = ui->vehiculosClienteTable->rowCount();

        // Insert a new row at the end of the table
        ui->vehiculosClienteTable->insertRow(numRows);

        // Populate the table with the data from the new Cliente object
        // Mostrar la información del vehículo en la tabla
        QTableWidgetItem *itemPlaca = new QTableWidgetItem(QString::fromStdString(newVehiculo.getPlaca()));
        QTableWidgetItem *itemDentroTaller = new QTableWidgetItem(QString::fromStdString(newVehiculo.getEnTaller() ? "Sí" : "No"));
        QTableWidgetItem *itemNumServicios = new QTableWidgetItem(QString::number(newVehiculo.getNumServicios()));

        ui->vehiculosClienteTable->setItem(numRows, 0, itemPlaca);
        ui->vehiculosClienteTable->setItem(numRows, 1, itemDentroTaller);
        ui->vehiculosClienteTable->setItem(numRows, 2, itemNumServicios);

        actItemsTabla(ui->vehiculosClienteTable);
    }
}

// Botón para eliminar vehículo
void CentroGarantiaVehiculo::on_pushButton_6_clicked()
{
    // Get the current row
    int row = ui->vehiculosClienteTable->currentRow();

    // If there is no row selected, return
    if (row == -1)
    {
        qDebug() << "Error: No se ha seleccionado una fila";
        return;
    }

    // Remove the row from the table
    ui->vehiculosClienteTable->removeRow(row);
    // Remove the corresponding vehicle from vehiculosVector
}

void CentroGarantiaVehiculo::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_2);
}

/*
 *
 *************** TAB MENU OTROS***************
 *
 */

void CentroGarantiaVehiculo::on_pushButton_12_clicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (button)
    {
        if (button->text() == "GENERAR")
        {
            button->setText("GENERANDO ...");
        }
        else if (button->text() == "GENERANDO ...")
        {
            button->setText("GENERAR");
        }
    }
}

void CentroGarantiaVehiculo::on_pushButton_4_clicked()
{
    placaActual = ui->vehiculosClienteTable->item(ui->vehiculosClienteTable->currentRow(), 0)->text().toStdString();
    ui->label_servicios_placa->setText("Servicios al Vehículo de Placa: " + QString::fromStdString(placaActual));
    ui->stackedWidget->setCurrentWidget(ui->page_3);
    // Limpiar la tabla de vehículos del cliente
    ui->serviciosTable->clearContents();
    ui->serviciosTable->setRowCount(0);

    // Populate the serviciosTable with the items from serviciosVector
    vector<Servicio> serviciosVector = Servicio::cargarServiciosDesdeArchivo(placaActual);
    for (Servicio servicio : serviciosVector)
    {
        int numRows = ui->serviciosTable->rowCount();
        // Insert a new row at the end of the table
        ui->serviciosTable->insertRow(numRows);

        // Create new QTableWidgetItem objects for each column
        QTableWidgetItem *itemFechaIngreso = new QTableWidgetItem(QString::fromStdString(servicio.getFechaIni()));
        QTableWidgetItem *itemFechaSalida = new QTableWidgetItem(QString::fromStdString(servicio.getHoraIni()));
        QTableWidgetItem *itemRazon = new QTableWidgetItem(QString::fromStdString(servicio.getRazon()));
        QTableWidgetItem *itemKilometrajeIngreso = new QTableWidgetItem(QString::number(servicio.getKmIngreso()));

        // Insert the QTableWidgetItem objects into the serviciosTable
        ui->serviciosTable->setItem(numRows, 0, itemFechaIngreso);
        ui->serviciosTable->setItem(numRows, 1, itemFechaSalida);
        ui->serviciosTable->setItem(numRows, 2, itemRazon);
        ui->serviciosTable->setItem(numRows, 3, itemKilometrajeIngreso);
    }

    actItemsTabla(ui->serviciosTable);
    ui->serviciosTable->verticalHeader()->setVisible(false);
    // Actualizar tabla de vehículos para cuando vuelva a revisar
    rellenarTablaVehiculos(ui->vehiculosClienteTable);
}

// Botón para ingresar un vehículo al taller
void CentroGarantiaVehiculo::on_pushButton_9_clicked()
{
    QDialog dialog(nullptr);
    QFormLayout form(&dialog);

    // Lista de fallas
    QComboBox *comboBoxRazon = new QComboBox(&dialog);
    string fallas[] = {"Ruidos por suspensión",
                       "Acelera de forma brusca",
                       "Se escuchan chirridos y se detiene el vehículo",
                       "Embrague resbaladizo",
                       "Arranque lento",
                       "Bolsas de aire defectuosas",
                       "Desvío de dirección",
                       "Ruido al frenar",
                       "Fuga de refrigerante",
                       "El seguro de la puerta se desactiva inesperadamente"};
    comboBoxRazon->addItems({"Ruidos por suspensión",
                             "Acelera de forma brusca",
                             "Se escuchan chirridos y se detiene el vehículo",
                             "Embrague resbaladizo",
                             "Arranque lento",
                             "Bolsas de aire defectuosas",
                             "Desvío de dirección",
                             "Ruido al frenar",
                             "Fuga de refrigerante",
                             "El seguro de la puerta se desactiva inesperadamente"});
    // Para registrar kilometraje de ingreso
    QLineEdit *lineEditKmIngreso = new QLineEdit(&dialog);

    form.addRow("Razón:", comboBoxRazon);
    form.addRow("Kilometraje de Ingreso:", lineEditKmIngreso);

    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);

    QObject::connect(&buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    QObject::connect(&buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    if (dialog.exec() == QDialog::Accepted)
    {
        int idRazon = comboBoxRazon->currentIndex();
        QString kmIngreso = lineEditKmIngreso->text();
        if (idRazon == -1 || kmIngreso == "")
        {
            qDebug() << "Error: No se puede dejar campos vacios";
            return;
        }
        string razon = fallas[idRazon];
        // Obtener hora de entrada (hh:mm)
        time_t now = std::time(nullptr);
        tm *now_tm = std::localtime(&now);
        char time_str[6];
        strftime(time_str, sizeof(time_str), "%H:%M", now_tm);
        string time_string(time_str);
        // Crear servicio, guardarlo e informar al taller
        Servicio servicio(placaActual, QDate::currentDate().toString("dd-MM-yyyy").toStdString(), time_string, razon, kmIngreso.toInt());
        Servicio::guardarServicioEnArchivo(servicio);
        enviarVehiculo(cedulaActual, placaActual, razon, kmIngreso.toInt());

        // Get the current number of rows in the table
        int numRows = ui->serviciosTable->rowCount();

        // Insert a new row at the end of the table
        ui->serviciosTable->insertRow(numRows);

        // Populate the table with the data from the new Cliente object
        // Mostrar la información del vehículo en la tabla
        // Create new QTableWidgetItem objects for each column
        QTableWidgetItem *itemFechaIngreso = new QTableWidgetItem(QString::fromStdString(servicio.getFechaIni()));
        QTableWidgetItem *itemFechaSalida = new QTableWidgetItem(QString::fromStdString(servicio.getHoraIni()));
        QTableWidgetItem *itemRazon = new QTableWidgetItem(QString::fromStdString(servicio.getRazon()));
        QTableWidgetItem *itemKilometrajeIngreso = new QTableWidgetItem(QString::number(servicio.getKmIngreso()));

        // Insert the QTableWidgetItem objects into the serviciosTable
        ui->serviciosTable->setItem(numRows, 0, itemFechaIngreso);
        ui->serviciosTable->setItem(numRows, 1, itemFechaSalida);
        ui->serviciosTable->setItem(numRows, 2, itemRazon);
        ui->serviciosTable->setItem(numRows, 3, itemKilometrajeIngreso);

        actItemsTabla(ui->serviciosTable);
    }
}


void CentroGarantiaVehiculo::on_btn_aleatorios_clicked()
{
   
    string fallas[] = {"Ruidos por suspensión",
                       "Acelera de forma brusca",
                       "Se escuchan chirridos y se detiene el vehículo",
                       "Embrague resbaladizo",
                       "Arranque lento",
                       "Bolsas de aire defectuosas",
                       "Desvío de dirección",
                       "Ruido al frenar",
                       "Fuga de refrigerante",
                       "El seguro de la puerta se desactiva inesperadamente"};
    for (int i = 0; i < NUM_RANDOMS; i++)
    {
        enviarVehiculo("cedula", "placa" + to_string(i), fallas[rand() % 10], rand() % 1000);
    }
}
