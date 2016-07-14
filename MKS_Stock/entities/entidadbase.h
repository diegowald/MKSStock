#ifndef ENTIDADBASE_H
#define ENTIDADBASE_H

#include <QObject>
#include <QSqlRecord>

enum class StatusEntidad
{
    SIN_CAMBIOS,
    NUEVO,
    MODIFICADO,
    BORRADO,
    INICIALIZANDO
};

class EntidadBase : public QObject
{
    Q_OBJECT
public:
    explicit EntidadBase(QObject *parent = 0);

    int id() const;

    void setId(int value);
    StatusEntidad status() const;

    void beginInitialize();
    void endInitialize();
protected:
    void updateStatus(StatusEntidad newStatus = StatusEntidad::MODIFICADO);

signals:

public slots:

private:
    int _id;
    StatusEntidad _status;
};

typedef QSharedPointer<EntidadBase> EntidadBasePtr;

#endif // ENTIDADBASE_H
