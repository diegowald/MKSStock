/********************************************************************************
** Form generated from reading UI file 'dlgubicacion.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGUBICACION_H
#define UI_DLGUBICACION_H

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

class Ui_DlgUbicacion
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *txtNombre;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DlgUbicacion)
    {
        if (DlgUbicacion->objectName().isEmpty())
            DlgUbicacion->setObjectName(QStringLiteral("DlgUbicacion"));
        DlgUbicacion->resize(199, 70);
        verticalLayout = new QVBoxLayout(DlgUbicacion);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(DlgUbicacion);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        txtNombre = new QLineEdit(DlgUbicacion);
        txtNombre->setObjectName(QStringLiteral("txtNombre"));

        formLayout->setWidget(0, QFormLayout::FieldRole, txtNombre);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(DlgUbicacion);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DlgUbicacion);
        QObject::connect(buttonBox, SIGNAL(accepted()), DlgUbicacion, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DlgUbicacion, SLOT(reject()));

        QMetaObject::connectSlotsByName(DlgUbicacion);
    } // setupUi

    void retranslateUi(QDialog *DlgUbicacion)
    {
        DlgUbicacion->setWindowTitle(QApplication::translate("DlgUbicacion", "Dialog", 0));
        label->setText(QApplication::translate("DlgUbicacion", "Nombre", 0));
    } // retranslateUi

};

namespace Ui {
    class DlgUbicacion: public Ui_DlgUbicacion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGUBICACION_H
