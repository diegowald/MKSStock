#ifndef WINDOWUSUARIOS_H
#define WINDOWUSUARIOS_H

#include <QMainWindow>
#include "models/modelbase.h"


namespace Ui {
class WindowUsuarios;
}

class WindowUsuarios : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowUsuarios(QWidget *parent = 0);
    ~WindowUsuarios();

private slots:
    void on_actionNuevo_triggered();

    void on_tbl_doubleClicked(const QModelIndex &index);

private:
    void llenarTabla(ResponsePtr response);
    void refresh();

private:
    Ui::WindowUsuarios *ui;
};

#endif // WINDOWUSUARIOS_H
