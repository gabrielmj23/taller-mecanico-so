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

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_12_clicked();

private:
    Ui::CentroGarantiaVehiculo *ui;
};
#endif // CENTROGARANTIAVEHICULO_H
