
#include <QHeaderView>
#include <QLineEdit>
#include <QDialog>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QTableWidgetItem>
#include <QDebug>
#include <QDate>
#include <QString>

#include "centrogarantiavehiculo.h"
#include "./ui_centrogarantiavehiculo.h"
#include "Clases.h"

using namespace std;

//Ejemplo Servicios
Servicio servicios[] = {
    {"ABC123", "01-01-2021", "02-01-2021", "Cambio de aceite", 1000},
    {"DEF456", "01-01-2021", "02-01-2021", "Cambio de aceite", 1000},
    {"GHI789", "01-01-2021", "02-01-2021", "Cambio de aceite", 1000},
    {"GHI777", "01-06-2021", "02-07-2021", "Cambio de aceite", 2000},
    {"GHI777", "01-01-2021", "02-01-2021", "Cambio de aceite", 1000}
    };
int  numServicios = sizeof(servicios) / sizeof(servicios[0]);

// Ejemplo de Vehiculos
Vehiculo vehiculos[] = {
    {"123456789", "ABC123", true},
    {"987654321", "DEF456", false},
    {"456789123", "GHI789", true},
    {"456789124", "GHI788", true},
    {"456789123", "GHI777", false}};

int numVehiculos = sizeof(vehiculos) / sizeof(vehiculos[0]);

// Arreglo clientes ejemplo
Cliente clientes[] = {
    {"John Doe", "123456789", "01-01-2021", "555-1234"},
    {"Jane Smith", "987654321", "15-02-2021", "555-5678"},
    {"Alice Johnson", "456789123", "10-03-2021", "555-9012"}};

// actualiza las propiedades de los items de la tabla (centrar y no editable)
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

CentroGarantiaVehiculo::CentroGarantiaVehiculo(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::CentroGarantiaVehiculo)
{
    ui->setupUi(this);

    /*
    *
        TAB MANUAL
    *
    */

    /*
     *
     * pagina 1 de stacked widget
     */

    // Tabla de clientes
    ui->clienteTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Agregar clientes a la tabla
    for (int i = 0; i < 3; i++)
    {
        ui->clienteTableWidget->insertRow(i);
        ui->clienteTableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(clientes[i].getNombre())));
        ui->clienteTableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(clientes[i].getCedula())));
        ui->clienteTableWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(clientes[i].getFechaRegistro())));
        ui->clienteTableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(clientes[i].getNumVehiculos(vehiculos, numVehiculos))));
        ui->clienteTableWidget->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(clientes[i].getNumContacto())));
    }

    actItemsTabla(ui->clienteTableWidget);

    /*
     * pagina 2 de stacked widget
     */

    // Tabla de vehiculos x cliente
    ui->vehiculosClienteTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

CentroGarantiaVehiculo::~CentroGarantiaVehiculo()
{
    delete ui;
}

/*
 *
 *Boton para agregar clientes a la tabla
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

        // Get the current number of rows in the table
        int numRows = ui->clienteTableWidget->rowCount();

        // Insert a new row at the end of the table
        ui->clienteTableWidget->insertRow(numRows);

        // Populate the table with the data from the new Cliente object
        QTableWidgetItem *itemNombre = new QTableWidgetItem(QString::fromStdString(newCliente.getNombre()));
        QTableWidgetItem *itemCedula = new QTableWidgetItem(QString::fromStdString(newCliente.getCedula()));
        QTableWidgetItem *itemNumCarros = new QTableWidgetItem(QString::number(newCliente.getNumVehiculos(vehiculos, numVehiculos)));
        QTableWidgetItem *itemFechaRegistro = new QTableWidgetItem(QString::fromStdString(newCliente.getFechaRegistro()));
        QTableWidgetItem *itemNumContacto = new QTableWidgetItem(QString::fromStdString(newCliente.getNumContacto()));

        ui->clienteTableWidget->setItem(numRows, 0, itemNombre);
        ui->clienteTableWidget->setItem(numRows, 1, itemCedula);
        ui->clienteTableWidget->setItem(numRows, 2, itemNumCarros);
        ui->clienteTableWidget->setItem(numRows, 3, itemFechaRegistro);
        ui->clienteTableWidget->setItem(numRows, 4, itemNumContacto);

        actItemsTabla(ui->clienteTableWidget);
    }
}

/*
 *
 *************** TAB MANUAL ***************
 *
 */

/*
 *
 *************** STACKED WIDGET CLIENTES***************
 *
 */

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
 *Boton para eliminar clientes de la tabla
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
 *Boton que permite seleccionar un cliente de la tabla y ver sus vehiculos
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

    // Limpiar la tabla de vehículos del cliente
    ui->vehiculosClienteTable->clearContents();
    ui->vehiculosClienteTable->setRowCount(0);

    // Iterar en el arreglo de vehículos
    for (Vehiculo vehiculo : vehiculos)
      
    {

        // Verificar si el vehículo tiene la misma cédula del cliente
        if (vehiculo.getCedulaCliente().compare(cedula.toStdString()) == 0)
        {
            // Obtener la información del vehículo
            string placa = vehiculo.getPlaca();
            string dentroTaller = vehiculo.getUbicacion();

            // Agregar una nueva fila a la tabla de vehículos del cliente
            int numRows = ui->vehiculosClienteTable->rowCount();
            ui->vehiculosClienteTable->insertRow(numRows);

            // Mostrar la información del vehículo en la tabla
            QTableWidgetItem *itemPlaca = new QTableWidgetItem(QString::fromStdString(placa));
            QTableWidgetItem *itemDentroTaller = new QTableWidgetItem(QString::fromStdString(dentroTaller));
            QTableWidgetItem *itemNumServicios = new QTableWidgetItem(QString::number(vehiculo.getNumServicios(servicios, numServicios)));

            ui->vehiculosClienteTable->setItem(numRows, 0, itemPlaca);
            ui->vehiculosClienteTable->setItem(numRows, 1, itemDentroTaller);
            ui->vehiculosClienteTable->setItem(numRows, 2, itemNumServicios);

            actItemsTabla(ui->vehiculosClienteTable);
        }
    }
}

/*
 *
 *************** STACKED WIDGET VEHICULOS X CLIENTE***************
 *
 */

/*
 *
 *Boton para regresar a stacked widget clientes
 *
 */
void CentroGarantiaVehiculo::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page);
}
