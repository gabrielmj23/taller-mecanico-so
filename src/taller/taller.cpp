#include "taller.h"
#include "./ui_taller.h"

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <pthread.h>
#include <QScreen>
#include <QString>
#include <QLabel>
#include <QWidget>
#include <QTabBar>
#include <QHeaderView>
#include <QTableWidgetItem>
#include <QFile>
#include <QDialog>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QLineEdit>

#include "clases.h"
#include "Inventario.h"
#include "Cliente.h"
#include "Servicio.h"
#include "ClienteVehiculo.h"
#include "EstacionTrabajo.h"
#include "Vehiculo.h"
#include "server.h"
using namespace std;

int serviciosCompletados = 0;

vector<VehiculoCola> vehiculosCola = {
    {1, "ABC123", "09:00"},
    {2, "DEF456", "10:00"},
    {3, "GHI789", "11:00"},
    {4, "GHI788", "12:00"},
    {5, "GHI777", "13:00"},
    {6, "GHI776", "14:00"},
    {7, "GHI775", "15:00"},
};

// Inventario de repuestos
Inventario inventario;

// Estaciones de trabajo del taller
vector<EstacionTrabajo> estaciones = {
    EstacionTrabajo("Lubricación"),
    EstacionTrabajo("Motor"),
    EstacionTrabajo("Transmisión"),
    EstacionTrabajo("Dirección"),
    EstacionTrabajo("Combustible"),
    EstacionTrabajo("Suspensión"),
    EstacionTrabajo("Frenos"),
    EstacionTrabajo("Seguridad"),
    EstacionTrabajo("Electricidad"),
    EstacionTrabajo("Refrigeración"),
    EstacionTrabajo("Intercambio de calor")};

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

// Agrega la imagen del Corolla
void imagenCorolla(Ui::Taller *ui)
{
    // Add an image to the centralWidget at position (10, 10)
    QString imagePath = "../taller/corolla.png";
    if (QFile::exists(imagePath))
    {
        QLabel *imageLabel = new QLabel(ui->tabWidget->widget(3));
        QPixmap image(imagePath);
        imageLabel->setPixmap(image);
        imageLabel->setGeometry(10, 90, image.width(), image.height());
        imageLabel->show();
    }
    else
    {
        qDebug() << "Error: No se encontró el archivo de la imagen";
    }
}

// Manejador de titulo dependiendo del tab seleccionado
void tabManager(int index, Ui::Taller *ui)
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
    {
        ui->label_2->setText("Centro de Diagnóstico");
        imagenCorolla(ui);
    }
    break;
    case 4:
        ui->label_2->setText("Repuestos");
        break;
    case 5:
        ui->label_2->setText("Estaciones del Sistema");
        break;
    default:
        ui->label_2->setText("Tab no reconocido");
        break;
    }
}

// Rellena la tabla de clientes
void rellenarTablaClientes(Ui::Taller *ui)
{
    // Agregar clientes a la tabla
    vector<Cliente> clientes = Cliente::cargarClientesDesdeArchivo();
    vector<Vehiculo> vehiculos = Vehiculo::cargarVehiculosDesdeArchivo();
    for (int i = 0; i < clientes.size(); i++)
    {
        ui->tablaClientes->insertRow(i);
        ui->tablaClientes->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(clientes[i].getNombre())));
        ui->tablaClientes->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(clientes[i].getCedula())));
        ui->tablaClientes->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(clientes[i].getFechaRegistro())));
        ui->tablaClientes->setItem(i, 3, new QTableWidgetItem(QString::number(clientes[i].getNumVehiculos(vehiculos))));
        ui->tablaClientes->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(clientes[i].getNumContacto())));
    }
    ui->label_num_clientes->setText("Clientes: " + QString::number(clientes.size()));
    actItemsTabla(ui->tablaClientes);
}

// Rellena la tabla de repuestos
void rellenarTablaRepuestos(Ui::Taller *ui)
{
    // Agregar repuestos a la tabla
    map<string, int> stock = inventario.getStock();
    int i = 0;
    for (auto p : stock)
    {
        ui->tablaRepuestos->insertRow(i);
        ui->tablaRepuestos->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(p.first)));
        ui->tablaRepuestos->setItem(i, 1, new QTableWidgetItem(QString::number(p.second)));
        ui->tablaRepuestos->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(p.second == 0 ? "Agotado" : "Disponible")));
        i++;
    }
    actItemsTabla(ui->tablaRepuestos);
}

// Rellena la tabla de últimas entradas y salidas
void rellenarEntradasSalidas(Ui::Taller *ui)
{
    vector<ClienteVehiculo> clientesVehiculo = ClienteVehiculo::leerClienteVehiculosDeArchivo();
    for (int i = 0; i < clientesVehiculo.size(); i++)
    {
        ClienteVehiculo clienteVehiculo = clientesVehiculo[i];
        ui->tablaClienteVehiculo->insertRow(ui->tablaClienteVehiculo->rowCount());
        ui->tablaClienteVehiculo->setItem(ui->tablaClienteVehiculo->rowCount() - 1, 0, new QTableWidgetItem(QString::fromStdString(clienteVehiculo.getTipo())));
        ui->tablaClienteVehiculo->setItem(ui->tablaClienteVehiculo->rowCount() - 1, 1, new QTableWidgetItem(QString::fromStdString(clienteVehiculo.getNombre())));
        ui->tablaClienteVehiculo->setItem(ui->tablaClienteVehiculo->rowCount() - 1, 2, new QTableWidgetItem(QString::fromStdString(clienteVehiculo.getHora())));
        ui->tablaClienteVehiculo->setItem(ui->tablaClienteVehiculo->rowCount() - 1, 3, new QTableWidgetItem(QString::fromStdString(clienteVehiculo.getPlaca())));
    }
    actItemsTabla(ui->tablaClienteVehiculo);
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

    // Extiende los titulos de la tabla en lo horizontal
    ui->tablaClienteVehiculo->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tablaClientes->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tablaVehiculos->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tablaServicios->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tablaVehiculosCola->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tablaRepuestos->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tablaEstaciones->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Agrega últimas entradas y salidas
    rellenarEntradasSalidas(ui);

    // Quita la enumeracion de las filas
    ui->tablaClienteVehiculo->verticalHeader()->setVisible(false);
    ui->tablaClientes->verticalHeader()->setVisible(false);
    ui->tablaVehiculos->verticalHeader()->setVisible(false);
    ui->tablaServicios->verticalHeader()->setVisible(false);
    ui->tablaVehiculosCola->verticalHeader()->setVisible(false);
    ui->tablaRepuestos->verticalHeader()->setVisible(false);
    ui->tablaEstaciones->verticalHeader()->setVisible(false);

    // Agregar clientes a la tabla
    rellenarTablaClientes(ui);

    // Para que se muestre el titulo del tab seleccionado al iniciar la aplicacion
    tabManager(ui->tabWidget->currentIndex(), ui);

    // Agregar vehiculos en cola a la tabla
    for (int i = 0; i < vehiculosCola.size(); i++)
    {
        ui->tablaVehiculosCola->insertRow(i);
        ui->tablaVehiculosCola->setItem(i, 0, new QTableWidgetItem(QString::number(vehiculosCola[i].nroPuesto)));
        ui->tablaVehiculosCola->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(vehiculosCola[i].placa)));
        ui->tablaVehiculosCola->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(vehiculosCola[i].hora)));
    }

    actItemsTabla(ui->tablaVehiculosCola);

    // Agregar repuestos a la tabla
    rellenarTablaRepuestos(ui);

    // Agregar estaciones a la tabla
    for (int i = 0; i < estaciones.size(); i++)
    {
        ui->tablaEstaciones->insertRow(i);
        ui->tablaEstaciones->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(estaciones[i].getNombre())));
        ui->tablaEstaciones->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(estaciones[i].getTrabajando() ? estaciones[i].getPlaca() : "Vacía")));
        ui->tablaEstaciones->setItem(i, 2, new QTableWidgetItem(QString::fromStdString("00:00")));
    }

    actItemsTabla(ui->tablaEstaciones);

    // Iniciar servidor
    pthread_t server_thread;
    pthread_create(&server_thread, NULL, init_hilo_server, NULL);
}

Ui::Taller *Taller::getUi() const
{
    return ui;
}

Taller::~Taller()
{
    delete ui;
}

// Manejador de titulo dependiendo del tab seleccionado
void Taller::on_tabWidget_currentChanged(int index)
{
    tabManager(index, ui);
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
    vector<Vehiculo> vehiculos = Vehiculo::cargarVehiculosDesdeArchivo();
    for (Vehiculo vehiculo : vehiculos)
    {
        // Obtener la información del vehículo
        string placa = vehiculo.getPlaca();
        string dentroTaller = vehiculo.getEnTaller() ? "Sí" : "No";

        // Agregar una nueva fila a la tabla de vehículos del cliente
        int numRows = ui->tablaVehiculos->rowCount();
        ui->tablaVehiculos->insertRow(numRows);

        // Mostrar la información del vehículo en la tabla
        QTableWidgetItem *itemPlaca = new QTableWidgetItem(QString::fromStdString(placa));
        QTableWidgetItem *itemDentroTaller = new QTableWidgetItem(QString::fromStdString(dentroTaller));
        QTableWidgetItem *itemNumServicios = new QTableWidgetItem(QString::number(vehiculo.getNumServicios()));

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
    vector<Servicio> serviciosVector = Servicio::cargarServiciosDesdeArchivo(placa.toStdString());
    for (Servicio servicio : serviciosVector)
    {

        int numRows = ui->tablaServicios->rowCount();
        // Insert a new row at the end of the table
        ui->tablaServicios->insertRow(numRows);

        // Create new QTableWidgetItem objects for each column
        QTableWidgetItem *itemFechaIngreso = new QTableWidgetItem(QString::fromStdString(servicio.getFechaIni()));
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

void Taller::on_btn_repuestos_clicked()
{
    QDialog dialog(nullptr);
    QFormLayout form(&dialog);

    QLineEdit *lineEditNombre = new QLineEdit(&dialog);
    QLineEdit *lineEditCantidad = new QLineEdit(&dialog);
    form.addRow("Pieza:", lineEditNombre);
    form.addRow("Cantidad a agregar:", lineEditCantidad);

    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);

    QObject::connect(&buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    QObject::connect(&buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    if (dialog.exec() == QDialog::Accepted)
    {
        QString nombre = lineEditNombre->text();
        QString cantidad = lineEditCantidad->text();
        if (nombre == "" || cantidad == "")
        {
            qDebug() << "Error: No se puede dejar campos vacios";
            return;
        }

        // Agregar pieza
        inventario.agregarPiezas(Pieza(nombre.toStdString(), FUNCIONA), cantidad.toInt());
        rellenarTablaRepuestos(ui);
    }
}
