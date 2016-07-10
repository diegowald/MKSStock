#ifndef DLGUSUARIO_H
#define DLGUSUARIO_H

#include <QDialog>
#include "entities/usuario.h"

namespace Ui {
class DlgUsuario;
}

class DlgUsuario : public QDialog
{
    Q_OBJECT

public:
    explicit DlgUsuario(UsuarioPtr usuario, QWidget *parent = 0);
    ~DlgUsuario();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DlgUsuario *ui;
    UsuarioPtr _usuario;
};

#endif // DLGUSUARIO_H
