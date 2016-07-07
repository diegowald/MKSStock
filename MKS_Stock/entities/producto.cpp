#include "producto.h"

Producto::Producto(QObject *parent) : EntidadBase(parent)
{

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
}

void Producto::setDescripcion(const QString &value)
{
    _descripcion = value;
}
