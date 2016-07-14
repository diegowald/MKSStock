/********************************************************************************
** Form generated from reading UI file 'tablecontrolledwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLECONTROLLEDWINDOW_H
#define UI_TABLECONTROLLEDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TableControlledWindow
{
public:
    QAction *actionNuevo;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTableWidget *table;
    QMenuBar *menubar;
    QMenu *menuAcciones;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TableControlledWindow)
    {
        if (TableControlledWindow->objectName().isEmpty())
            TableControlledWindow->setObjectName(QStringLiteral("TableControlledWindow"));
        TableControlledWindow->resize(800, 600);
        actionNuevo = new QAction(TableControlledWindow);
        actionNuevo->setObjectName(QStringLiteral("actionNuevo"));
        centralwidget = new QWidget(TableControlledWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        table = new QTableWidget(centralwidget);
        table->setObjectName(QStringLiteral("table"));
        table->setEditTriggers(QAbstractItemView::DoubleClicked);
        table->setAlternatingRowColors(true);
        table->setSelectionMode(QAbstractItemView::SingleSelection);
        table->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(table);

        TableControlledWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TableControlledWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuAcciones = new QMenu(menubar);
        menuAcciones->setObjectName(QStringLiteral("menuAcciones"));
        TableControlledWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(TableControlledWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TableControlledWindow->setStatusBar(statusbar);

        menubar->addAction(menuAcciones->menuAction());
        menuAcciones->addAction(actionNuevo);

        retranslateUi(TableControlledWindow);

        QMetaObject::connectSlotsByName(TableControlledWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TableControlledWindow)
    {
        TableControlledWindow->setWindowTitle(QApplication::translate("TableControlledWindow", "MainWindow", 0));
        actionNuevo->setText(QApplication::translate("TableControlledWindow", "Nuevo", 0));
        menuAcciones->setTitle(QApplication::translate("TableControlledWindow", "Acciones", 0));
    } // retranslateUi

};

namespace Ui {
    class TableControlledWindow: public Ui_TableControlledWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLECONTROLLEDWINDOW_H
