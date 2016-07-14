/********************************************************************************
** Form generated from reading UI file 'windowusuarios.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWUSUARIOS_H
#define UI_WINDOWUSUARIOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowUsuarios
{
public:
    QAction *actionNuevo;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tbl;
    QMenuBar *menubar;
    QMenu *menuAcciones;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WindowUsuarios)
    {
        if (WindowUsuarios->objectName().isEmpty())
            WindowUsuarios->setObjectName(QStringLiteral("WindowUsuarios"));
        WindowUsuarios->resize(800, 600);
        actionNuevo = new QAction(WindowUsuarios);
        actionNuevo->setObjectName(QStringLiteral("actionNuevo"));
        centralwidget = new QWidget(WindowUsuarios);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        tbl = new QTableWidget(centralwidget);
        tbl->setObjectName(QStringLiteral("tbl"));
        tbl->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tbl->setEditTriggers(QAbstractItemView::DoubleClicked);
        tbl->setAlternatingRowColors(true);
        tbl->setSelectionMode(QAbstractItemView::SingleSelection);
        tbl->setSelectionBehavior(QAbstractItemView::SelectRows);
        tbl->setGridStyle(Qt::SolidLine);

        horizontalLayout->addWidget(tbl);

        WindowUsuarios->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WindowUsuarios);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 19));
        menuAcciones = new QMenu(menubar);
        menuAcciones->setObjectName(QStringLiteral("menuAcciones"));
        WindowUsuarios->setMenuBar(menubar);
        statusbar = new QStatusBar(WindowUsuarios);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        WindowUsuarios->setStatusBar(statusbar);

        menubar->addAction(menuAcciones->menuAction());
        menuAcciones->addAction(actionNuevo);

        retranslateUi(WindowUsuarios);

        QMetaObject::connectSlotsByName(WindowUsuarios);
    } // setupUi

    void retranslateUi(QMainWindow *WindowUsuarios)
    {
        WindowUsuarios->setWindowTitle(QApplication::translate("WindowUsuarios", "Usuarios", 0));
        actionNuevo->setText(QApplication::translate("WindowUsuarios", "Nuevo", 0));
        menuAcciones->setTitle(QApplication::translate("WindowUsuarios", "Acciones", 0));
    } // retranslateUi

};

namespace Ui {
    class WindowUsuarios: public Ui_WindowUsuarios {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWUSUARIOS_H
