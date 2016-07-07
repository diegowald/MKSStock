#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <QObject>
#include "entidadbase.h"

class Producto : public EntidadBase
{
    Q_OBJECT
public:
    explicit Producto(QObject *parent = 0);

    QString nombre() const;
    QString descripcion() const;

    void setNombre(const QString &value);
    void setDescripcion(const QString &value);
signals:

public slots:
private:
    QString _nombre;
    QString _descripcion;
};

#endif // PRODUCTO_H
