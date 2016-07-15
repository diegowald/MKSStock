#include "stockcontrolledwindow.h"
#include "ui_stockcontrolledwindow.h"
#include <QTableWidgetItem>
#include "controllers/controllerbase.h"
#include "controllers/controllermovimientosstock.h"
#include "models/modelcontainer.h"
#include "entities/ubicacion.h"
#include "entities/producto.h"


StockControlledWindow::StockControlledWindow(QWidget *parent) :
    ControlledView (parent),
    ui(new Ui::StockControlledWindow)
{
    ui->setupUi(this);
    _firstRefresh = true;
}

StockControlledWindow::~StockControlledWindow()
{
    delete ui;
}

void StockControlledWindow::refresh()
{
    if (_firstRefresh)
    {
        _firstRefresh = false;
        llenarComboUbicaciones();
        llenarComboProductos();
    }

    int idUbicacion = ui->cboUbicaciones->currentData(Qt::UserRole).toInt();
    int idProducto = ui->cboProductos->currentData(Qt::UserRole).toInt();

    ControllerMovimientosStock* c = dynamic_cast<ControllerMovimientosStock*>(controller());


    ResponsePtr existencia;

    if ((idUbicacion == -1) && (idProducto == -1))
    {
        existencia =  c->existencia();
    }
    else if ((idUbicacion == -1) && (idProducto != -1))
    {
        existencia = c->existenciaProducto(idProducto);
    }
    else if ((idUbicacion != -1) && (idProducto == -1))
    {
        existencia = c->existenciaUbicacion(idUbicacion);
    }
    else
    {
        existencia = c->existenciaProductoUbicacion(idProducto, idUbicacion);
    }
    llenarTabla(existencia);
}

void StockControlledWindow::llenarTabla(ResponsePtr response)
{
    ui->table->clear();
    ui->table->setRowCount(0);
    QList<EntidadBasePtr> list = response->list();

    QStringList headers = controller()->headers();
    ui->table->setColumnCount(headers.count());

    QStringList displayHeaders;
    foreach(QString header, headers)
    {
        displayHeaders.append(controller()->displayHeader(header));
    }

    ui->table->setHorizontalHeaderLabels(displayHeaders);
    foreach(auto entidad, list)
    {
        int row = ui->table->rowCount();
        ui->table->setRowCount(row + 1);
        int col = 0;
        foreach(QString f, headers)
        {
            QTableWidgetItem *item = new QTableWidgetItem(controller()->value(entidad, f).toString());
            ui->table->setItem(row, col, item);
            item->setData(Qt::UserRole, QVariant::fromValue(entidad));
            ++col;
        }
    }
}

void StockControlledWindow::on_cboUbicaciones_currentIndexChanged(int index)
{
    refresh();
}

void StockControlledWindow::on_cboProductos_currentIndexChanged(int index)
{
    refresh();
}


void StockControlledWindow::llenarComboUbicaciones()
{
    ResponsePtr response = ModelContainer::instance().model(MODELS::UBICACIONES)->get();
    ui->cboUbicaciones->clear();
    ui->cboUbicaciones->addItem("<Todo>", -1);

    foreach (EntidadBasePtr entidad, response->list())
    {
        UbicacionPtr ubicacion = qSharedPointerDynamicCast<Ubicacion>(entidad);
        ui->cboUbicaciones->addItem(ubicacion->nombre(), ubicacion->id());
    }
}

void StockControlledWindow::llenarComboProductos()
{
    ResponsePtr response = ModelContainer::instance().model(MODELS::PRODUCTOS)->get();
    ui->cboProductos->clear();
    ui->cboProductos->addItem("<Todo>", -1);

    foreach (EntidadBasePtr entidad, response->list())
    {
        ProductoPtr producto = qSharedPointerDynamicCast<Producto>(entidad);
        ui->cboProductos->addItem(producto->nombre(), producto->id());
    }
}
