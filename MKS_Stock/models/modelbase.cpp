#include "modelbase.h"
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>

modelBase::modelBase(const QString &tableName, const QString &idxColumnName, QObject *parent) : QObject(parent)
{
    _tableName = tableName;
    _idxColumnName = idxColumnName;
}


void modelBase::mapField(const QString &fieldName, GetFunction getter, SetFunction setter)
{
    _getters[fieldName] = getter;
    _setters[fieldName] = setter;
}

QList<EntidadBasePtr> modelBase::get()
{
    QList<EntidadBasePtr> result;

    QSqlQuery query(_database);

    QString sql = "SELECT * from %1;";
    sql = sql.arg(_tableName);

    query.exec(sql);
    if (query.lastError().text() != " ")
        qDebug() << query.lastError().text();

    while (query.next())
    {
        result.append(createEntity(query.record()));
    }
    _database.close();

    return result;
}

EntidadBasePtr modelBase::createEntity(const QSqlRecord &record)
{
    return internalCreateEntity(record);
}
