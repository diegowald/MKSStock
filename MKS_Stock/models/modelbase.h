#ifndef MODELBASE_H
#define MODELBASE_H

#include <QObject>
#include <functional>
#include "entities/entidadbase.h"
#include <QVariant>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlRecord>
#include "models/response.h"

typedef std::function<QVariant (EntidadBasePtr)> GetFunction;
typedef std::function<bool (EntidadBasePtr, const QVariant&)> SetFunction;

class modelBase : public QObject
{
    Q_OBJECT
public:
    explicit modelBase(QSqlDatabase &database, const QString &tableName, const QString &idxColumnName, QObject *parent = 0);


    ResponsePtr get();
    ResponsePtr get(QList<int> &ids);
    ResponsePtr get(QSqlQuery &qry);
    void persist(EntidadBasePtr entidad);
    void persist(QList<EntidadBasePtr> &list);

    QStringList headers();
    QVariant value(EntidadBasePtr entidad, const QString &field);

    virtual void mapFields() = 0;
signals:

public slots:

protected:
    void mapField(const QString &fieldName, GetFunction getter, SetFunction setter);
    virtual EntidadBasePtr internalCreateEntity(const QSqlRecord &record) = 0;

    QSqlDatabase &database();

private:

    EntidadBasePtr createEntity(const QSqlRecord &record);
    QSqlQuery *getQuery(EntidadBasePtr entidad);
    QSqlQuery *crearInsert(EntidadBasePtr entidad);
    QSqlQuery *crearUpdate(EntidadBasePtr entidad);
    QSqlQuery *crearDelete(EntidadBasePtr entidad);
    QStringList getFieldNamesWithoutIdxColumnName();



private:
    QMap<QString, GetFunction> _getters;
    QMap<QString, SetFunction> _setters;
    QString _tableName;
    QString _idxColumnName;

    QString _dbName;
    QSqlDatabase _database;
};

typedef QSharedPointer<modelBase> modelBasePtr;

#endif // MODELBASE_H
