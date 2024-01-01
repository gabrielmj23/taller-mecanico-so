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
    // Show the main window
    w.show();

    return a.exec();
}
