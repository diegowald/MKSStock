#ifndef DLGUBICACION_H
#define DLGUBICACION_H

#include <QDialog>
#include "entities/ubicacion.h"
namespace Ui {
class DlgUbicacion;
}

class DlgUbicacion : public QDialog
{
    Q_OBJECT

public:
    explicit DlgUbicacion(UbicacionPtr ubicacion, QWidget *parent = 0);
    ~DlgUbicacion();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DlgUbicacion *ui;

    UbicacionPtr _ubicacion;
};

#endif // DLGUBICACION_H
