#include "controllerbase.h"

ControllerBase::ControllerBase(modelBasePtr model, QObject *parent) : QObject(parent)
{
    _model = model;
}

void ControllerBase::addView(ControlledView *view)
{
    _views.append(view);
    view->setController(this);
}

QStringList ControllerBase::headers()
{
    return _model->headers();
}

QString ControllerBase::displayHeader(const QString &fieldName) const
{
    return _model->displayHeader(fieldName);
}

QVariant ControllerBase::value(EntidadBasePtr entidad, const QString &field)
{
    return _model->value(entidad, field);
}

ResponsePtr ControllerBase::get()
{
    return _model->get();
}

void ControllerBase::nuevaEntidad()
{
    EntidadBasePtr entidad = crearNuevaEntidad();
    if (!entidad.isNull())
    {
        _model->persist(entidad);
        foreach(ControlledView *v, _views)
        {
            v->refresh();
        }
    }
}

void ControllerBase::editarEntidad(EntidadBasePtr entidad)
{
    if (editarEntidadExistente(entidad))
    {
        _model->persist(entidad);
        foreach(ControlledView *v, _views)
        {
            v->refresh();
        }
    }
}


modelBasePtr ControllerBase::model()
{
    return _model;
}
