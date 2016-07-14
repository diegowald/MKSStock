/********************************************************************************
** Form generated from reading UI file 'dialogmovimientostock.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGMOVIMIENTOSTOCK_H
#define UI_DIALOGMOVIMIENTOSTOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogMovimientoStock
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *cboProducto;
    QLabel *label_2;
    QComboBox *cboUbicacion;
    QLabel *label_3;
    QLineEdit *txtExistencia;
    QLabel *label_4;
    QComboBox *cboNuevaUbicacion;
    QLabel *label_5;
    QSpinBox *spinCantidad;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogMovimientoStock)
    {
        if (DialogMovimientoStock->objectName().isEmpty())
            DialogMovimientoStock->setObjectName(QStringLiteral("DialogMovimientoStock"));
        DialogMovimientoStock->resize(259, 183);
        verticalLayout = new QVBoxLayout(DialogMovimientoStock);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(DialogMovimientoStock);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        cboProducto = new QComboBox(DialogMovimientoStock);
        cboProducto->setObjectName(QStringLiteral("cboProducto"));

        formLayout->setWidget(0, QFormLayout::FieldRole, cboProducto);

        label_2 = new QLabel(DialogMovimientoStock);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        cboUbicacion = new QComboBox(DialogMovimientoStock);
        cboUbicacion->setObjectName(QStringLiteral("cboUbicacion"));

        formLayout->setWidget(1, QFormLayout::FieldRole, cboUbicacion);

        label_3 = new QLabel(DialogMovimientoStock);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        txtExistencia = new QLineEdit(DialogMovimientoStock);
        txtExistencia->setObjectName(QStringLiteral("txtExistencia"));

        formLayout->setWidget(2, QFormLayout::FieldRole, txtExistencia);

        label_4 = new QLabel(DialogMovimientoStock);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        cboNuevaUbicacion = new QComboBox(DialogMovimientoStock);
        cboNuevaUbicacion->setObjectName(QStringLiteral("cboNuevaUbicacion"));

        formLayout->setWidget(3, QFormLayout::FieldRole, cboNuevaUbicacion);

        label_5 = new QLabel(DialogMovimientoStock);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        spinCantidad = new QSpinBox(DialogMovimientoStock);
        spinCantidad->setObjectName(QStringLiteral("spinCantidad"));

        formLayout->setWidget(4, QFormLayout::FieldRole, spinCantidad);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(DialogMovimientoStock);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DialogMovimientoStock);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogMovimientoStock, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogMovimientoStock, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogMovimientoStock);
    } // setupUi

    void retranslateUi(QDialog *DialogMovimientoStock)
    {
        DialogMovimientoStock->setWindowTitle(QApplication::translate("DialogMovimientoStock", "Dialog", 0));
        label->setText(QApplication::translate("DialogMovimientoStock", "Producto", 0));
        label_2->setText(QApplication::translate("DialogMovimientoStock", "Ubicacion", 0));
        label_3->setText(QApplication::translate("DialogMovimientoStock", "Existencia", 0));
        label_4->setText(QApplication::translate("DialogMovimientoStock", "Nueva Ubicaci\303\263n", 0));
        label_5->setText(QApplication::translate("DialogMovimientoStock", "Cantidad a mover", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogMovimientoStock: public Ui_DialogMovimientoStock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGMOVIMIENTOSTOCK_H
