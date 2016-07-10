#ifndef MODELCONTAINER_H
#define MODELCONTAINER_H

#include <QObject>
#include <QSqlDatabase>
#include "models/modelbase.h"
#include <QMap>

enum class MODELS
{
    USUARIOS
};

class ModelContainer : public QObject
{
    Q_OBJECT
public:
    static ModelContainer &instance();
    static void initialize();
    static void finalize();

    modelBasePtr model(MODELS modelName);

private:
    explicit ModelContainer(QObject *parent = 0);
    void init();

private:
    static ModelContainer *_instance;

private:
    QSqlDatabase _database;
    QString _dbName;

    QMap<MODELS, modelBasePtr> _models;
};

#endif // MODELCONTAINER_H
