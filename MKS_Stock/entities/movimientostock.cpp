#include "movimientostock.h"

#include "usuario.h"
#include "producto.h"
#include "ubicacion.h"
#include <QDateTime>
#include <QVariant>


MovimientoStock::MovimientoStock(QObject *parent) : EntidadBase(parent)
{
    _idUsuario = -1;
    _idProducto = -1;
    _idUbicacion = -1;
    _idMovimientoAnterior = -1;
    _fechaHora = QDateTime::currentDateTime();
}

MovimientoStock::MovimientoStock(const QSqlRecord &record, QObject *parent) : EntidadBase(record, parent)
{
    _idUsuario = record.value("idUsuario").toInt();
    _idProducto = record.value("idProducto").toInt();
    _idUbicacion = record.value("idUbicacion").toInt();
    _idMovimientoAnterior = record.value("idMovimientoAnterior").toInt();
    _fechaHora = record.value("fechaHora").toDateTime();
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

int MovimientoStock::cantidad() const
{
    return _cantidad;
}

void MovimientoStock::setUsuario(QSharedPointer<Usuario> value)
{
    _usuario = value;
    _idUsuario = value->id();
    updateStatus();
}

void MovimientoStock::setProducto(QSharedPointer<Producto> value)
{
    _producto = value;
    _idProducto = value->id();
    updateStatus();
}

void MovimientoStock::setUbicacion(QSharedPointer<Ubicacion> value)
{
    _ubicacion = value;
    _idUbicacion = value->id();
    updateStatus();
}

void MovimientoStock::setMovimientoAnterior(MovimientoStockPtr value)
{
    _movimientoAnterior = value;
    _idMovimientoAnterior = value->id();
    updateStatus();
}

void MovimientoStock::setFechaHora(const QDateTime &value)
{
    _fechaHora = value;
    updateStatus();
}

void MovimientoStock::setCantidad(int value)
{
    _cantidad = value;
    updateStatus();
}

int MovimientoStock::idUsuario() const
{
    return _idUsuario;
}

int MovimientoStock::idProducto() const
{
    return _idProducto;
}

int MovimientoStock::idUbicacion() const
{
    return _idUbicacion;
}

int MovimientoStock::idMovimientoAnterior() const
{
    return _idMovimientoAnterior;
}

void MovimientoStock::setIdUsuario(int value)
{
    _idUsuario = value;
    updateStatus();
}

void MovimientoStock::setIdProducto(int value)
{
    _idProducto = value;
    updateStatus();
}

void MovimientoStock::setIdUbicacion(int value)
{
    _idUbicacion = value;
    updateStatus();
}

void MovimientoStock::setIdMovimientoAnterior(int value)
{
    _idMovimientoAnterior = value;
    updateStatus();
}
