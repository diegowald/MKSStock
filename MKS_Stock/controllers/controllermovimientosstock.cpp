#include "controllermovimientosstock.h"
#include "models/modelcontainer.h"
#include "entities/movimientostock.h"
#include "views/dialogmovimientostock.h"

ControllerMovimientosStock::ControllerMovimientosStock(QObject *parent) :
    ControllerBase(ModelContainer::instance().model(MODELS::MOVIMIENTOS_STOCK), parent)
{
    _modelMovimientosStock = qSharedPointerDynamicCast<ModelMovimientosStock>(model());
}

EntidadBasePtr ControllerMovimientosStock::crearNuevaEntidad()
{
    MovimientoStockPtr m = MovimientoStockPtr::create();
    DialogMovimientoStock dlg(m);
    if (dlg.exec() == QDialog::Accepted)
    {
        return m;
    }
    else
    {
        return MovimientoStockPtr();
    }
}

bool ControllerMovimientosStock::editarEntidadExistente(EntidadBasePtr entidad)
{
    bool result = false;
    MovimientoStockPtr m = _modelMovimientosStock->cast(entidad);
    DialogMovimientoStock dlg(m);
    if (dlg.exec() == QDialog::Accepted)
    {
        result = true;
    }
    return result;
}


ResponsePtr ControllerMovimientosStock::existenciaProducto(int idProducto)
{
    return _modelMovimientosStock->existenciaProducto(idProducto);
}

ResponsePtr ControllerMovimientosStock::existenciaProductoUbicacion(int idProducto, int idUbicacion)
{
    return _modelMovimientosStock->existenciaProductoUbicacion(idProducto, idUbicacion);
}

ResponsePtr ControllerMovimientosStock::existenciaUbicacion(int idUbicacion)
{
    return _modelMovimientosStock->existenciaUbicacion(idUbicacion);
}

ResponsePtr ControllerMovimientosStock::existencia()
{
    return _modelMovimientosStock->existencia();
}
