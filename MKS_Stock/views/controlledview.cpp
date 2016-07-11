#include "controlledview.h"
#include "controllers/controllerbase.h"

ControlledView::ControlledView(QWidget *parent) : QMainWindow(parent)
{

}

void ControlledView::setController(ControllerBase *controller)
{
    _controller = controller;
    refresh();
}

ControllerBase *ControlledView::controller()
{
    return _controller;
}

QStringList ControlledView::headers()
{
    return controller()->headers();
}
