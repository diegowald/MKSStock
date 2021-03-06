#ifndef MODELMOVIMIENTOSSTOCK_H
#define MODELMOVIMIENTOSSTOCK_H

#include <QObject>
#include "models/modelbase.h"
#include "entities/movimientostock.h"

class ModelMovimientosStock : public modelBase
{
    Q_OBJECT
public:
    explicit ModelMovimientosStock(QSqlDatabase &database, QObject *parent = 0);

    ResponsePtr existenciaProducto(int idProducto);
    ResponsePtr existenciaProductoUbicacion(int idProducto, int idUbicacion);
    ResponsePtr existenciaUbicacion(int idUbicacion);
    ResponsePtr existencia();
    MovimientoStockPtr cast(EntidadBasePtr entidad);

protected:
    virtual EntidadBasePtr internalCreateEntity();
    virtual void mapFields();

signals:

public slots:
};

typedef QSharedPointer<ModelMovimientosStock> ModelMovimientosStockPtr;

#endif // MODELMOVIMIENTOSSTOCK_H
