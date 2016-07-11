#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include "controllers/controllerbase.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void crearSubWindow(QWidget *wnd, const QString &windowName);

private slots:
    void on_actionStock_triggered();

    void on_actionUsuarios_triggered();

    void on_actionUbicaciones_triggered();

    void on_actionProductos_triggered();

    void on_actionMovimientos_de_Inventario_triggered();

private:
    Ui::MainWindow *ui;
    QMap<QString, ControllerBasePtr> _controllers;
};

#endif // MAINWINDOW_H
