#include "controllerusuarios.h"
#include "models/modelcontainer.h"
#include "entities/usuario.h"
#include "views/dlgusuario.h"

ControllerUsuarios::ControllerUsuarios(QObject *parent) :
    ControllerBase(ModelContainer::instance().model(MODELS::USUARIOS), parent)
{
    _modelUsuarios = qSharedPointerDynamicCast<ModelUsuarios>(model());
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

bool ControllerUsuarios::editarEntidadExistente(EntidadBasePtr entidad)
{
    bool result = false;
    UsuarioPtr u = _modelUsuarios->cast(entidad);
    DlgUsuario dlg(u);
    if (dlg.exec() == QDialog::Accepted)
    {
        result = true;
    }
    return result;
}

