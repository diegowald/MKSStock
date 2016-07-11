#ifndef DLGPRODUCTO_H
#define DLGPRODUCTO_H

#include <QDialog>
#include "entities/producto.h"

namespace Ui {
class DlgProducto;
}

class DlgProducto : public QDialog
{
    Q_OBJECT

public:
    explicit DlgProducto(ProductoPtr producto, QWidget *parent = 0);
    ~DlgProducto();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DlgProducto *ui;
    ProductoPtr _producto;
};

#endif // DLGPRODUCTO_H
