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
    mapField("id", 1, [&] (EntidadBasePtr entidad) -> QVariant
    {
        return cast(entidad)->id();
    },
    [&] (EntidadBasePtr entidad, const QVariant &value) -> bool
    {
        return true;
    }
    );

    mapField("idUsuario", 2, [&] (EntidadBasePtr entidad) -> QVariant
    {
        return cast(entidad)->idUsuario();
    },
    [&] (EntidadBasePtr entidad, const QVariant &value) -> bool
    {
        cast(entidad)->setIdUsuario(value.toInt());
        return true;
    }
    );

    mapField("idProducto", 3, [&] (EntidadBasePtr entidad) -> QVariant
    {
        return cast(entidad)->idProducto();
    },
    [&] (EntidadBasePtr entidad, const QVariant &value) -> bool
    {
        cast(entidad)->setIdProducto(value.toInt());
        return true;
    }
    );

    mapField("idUbicacion", 4, [&] (EntidadBasePtr entidad) -> QVariant
    {
        return cast(entidad)->idUbicacion();
    },
    [&] (EntidadBasePtr entidad, const QVariant &value) -> bool
    {
        cast(entidad)->setIdUbicacion(value.toInt());
        return true;
    }
    );

    mapField("idMovimientoAnterior", 5, [&] (EntidadBasePtr entidad) -> QVariant
    {
        return cast(entidad)->idMovimientoAnterior();
    },
    [&] (EntidadBasePtr entidad, const QVariant &value) -> bool
    {
        cast(entidad)->setIdMovimientoAnterior(value.toInt());
        return true;
    }
    );

    mapField("fechaHora", 6, [&] (EntidadBasePtr entidad) -> QVariant
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

    QString sql =
    "select * from movimientosStock left join (select idMovimientoAnterior, "
    "sum(cantidad) as cantidadQuitada from movimientosStock "
    "group by idMovimientoAnterior) m1 on "
    "movimientosStock.id = m1.idMovimientoAnterior where cantidad - cantidadQuitada > 0 "
    "and movimientosStock.idProducto = :idProducto;";
    query.prepare(sql);

    query.bindValue(":idProducto", idProducto);
    return get(query);
}
