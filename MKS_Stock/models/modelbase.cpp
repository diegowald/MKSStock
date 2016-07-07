#include "modelbase.h"

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
