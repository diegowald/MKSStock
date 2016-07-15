#include "modelmovimientosstock.h"
#include <QSqlQuery>
#include "entities/ubicacion.h"
#include "entities/usuario.h"
#include "entities/producto.h"

ModelMovimientosStock::ModelMovimientosStock(QSqlDatabase &database, QObject *parent) : modelBase(database, "movimientosStock", "id", parent)
{
}

EntidadBasePtr ModelMovimientosStock::internalCreateEntity()
{
    return MovimientoStockPtr::create();
}

void ModelMovimientosStock::mapFields()
{
    mapField("id", 1, "#", true, true, [&] (EntidadBasePtr entidad) -> QVariant
    {
        return cast(entidad)->id();
    },
    [&] (EntidadBasePtr entidad, const QVariant &value) -> bool
    {
        entidad->setId(value.toInt());
        return true;
    }
    );

    mapField("idUsuario", 2, "", false, true, [&] (EntidadBasePtr entidad) -> QVariant
    {
        return cast(entidad)->idUsuario();
    },
    [&] (EntidadBasePtr entidad, const QVariant &value) -> bool
    {
        cast(entidad)->setIdUsuario(value.toInt());
        return true;
    }
    );

    mapField("idProducto", 3, "", false, true, [&] (EntidadBasePtr entidad) -> QVariant
    {
        return cast(entidad)->idProducto();
    },
    [&] (EntidadBasePtr entidad, const QVariant &value) -> bool
    {
        cast(entidad)->setIdProducto(value.toInt());
        return true;
    }
    );

    mapField("idUbicacion", 4, "", false, true, [&] (EntidadBasePtr entidad) -> QVariant
    {
        return cast(entidad)->idUbicacion();
    },
    [&] (EntidadBasePtr entidad, const QVariant &value) -> bool
    {
        cast(entidad)->setIdUbicacion(value.toInt());
        return true;
    }
    );

    mapField("idMovimientoAnterior", 5, "", false, true, [&] (EntidadBasePtr entidad) -> QVariant
    {
        return cast(entidad)->idMovimientoAnterior();
    },
    [&] (EntidadBasePtr entidad, const QVariant &value) -> bool
    {
        cast(entidad)->setIdMovimientoAnterior(value.toInt());
        return true;
    }
    );

    mapField("fechaHora", 6, "Fecha", true, true, [&] (EntidadBasePtr entidad) -> QVariant
    {
        return cast(entidad)->fechaHora();
    },
    [&] (EntidadBasePtr entidad, const QVariant &value) -> bool
    {
        cast(entidad)->setFechaHora(value.toDateTime());
        return true;
    }
    );

    mapField("usuario", 7, "Usuario", false, false, [&] (EntidadBasePtr entidad) -> QVariant
    {
        return QVariant::fromValue(cast(entidad)->usuario());
    },
    [&] (EntidadBasePtr entidad, const QVariant &value) -> bool
    {
        cast(entidad)->setUsuario(value.value<UsuarioPtr>());
        return true;
    });

    mapField("Producto", 8, "Producto", false, false, [&] (EntidadBasePtr entidad) -> QVariant
    {
        return QVariant::fromValue(cast(entidad)->producto());
    },
    [&] (EntidadBasePtr entidad, const QVariant &value) -> bool
    {
        cast(entidad)->setProducto(value.value<ProductoPtr>());
        return true;
    });

    mapField("Ubicacion", 9, "Ubicacion", false, false, [&] (EntidadBasePtr entidad) -> QVariant
    {
        return QVariant::fromValue(cast(entidad)->ubicacion());
    },
    [&] (EntidadBasePtr entidad, const QVariant &value) -> bool
    {
        cast(entidad)->setUbicacion(value.value<UbicacionPtr>());
        return true;
    });

    mapField("Movimiento Anterior", 10, "Movimiento Anterior", false, false, [&] (EntidadBasePtr entidad) -> QVariant
    {
        return QVariant::fromValue(cast(entidad)->movimientoAnterior());
    },
    [&] (EntidadBasePtr entidad, const QVariant &value) -> bool
    {
        cast(entidad)->setMovimientoAnterior(value.value<MovimientoStockPtr>());
        return true;
    });

    mapField("nombreUsuario", 11, "Usuario", true, false, [&] (EntidadBasePtr entidad) -> QVariant
    {
        UsuarioPtr usuario = cast(entidad)->usuario();
        QString s = "";
        if (!usuario.isNull())
        {
            QString tmp = "%1 %2";
            s = tmp.arg(usuario->nombre()).arg(usuario->apellido());
        }
        return s;
    },
    [&] (EntidadBasePtr entidad, const QVariant &value) -> bool
    {
        return true;
    });

    mapField("nombreProducto", 12, "Producto", true, false, [&] (EntidadBasePtr entidad) -> QVariant
    {
        ProductoPtr producto = cast(entidad)->producto();
        return producto.isNull() ? "" : producto->nombre();
    },
    [&] (EntidadBasePtr entidad, const QVariant &value) -> bool
    {
        return true;
    });

    mapField("nombreUbicacion", 13, "Ubicacion", true, false, [&] (EntidadBasePtr entidad) -> QVariant
    {
        UbicacionPtr ubicacion = cast(entidad)->ubicacion();
        return ubicacion.isNull() ? "" : ubicacion->nombre();
    },
    [&] (EntidadBasePtr entidad, const QVariant &value) -> bool
    {
        cast(entidad)->setUbicacion(value.value<UbicacionPtr>());
        return true;
    });

    mapField("nombreMovimientoAnterior", 14, "Movimiento Anterior", true, false, [&] (EntidadBasePtr entidad) -> QVariant
    {
        QString s = "";
        MovimientoStockPtr mov = cast(entidad)->movimientoAnterior();
        if (!mov.isNull())
        {
            QString tmp = "%1 : %2 (%3)";
            QString fecha;
            if (mov->fechaHora().date() == QDate::currentDate())
            {
                fecha = mov->fechaHora().toString("hh:mm");
            }
            else
            {
                fecha = mov->fechaHora().toString("dd/MM/yyyy");
            }
            QString ubicacion = mov->ubicacion().isNull() ? "" : mov->ubicacion()->nombre();

            s = tmp.arg(fecha).arg(ubicacion).arg(mov->cantidad());
        }
        return s;
    },
    [&] (EntidadBasePtr entidad, const QVariant &value) -> bool
    {
        return true;
    });
}

MovimientoStockPtr ModelMovimientosStock::cast(EntidadBasePtr entidad)
{
    return qSharedPointerDynamicCast<MovimientoStock>(entidad);
}

ResponsePtr ModelMovimientosStock::getPorProducto(int idProducto)
{
    QSqlQuery query(database());

    QString sql = "select ms.id, ms.fechaHora, ms.idUsuario, ms.idProducto, ms.idUbicacion, ms.idMovimientoAnterior, ms.cantidad - ifnull(qty,0) as cantidad "
                  " from movimientosStock ms left join (select idMovimientoAnterior, sum(ifnull(cantidad, 0)) as qty from movimientosStock group by idMovimientoAnterior) t1 "
                  " on ms.id = t1.idMovimientoAnterior where ms.idProducto = :idProducto;";

    query.prepare(sql);

    query.bindValue(":idProducto", idProducto);
    return get(query);
}
