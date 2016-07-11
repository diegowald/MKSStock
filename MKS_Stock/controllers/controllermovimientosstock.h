#ifndef CONTROLLERMOVIMIENTOSSTOCK_H
#define CONTROLLERMOVIMIENTOSSTOCK_H

#include <QObject>
#include "controllerbase.h"

class ControllerMovimientosStock : public ControllerBase
{
    Q_OBJECT
public:
    explicit ControllerMovimientosStock(QObject *parent = 0);

signals:

public slots:

protected:
    virtual EntidadBasePtr crearNuevaEntidad() override;
};

typedef QSharedPointer<ControllerMovimientosStock> ControllerMovimientosStockPtr;
#endif // CONTROLLERMOVIMIENTOSSTOCK_H
