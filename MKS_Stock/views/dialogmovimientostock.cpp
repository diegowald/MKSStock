#include "dialogmovimientostock.h"
#include "ui_dialogmovimientostock.h"
#include "models/modelbase.h"
#include "models/modelcontainer.h"
#include "models/modelmovimientosstock.h"
#include "entities/producto.h"
#include "entities/ubicacion.h"

DialogMovimientoStock::DialogMovimientoStock(MovimientoStockPtr movimientoStock, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogMovimientoStock)
{
    ui->setupUi(this);

    _movimientoStock = movimientoStock;

    llenarComboProductos();
    ui->cboProducto->setCurrentIndex(ui->cboProducto->findData(_movimientoStock->idProducto(), Qt::UserRole));
    ui->cboUbicacion->setCurrentIndex(ui->cboUbicacion->findData(_movimientoStock->idUbicacion(), Qt::UserRole));
    ui->txtExistencia->setText(QString::number(_movimientoStockAnterior->cantidad()));
    ui->spinCantidad->setMinimum(1);
    ui->spinCantidad->setMaximum(_movimientoStockAnterior->cantidad());
    ui->spinCantidad->setValue(_movimientoStockAnterior->cantidad());
}

DialogMovimientoStock::~DialogMovimientoStock()
{
    delete ui;
}

void DialogMovimientoStock::on_buttonBox_accepted()
{
    _movimientoStock->setIdProducto(ui->cboProducto->currentData(Qt::UserRole).toInt());
    _movimientoStock->setIdUbicacion(ui->cboNuevaUbicacion->currentData(Qt::UserRole).toInt());
    _movimientoStock->setMovimientoAnterior(_movimientoStockAnterior);
    _movimientoStock->setCantidad(ui->spinCantidad->value());
    close();
}

void DialogMovimientoStock::on_cboProducto_currentIndexChanged(int index)
{
    llenarComboUbicacionesExistente();
}

void DialogMovimientoStock::llenarComboProductos()
{
    ui->cboProducto->clear();
    ResponsePtr productos = ModelContainer::instance().model(MODELS::PRODUCTOS)->get();
    foreach (EntidadBasePtr p, productos->list())
    {
        ProductoPtr prod = qSharedPointerDynamicCast<Producto>(p);
        ui->cboProducto->addItem(prod->nombre(), prod->id());
    }
}

void DialogMovimientoStock::llenarComboUbicacionesExistente()
{
    int idProducto = ui->cboProducto->currentData(Qt::UserRole).toInt();
    ModelMovimientosStockPtr m = qSharedPointerDynamicCast<ModelMovimientosStock>(
                ModelContainer::instance().model(MODELS::MOVIMIENTOS_STOCK));
    ResponsePtr existencia = m->getPorProducto(idProducto);
}

void DialogMovimientoStock::llenarComboUbicaciones()
{
    ui->cboNuevaUbicacion->clear();
    ResponsePtr ubicaciones = ModelContainer::instance().model(MODELS::UBICACIONES)->get();
    foreach (EntidadBasePtr u, ubicaciones->list())
    {
        UbicacionPtr ub = qSharedPointerDynamicCast<Ubicacion>(u);
        ui->cboNuevaUbicacion->addItem(ub->nombre(), ub->id());
    }
}
