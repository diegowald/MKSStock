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
    ResponsePtr get(int id);
    ResponsePtr get(QList<int> &ids);
    ResponsePtr get(QSqlQuery &qry);
    void persist(EntidadBasePtr entidad);
    void persist(QList<EntidadBasePtr> &list);

    QStringList headers();
    QString displayHeader(const QString &fieldName) const;
    QVariant value(EntidadBasePtr entidad, const QString &field);

    virtual void mapFields() = 0;
signals:

public slots:

protected:
    void mapField(const QString &fieldName, int order, const QString &displayFieldName, bool isVisible, bool persistOnDB, GetFunction getter, SetFunction setter);
    virtual EntidadBasePtr internalCreateEntity() = 0;

    QSqlDatabase &database();

private:

    EntidadBasePtr createEntity(const QSqlRecord &record);
    QSqlQuery *getQuery(EntidadBasePtr entidad);
    QSqlQuery *crearInsert(EntidadBasePtr entidad);
    QSqlQuery *crearUpdate(EntidadBasePtr entidad);
    QSqlQuery *crearDelete(EntidadBasePtr entidad);
    QStringList getFieldNamesWithoutIdxColumnName();



private:
    class Field
    {
    public:
        GetFunction _getter;
        SetFunction _setter;
        QString _displayName;
        bool _isVisible;
        bool _persistOnDB;
    };
    typedef QSharedPointer<Field> FieldPtr;

    QMap<int, QString> _fieldOrder;
    QMap<QString, FieldPtr> _fields;

    QString _tableName;
    QString _idxColumnName;

    QString _dbName;
    QSqlDatabase _database;
};

typedef QSharedPointer<modelBase> modelBasePtr;

#endif // MODELBASE_H
