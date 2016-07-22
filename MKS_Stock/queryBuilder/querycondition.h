#ifndef QUERYCONDITION_H
#define QUERYCONDITION_H

#include <QObject>
#include <QVariant>
#include <QSqlQuery>

enum class Condition
{
    EQUAL,
    NOT_EQUAL,
    IN,
    NOT_IN,
    IS_NULL,
    IS_NOT_NULL,
    BETWEEN,
    LIKE,
    LESS_THAN,
    GREATER_THAN,
    LESS_OR_EQUAL_THAN,
    GREATER_OR_EQUAL_THAN
};

class QueryCondition : public QObject
{
    Q_OBJECT
public:
    explicit QueryCondition(const QString &fieldName, const Condition condition, QObject *parent = 0);
    explicit QueryCondition(const QString &fieldName, const Condition condition, const QVariant &value, QObject *parent = 0);
    explicit QueryCondition(const QString &fieldName, const Condition condition, const QVariant &value1, const QVariant &value2, QObject *parent = 0);
    explicit QueryCondition(const QString &fieldName, const Condition condition, const QString &paramName, QObject *parent = 0);

    void setValue(const QVariant &value);
    void setValue(const QVariant &value1, const QVariant &value2);
    void setValue(const QVariantList &values);
    void appendValue(const QVariant &value);

    QString conditionString() const;
    void bind(QSqlQuery &query);

signals:

public slots:

private:
    QString _fieldName;
    Condition _condition;
    QVariantList _values;
    QString _paramName;
};

typedef QSharedPointer<QueryCondition> QueryConditionPtr;
#endif // QUERYCONDITION_H
