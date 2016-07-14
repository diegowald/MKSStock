#include "entidadbase.h"
#include <QVariant>


EntidadBase::EntidadBase(QObject *parent) : QObject(parent)
{
    _id = -1;
    _status = StatusEntidad::NUEVO;
}

int EntidadBase::id() const
{
    return _id;
}

void EntidadBase::setId(int value)
{
    _id = value;
}

StatusEntidad EntidadBase::status() const
{
    return _status;
}

void EntidadBase::updateStatus(StatusEntidad newStatus)
{
    if (_status == StatusEntidad::INICIALIZANDO)
        return;

    switch (newStatus)
    {
    case StatusEntidad::INICIALIZANDO:
        _status = newStatus;
        break;
    case StatusEntidad::SIN_CAMBIOS:
        _status = newStatus;
        break;
    case StatusEntidad::NUEVO:
        _status = newStatus;
        break;
    case StatusEntidad::MODIFICADO:
        _status = _status != StatusEntidad::NUEVO ? newStatus : _status;
        break;
    case StatusEntidad::BORRADO:
        _status = _status == StatusEntidad::NUEVO ? StatusEntidad::SIN_CAMBIOS : newStatus;
        break;
    }
}

void EntidadBase::beginInitialize()
{
    _status = StatusEntidad::INICIALIZANDO;
}

void EntidadBase::endInitialize()
{
    _status = StatusEntidad::SIN_CAMBIOS;
}
