#ifndef CENTROGARANTIAVEHICULO_H
#define CENTROGARANTIAVEHICULO_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class CentroGarantiaVehiculo;
}
QT_END_NAMESPACE

class CentroGarantiaVehiculo : public QMainWindow
{
    Q_OBJECT

public:
    CentroGarantiaVehiculo(QWidget *parent = nullptr);
    ~CentroGarantiaVehiculo();

private slots:
    void on_pushButton_2_clicked();

    void on_agregarPButton_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::CentroGarantiaVehiculo *ui;
};
#endif // CENTROGARANTIAVEHICULO_H
