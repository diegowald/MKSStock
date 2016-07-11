#include "controllerproductos.h"
#include "models/modelcontainer.h"
#include "entities/producto.h"
#include "views/dlgproducto.h"

ControllerProductos::ControllerProductos(QObject *parent) :
    ControllerBase(ModelContainer::instance().model(MODELS::PRODUCTOS), parent)
{
    _modelProductos = qSharedPointerDynamicCast<ModelProductos>(model());
}

EntidadBasePtr ControllerProductos::crearNuevaEntidad()
{
    ProductoPtr p = ProductoPtr::create();
    DlgProducto dlg(p);
    if (dlg.exec() == QDialog::Accepted)
    {
        return p;
    }
    else
    {
        return ProductoPtr();
    }
}

bool ControllerProductos::editarEntidadExistente(EntidadBasePtr entidad)
{
    bool result = false;
    ProductoPtr p = _modelProductos->cast(entidad);
    DlgProducto dlg(p);
    if (dlg.exec() == QDialog::Accepted)
    {
        result = true;
    }
    return result;
}
