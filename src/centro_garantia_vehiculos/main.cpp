#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QScreen>
#include <QTableWidget>
#include <QHeaderView>
#include <QLineEdit>
#include <QDebug>
#include <QDate> 
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>

using namespace std;

class Cliente {
public:
    QString nombre;
    QString cedula;
    int numCarros;
    QString fechaRegistro;
    QString numContacto;
};

class CustomTableWidget : public QTableWidget {
public:
    CustomTableWidget(QWidget* parent = nullptr) : QTableWidget(parent) {}

    void populateTable(Cliente* clientes, int clientesLength) {
        // Set the number of rows and columns in the table
        int numRows = clientesLength;
        int numColumns = 5;
        setRowCount(numRows);
        setColumnCount(numColumns);

        // Set the column headers
        QStringList headers;
        headers << "Nombre" << "Cedula" << "Numero de Carros" << "Fecha de Registro" << "Numero de Contacto";
        setHorizontalHeaderLabels(headers);

        // Set the table to stretch to fit the available space
        horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        // Adjust the table height based on the number of rows
        int tableHeight = numRows * rowHeight(0) + horizontalHeader()->height() + frameWidth() * 2;
        setFixedHeight(tableHeight);

        for (int row = 0; row < clientesLength; row++) {
            QTableWidgetItem* itemNombre = new QTableWidgetItem(clientes[row].nombre);
            QTableWidgetItem* itemCedula = new QTableWidgetItem(clientes[row].cedula);
            QTableWidgetItem* itemNumCarros = new QTableWidgetItem(QString::number(clientes[row].numCarros));
            QTableWidgetItem* itemFechaRegistro = new QTableWidgetItem(clientes[row].fechaRegistro);
            QTableWidgetItem* itemNumContacto = new QTableWidgetItem(clientes[row].numContacto);

            setItem(row, 0, itemNombre);
            setItem(row, 1, itemCedula);
            setItem(row, 2, itemNumCarros);
            setItem(row, 3, itemFechaRegistro);
            setItem(row, 4, itemNumContacto);
        }
    }
};




int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Centro de Garantia y Vehiculos");
    window.setGeometry(0, 0, 983, 838);
    window.setFixedSize(983, 738); // Para que no se pueda cambiar el tamaño de la ventana

    // Para centrar la posicion de la ventana segun la pantalla
    QScreen* screen = QGuiApplication::primaryScreen();
    if (const QScreen *screen = QGuiApplication::primaryScreen()) {
        int screenWidth = screen->size().width();
        int screenHeight = screen->size().height();
        int windowWidth = window.width();
        int windowHeight = window.height();
        int x = (screenWidth - windowWidth) / 2;
        int y = (screenHeight - windowHeight) / 2;
        window.setGeometry(x, y, windowWidth, windowHeight);
    }

    CustomTableWidget tableWidget(&window);
    tableWidget.setGeometry(10, 40, 963, 600);

    // Example array of Cliente objects
    Cliente clientes[] = {
        {"John Doe", "123456789", 2, "2021-01-01", "555-1234"},
        {"Jane Smith", "987654321", 1, "2021-02-15", "555-5678"},
        {"Alice Johnson", "456789123", 3, "2021-03-10", "555-9012"}
    };

    int clientesLength = sizeof(clientes) / sizeof(clientes[0]);

    tableWidget.populateTable(clientes, clientesLength);

    QLineEdit searchBox(&window);
    searchBox.setGeometry(10, 10, 200, 30);
    QObject::connect(&searchBox, &QLineEdit::textChanged, [&tableWidget](const QString &text){
        for (int row = 0; row < tableWidget.rowCount(); row++) {
            QTableWidgetItem* item = tableWidget.item(row, 0);
            bool match = item && item->text().contains(text, Qt::CaseInsensitive);
            tableWidget.setRowHidden(row, !match);
        }
    });

    QPushButton addButton("Add Cliente", &window);
    addButton.setGeometry(10, 650, 100, 30);
    addButton.setStyleSheet("background-color: green; color: white;");
    QObject::connect(&addButton, &QPushButton::clicked, [&tableWidget]() {
        // Create a new Cliente object
        Cliente newCliente;
        newCliente.nombre = "New Cliente";
        newCliente.cedula = "123456789";
        newCliente.numCarros = 1;
        newCliente.fechaRegistro = QDate::currentDate().toString("yyyy-MM-dd"); // Set fechaRegistro to today's date
        newCliente.numContacto = "555-4321";

        // Get the current number of rows in the table
        int numRows = tableWidget.rowCount();

        // Insert a new row at the end of the table
        tableWidget.insertRow(numRows);

        // Populate the table with the data from the new Cliente object
        QTableWidgetItem* itemNombre = new QTableWidgetItem(newCliente.nombre);
        QTableWidgetItem* itemCedula = new QTableWidgetItem(newCliente.cedula);
        QTableWidgetItem* itemNumCarros = new QTableWidgetItem(QString::number(newCliente.numCarros));
        QTableWidgetItem* itemFechaRegistro = new QTableWidgetItem(newCliente.fechaRegistro);
        QTableWidgetItem* itemNumContacto = new QTableWidgetItem(newCliente.numContacto);

        tableWidget.setItem(numRows, 0, itemNombre);
        tableWidget.setItem(numRows, 1, itemCedula);
        tableWidget.setItem(numRows, 2, itemNumCarros);
        tableWidget.setItem(numRows, 3, itemFechaRegistro);
        tableWidget.setItem(numRows, 4, itemNumContacto);

        // Reset the table height based on the number of rows
        int tableHeight = (numRows + 1) * tableWidget.rowHeight(0) + tableWidget.horizontalHeader()->height() + tableWidget.frameWidth() * 2;
        tableWidget.setFixedHeight(tableHeight);
    });

    // Move the button up and to the right of the table
    addButton.move(tableWidget.x() + tableWidget.width() - addButton.width(), tableWidget.y() - addButton.height());

    window.show();

    return app.exec();
}
