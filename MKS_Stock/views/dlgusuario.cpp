#include "dlgusuario.h"
#include "ui_dlgusuario.h"

DlgUsuario::DlgUsuario(UsuarioPtr usuario, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgUsuario)
{
    ui->setupUi(this);
    _usuario = usuario;
    ui->txtApellido->setText(_usuario->apellido());
    ui->txtNombre->setText(_usuario->nombre());
}

DlgUsuario::~DlgUsuario()
{
    delete ui;
}

void DlgUsuario::on_buttonBox_accepted()
{
    _usuario->setNombre(ui->txtNombre->text());
    _usuario->setApellido(ui->txtApellido->text());
    close();
}
