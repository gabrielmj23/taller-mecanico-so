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

private:
    Ui::CentroGarantiaVehiculo *ui;
};
#endif // CENTROGARANTIAVEHICULO_H
