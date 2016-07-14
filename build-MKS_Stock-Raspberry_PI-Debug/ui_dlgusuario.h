/********************************************************************************
** Form generated from reading UI file 'dlgusuario.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGUSUARIO_H
#define UI_DLGUSUARIO_H

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

class Ui_DlgUsuario
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *Apellido;
    QLineEdit *txtApellido;
    QLabel *label_2;
    QLineEdit *txtNombre;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DlgUsuario)
    {
        if (DlgUsuario->objectName().isEmpty())
            DlgUsuario->setObjectName(QStringLiteral("DlgUsuario"));
        DlgUsuario->resize(210, 98);
        verticalLayout = new QVBoxLayout(DlgUsuario);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        Apellido = new QLabel(DlgUsuario);
        Apellido->setObjectName(QStringLiteral("Apellido"));

        formLayout->setWidget(0, QFormLayout::LabelRole, Apellido);

        txtApellido = new QLineEdit(DlgUsuario);
        txtApellido->setObjectName(QStringLiteral("txtApellido"));

        formLayout->setWidget(0, QFormLayout::FieldRole, txtApellido);

        label_2 = new QLabel(DlgUsuario);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        txtNombre = new QLineEdit(DlgUsuario);
        txtNombre->setObjectName(QStringLiteral("txtNombre"));

        formLayout->setWidget(1, QFormLayout::FieldRole, txtNombre);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(DlgUsuario);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DlgUsuario);
        QObject::connect(buttonBox, SIGNAL(accepted()), DlgUsuario, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DlgUsuario, SLOT(reject()));

        QMetaObject::connectSlotsByName(DlgUsuario);
    } // setupUi

    void retranslateUi(QDialog *DlgUsuario)
    {
        DlgUsuario->setWindowTitle(QApplication::translate("DlgUsuario", "Dialog", 0));
        Apellido->setText(QApplication::translate("DlgUsuario", "Apellido", 0));
        label_2->setText(QApplication::translate("DlgUsuario", "Nombre", 0));
    } // retranslateUi

};

namespace Ui {
    class DlgUsuario: public Ui_DlgUsuario {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGUSUARIO_H
