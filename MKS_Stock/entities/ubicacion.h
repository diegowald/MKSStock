#ifndef UBICACION_H
#define UBICACION_H

#include <QObject>
#include "entidadbase.h"

class Ubicacion : public EntidadBase
{
    Q_OBJECT
public:
    //explicit Ubicacion(QObject *parent = 0);
    explicit Ubicacion(const QSqlRecord &record, QObject *parent = 0);

    QString nombre() const;

    void setNombre(const QString &value);
signals:

public slots:

private:
    QString _nombre;
};

#endif // UBICACION_H
