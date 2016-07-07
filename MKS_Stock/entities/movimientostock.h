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

    QSharedPointer<Usuario> usuario();
    QSharedPointer<Producto> producto();
    QSharedPointer<Ubicacion> ubicacion();
    QSharedPointer<MovimientoStock> movimientoAnterior();
    QDateTime fechaHora() const;

    void setUsuario(QSharedPointer<Usuario> value);
    void setProducto(QSharedPointer<Producto> value);
    void setUbicacion(QSharedPointer<Ubicacion> value);
    void setMovimientoAnterior(QSharedPointer<MovimientoStock> value);

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
};

#endif // MOVIMIENTOSTOCK_H
