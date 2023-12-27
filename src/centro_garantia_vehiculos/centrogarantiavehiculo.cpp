#include "centrogarantiavehiculo.h"
#include "./ui_centrogarantiavehiculo.h"

CentroGarantiaVehiculo::CentroGarantiaVehiculo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CentroGarantiaVehiculo)
{
    ui->setupUi(this);
}

CentroGarantiaVehiculo::~CentroGarantiaVehiculo()
{
    delete ui;
}
