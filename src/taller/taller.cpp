#include "taller.h"
#include "./ui_taller.h"

Taller::Taller(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Taller)
{
    ui->setupUi(this);
}

Ui::Taller *Taller::getUi() const
{
    return ui;
}

Taller::~Taller()
{
    delete ui;
}

// manejador de titulo dependiendo del tab seleccionado
void Taller::on_tabWidget_currentChanged(int index)
{
    switch (index)
    {
    case 0:
        ui->label_2->setText("Inicio");
        break;
    case 1:
        ui->label_2->setText("Clientes");
        break;
    case 2:
        ui->label_2->setText("Estacionamiento");
        break;
    case 3:
        ui->label_2->setText("Centro de Diagnóstico");
        break;
    case 4:
        ui->label_2->setText("Piezas");
        break;
    case 5:
        ui->label_2->setText("Compra de Piezas");
        break;
    case 6:
        ui->label_2->setText("Estaciones del Sistema");
        break;
    default:
        ui->label_2->setText("Tab no reconocido");
        break;
    }
}
