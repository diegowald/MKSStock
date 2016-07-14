#include "usuario.h"
#include <QVariant>


Usuario::Usuario(QObject *parent) : EntidadBase(parent)
{
    _nombre = "";
    _apellido = "";
    _password = "";
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
