#include "windowusuarios.h"
#include "ui_windowusuarios.h"
#include "models/modelcontainer.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include "entities/usuario.h"
#include "views/dlgusuario.h"


WindowUsuarios::WindowUsuarios(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowUsuarios)
{
    ui->setupUi(this);
    refresh();
}



WindowUsuarios::~WindowUsuarios()
{
    delete ui;
}

void WindowUsuarios::refresh()
{
    ResponsePtr usuarios = ModelContainer::instance().model(MODELS::USUARIOS)->get();
    llenarTabla(usuarios);
}

void WindowUsuarios::llenarTabla(ResponsePtr response)
{
    ui->tbl->clear();
    ui->tbl->setRowCount(0);
    QList<EntidadBasePtr> list = response->list();

    ui->tbl->setColumnCount(3);
    QStringList headers;
    headers.append("#");
    headers.append("Nombre");
    headers.append("Apellido");

    ui->tbl->setHorizontalHeaderLabels(headers);
    foreach(auto entidad, list)
    {
        int row = ui->tbl->rowCount();
        ui->tbl->setRowCount(row + 1);
        UsuarioPtr u = qSharedPointerDynamicCast<Usuario>(entidad);
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(u->id()));
        ui->tbl->setItem(row, 0, item);
        item->setData(Qt::UserRole, QVariant::fromValue(u));
        item = new QTableWidgetItem(u->nombre());
        ui->tbl->setItem(row, 1, item);
        item = new QTableWidgetItem(u->apellido());
        ui->tbl->setItem(row, 2, item);
    }
}


void WindowUsuarios::on_actionNuevo_triggered()
{
    UsuarioPtr usuario = UsuarioPtr::create();
    DlgUsuario dlg(usuario, this);
    if (dlg.exec() == QDialog::Accepted)
    {
        ModelContainer::instance().model(MODELS::USUARIOS)->persist(usuario);
        refresh();
    }
}

void WindowUsuarios::on_tbl_doubleClicked(const QModelIndex &index)
{
    QTableWidgetItem *item = ui->tbl->item(index.row(), 0);
    UsuarioPtr u = item->data(Qt::UserRole).value<UsuarioPtr>();
    DlgUsuario dlg(u, this);
    if (dlg.exec() == QDialog::Accepted)
    {
        ModelContainer::instance().model(MODELS::USUARIOS)->persist(u);
        refresh();
    }
}
