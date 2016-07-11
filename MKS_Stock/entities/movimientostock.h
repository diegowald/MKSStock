#ifndef MOVIMIENTOSTOCK_H
#define MOVIMIENTOSTOCK_H

#include <QObject>
#include <QSharedPointer>
#include <QDateTime>
#include "entidadbase.h"

class Usuario;
class Producto;
class Ubicacion;

class MovimientoStock : public EntidadBase
{
    Q_OBJECT
public:
    explicit MovimientoStock(QObject *parent = 0);
    explicit MovimientoStock(const QSqlRecord &record, QObject *parent = 0);

    QSharedPointer<Usuario> usuario();
    QSharedPointer<Producto> producto();
    QSharedPointer<Ubicacion> ubicacion();
    QSharedPointer<MovimientoStock> movimientoAnterior();
    QDateTime fechaHora() const;
    int cantidad() const;

    void setUsuario(QSharedPointer<Usuario> value);
    void setProducto(QSharedPointer<Producto> value);
    void setUbicacion(QSharedPointer<Ubicacion> value);
    void setMovimientoAnterior(QSharedPointer<MovimientoStock> value);
    void setFechaHora(const QDateTime &value);
    void setCantidad(int value);

    int idUsuario() const;
    int idProducto() const;
    int idUbicacion() const;
    int idMovimientoAnterior() const;

    void setIdUsuario(int value);
    void setIdProducto(int value);
    void setIdUbicacion(int value);
    void setIdMovimientoAnterior(int value);

signals:

public slots:

private:

    QSharedPointer<Usuario> _usuario;
    QSharedPointer<Producto> _producto;
    QSharedPointer<Ubicacion> _ubicacion;
    QSharedPointer<MovimientoStock> _movimientoAnterior;
    int _idUsuario;
    int _idProducto;
    int _idUbicacion;
    int _idMovimientoAnterior;
    QDateTime _fechaHora;
    int _cantidad;
};

typedef QSharedPointer<MovimientoStock> MovimientoStockPtr;

#endif // MOVIMIENTOSTOCK_H
