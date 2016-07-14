#ifndef CONTROLLERBASE_H
#define CONTROLLERBASE_H

#include <QObject>
#include "models/modelbase.h"

#include "views/controlledview.h"

class ControllerBase : public QObject
{
    Q_OBJECT
public:
    explicit ControllerBase(modelBasePtr model, QObject *parent = 0);
    void addView(ControlledView *view);

    QStringList headers();
    QString displayHeader(const QString &fieldName) const;
    QVariant value(EntidadBasePtr entidad, const QString &field);
    ResponsePtr get();

    void nuevaEntidad();
    void editarEntidad(EntidadBasePtr entidad);

protected:
    virtual EntidadBasePtr crearNuevaEntidad() = 0;
    virtual bool editarEntidadExistente(EntidadBasePtr entidad) = 0;
    modelBasePtr model();
signals:

public slots:
private:
    QList<ControlledView*> _views;
    modelBasePtr _model;
};

typedef QSharedPointer<ControllerBase> ControllerBasePtr;
#endif // CONTROLLERBASE_H
