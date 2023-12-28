
#include <QHeaderView>
#include <QLineEdit>
#include <QDialog>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QTableWidgetItem>
#include <QDebug>
#include <QDate>

#include "centrogarantiavehiculo.h"
#include "./ui_centrogarantiavehiculo.h"
#include "Cliente.h"

using namespace std;

//actualiza las propiedades de los items de la tabla (centrar y no editable)
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

    // Tabla de clientes
    ui->clienteTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Arreglo clientes ejemplo
    Cliente clientes[] = {
        {"John Doe", "123456789", "01-01-2021", "555-1234"},
        {"Jane Smith", "987654321", "15-02-2021", "555-5678"},
        {"Alice Johnson", "456789123", "10-03-2021", "555-9012"}};

    // Agregar clientes a la tabla
    for (int i = 0; i < 3; i++)
    {
        ui->clienteTableWidget->insertRow(i);
        ui->clienteTableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(clientes[i].getNombre())));
        ui->clienteTableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(clientes[i].getCedula())));
        ui->clienteTableWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(clientes[i].getFechaRegistro())));
        ui->clienteTableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(clientes[i].getNumVehiculos())));
        ui->clienteTableWidget->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(clientes[i].getNumContacto())));
    }

    actItemsTabla(ui->clienteTableWidget);
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
        QTableWidgetItem *itemNumCarros = new QTableWidgetItem(QString::number(newCliente.getNumVehiculos()));
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

void CentroGarantiaVehiculo::on_lineEdit_textChanged(const QString &arg1)
{
    qDebug() << "Text changed: ";
    for (int row = 0; row < ui->clienteTableWidget->rowCount(); row++)
    {
        QTableWidgetItem *item = ui->clienteTableWidget->item(row, 0);
        bool match = item && item->text().contains(arg1, Qt::CaseInsensitive);
        ui->clienteTableWidget->setRowHidden(row, !match);
    }
}
