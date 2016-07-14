#include "ubicacion.h"
#include <QVariant>


Ubicacion::Ubicacion(QObject *parent) : EntidadBase(parent)
{
    _nombre = "";
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
