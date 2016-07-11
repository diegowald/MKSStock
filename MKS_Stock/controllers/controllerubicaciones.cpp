#include "controllerubicaciones.h"
#include "models/modelcontainer.h"
#include "views/dlgubicacion.h"
#include "entities/ubicacion.h"

ControllerUbicaciones::ControllerUbicaciones(QObject *parent) :
    ControllerBase(ModelContainer::instance().model(MODELS::UBICACIONES), parent)
{
    _modelUbicaciones = qSharedPointerDynamicCast<ModelUbicaciones>(model());
}


EntidadBasePtr ControllerUbicaciones::crearNuevaEntidad()
{
    UbicacionPtr u = UbicacionPtr::create();
    DlgUbicacion dlg(u);
    if (dlg.exec() == QDialog::Accepted)
    {
        return u;
    }
    else
    {
        return UbicacionPtr();
    }
}

bool ControllerUbicaciones::editarEntidadExistente(EntidadBasePtr entidad)
{
    bool result = false;
    UbicacionPtr u = _modelUbicaciones->cast(entidad);
    DlgUbicacion dlg(u);
    if (dlg.exec() == QDialog::Accepted)
    {
        result = true;
    }
    return result;
}
