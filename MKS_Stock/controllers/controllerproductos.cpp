#include "controllerproductos.h"
#include "models/modelcontainer.h"
#include "entities/producto.h"
#include "views/dlgproducto.h"

ControllerProductos::ControllerProductos(QObject *parent) :
    ControllerBase(ModelContainer::instance().model(MODELS::PRODUCTOS), parent)
{

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
