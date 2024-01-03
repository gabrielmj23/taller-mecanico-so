#include "taller.h"
#include "./ui_taller.h"

#include <string>
#include <vector>
#include <QScreen>
#include <QString>
#include <QLabel>
#include <QWidget>
#include <QTabBar>
#include <QHeaderView>
#include <QTableWidgetItem>

#include "clases.h"

// Ejemplo de Vehiculos

std::vector<Vehiculo> vehiculosVector = {
    {"123456789", "ABC123", true},
    {"987654321", "DEF456", false},
    {"456789123", "GHI789", true},
    {"456789124", "GHI788", true},
    {"456789123", "GHI777", false}};

// variables globales

std::vector<ClienteVehiculo> clientesVehiculo = {
    {"Entrada", "Karim Sahili", "09:00", "JK37Y2"},
    {"Salida", "Hamudi Sahili", "10:00", "JK23hf"},
    {"Entrada", "Samy Sahili", "12:00", "KHH323"},
    {"Salida", "Ali Sahili", "16:00", "KLHH23"},
    {"Entrada", "Karim Sahili", "09:00", "JK37Y2"},
    {"Salida", "Hamudi Sahili", "10:00", "JK23hf"},
    {"Entrada", "Samy Sahili", "12:00", "KHH323"},
    {"Salida", "Ali Sahili", "16:00", "KLHH23"},
    {"Entrada", "Karim Sahili", "09:00", "JK37Y2"},
    {"Salida", "Hamudi Sahili", "10:00", "JK23hf"},
    {"Entrada", "Samy Sahili", "12:00", "KHH323"},
    {"Salida", "Ali Sahili", "16:00", "KLHH23"},
    {"Entrada", "Karim Sahili", "09:00", "JK37Y2"},
    {"Salida", "Hamudi Sahili", "10:00", "JK23hf"},
    {"Entrada", "Samy Sahili", "12:00", "KHH323"}};

// Ejemplo Servicios
std::vector<Servicio> serviciosVector = {
    {"ABC123", "01-01-2021", "02-01-2021", "Cambio de aceite", 1000},
    {"GHI777", "01-01-2021", "02-01-2021", "Cambio de aceite", 1000},
    {"GHI789", "01-01-2021", "02-01-2021", "Cambio de aceite", 30000},
    {"GHI777", "01-06-2021", "02-07-2021", "Cambio de aceite", 2000},
    {"GHI777", "01-01-2021", "02-01-2021", "Cambio de aceite", 1000}};

// Arreglo clientes ejemplo
vector<Cliente> clientes = {
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

Taller::Taller(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Taller)
{
    ui->setupUi(this);

    // Set the title text of each tab to be horizontal
    for (int i = 0; i < ui->tabWidget->count(); i++)
    {
        QWidget *tabWidget = ui->tabWidget->widget(i);
        QLabel *titleLabel = new QLabel(ui->tabWidget->tabText(i));
        titleLabel->setAlignment(Qt::AlignHCenter);
        ui->tabWidget->setTabText(i, "");
        ui->tabWidget->tabBar()->setTabButton(i, QTabBar::LeftSide, titleLabel);
    }

    // extiende los titulos de la tabla en lo horizontal
    ui->tablaClienteVehiculo->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tablaClientes->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tablaVehiculos->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tablaServicios->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // agrega ejemplos a la tablaClienteVehiculo
    for (int i = 0; i < clientesVehiculo.size(); i++)
    {
        ClienteVehiculo clienteVehiculo = clientesVehiculo[i];
        ui->tablaClienteVehiculo->insertRow(ui->tablaClienteVehiculo->rowCount());
        ui->tablaClienteVehiculo->setItem(ui->tablaClienteVehiculo->rowCount() - 1, 0, new QTableWidgetItem(QString::fromStdString(clienteVehiculo.tipo)));
        ui->tablaClienteVehiculo->setItem(ui->tablaClienteVehiculo->rowCount() - 1, 1, new QTableWidgetItem(QString::fromStdString(clienteVehiculo.nombre)));
        ui->tablaClienteVehiculo->setItem(ui->tablaClienteVehiculo->rowCount() - 1, 2, new QTableWidgetItem(QString::fromStdString(clienteVehiculo.hora)));
        ui->tablaClienteVehiculo->setItem(ui->tablaClienteVehiculo->rowCount() - 1, 3, new QTableWidgetItem(QString::fromStdString(clienteVehiculo.placa)));
    }

    actItemsTabla(ui->tablaClienteVehiculo);

    // Quita la enumeracion de las filas
    ui->tablaClienteVehiculo->verticalHeader()->setVisible(false);
    ui->tablaClientes->verticalHeader()->setVisible(false);
    ui->tablaVehiculos->verticalHeader()->setVisible(false);
    ui->tablaServicios->verticalHeader()->setVisible(false);

    // Agregar clientes a la tabla
    for (int i = 0; i < 3; i++)
    {
        ui->tablaClientes->insertRow(i);
        ui->tablaClientes->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(clientes[i].getNombre())));
        ui->tablaClientes->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(clientes[i].getCedula())));
        ui->tablaClientes->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(clientes[i].getFechaRegistro())));
        ui->tablaClientes->setItem(i, 3, new QTableWidgetItem(QString::number(clientes[i].getNumVehiculos(vehiculosVector))));
        ui->tablaClientes->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(clientes[i].getNumContacto())));
    }

    actItemsTabla(ui->tablaClientes);
}

Ui::Taller *Taller::getUi() const
{
    return ui;
}

Taller::~Taller()
{
    delete ui;
}

// manejador de titulo dependiendo del tab seleccionado
void Taller::on_tabWidget_currentChanged(int index)
{
    switch (index)
    {
    case 0:
        ui->label_2->setText("Inicio");
        break;
    case 1:
        ui->label_2->setText("Clientes");
        break;
    case 2:
        ui->label_2->setText("Estacionamiento");
        break;
    case 3:
        ui->label_2->setText("Centro de Diagnóstico");
        break;
    case 4:
        ui->label_2->setText("Piezas");
        break;
    case 5:
        ui->label_2->setText("Compra de Piezas");
        break;
    case 6:
        ui->label_2->setText("Estaciones del Sistema");
        break;
    default:
        ui->label_2->setText("Tab no reconocido");
        break;
    }
}

void Taller::on_lineEdit_textChanged(const QString &arg1)
{
    for (int row = 0; row < ui->tablaClientes->rowCount(); row++)
    {
        QTableWidgetItem *item = ui->tablaClientes->item(row, 0);
        bool match = item && item->text().contains(arg1, Qt::CaseInsensitive);
        ui->tablaClientes->setRowHidden(row, !match);
    }
}

void Taller::on_pushButton_clicked()
{

    // Get the current row
    int row = ui->tablaClientes->currentRow();

    // If there is no row selected, return
    if (row == -1)
    {
        qDebug() << "Error: No se ha seleccionado una fila";
        return;
    }
    QTableWidgetItem *nombreItem = ui->tablaClientes->item(row, 0);
    QString nombre = nombreItem->text();

    // Set the label to the cliente's name
    ui->label->setText("Vehiculos de " + nombre);

    // Limpiar la tabla de vehículos del cliente
    ui->tablaVehiculos->clearContents();

    ui->tablaVehiculos->setRowCount(0);

    // Iterar en el arreglo de vehículos
    for (Vehiculo vehiculo : vehiculosVector)

    {

        // Obtener la información del vehículo
        string placa = vehiculo.getPlaca();
        string dentroTaller = vehiculo.getUbicacion();

        // Agregar una nueva fila a la tabla de vehículos del cliente
        int numRows = ui->tablaVehiculos->rowCount();
        ui->tablaVehiculos->insertRow(numRows);

        // Mostrar la información del vehículo en la tabla
        QTableWidgetItem *itemPlaca = new QTableWidgetItem(QString::fromStdString(placa));
        QTableWidgetItem *itemDentroTaller = new QTableWidgetItem(QString::fromStdString(dentroTaller));
        QTableWidgetItem *itemNumServicios = new QTableWidgetItem(QString::number(vehiculo.getNumServicios(serviciosVector)));

        ui->tablaVehiculos->setItem(numRows, 0, itemPlaca);
        ui->tablaVehiculos->setItem(numRows, 1, itemDentroTaller);
        ui->tablaVehiculos->setItem(numRows, 2, itemNumServicios);

        actItemsTabla(ui->tablaVehiculos);
    }
    ui->stackedWidget->setCurrentWidget(ui->page_2);
}

void Taller::on_pushButton_3_clicked()
{

    ui->stackedWidget->setCurrentWidget(ui->page);
}

void Taller::on_pushButton_2_clicked()
{

    // Get the current row
    int row = ui->tablaVehiculos->currentRow();

    // If there is no row selected, return
    if (row == -1)
    {
        qDebug() << "Error: No se ha seleccionado una fila";
        return;
    }

    QTableWidgetItem *placaItem = ui->tablaVehiculos->item(row, 0);
    QString placa = placaItem->text();

    ui->stackedWidget->setCurrentWidget(ui->page_3);
    // Limpiar la tabla de vehículos del cliente
    ui->tablaServicios->clearContents();
    ui->tablaServicios->setRowCount(0);

    // Populate the tablaServicios with the items from serviciosVector
    for (Servicio servicio : serviciosVector)
    {

        int numRows = ui->tablaServicios->rowCount();
        // Insert a new row at the end of the table
        ui->tablaServicios->insertRow(numRows);

        // Create new QTableWidgetItem objects for each column
        QTableWidgetItem *itemFechaIngreso = new QTableWidgetItem(QString::fromStdString(servicio.getFechaIni()));
        itemFechaIngreso->setData(Qt::UserRole, servicio.getId());
        QTableWidgetItem *itemFechaSalida = new QTableWidgetItem(QString::fromStdString(servicio.getFechaFin()));
        QTableWidgetItem *itemRazon = new QTableWidgetItem(QString::fromStdString(servicio.getRazon()));
        QTableWidgetItem *itemKilometrajeIngreso = new QTableWidgetItem(QString::number(servicio.getKmIngreso()));

        // Insert the QTableWidgetItem objects into the tablaServicios
        ui->tablaServicios->setItem(numRows, 0, itemFechaIngreso);
        ui->tablaServicios->setItem(numRows, 1, itemFechaSalida);
        ui->tablaServicios->setItem(numRows, 2, itemRazon);
        ui->tablaServicios->setItem(numRows, 3, itemKilometrajeIngreso);
    }

    actItemsTabla(ui->tablaServicios);
}

void Taller::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_2);
}
