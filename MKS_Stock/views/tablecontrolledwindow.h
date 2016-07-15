#ifndef TABLECONTROLLEDWINDOW_H
#define TABLECONTROLLEDWINDOW_H

#include <QMainWindow>
#include "views/controlledview.h"
#include "models/modelbase.h"


namespace Ui {
class TableControlledWindow;
}

class TableControlledWindow : public ControlledView
{
    Q_OBJECT

public:
    explicit TableControlledWindow(QWidget *parent = 0);
    ~TableControlledWindow();

    // ControlledView interface
public:
    virtual void refresh() override;
private slots:
    void on_actionNuevo_triggered();

    void on_table_doubleClicked(const QModelIndex &index);

private:
    void llenarTabla(ResponsePtr response);

private:
    Ui::TableControlledWindow *ui;

};

#endif // TABLECONTROLLEDWINDOW_H
