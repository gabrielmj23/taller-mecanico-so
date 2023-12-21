#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QScreen>
#include <QTableWidget>
#include <QHeaderView>
#include <QLineEdit>
#include <QDebug>

using namespace std;

class Cliente {
public:
    QString nombre;
    QString cedula;
    int numCarros;
    QString fechaRegistro;
    QString numContacto;
};


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Centro de Garantia y Vehiculos");
    window.setGeometry(0, 0, 983, 838);
    window.setFixedSize(983, 838); // Para que no se pueda cambiar el tamaño de la ventana

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

    QTableWidget tableWidget(&window);
    tableWidget.setGeometry(10, 40, 963, 788);

    // Set the number of rows and columns in the table
    int numRows = 10;
    int numColumns = 5;
    tableWidget.setRowCount(numRows);
    tableWidget.setColumnCount(numColumns);

    // Set the column headers
    QStringList headers;
    headers << "Nombre" << "Cedula" << "Numero de Carros" << "Fecha de Registro" << "Numero de Contacto";
    tableWidget.setHorizontalHeaderLabels(headers);

    // Set the table to stretch to fit the available space
    tableWidget.horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableWidget.verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Example array of Cliente objects
    Cliente Clientes[] = {
        {"John Doe", "123456789", 2, "2021-01-01", "555-1234"},
        {"Jane Smith", "987654321", 1, "2021-02-15", "555-5678"},
        {"Alice Johnson", "456789123", 3, "2021-03-10", "555-9012"}
        // Add more objects as needed
    };

    // Populate the table with data from the Cliente objects
    for (int row = 0; row < 3; row++) {
        QTableWidgetItem* itemNombre = new QTableWidgetItem(Clientes[row].nombre);
        QTableWidgetItem* itemCedula = new QTableWidgetItem(Clientes[row].cedula);
        QTableWidgetItem* itemNumCarros = new QTableWidgetItem(QString::number(Clientes[row].numCarros));
        QTableWidgetItem* itemFechaRegistro = new QTableWidgetItem(Clientes[row].fechaRegistro);
        QTableWidgetItem* itemNumContacto = new QTableWidgetItem(Clientes[row].numContacto);

        tableWidget.setItem(row, 0, itemNombre);
        tableWidget.setItem(row, 1, itemCedula);
        tableWidget.setItem(row, 2, itemNumCarros);
        tableWidget.setItem(row, 3, itemFechaRegistro);
        tableWidget.setItem(row, 4, itemNumContacto);
    }

    QLineEdit searchBox(&window);
    searchBox.setGeometry(10, 10, 200, 20);
QObject::connect(&searchBox, &QLineEdit::textChanged, [&tableWidget](const QString &text){
    for (int row = 0; row < tableWidget.rowCount(); row++) {
        QTableWidgetItem* item = tableWidget.item(row, 0);
        bool match = item && item->text().contains(text, Qt::CaseInsensitive);
        tableWidget.setRowHidden(row, !match);
    }
});

    window.show();

    return app.exec();
}
