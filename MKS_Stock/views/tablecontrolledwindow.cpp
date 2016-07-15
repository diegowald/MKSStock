#include "tablecontrolledwindow.h"
#include "ui_tablecontrolledwindow.h"
#include <QTableWidgetItem>
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


void TableControlledWindow::refresh()
{
    ResponsePtr entidades = controller()->get();
    llenarTabla(entidades);
}

void TableControlledWindow::on_actionNuevo_triggered()
{
    controller()->nuevaEntidad();
}

void TableControlledWindow::on_table_doubleClicked(const QModelIndex &index)
{
    QTableWidgetItem *item = ui->table->item(index.row(), index.column());
    EntidadBasePtr entidad = item->data(Qt::UserRole).value<EntidadBasePtr>();
    controller()->editarEntidad(entidad);
}
