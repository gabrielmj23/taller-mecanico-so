
#include <QHeaderView>
#include <QLineEdit>
#include <QDialog>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QTableWidgetItem>
#include <QDebug>
#include <QDate>
#include <QString>
#include <vector>

#include "centrogarantiavehiculo.h"
#include "./ui_centrogarantiavehiculo.h"
#include "Clases.h"

// variables globales

string cedulaActual = "";
string placaActual = "";

// Ejemplo Servicios
std::vector<Servicio> serviciosVector = {
    {"ABC123", "01-01-2021", "02-01-2021", "Cambio de aceite", 1000},
    {"GHI777", "01-01-2021", "02-01-2021", "Cambio de aceite", 1000},
    {"GHI789", "01-01-2021", "02-01-2021", "Cambio de aceite", 30000},
    {"GHI777", "01-06-2021", "02-07-2021", "Cambio de aceite", 2000},
    {"GHI777", "01-01-2021", "02-01-2021", "Cambio de aceite", 1000}};

// Ejemplo de Vehiculos

std::vector<Vehiculo> vehiculosVector = {
    {"123456789", "ABC123", true},
    {"987654321", "DEF456", false},
    {"456789123", "GHI789", true},
    {"456789124", "GHI788", true},
    {"456789123", "GHI777", false}};



// Arreglo clientes ejemplo
vector<Cliente> clientes = {
    {"John Doe", "123456789", "01-01-2021", "555-1234"},
    {"Jane Smith", "987654321", "15-02-2021", "555-5678"},
    {"Alice Johnson", "456789123", "10-03-2021", "555-9012"}
};







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
        ui->clienteTableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(clientes[i].getNumVehiculos(vehiculosVector))));
        ui->clienteTableWidget->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(clientes[i].getNumContacto())));
    }

    actItemsTabla(ui->clienteTableWidget);

    /*
     * pagina 2 de stacked widget
     */

    // Tabla de vehiculos x cliente
    ui->vehiculosClienteTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->serviciosTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
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
        QTableWidgetItem *itemNumCarros = new QTableWidgetItem(QString::number(newCliente.getNumVehiculos(vehiculosVector)));
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
    cedulaActual = cedula.toStdString();
    QTableWidgetItem *nombreItem = ui->clienteTableWidget->item(row, 0);
    QString nombre = nombreItem->text();

    // Set the label to the cliente's name
    ui->label->setText("Vehiculos de " + nombre);

    // Limpiar la tabla de vehículos del cliente
    ui->vehiculosClienteTable->clearContents();

    ui->vehiculosClienteTable->setRowCount(0);

    // Iterar en el arreglo de vehículos
    for (Vehiculo vehiculo : vehiculosVector)

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
            QTableWidgetItem *itemNumServicios = new QTableWidgetItem(QString::number(vehiculo.getNumServicios(serviciosVector)));

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
        Vehiculo newVehiculo(cedulaActual, placa.toStdString(), false);
        vehiculosVector.push_back(newVehiculo);

        // Get the current number of rows in the table
        int numRows = ui->vehiculosClienteTable->rowCount();

        // Insert a new row at the end of the table
        ui->vehiculosClienteTable->insertRow(numRows);

        // Populate the table with the data from the new Cliente object
        // Mostrar la información del vehículo en la tabla
        QTableWidgetItem *itemPlaca = new QTableWidgetItem(QString::fromStdString(newVehiculo.getPlaca()));
        QTableWidgetItem *itemDentroTaller = new QTableWidgetItem(QString::fromStdString(newVehiculo.getUbicacion()));
        QTableWidgetItem *itemNumServicios = new QTableWidgetItem(QString::number(newVehiculo.getNumServicios(serviciosVector)));

        ui->vehiculosClienteTable->setItem(numRows, 0, itemPlaca);
        ui->vehiculosClienteTable->setItem(numRows, 1, itemDentroTaller);
        ui->vehiculosClienteTable->setItem(numRows, 2, itemNumServicios);

        actItemsTabla(ui->vehiculosClienteTable);
    }
}

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
    

    ui->stackedWidget->setCurrentWidget(ui->page_3);
    // Limpiar la tabla de vehículos del cliente
    ui->serviciosTable->clearContents();
    ui->serviciosTable->setRowCount(0);

    // Populate the serviciosTable with the items from serviciosVector
    for (Servicio servicio: serviciosVector)
    {

        // Check if the servicio's placa matches the placaActual
        if (servicio.getPlacaVehiculo().compare(placaActual) == 0)
        {
            int numRows = ui->serviciosTable->rowCount();  
            // Insert a new row at the end of the table
            ui->serviciosTable->insertRow(numRows);

            // Create new QTableWidgetItem objects for each column
            QTableWidgetItem *itemFechaIngreso = new QTableWidgetItem(QString::fromStdString(servicio.getFechaIni()));
            itemFechaIngreso->setData(Qt::UserRole, servicio.getId());
            QTableWidgetItem *itemFechaSalida = new QTableWidgetItem(QString::fromStdString(servicio.getFechaFin()));
            QTableWidgetItem *itemRazon = new QTableWidgetItem(QString::fromStdString(servicio.getRazon()));
            QTableWidgetItem *itemKilometrajeIngreso = new QTableWidgetItem(QString::number(servicio.getKmIngreso()));

            // Insert the QTableWidgetItem objects into the serviciosTable
            ui->serviciosTable->setItem(numRows, 0, itemFechaIngreso);
            ui->serviciosTable->setItem(numRows, 1, itemFechaSalida);
            ui->serviciosTable->setItem(numRows, 2, itemRazon);
            ui->serviciosTable->setItem(numRows, 3, itemKilometrajeIngreso);
        }
    }

    actItemsTabla(ui->serviciosTable);

    ui->serviciosTable->verticalHeader()->setVisible(false);
}




void CentroGarantiaVehiculo::on_pushButton_9_clicked()
{
    QDialog dialog(nullptr);
    QFormLayout form(&dialog);

    QLineEdit *lineEditRazon = new QLineEdit(&dialog);
    QLineEdit *lineEditKmIngreso = new QLineEdit(&dialog);


    form.addRow("Razon:", lineEditRazon);
    form.addRow("Kilometraje de Ingreso:", lineEditKmIngreso);
    

    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);

    QObject::connect(&buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    QObject::connect(&buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    if (dialog.exec() == QDialog::Accepted)
    {
        QString razon = lineEditRazon->text();
        QString kmIngreso = lineEditKmIngreso->text();

        if ( razon == "" || kmIngreso == "" )
        {
            qDebug() << "Error: No se puede dejar campos vacios";
            return;
        }

        // Create a new Servicio object
        Servicio servicio(placaActual, QDate::currentDate().toString("dd-MM-yyyy").toStdString(), "Sigue en Taller", razon.toStdString(), kmIngreso.toDouble());
        serviciosVector.push_back(servicio);

        // Get the current number of rows in the table
        int numRows = ui->serviciosTable->rowCount();

        // Insert a new row at the end of the table
        ui->serviciosTable->insertRow(numRows);

        // Populate the table with the data from the new Cliente object
        // Mostrar la información del vehículo en la tabla
            // Create new QTableWidgetItem objects for each column
            QTableWidgetItem *itemFechaIngreso = new QTableWidgetItem(QString::fromStdString(servicio.getFechaIni()));
            itemFechaIngreso->setData(Qt::UserRole, servicio.getId());
            QTableWidgetItem *itemFechaSalida = new QTableWidgetItem(QString::fromStdString(servicio.getFechaFin()));
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

