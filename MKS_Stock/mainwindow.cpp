#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMdiSubWindow>
#include "models/modelcontainer.h"
#include "views/windowusuarios.h"
#include "views/tablecontrolledwindow.h"
#include "views/stockcontrolledwindow.h"
#include "controllers/controllerubicaciones.h"
#include "controllers/controllerusuarios.h"
#include "controllers/controllerproductos.h"
#include "controllers/controllermovimientosstock.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ModelContainer::initialize();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::crearSubWindow(QWidget *wnd, const QString &windowName)
{
    QMdiSubWindow *subWindow = ui->mdiArea->addSubWindow(wnd);
    subWindow->setObjectName(windowName);
    wnd->setAttribute(Qt::WA_DeleteOnClose);
    subWindow->setWindowIcon(wnd->windowIcon());
    subWindow->setWindowTitle(windowName);
    subWindow->show();
}

void MainWindow::on_actionStock_triggered()
{
    if (!_controllers.contains("movimientosStock"))
    {
        _controllers["movimientosStock"] = ControllerMovimientosStockPtr::create();
    }
    StockControlledWindow *wnd = new StockControlledWindow (this);
    _controllers["movimientosStock"]->addView(wnd);
    crearSubWindow(wnd, "Stock");
}

void MainWindow::on_actionUsuarios_triggered()
{
    /*WindowUsuarios *wnd = new WindowUsuarios(this);
    crearSubWindow(wnd, "Usuarios");*/
    if (!_controllers.contains("usuarios"))
    {
        _controllers["usuarios"] = ControllerUsuariosPtr::create();
    }
    TableControlledWindow *wnd = new TableControlledWindow(this);
    _controllers["usuarios"]->addView(wnd);
    crearSubWindow(wnd, "Usuarios");
}

void MainWindow::on_actionUbicaciones_triggered()
{
    if (!_controllers.contains("ubicaciones"))
    {
        _controllers["ubicaciones"] = ControllerUbicacionesPtr::create();
    }
    TableControlledWindow *wnd = new TableControlledWindow(this);
    _controllers["ubicaciones"]->addView(wnd);
    crearSubWindow(wnd, "Ubicaciones");
}

void MainWindow::on_actionProductos_triggered()
{
    if (!_controllers.contains("productos"))
    {
        _controllers["productos"] = ControllerProductosPtr::create();
    }
    TableControlledWindow *wnd = new TableControlledWindow(this);
    _controllers["productos"]->addView(wnd);
    crearSubWindow(wnd, "productos");
}

void MainWindow::on_actionMovimientos_de_Inventario_triggered()
{
    if (!_controllers.contains("movimientosStock"))
    {
        _controllers["movimientosStock"] = ControllerMovimientosStockPtr::create();
    }
    TableControlledWindow *wnd = new TableControlledWindow(this);
    _controllers["movimientosStock"]->addView(wnd);
    crearSubWindow(wnd, "movimientosStock");
}
