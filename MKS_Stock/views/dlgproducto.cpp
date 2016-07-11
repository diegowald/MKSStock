#include "dlgproducto.h"
#include "ui_dlgproducto.h"

DlgProducto::DlgProducto(ProductoPtr producto, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgProducto)
{
    ui->setupUi(this);
    _producto = producto;

    ui->txtNombre->setText(_producto->nombre());
    ui->txtDescripcion->setText(_producto->descripcion());
}

DlgProducto::~DlgProducto()
{
    delete ui;
}

void DlgProducto::on_buttonBox_accepted()
{
    _producto->setNombre(ui->txtNombre->text());
    _producto->setDescripcion(ui->txtDescripcion->text());
    close();
}
