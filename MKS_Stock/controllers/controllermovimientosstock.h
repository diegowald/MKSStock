#ifndef CONTROLLERMOVIMIENTOSSTOCK_H
#define CONTROLLERMOVIMIENTOSSTOCK_H

#include <QObject>
#include "controllerbase.h"
#include "models/modelmovimientosstock.h"



class ControllerMovimientosStock : public ControllerBase
{
    Q_OBJECT
public:
    explicit ControllerMovimientosStock(QObject *parent = 0);

    ResponsePtr existenciaProducto(int idProducto);
    ResponsePtr existenciaProductoUbicacion(int idProducto, int idUbicacion);
    ResponsePtr existenciaUbicacion(int idUbicacion);
    ResponsePtr existencia();
signals:

public slots:

protected:
    virtual EntidadBasePtr crearNuevaEntidad() override;
    virtual bool editarEntidadExistente(EntidadBasePtr entidad) override;

private:
    ModelMovimientosStockPtr _modelMovimientosStock;
};

typedef QSharedPointer<ControllerMovimientosStock> ControllerMovimientosStockPtr;
#endif // CONTROLLERMOVIMIENTOSSTOCK_H
