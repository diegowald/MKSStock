#include "response.h"
#include <QSharedPointer>

Response::Response(int total, int from, int to, int status, QObject *parent) : QObject(parent)
{
    _totalCount = total;
    _from = from;
    _to = to;
    _status = status;
}

QList<EntidadBasePtr> &Response::list()
{
    return _list;
}

int Response::totalCount() const
{
    return _totalCount;
}

int Response::from() const
{
    return _from;
}

int Response::to() const
{
    return _to;
}

int Response::status() const
{
    return _status;
}
