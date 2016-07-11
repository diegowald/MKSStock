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

    ResponsePtr getPorProducto(int idProducto);
    MovimientoStockPtr cast(EntidadBasePtr entidad);

protected:
    virtual EntidadBasePtr internalCreateEntity(const QSqlRecord &record);
    virtual void mapFields();

signals:

public slots:
};

typedef QSharedPointer<ModelMovimientosStock> ModelMovimientosStockPtr;

#endif // MODELMOVIMIENTOSSTOCK_H
