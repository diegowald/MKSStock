#include "usuario.h"
#include <QVariant>


Usuario::Usuario(QObject *parent) : EntidadBase(parent)
{
    _nombre = "";
    _apellido = "";
    _password = "";
}

Usuario::Usuario(const QSqlRecord &record, QObject *parent) : EntidadBase(record, parent)
{
    _nombre = record.value("nombre").toString();
    _apellido = record.value("apellido").toString();
    _password = record.value("password").toString();
}

QString Usuario::nombre() const
{
    return _nombre;
}

QString Usuario::apellido() const
{
    return _apellido;
}

QString Usuario::password() const
{
    return _password;
}

void Usuario::setNombre(const QString &value)
{
    _nombre = value;
    updateStatus();
}

void Usuario::setApellido(const QString &value)
{
    _apellido = value;
    updateStatus();
}

void Usuario::setPassword(const QString &value)
{
    _password = value;
    updateStatus();
}
