#include "manual.h"
#include <QApplication>
#include <QMainWindow>
#include <QTabWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>

using namespace std;

class Cliente
{
public:
    QString nombre;
    QString cedula;
    int numCarros;
    QString fechaRegistro;
    QString numContacto;
};

class CustomTableWidget : public QTableWidget
{
public:
    CustomTableWidget(QWidget *parent = nullptr) : QTableWidget(parent) {}

    void populateTable(Cliente *clientes, int clientesLength)
    {
        // Set the number of rows and columns in the table
        int numRows = clientesLength;
        int numColumns = 5;
        setRowCount(numRows);
        setColumnCount(numColumns);

        // Set the column headers
        QStringList headers;
        headers << "Nombre"
                << "Cedula"
                << "Numero de Carros"
                << "Fecha de Registro"
                << "Numero de Contacto";
        setHorizontalHeaderLabels(headers);

        // Set the table to stretch to fit the available space
        horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        // Adjust the table height based on the number of rows
        int tableHeight = numRows * rowHeight(0) + horizontalHeader()->height() + frameWidth() * 2;
        setFixedHeight(tableHeight);

        for (int row = 0; row < clientesLength; row++)
        {
            QTableWidgetItem *itemNombre = new QTableWidgetItem(clientes[row].nombre);
            QTableWidgetItem *itemCedula = new QTableWidgetItem(clientes[row].cedula);
            QTableWidgetItem *itemNumCarros = new QTableWidgetItem(QString::number(clientes[row].numCarros));
            QTableWidgetItem *itemFechaRegistro = new QTableWidgetItem(clientes[row].fechaRegistro);
            QTableWidgetItem *itemNumContacto = new QTableWidgetItem(clientes[row].numContacto);

            setItem(row, 0, itemNombre);
            setItem(row, 1, itemCedula);
            setItem(row, 2, itemNumCarros);
            setItem(row, 3, itemFechaRegistro);
            setItem(row, 4, itemNumContacto);
        }
    }
};

Manual::Manual(QWidget *parent) : QWidget(parent)
{
    /*
     *
     *   TABLA DE CLIENTES
     *
     */

    CustomTableWidget *tableWidget = new CustomTableWidget(this);


    // Arreglo clientes ejemplo
    Cliente clientes[] = {
        {"John Doe", "123456789", 2, "2021-01-01", "555-1234"},
        {"Jane Smith", "987654321", 1, "2021-02-15", "555-5678"},
        {"Alice Johnson", "456789123", 3, "2021-03-10", "555-9012"}};

    int clientesLength = sizeof(clientes) / sizeof(clientes[0]);

    tableWidget->populateTable(clientes, clientesLength);
}
