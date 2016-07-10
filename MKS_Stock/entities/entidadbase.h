#ifndef ENTIDADBASE_H
#define ENTIDADBASE_H

#include <QObject>
#include <QSqlRecord>

enum class StatusEntidad
{
    SIN_CAMBIOS,
    NUEVO,
    MODIFICADO,
    BORRADO
};

class EntidadBase : public QObject
{
    Q_OBJECT
public:
    explicit EntidadBase(const QSqlRecord &record, QObject *parent = 0);
    explicit EntidadBase(QObject *parent = 0);

    int id() const;

    StatusEntidad status() const;

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
