#include "controllerubicaciones.h"
#include "models/modelcontainer.h"
#include "views/dlgubicacion.h"
#include "entities/ubicacion.h"

ControllerUbicaciones::ControllerUbicaciones(QObject *parent) :
    ControllerBase(ModelContainer::instance().model(MODELS::UBICACIONES), parent)
{

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
