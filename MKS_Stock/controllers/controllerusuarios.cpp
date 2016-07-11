#include "controllerusuarios.h"
#include "models/modelcontainer.h"
#include "entities/usuario.h"
#include "views/dlgusuario.h"

ControllerUsuarios::ControllerUsuarios(QObject *parent) :
    ControllerBase(ModelContainer::instance().model(MODELS::USUARIOS), parent)
{

}


EntidadBasePtr ControllerUsuarios::crearNuevaEntidad()
{
    UsuarioPtr u = UsuarioPtr::create();
    DlgUsuario dlg(u);
    if (dlg.exec() == QDialog::Accepted)
    {
        return u;
    }
    else
    {
        return UsuarioPtr();
    }
}
