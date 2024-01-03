#ifndef TALLER_H
#define TALLER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Taller;
}
QT_END_NAMESPACE

class Taller : public QMainWindow
{
    Q_OBJECT

public:
    Taller(QWidget *parent = nullptr);
    ~Taller();
    Ui::Taller* getUi() const;

private slots:

    void on_tabWidget_currentChanged(int index);


    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::Taller *ui;
};
#endif // TALLER_H
