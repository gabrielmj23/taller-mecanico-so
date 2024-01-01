#include "taller.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QFile>
#include <QScreen>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "taller_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    Taller w;

    // Colocar el logo de la aplicación
    QString imagePath = "../centro_garantia_vehiculos/logo500.png";
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
    w.show();
    return a.exec();
}
