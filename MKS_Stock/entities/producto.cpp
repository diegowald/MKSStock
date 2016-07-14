#include "producto.h"
#include <QVariant>


Producto::Producto(QObject *parent) : EntidadBase(parent)
{
    _nombre = "";
    _descripcion = "";
}

QString Producto::nombre() const
{
    return _nombre;
}

QString Producto::descripcion() const
{
    return _descripcion;
}

void Producto::setNombre(const QString &value)
{
    _nombre = value;
    updateStatus();
}

void Producto::setDescripcion(const QString &value)
{
    _descripcion = value;
    updateStatus();
}
