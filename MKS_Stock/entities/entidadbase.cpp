#include "entidadbase.h"

EntidadBase::EntidadBase(QObject *parent) : QObject(parent)
{

}

int EntidadBase::id() const
{
    return _id;
}

StatusEntidad EntidadBase::status() const
{
    return _status;
}

void EntidadBase::updateStatus(StatusEntidad newStatus)
{
    switch (newStatus)
    {
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
