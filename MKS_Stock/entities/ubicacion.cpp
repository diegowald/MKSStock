#include "ubicacion.h"

Ubicacion::Ubicacion(QObject *parent) : EntidadBase(parent)
{

}

QString Ubicacion::nombre() const
{
    return _nombre;
}

void Ubicacion::setNombre(const QString &value)
{
    _nombre = value;
}
