#ifndef MODELUBICACIONES_H
#define MODELUBICACIONES_H

#include <QObject>

#include "models/modelbase.h"
#include "entities/ubicacion.h"

class ModelUbicaciones : public modelBase
{
    Q_OBJECT
public:
    explicit ModelUbicaciones(QSqlDatabase &database, QObject *parent = 0);

    UbicacionPtr cast(EntidadBasePtr entidad);
protected:
    virtual EntidadBasePtr internalCreateEntity();
    virtual void mapFields();


signals:

public slots:
};

typedef QSharedPointer<ModelUbicaciones> ModelUbicacionesPtr;

#endif // MODELUBICACIONES_H
