#ifndef CONTROLLERUBICACIONES_H
#define CONTROLLERUBICACIONES_H

#include <QObject>
#include "controllerbase.h"

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
};

typedef QSharedPointer<ControllerUbicaciones> ControllerUbicacionesPtr;

#endif // CONTROLLERUBICACIONES_H
