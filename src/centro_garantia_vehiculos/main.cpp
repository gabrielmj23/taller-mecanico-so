#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QScreen>
#include <QTableWidget>
#include <QHeaderView>

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
    tableWidget.setGeometry(10, 10, 963, 818);

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

    window.show();

    return app.exec();
}
