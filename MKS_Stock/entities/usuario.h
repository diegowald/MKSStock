#ifndef USUARIO_H
#define USUARIO_H

#include <QObject>
#include "entidadbase.h"

class Usuario : public EntidadBase
{
    Q_OBJECT
public:
    explicit Usuario(QObject *parent = 0);

    QString nombre() const;
    QString apellido() const;
    QString password() const;

    void setNombre(const QString &value);
    void setApellido(const QString &value);
    void setPassword(const QString &value);
signals:

public slots:
private:
    QString _nombre;
    QString _apellido;
    QString _password;
};

#endif // USUARIO_H
