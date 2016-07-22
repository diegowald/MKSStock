#include "modelubicaciones.h"

ModelUbicaciones::ModelUbicaciones(QSqlDatabase &database, QObject *parent) : modelBase (database, "ubicaciones", "id", parent)
{
}

EntidadBasePtr ModelUbicaciones::internalCreateEntity()
{
    return UbicacionPtr::create();
}

void ModelUbicaciones::mapFields()
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

    mapField("oculto", 3, "Oculto", false, true, [&] (EntidadBasePtr entidad) -> QVariant
    {
        return cast(entidad)->oculto();
    },
    [&] (EntidadBasePtr entidad, const QVariant &value) -> bool
    {
        cast(entidad)->setOculto(value.toBool());
        return true;
    });
}

UbicacionPtr ModelUbicaciones::cast(EntidadBasePtr entidad)
{
    return qSharedPointerDynamicCast<Ubicacion>(entidad);
}
