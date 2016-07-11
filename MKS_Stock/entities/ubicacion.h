#ifndef UBICACION_H
#define UBICACION_H

#include <QObject>
#include "entidadbase.h"

class Ubicacion : public EntidadBase
{
    Q_OBJECT
public:
    explicit Ubicacion(const QSqlRecord &record, QObject *parent = 0);
    explicit Ubicacion(QObject *parent = 0);

    QString nombre() const;

    void setNombre(const QString &value);
signals:

public slots:

private:
    QString _nombre;
};

typedef QSharedPointer<Ubicacion> UbicacionPtr;

#endif // UBICACION_H
