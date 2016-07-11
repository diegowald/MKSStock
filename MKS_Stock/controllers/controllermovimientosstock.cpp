#include "controllermovimientosstock.h"
#include "models/modelcontainer.h"
#include "entities/movimientostock.h"
#include "views/dialogmovimientostock.h"

ControllerMovimientosStock::ControllerMovimientosStock(QObject *parent) :
    ControllerBase(ModelContainer::instance().model(MODELS::MOVIMIENTOS_STOCK), parent)
{

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
