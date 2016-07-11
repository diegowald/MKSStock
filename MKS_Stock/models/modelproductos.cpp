#include "modelproductos.h"

ModelProductos::ModelProductos(QSqlDatabase &database, QObject *parent) : modelBase(database, "productos", "id", parent)
{
}

EntidadBasePtr ModelProductos::internalCreateEntity(const QSqlRecord &record)
{
    return ProductoPtr::create(record);
}

void ModelProductos::mapFields()
{
    mapField("id", 1, [&] (EntidadBasePtr entidad) -> QVariant
    {
        return cast(entidad)->id();
    },
    [&] (EntidadBasePtr entidad, const QVariant &value) -> bool
    {
        return true;
    }
    );

    mapField("nombre", 2, [&] (EntidadBasePtr entidad) -> QVariant
    {
        return cast(entidad)->nombre();
    },
    [&] (EntidadBasePtr entidad, const QVariant &value) -> bool
    {
        cast(entidad)->setNombre(value.toString());
        return true;
    }
    );

    mapField("descripcion", 3, [&] (EntidadBasePtr entidad) -> QVariant
    {
        return cast(entidad)->descripcion();
    },
    [&] (EntidadBasePtr entidad, const QVariant &value) -> bool
    {
        cast(entidad)->setDescripcion(value.toString());
        return true;
    });
}

ProductoPtr ModelProductos::cast(EntidadBasePtr entidad)
{
    return qSharedPointerDynamicCast<Producto>(entidad);
}
