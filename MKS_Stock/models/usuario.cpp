#include "usuario.h"

Usuario::Usuario(QObject *parent) : EntidadBase(parent)
{

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
}

void Usuario::setApellido(const QString &value)
{
    _apellido = value;
}

void Usuario::setPassword(const QString &value)
{
    _password = value;
}
