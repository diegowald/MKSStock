#ifndef MODELPRODUCTOS_H
#define MODELPRODUCTOS_H

#include <QObject>

#include "models/modelbase.h"
#include "entities/producto.h"

class ModelProductos : public modelBase
{
    Q_OBJECT
public:
    explicit ModelProductos(QSqlDatabase &database, QObject *parent = 0);

protected:
    virtual EntidadBasePtr internalCreateEntity(const QSqlRecord &record);
    virtual void mapFields();

    ProductoPtr cast(EntidadBasePtr entidad);
signals:

public slots:
};

typedef QSharedPointer<ModelProductos> ModelProductosPtr;
#endif // MODELPRODUCTOS_H
