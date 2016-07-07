#ifndef MODELBASE_H
#define MODELBASE_H

#include <QObject>
#include <functional>
#include "entidadbase.h"
#include <QVariant>

typedef std::function<QVariant (EntidadBasePtr)> GetFunction;
typedef std::function<bool (EntidadBasePtr, const QVariant&)> SetFunction;

class modelBase : public QObject
{
    Q_OBJECT
public:
    explicit modelBase(const QString &tableName, const QString &idxColumnName, QObject *parent = 0);

    void mapField(const QString &fieldName, GetFunction getter, SetFunction setter);
signals:

public slots:

private:
    QMap<QString, GetFunction> _getters;
    QMap<QString, SetFunction> _setters;
    QString _tableName;
    QString _idxColumnName;
};

#endif // MODELBASE_H
