#include "ubicacion.h"
#include <QVariant>


Ubicacion::Ubicacion(QObject *parent) : EntidadBase(parent)
{
    _nombre = "";
}

Ubicacion::Ubicacion(const QSqlRecord &record, QObject *parent) : EntidadBase(record, parent)
{
    _nombre = record.value("nombre").toString();
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
