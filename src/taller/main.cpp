#include "taller.h"
#include "ui_taller.h" // Include the header file that defines the Ui::Taller class

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QFile>
#include <QScreen>
#include <QString>
#include <QLabel>
#include <QWidget>
#include <QTabBar>
#include <QHeaderView>
#include <vector>
#include <QTableWidgetItem>

#include "clases.h"

//variables globales

std::vector<ClienteVehiculo> clientesVehiculo = {
    {"Entrada", "Karim Sahili","09:00", "JK37Y2"},
    {"Salida", "Hamudi Sahili","10:00", "JK23hf"},
    {"Entrada", "Samy Sahili","12:00", "KHH323"},
    {"Salida", "Ali Sahili","16:00", "KLHH23"},
    {"Entrada", "Karim Sahili","09:00", "JK37Y2"},
    {"Salida", "Hamudi Sahili","10:00", "JK23hf"},
    {"Entrada", "Samy Sahili","12:00", "KHH323"},
    {"Salida", "Ali Sahili","16:00", "KLHH23"},
    {"Entrada", "Karim Sahili","09:00", "JK37Y2"},
    {"Salida", "Hamudi Sahili","10:00", "JK23hf"},
    {"Entrada", "Samy Sahili","12:00", "KHH323"},
    {"Salida", "Ali Sahili","16:00", "KLHH23"},
    {"Entrada", "Karim Sahili","09:00", "JK37Y2"},
    {"Salida", "Hamudi Sahili","10:00", "JK23hf"},
    {"Entrada", "Samy Sahili","12:00", "KHH323"}
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



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages)
    {
        const QString baseName = "taller_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName))
        {
            a.installTranslator(&translator);
            break;
        }
    }
    Taller w;

    // Colocar el logo de la aplicación
    QString imagePath = "../taller/logo500.png";
    if (!QFile::exists(imagePath))
    {
        qDebug() << "Error: No se encontró el archivo del icono";
    }
    a.setWindowIcon(QIcon(imagePath));

    /*
     *
     *   Para cambiar el tamaño y posicion de la ventana
     *
     */
    w.setGeometry(0, 0, 983, 738);
    w.setFixedSize(983, 738); // Para que no se pueda cambiar el tamaño de la ventana

    // Para centrar la posicion de la ventana segun la pantalla
    QScreen *screen = QGuiApplication::primaryScreen();
    if (const QScreen *screen = QGuiApplication::primaryScreen())
    {
        int screenWidth = screen->size().width();
        int screenHeight = screen->size().height();
        int wWidth = w.width();
        int wHeight = w.height();
        int x = (screenWidth - wWidth) / 2;
        int y = (screenHeight - wHeight) / 2;
        w.setGeometry(x, y, wWidth, wHeight);
    }

    

    // Access the UI
    Ui::Taller *ui = w.getUi();
    // Now you can use the `ui` pointer to interact with the UI elements

    // Set the title text of each tab to be horizontal
    for (int i = 0; i < ui->tabWidget->count(); i++)
    {
        QWidget *tabWidget = ui->tabWidget->widget(i);
        QLabel *titleLabel = new QLabel(ui->tabWidget->tabText(i));
        titleLabel->setAlignment(Qt::AlignHCenter);
        ui->tabWidget->setTabText(i, "");
        ui->tabWidget->tabBar()->setTabButton(i, QTabBar::LeftSide, titleLabel);
    }



   

    // Add an image to the centralWidget at position (10, 10)
    imagePath = "../taller/logo41.png";
    if (QFile::exists(imagePath))
    {
        QLabel *imageLabel = new QLabel(&w);
        QPixmap image(imagePath);
        imageLabel->setPixmap(image);
        imageLabel->setGeometry(10, 10, image.width(), image.height());
        imageLabel->show();
    }
    else
    {
        qDebug() << "Error: No se encontró el archivo de la imagen";
    }

    //extiende los titulos de la tabla en lo horizontal
    ui->tablaClienteVehiculo->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        

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

    // Show the main window
    w.show();

    return a.exec();
    }
