#include "modelusuarios.h"
#include "entities/usuario.h"

ModelUsuarios::ModelUsuarios(QSqlDatabase &database, QObject *parent) : modelBase (database, "usuarios", "id", parent)
{

}

EntidadBasePtr ModelUsuarios::internalCreateEntity(const QSqlRecord &record)
{
    return UsuarioPtr::create(record, this);
}


void ModelUsuarios::mapFields()
{
    mapField("id", [&] (EntidadBasePtr entidad) -> QVariant
    {
        return cast(entidad)->id();
    },
    [&] (EntidadBasePtr entidad, const QVariant &value) -> bool
    {
        return true;
    }
    );

    mapField("nombre", [&] (EntidadBasePtr entidad) -> QVariant
    {
        return cast(entidad)->nombre();
    },
    [&] (EntidadBasePtr entidad, const QVariant &value) -> bool
    {
        cast(entidad)->setNombre(value.toString());
        return true;
    }
    );

    mapField("apellido", [&] (EntidadBasePtr entidad) -> QVariant
    {
        return cast(entidad)->apellido();
    },
    [&] (EntidadBasePtr entidad, const QVariant &value) -> bool
    {
        cast(entidad)->setApellido(value.toString());
        return true;
    });

    mapField("password", [&] (EntidadBasePtr entidad) -> QVariant
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
