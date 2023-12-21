#include <QApplication>
#include <QWidget>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Interfaz Simple");
    window.setGeometry(100, 100, 200, 100);

    QPushButton button("Haz clic", &window);
    button.setGeometry(50, 20, 100, 30);

    window.show();

    return app.exec();
}
