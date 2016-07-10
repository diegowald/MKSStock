#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMdiSubWindow>
#include "models/modelcontainer.h"
#include "views/windowusuarios.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ModelContainer::initialize();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionStock_triggered()
{
}

void MainWindow::on_actionUsuarios_triggered()
{
    WindowUsuarios *wnd = new WindowUsuarios(this);

    QMdiSubWindow *subWindow = ui->mdiArea->addSubWindow(wnd);
    subWindow->setObjectName("Usuarios");
    wnd->setAttribute(Qt::WA_DeleteOnClose);
    subWindow->setWindowIcon(wnd->windowIcon());
    subWindow->show();
}
