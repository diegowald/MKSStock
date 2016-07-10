#ifndef RESPONSE_H
#define RESPONSE_H

#include <QObject>
#include "entities/entidadbase.h"
#include <QSharedPointer>

class Response : public QObject
{
    Q_OBJECT
public:
    explicit Response(int total, int from, int to, int status, QObject *parent = 0);

    QList<EntidadBasePtr> &list();
    int totalCount() const;
    int from() const;
    int to() const;
    int status() const;

signals:

public slots:

private:
    QList<EntidadBasePtr> _list;
    int _totalCount;
    int _from;
    int _to;
    int _status;
};

typedef QSharedPointer<Response> ResponsePtr;

#endif // RESPONSE_H
