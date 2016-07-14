/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionUsuarios;
    QAction *actionUbicaciones;
    QAction *actionProductos;
    QAction *actionStock;
    QAction *actionMovimientos_de_Inventario;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QMdiArea *mdiArea;
    QMenuBar *menuBar;
    QMenu *menuInventario;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 480);
        actionUsuarios = new QAction(MainWindow);
        actionUsuarios->setObjectName(QStringLiteral("actionUsuarios"));
        actionUbicaciones = new QAction(MainWindow);
        actionUbicaciones->setObjectName(QStringLiteral("actionUbicaciones"));
        actionProductos = new QAction(MainWindow);
        actionProductos->setObjectName(QStringLiteral("actionProductos"));
        actionStock = new QAction(MainWindow);
        actionStock->setObjectName(QStringLiteral("actionStock"));
        actionMovimientos_de_Inventario = new QAction(MainWindow);
        actionMovimientos_de_Inventario->setObjectName(QStringLiteral("actionMovimientos_de_Inventario"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QStringLiteral("mdiArea"));

        horizontalLayout->addWidget(mdiArea);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 19));
        menuInventario = new QMenu(menuBar);
        menuInventario->setObjectName(QStringLiteral("menuInventario"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuInventario->menuAction());
        menuInventario->addAction(actionUsuarios);
        menuInventario->addAction(actionUbicaciones);
        menuInventario->addAction(actionProductos);
        menuInventario->addAction(actionMovimientos_de_Inventario);
        menuInventario->addAction(actionStock);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionUsuarios->setText(QApplication::translate("MainWindow", "Usuarios", 0));
        actionUbicaciones->setText(QApplication::translate("MainWindow", "Ubicaciones", 0));
        actionProductos->setText(QApplication::translate("MainWindow", "Productos", 0));
        actionStock->setText(QApplication::translate("MainWindow", "Stock", 0));
        actionMovimientos_de_Inventario->setText(QApplication::translate("MainWindow", "Movimientos de Inventario", 0));
        menuInventario->setTitle(QApplication::translate("MainWindow", "Inventario", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
