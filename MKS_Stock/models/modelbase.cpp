#include "modelbase.h"
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QSet>

modelBase::modelBase(QSqlDatabase &database, const QString &tableName, const QString &idxColumnName, QObject *parent) : QObject(parent)
{
    _database = database;
    _tableName = tableName;
    _idxColumnName = idxColumnName;
}


void modelBase::mapField(const QString &fieldName, GetFunction getter, SetFunction setter)
{
    _getters[fieldName] = getter;
    _setters[fieldName] = setter;
}

ResponsePtr modelBase::get()
{
    QSqlQuery query(_database);

    if (!_database.isOpen())
    {
        _database.open();
    }

    QString sql = "SELECT COUNT(*) from %1";
    sql = sql.arg(_tableName);
    query.exec(sql);

    query.next();
    int total = query.record().value(0).toInt();

    ResponsePtr response = ResponsePtr::create(total, -1, -1, 0, this);

    sql = "SELECT * from %1;";
    sql = sql.arg(_tableName);

    query.exec(sql);
    if (query.lastError().text() != " ")
        qDebug() << query.lastError().text();

    while (query.next())
    {
        response->list().append(createEntity(query.record()));
    }

    return response;
}

EntidadBasePtr modelBase::createEntity(const QSqlRecord &record)
{
    return internalCreateEntity(record);
}

void modelBase::persist(EntidadBasePtr entidad)
{
    QList<EntidadBasePtr> l;
    l.append(entidad);
    persist(l);
}

void modelBase::persist(QList<EntidadBasePtr> &list)
{
    if (!_database.isOpen())
    {
        _database.open();
    }
    foreach(EntidadBasePtr entidad, list)
    {
        if (entidad->status() != StatusEntidad::SIN_CAMBIOS)
        {
            QSqlQuery *query = getQuery(entidad);
            if (query != NULL)
            {
                query->exec();
                if (query->lastError().text() != " ")
                    qDebug() << query->lastError().text();
                delete query;
            }
        }
    }
}

QSqlQuery *modelBase::getQuery(EntidadBasePtr entidad)
{
    QSqlQuery *qry = NULL;
    switch(entidad->status())
    {
    case StatusEntidad::NUEVO:
        qry = crearInsert(entidad);
        break;
    case StatusEntidad::MODIFICADO:
        qry = crearUpdate(entidad);
        break;
    case StatusEntidad::BORRADO:
        qry = crearDelete(entidad);
        break;
    case StatusEntidad::SIN_CAMBIOS:
        break;
    }

    return qry;
}

QStringList modelBase::getFieldNamesWithoutIdxColumnName()
{
    QSet<QString> flds = QSet<QString>::fromList(_getters.keys());

    flds.remove(_idxColumnName);
    return flds.toList();
}

QSqlQuery *modelBase::crearInsert(EntidadBasePtr entidad)
{
    QString s = "INSERT INTO %1 (%2) VALUES (%3);";

    QStringList flds = getFieldNamesWithoutIdxColumnName();

    QString sql = s.arg(_tableName).arg(flds.join(", "));

    QStringList params;
    foreach(QString fld, flds)
    {
        params.append(":" + fld);
    }

    sql = sql.arg(params.join(", "));

    QSqlQuery *qry = new QSqlQuery(_database);
    qry->prepare(sql);
    foreach(QString fld, flds)
    {
        qry->bindValue(":" + fld, _getters[fld](entidad));
    }
    return qry;
}

QSqlQuery *modelBase::crearUpdate(EntidadBasePtr entidad)
{
    QString s = "UPDATE %1 SET %2 WHERE %3;";

    QStringList flds = getFieldNamesWithoutIdxColumnName();

    QString sql = s.arg(_tableName);

    QStringList params;
    foreach(QString fld, flds)
    {
        params.append(fld + "= :" + fld);
    }

    sql = sql.arg(params.join(", "));

    sql = sql.arg(_idxColumnName + " = :idxColumn");

    QSqlQuery *qry = new QSqlQuery(_database);
    qry->prepare(sql);
    foreach(QString fld, flds)
    {
        qry->bindValue(":" + fld, _getters[fld](entidad));
    }

    qry->bindValue(":idxColumn", _getters[_idxColumnName](entidad));
    return qry;
}

QSqlQuery *modelBase::crearDelete(EntidadBasePtr entidad)
{
    QString s = "DELETE %1 WHERE %2";

    QString sql = s.arg(_tableName);

    sql = sql.arg(_idxColumnName + " = :idxColumn");

    QSqlQuery *qry = new QSqlQuery(_database);
    qry->prepare(sql);

    qry->bindValue(":idxColumn", _getters[_idxColumnName](entidad));
    return qry;
}
