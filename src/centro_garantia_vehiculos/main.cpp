
#include <QApplication>
#include <QMainWindow>
#include <QTabWidget>
#include "manual.h"
#include <QFile>
#include <QDebug>
#include <QIcon>
#include <QScreen>
#include <QGuiApplication>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Colocar el logo de la aplicación
    QString imagePath = "C:/Users/karim/Desktop/taller-mecanico-so/src/centro_garantia_vehiculos/assets/logo500.png";
    if (!QFile::exists(imagePath))
    {
        qDebug() << "Error: No se encontró el archivo del icono";
    }
    app.setWindowIcon(QIcon(imagePath));

    // Establecer tamanio para pantallas
    QMainWindow window;
    window.setWindowTitle("Centro de Garantía y Vehículos");
    window.setGeometry(0, 0, 983, 838);
    window.setFixedSize(983, 738); // Para que no se pueda cambiar el tamaño de la ventana

    // Para centrar la posicion de la ventana segun la pantalla
    QScreen *screen = QGuiApplication::primaryScreen();
    if (const QScreen *screen = QGuiApplication::primaryScreen())
    {
        int screenWidth = screen->size().width();
        int screenHeight = screen->size().height();
        int windowWidth = window.width();
        int windowHeight = window.height();
        int x = (screenWidth - windowWidth) / 2;
        int y = (screenHeight - windowHeight) / 2;
        window.setGeometry(x, y, windowWidth, windowHeight);
    }
    // Create the tab manager
    QTabWidget tabManager(&window);

    // Create the panels for each tab
    Manual *firstTab = new Manual(); // Use the Manual widget from manual.cpp
    tabManager.addTab(firstTab, "Manual");

    QWidget *secondTab = new QWidget();
    secondTab->setStyleSheet("background-color: blue;");
    tabManager.addTab(secondTab, "Aleatorio");

    QWidget *thirdTab = new QWidget();
    thirdTab->setStyleSheet("background-color: green;");
    tabManager.addTab(thirdTab, "Ajustes");

    // Set the tab manager as the central widget of the main window
    window.setCentralWidget(&tabManager);

    window.show();

    return app.exec();
}
