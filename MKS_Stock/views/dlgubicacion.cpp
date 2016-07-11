#include "dlgubicacion.h"
#include "ui_dlgubicacion.h"

DlgUbicacion::DlgUbicacion(UbicacionPtr ubicacion, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgUbicacion)
{
    ui->setupUi(this);
    _ubicacion = ubicacion;

    ui->txtNombre->setText(_ubicacion->nombre());
}

DlgUbicacion::~DlgUbicacion()
{
    delete ui;
}

void DlgUbicacion::on_buttonBox_accepted()
{
    _ubicacion->setNombre(ui->txtNombre->text());
    close();
}
