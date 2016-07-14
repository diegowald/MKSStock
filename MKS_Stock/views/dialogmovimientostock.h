#ifndef DIALOGMOVIMIENTOSTOCK_H
#define DIALOGMOVIMIENTOSTOCK_H

#include <QDialog>
#include "entities/movimientostock.h"
#include <QMap>


namespace Ui {
class DialogMovimientoStock;
}


class DialogMovimientoStock : public QDialog
{
    Q_OBJECT

public:
    explicit DialogMovimientoStock(MovimientoStockPtr movimientoStock, QWidget *parent = 0);
    ~DialogMovimientoStock();

private:
    void llenarComboProductos();
    void llenarComboUbicacionesExistente();
    void llenarComboUbicaciones();

private slots:
    void on_buttonBox_accepted();

    void on_cboProducto_currentIndexChanged(int index);

    void on_cboUbicacion_currentIndexChanged(int index);

private:
    Ui::DialogMovimientoStock *ui;
    MovimientoStockPtr _movimientoStock;
    MovimientoStockPtr _movimientoStockAnterior;
    QMap<int, MovimientoStockPtr> _movimientosAnterioresPorUbicacion;
};

#endif // DIALOGMOVIMIENTOSTOCK_H
