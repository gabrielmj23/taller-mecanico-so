#include "taller.h"
#include "./ui_taller.h"

Taller::Taller(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Taller)
{
    ui->setupUi(this);
}

Ui::Taller* Taller::getUi() const
{
    return ui;
}



    


Taller::~Taller()
{
    delete ui;
}
