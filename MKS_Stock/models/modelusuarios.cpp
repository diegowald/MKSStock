#include "modelusuarios.h"
#include "entities/usuario.h"

ModelUsuarios::ModelUsuarios(QSqlDatabase &database, QObject *parent) : modelBase (database, "usuarios", "id", parent)
{

}

EntidadBasePtr ModelUsuarios::internalCreateEntity()
{
    return UsuarioPtr::create(this);
}


void ModelUsuarios::mapFields()
{
    mapField("id", 1, "#", true, true, [&] (EntidadBasePtr entidad) -> QVariant
    {
        return entidad->id();
    },
    [&] (EntidadBasePtr entidad, const QVariant &value) -> bool
    {
        entidad->setId(value.toInt());
        return true;
    }
    );

    mapField("nombre", 2, "Nombre", true, true, [&] (EntidadBasePtr entidad) -> QVariant
    {
        return cast(entidad)->nombre();
    },
    [&] (EntidadBasePtr entidad, const QVariant &value) -> bool
    {
        cast(entidad)->setNombre(value.toString());
        return true;
    }
    );

    mapField("apellido", 3, "Apellido", true, true, [&] (EntidadBasePtr entidad) -> QVariant
    {
        return cast(entidad)->apellido();
    },
    [&] (EntidadBasePtr entidad, const QVariant &value) -> bool
    {
        cast(entidad)->setApellido(value.toString());
        return true;
    });

    mapField("password", 4, "Password", true, true, [&] (EntidadBasePtr entidad) -> QVariant
    {
        return cast(entidad)->password();
    },
    [&] (EntidadBasePtr entidad, const QVariant &value)
    {
        cast(entidad)->setPassword(value.toString());
        return true;
    });
}


UsuarioPtr ModelUsuarios::cast(EntidadBasePtr entidad)
{
    return qSharedPointerDynamicCast<Usuario>(entidad);
}
