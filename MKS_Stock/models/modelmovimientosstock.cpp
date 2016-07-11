#include "modelmovimientosstock.h"
#include <QSqlQuery>

ModelMovimientosStock::ModelMovimientosStock(QSqlDatabase &database, QObject *parent) : modelBase(database, "movimientosStock", "id", parent)
{
}

EntidadBasePtr ModelMovimientosStock::internalCreateEntity(const QSqlRecord &record)
{
    return MovimientoStockPtr::create(record);
}

void ModelMovimientosStock::mapFields()
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

    mapField("idUsuario", [&] (EntidadBasePtr entidad) -> QVariant
    {
        return cast(entidad)->idUsuario();
    },
    [&] (EntidadBasePtr entidad, const QVariant &value) -> bool
    {
        cast(entidad)->setIdUsuario(value.toInt());
        return true;
    }
    );

    mapField("idProducto", [&] (EntidadBasePtr entidad) -> QVariant
    {
        return cast(entidad)->idProducto();
    },
    [&] (EntidadBasePtr entidad, const QVariant &value) -> bool
    {
        cast(entidad)->setIdProducto(value.toInt());
        return true;
    }
    );

    mapField("idUbicacion", [&] (EntidadBasePtr entidad) -> QVariant
    {
        return cast(entidad)->idUbicacion();
    },
    [&] (EntidadBasePtr entidad, const QVariant &value) -> bool
    {
        cast(entidad)->setIdUbicacion(value.toInt());
        return true;
    }
    );

    mapField("idMovimientoAnterior", [&] (EntidadBasePtr entidad) -> QVariant
    {
        return cast(entidad)->idMovimientoAnterior();
    },
    [&] (EntidadBasePtr entidad, const QVariant &value) -> bool
    {
        cast(entidad)->setIdMovimientoAnterior(value.toInt());
        return true;
    }
    );

    QDateTime _fechaHora;
    mapField("fechaHora", [&] (EntidadBasePtr entidad) -> QVariant
    {
        return cast(entidad)->fechaHora();
    },
    [&] (EntidadBasePtr entidad, const QVariant &value) -> bool
    {
        cast(entidad)->setFechaHora(value.toDateTime());
        return true;
    }
    );
}

MovimientoStockPtr ModelMovimientosStock::cast(EntidadBasePtr entidad)
{
    return qSharedPointerDynamicCast<MovimientoStock>(entidad);
}

ResponsePtr ModelMovimientosStock::getPorProducto(int idProducto)
{
    QSqlQuery query(database());

    QString sql = "";

    return get(query);
}
