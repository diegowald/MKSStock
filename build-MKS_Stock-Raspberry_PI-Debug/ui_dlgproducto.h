/********************************************************************************
** Form generated from reading UI file 'dlgproducto.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGPRODUCTO_H
#define UI_DLGPRODUCTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DlgProducto
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *txtNombre;
    QLabel *label_2;
    QLineEdit *txtDescripcion;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DlgProducto)
    {
        if (DlgProducto->objectName().isEmpty())
            DlgProducto->setObjectName(QStringLiteral("DlgProducto"));
        DlgProducto->resize(222, 98);
        verticalLayout = new QVBoxLayout(DlgProducto);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(DlgProducto);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        txtNombre = new QLineEdit(DlgProducto);
        txtNombre->setObjectName(QStringLiteral("txtNombre"));

        formLayout->setWidget(0, QFormLayout::FieldRole, txtNombre);

        label_2 = new QLabel(DlgProducto);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        txtDescripcion = new QLineEdit(DlgProducto);
        txtDescripcion->setObjectName(QStringLiteral("txtDescripcion"));

        formLayout->setWidget(1, QFormLayout::FieldRole, txtDescripcion);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(DlgProducto);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DlgProducto);
        QObject::connect(buttonBox, SIGNAL(accepted()), DlgProducto, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DlgProducto, SLOT(reject()));

        QMetaObject::connectSlotsByName(DlgProducto);
    } // setupUi

    void retranslateUi(QDialog *DlgProducto)
    {
        DlgProducto->setWindowTitle(QApplication::translate("DlgProducto", "Dialog", 0));
        label->setText(QApplication::translate("DlgProducto", "Nombre", 0));
        label_2->setText(QApplication::translate("DlgProducto", "Descripci\303\263n", 0));
    } // retranslateUi

};

namespace Ui {
    class DlgProducto: public Ui_DlgProducto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGPRODUCTO_H
