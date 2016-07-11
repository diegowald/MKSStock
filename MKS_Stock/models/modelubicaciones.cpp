#include "modelubicaciones.h"

ModelUbicaciones::ModelUbicaciones(QSqlDatabase &database, QObject *parent) : modelBase (database, "ubicaciones", "id", parent)
{
}

EntidadBasePtr ModelUbicaciones::internalCreateEntity(const QSqlRecord &record)
{
    return UbicacionPtr::create(record);
}

void ModelUbicaciones::mapFields()
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
}

UbicacionPtr ModelUbicaciones::cast(EntidadBasePtr entidad)
{
    return qSharedPointerDynamicCast<Ubicacion>(entidad);
}
