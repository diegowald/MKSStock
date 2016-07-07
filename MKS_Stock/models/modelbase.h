#ifndef MODELBASE_H
#define MODELBASE_H

#include <QObject>
#include <functional>
#include "entities/entidadbase.h"
#include <QVariant>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlRecord>

typedef std::function<QVariant (EntidadBasePtr)> GetFunction;
typedef std::function<bool (EntidadBasePtr, const QVariant&)> SetFunction;

class modelBase : public QObject
{
    Q_OBJECT
public:
    explicit modelBase(const QString &tableName, const QString &idxColumnName, QObject *parent = 0);

    void mapField(const QString &fieldName, GetFunction getter, SetFunction setter);
    
    QList<EntidadBasePtr> get();

signals:

public slots:

private:
    EntidadBasePtr createEntity(const QSqlRecord &record);
    virtual EntidadBasePtr internalCreateEntity(const QSqlRecord &record) = 0;

private:
    QMap<QString, GetFunction> _getters;
    QMap<QString, SetFunction> _setters;
    QString _tableName;
    QString _idxColumnName;

    QSqlDatabase _database;
};

#endif // MODELBASE_H
