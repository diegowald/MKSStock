#ifndef CONTROLLERPRODUCTOS_H
#define CONTROLLERPRODUCTOS_H

#include <QObject>
#include "controllerbase.h"

class ControllerProductos : public ControllerBase
{
    Q_OBJECT
public:
    explicit ControllerProductos(QObject *parent = 0);

signals:

public slots:
protected:
    virtual EntidadBasePtr crearNuevaEntidad() override;
};

typedef QSharedPointer<ControllerProductos> ControllerProductosPtr;
#endif // CONTROLLERPRODUCTOS_H
