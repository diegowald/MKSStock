#include "ubicacion.h"
#include <QVariant>


Ubicacion::Ubicacion(QObject *parent) : EntidadBase(parent)
{
    _nombre = "";
    _oculto = false;
}

QString Ubicacion::nombre() const
{
    return _nombre;
}

void Ubicacion::setNombre(const QString &value)
{
    _nombre = value;
    updateStatus();
}


bool Ubicacion::oculto() const
{
    return _oculto;
}

void Ubicacion::setOculto(bool value)
{
    _oculto = value;
    updateStatus();
}
