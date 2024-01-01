#include "taller.h"
#include "./ui_taller.h"

Taller::Taller(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Taller)
{
    ui->setupUi(this);
}

Taller::~Taller()
{
    delete ui;
}
