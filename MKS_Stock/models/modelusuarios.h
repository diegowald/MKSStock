#ifndef MODELUSUARIOS_H
#define MODELUSUARIOS_H

#include <QObject>
#include "models/modelbase.h"
#include "entities/usuario.h"

class ModelUsuarios : public modelBase
{
    Q_OBJECT
public:
    explicit ModelUsuarios(QSqlDatabase &database, QObject *parent = 0);

    UsuarioPtr cast(EntidadBasePtr entidad);
protected:
    virtual EntidadBasePtr internalCreateEntity(const QSqlRecord &record);
    virtual void mapFields();

signals:

public slots:
};

typedef QSharedPointer<ModelUsuarios> ModelUsuariosPtr;
#endif // MODELUSUARIOS_H
