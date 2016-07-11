#ifndef CONTROLLERUSUARIOS_H
#define CONTROLLERUSUARIOS_H

#include <QObject>
#include "controllerbase.h"

class ControllerUsuarios : public ControllerBase
{
    Q_OBJECT
public:
    explicit ControllerUsuarios(QObject *parent = 0);

signals:

public slots:
    // ControllerBase interface
protected:
    virtual EntidadBasePtr crearNuevaEntidad() override;
};

typedef QSharedPointer<ControllerUsuarios> ControllerUsuariosPtr;

#endif // CONTROLLERUSUARIOS_H
