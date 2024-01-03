#include "taller.h"
#include "ui_taller.h" // Include the header file that defines the Ui::Taller class

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QFile>
#include <QScreen>
#include <QDebug>
#include <QLabel>
#include <QPixmap>


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

    // Show the main window
    w.show();

    return a.exec();
}
