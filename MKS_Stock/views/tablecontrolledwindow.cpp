#include "tablecontrolledwindow.h"
#include "ui_tablecontrolledwindow.h"
#include <QTableWidgetItem>
#include "entities/usuario.h"
#include "controllers/controllerbase.h"


TableControlledWindow::TableControlledWindow(QWidget *parent) :
    ControlledView (parent),
    ui(new Ui::TableControlledWindow)
{
    ui->setupUi(this);
}

TableControlledWindow::~TableControlledWindow()
{
    delete ui;
}

void TableControlledWindow::llenarTabla(ResponsePtr response)
{
    ui->table->clear();
    ui->table->setRowCount(0);
    QList<EntidadBasePtr> list = response->list();

    QStringList headers = controller()->headers();
    ui->table->setColumnCount(headers.count());
/*    headers.append("#");
    headers.append("Nombre");
    headers.append("Apellido");*/

    ui->table->setHorizontalHeaderLabels(headers);
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


void TableControlledWindow::refresh()
{
    ResponsePtr usuarios = controller()->get();
    llenarTabla(usuarios);
}

void TableControlledWindow::on_actionNuevo_triggered()
{
    controller()->nuevaEntidad();
}
