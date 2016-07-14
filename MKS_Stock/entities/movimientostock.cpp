#include "movimientostock.h"

#include "usuario.h"
#include "producto.h"
#include "ubicacion.h"
#include <QDateTime>
#include <QVariant>
#include "models/modelcontainer.h"
#include "models/modelbase.h"


MovimientoStock::MovimientoStock(QObject *parent) : EntidadBase(parent)
{
    _idUsuario = -1;
    _idProducto = -1;
    _idUbicacion = -1;
    _idMovimientoAnterior = -1;
    _fechaHora = QDateTime::currentDateTime();
}

QSharedPointer<Usuario> MovimientoStock::usuario()
{
    if ((_idUsuario != -1) && (_usuario.isNull()))
    {
        ResponsePtr response = ModelContainer::instance().model(MODELS::USUARIOS)->get(_idUsuario);
        if (response->list().count() > 0)
            _usuario = qSharedPointerDynamicCast<Usuario>(response->list().at(0));
    }
    return _usuario;
}

QSharedPointer<Producto> MovimientoStock::producto()
{
    if ((_idProducto != -1) && (_producto.isNull()))
    {
        ResponsePtr response = ModelContainer::instance().model(MODELS::PRODUCTOS)->get(_idProducto);
        if (response->list().count() > 0)
            _producto = qSharedPointerDynamicCast<Producto>(response->list().at(0));
    }
    return _producto;
}

QSharedPointer<Ubicacion> MovimientoStock::ubicacion()
{
    if ((_idUbicacion != -1) && (_ubicacion.isNull()))
    {
        ResponsePtr response = ModelContainer::instance().model(MODELS::UBICACIONES)->get(_idUbicacion);
        if (response->list().count() > 0)
            _ubicacion = qSharedPointerDynamicCast<Ubicacion>(response->list().at(0));
    }
    return _ubicacion;
}

QSharedPointer<MovimientoStock> MovimientoStock::movimientoAnterior()
{
    if ((_idMovimientoAnterior != -1) && (_movimientoAnterior.isNull()))
    {
        ResponsePtr response = ModelContainer::instance().model(MODELS::MOVIMIENTOS_STOCK)->get(_idMovimientoAnterior);
        if (response->list().count() > 0)
            _movimientoAnterior = qSharedPointerDynamicCast<MovimientoStock>(response->list().at(0));
    }

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
    _idUsuario = value.isNull() ? -1 : value->id();
    updateStatus();
}

void MovimientoStock::setProducto(QSharedPointer<Producto> value)
{
    _producto = value;
    _idProducto = value.isNull() ? -1 : value->id();
    updateStatus();
}

void MovimientoStock::setUbicacion(QSharedPointer<Ubicacion> value)
{
    _ubicacion = value;
    _idUbicacion = value.isNull() ? -1 : value->id();
    updateStatus();
}

void MovimientoStock::setMovimientoAnterior(MovimientoStockPtr value)
{
    _movimientoAnterior = value;
    _idMovimientoAnterior = value.isNull() ?  -1 : value->id();
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
    _usuario.clear();
    updateStatus();
}

void MovimientoStock::setIdProducto(int value)
{
    _idProducto = value;
    _producto.clear();
    updateStatus();
}

void MovimientoStock::setIdUbicacion(int value)
{
    _idUbicacion = value;
    _ubicacion.clear();
    updateStatus();
}

void MovimientoStock::setIdMovimientoAnterior(int value)
{
    _idMovimientoAnterior = value;
    _movimientoAnterior.clear();
    updateStatus();
}
