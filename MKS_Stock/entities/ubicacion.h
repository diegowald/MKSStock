#ifndef UBICACION_H
#define UBICACION_H

#include <QObject>
#include "entidadbase.h"

class Ubicacion : public EntidadBase
{
    Q_OBJECT
public:
    explicit Ubicacion(QObject *parent = 0);

    QString nombre() const;
    bool oculto() const;

    void setNombre(const QString &value);
    void setOculto(bool value);
signals:

public slots:

private:
    QString _nombre;
    bool _oculto;
};

typedef QSharedPointer<Ubicacion> UbicacionPtr;

#endif // UBICACION_H
