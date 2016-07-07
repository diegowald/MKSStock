#include "movimientostock.h"

#include "usuario.h"
#include "producto.h"
#include "ubicacion.h"

MovimientoStock::MovimientoStock(QObject *parent) : EntidadBase(parent)
{

}

QSharedPointer<Usuario> MovimientoStock::usuario()
{
    return _usuario;
}

QSharedPointer<Producto> MovimientoStock::producto()
{
    return _producto;
}

QSharedPointer<Ubicacion> MovimientoStock::ubicacion()
{
    return _ubicacion;
}

QSharedPointer<MovimientoStock> MovimientoStock::movimientoAnterior()
{
    return _movimientoAnterior;
}

QDateTime MovimientoStock::fechaHora() const
{
    return _fechaHora;
}

void MovimientoStock::setUsuario(QSharedPointer<Usuario> value)
{
    _usuario = value;
    _idUsuario = value->id();
}

void MovimientoStock::setProducto(QSharedPointer<Producto> value)
{
    _producto = value;
    _idProducto = value->id();
}

void MovimientoStock::setUbicacion(QSharedPointer<Ubicacion> value)
{
    _ubicacion = value;
    _idUbicacion = value->id();
}

void MovimientoStock::setMovimientoAnterior(QSharedPointer<MovimientoStock> value)
{
    _movimientoAnterior = value;
    _idMovimientoAnterior = value->id();
}
