#include "modelproductos.h"

ModelProductos::ModelProductos(QSqlDatabase &database, QObject *parent) : modelBase(database, "productos", "id", parent)
{
}

EntidadBasePtr ModelProductos::internalCreateEntity()
{
    return ProductoPtr::create();
}

void ModelProductos::mapFields()
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

    mapField("descripcion", 3, "Descripcion", true, true, [&] (EntidadBasePtr entidad) -> QVariant
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
