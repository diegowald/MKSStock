#include "querycondition.h"
#include <QDebug>


QueryCondition::QueryCondition(const QString &fieldName, const Condition condition, QObject *parent) : QObject (parent)
{
    _fieldName = fieldName;
    _condition = condition;
    _paramName = QString(":%1").arg(fieldName);
}

QueryCondition::QueryCondition(const QString &fieldName, const Condition condition, const QVariant &value, QObject *parent) : QObject (parent)
{
    _fieldName = fieldName;
    _condition = condition;
    _paramName = QString(":%1").arg(fieldName);
    _values.append(value);
}

QueryCondition::QueryCondition(const QString &fieldName, const Condition condition, const QVariant &value1, const QVariant &value2, QObject *parent) : QObject (parent)
{
    _fieldName = fieldName;
    _condition = condition;
    _paramName = QString("%1").arg(fieldName);
    _values.append(value1);
    _values.append(value2);
}

QueryCondition::QueryCondition(const QString &fieldName, const Condition condition, const QString &paramName, QObject *parent) : QObject(parent)
{
    _fieldName = fieldName;
    _condition = condition;
    _paramName = paramName;
}


void QueryCondition::setValue(const QVariant &value)
{
    _values.clear();
    _values.append(value);
}

void QueryCondition::setValue(const QVariant &value1, const QVariant &value2)
{
    _values.clear();
    _values.append(value1);
    _values.append(value2);
}

void QueryCondition::setValue(const QVariantList &values)
{
    _values.clear();
    _values << values;
}

void QueryCondition::appendValue(const QVariant &value)
{
    _values.append(value);
}


QString QueryCondition::conditionString() const
{
    QString tmp;
    switch (_condition)
    {
    case Condition::EQUAL:
        tmp = "(%1 = %2)";
        break;
    case Condition::NOT_EQUAL:
        tmp = "(%1 != %2)";
        break;
    case Condition::IN:
        tmp = "(%1 IN (%2))";
        break;
    case Condition::NOT_IN:
        tmp = "(%1 NOT IN (%2))";
        break;
    case Condition::IS_NULL:
        tmp = "(%1 IS NULL)";
        break;
    case Condition::IS_NOT_NULL:
        tmp = "(%1 IS NOT NULL)";
        break;
    case Condition::BETWEEN:
        tmp = "(%1 BETWEEN %2 AND %3)";
        break;
    case Condition::LIKE:
        tmp = "(%1 LIKE %2)";
        break;
    case Condition::LESS_THAN:
        tmp = "(%1 < %2)";
        break;
    case Condition::GREATER_THAN:
        tmp = "(%1 > %2)";
        break;
    case Condition::LESS_OR_EQUAL_THAN:
        tmp = "(%1 <= %2)";
        break;
    case Condition::GREATER_OR_EQUAL_THAN:
        tmp = "(%1 >= %2)";
        break;
    default:
        qDebug() << "NOT IMPLEMENTED???";
        break;
    }

    QString s;
    switch (_condition)
    {
    case Condition::EQUAL:
    case Condition::NOT_EQUAL:
    case Condition::LIKE:
    case Condition::LESS_THAN:
    case Condition::GREATER_THAN:
    case Condition::LESS_OR_EQUAL_THAN:
    case Condition::GREATER_OR_EQUAL_THAN:
        s = tmp.arg(_fieldName).arg(_paramName);
        break;
    case Condition::IN:
    case Condition::NOT_IN:
    {
        QStringList values;
        foreach (QVariant v, _values)
        {
            if (v.canConvert<int>())
            {
                values.append(v.toString());
            }
            else
            {
                values.append("'" + v.toString() + "'");
            }
        }

        s = tmp.arg(_fieldName).arg(values.join(", "));
        break;
    }
    case Condition::IS_NULL:
    case Condition::IS_NOT_NULL:
        s = tmp.arg(_fieldName);
        break;
    case Condition::BETWEEN:
        s = tmp.arg(_fieldName).arg(_paramName + "1").arg(_paramName + "2");
        break;
    default:
        qDebug() << "NOT IMPLEMENTED???";
        break;
    }
    return s;
}

void QueryCondition::bind(QSqlQuery &query)
{
    switch (_condition)
    {
    case Condition::EQUAL:
    case Condition::NOT_EQUAL:
    case Condition::LIKE:
    case Condition::LESS_THAN:
    case Condition::GREATER_THAN:
    case Condition::LESS_OR_EQUAL_THAN:
    case Condition::GREATER_OR_EQUAL_THAN:
        query.bindValue(_paramName, _values.at(0));
        break;
    case Condition::IN:
    case Condition::NOT_IN:
    case Condition::IS_NULL:
    case Condition::IS_NOT_NULL:
        break;
    case Condition::BETWEEN:
    {
        QString p1 = _paramName + "1";
        QString p2 = _paramName + "2";
        query.bindValue(p1, _values.at(0));
        query.bindValue(p2, _values.at(1));
        break;
    }
    default:
        qDebug() << "NOT IMPLEMENTED???";
        break;
    }
}
