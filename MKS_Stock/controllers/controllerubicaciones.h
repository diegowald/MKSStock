#ifndef CONTROLLERUBICACIONES_H
#define CONTROLLERUBICACIONES_H

#include <QObject>
#include "controllerbase.h"
#include "models/modelubicaciones.h"


class ControllerUbicaciones : public ControllerBase
{
    Q_OBJECT
public:
    explicit ControllerUbicaciones(QObject *parent = 0);

signals:

public slots:

    // ControllerBase interface
protected:
    virtual EntidadBasePtr crearNuevaEntidad() override;
    virtual bool editarEntidadExistente(EntidadBasePtr entidad) override;

private:
    ModelUbicacionesPtr _modelUbicaciones;
};

typedef QSharedPointer<ControllerUbicaciones> ControllerUbicacionesPtr;

#endif // CONTROLLERUBICACIONES_H
