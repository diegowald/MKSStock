#include "modelcontainer.h"

#include <QSharedPointer>
#include <QSqlDatabase>
#include "models/modelusuarios.h"
#include "models/modelubicaciones.h"
#include "models/modelproductos.h"


ModelContainer *ModelContainer::_instance;

void ModelContainer::initialize()
{
    _instance = new ModelContainer();
    _instance->init();
}

void ModelContainer::init()
{
    _dbName = "./stock.db";
    if (!QSqlDatabase::database(_dbName).isValid())
    {
        _database = QSqlDatabase::addDatabase("QSQLITE", _dbName);
    }
    else
    {
        _database = QSqlDatabase::database(_dbName);
    }
    _database.setDatabaseName(_dbName);


    _models[MODELS::USUARIOS] = ModelUsuariosPtr::create(_database);
    _models[MODELS::USUARIOS]->mapFields();

    _models[MODELS::UBICACIONES] = ModelUbicacionesPtr::create(_database);
    _models[MODELS::UBICACIONES]->mapFields();

    _models[MODELS::PRODUCTOS] = ModelProductosPtr::create(_database);
    _models[MODELS::PRODUCTOS]->mapFields();
}

ModelContainer &ModelContainer::instance()
{
    return *_instance;
}

ModelContainer::ModelContainer(QObject *parent) : QObject(parent)
{
}

modelBasePtr ModelContainer::model(MODELS modelName)
{
    return _models[modelName];
}
