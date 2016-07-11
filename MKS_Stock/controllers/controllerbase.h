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
    QVariant value(EntidadBasePtr entidad, const QString &field);
    ResponsePtr get();

    void nuevaEntidad();

protected:
    virtual EntidadBasePtr crearNuevaEntidad() = 0;
signals:

public slots:
private:
    QList<ControlledView*> _views;
    modelBasePtr _model;
};

typedef QSharedPointer<ControllerBase> ControllerBasePtr;
#endif // CONTROLLERBASE_H
