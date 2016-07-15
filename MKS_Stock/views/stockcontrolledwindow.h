#ifndef STOCKCONTROLLEDWINDOW_H
#define STOCKCONTROLLEDWINDOW_H

#include <QMainWindow>
#include "views/controlledview.h"
#include "models/modelbase.h"

namespace Ui {
class StockControlledWindow;
}

class StockControlledWindow : public ControlledView
{
    Q_OBJECT

public:
    explicit StockControlledWindow(QWidget *parent = 0);
    ~StockControlledWindow();

    // ControlledView interface
public:
    virtual void refresh() override;

private:
    void llenarTabla(ResponsePtr response);
    void llenarComboUbicaciones();
    void llenarComboProductos();

private slots:
    void on_cboUbicaciones_currentIndexChanged(int index);

    void on_cboProductos_currentIndexChanged(int index);

private:
    Ui::StockControlledWindow *ui;
    bool _firstRefresh;
};

#endif // STOCKCONTROLLEDWINDOW_H
