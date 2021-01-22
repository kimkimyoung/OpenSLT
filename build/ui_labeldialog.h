/********************************************************************************
** Form generated from reading UI file 'labeldialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LABELDIALOG_H
#define UI_LABELDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LabelDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QListWidget *listWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *LabelDialog)
    {
        if (LabelDialog->objectName().isEmpty())
            LabelDialog->setObjectName(QStringLiteral("LabelDialog"));
        LabelDialog->resize(421, 290);
        verticalLayout = new QVBoxLayout(LabelDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(LabelDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(LabelDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        listWidget = new QListWidget(LabelDialog);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);

        buttonBox = new QDialogButtonBox(LabelDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(LabelDialog);

        QMetaObject::connectSlotsByName(LabelDialog);
    } // setupUi

    void retranslateUi(QDialog *LabelDialog)
    {
        LabelDialog->setWindowTitle(QApplication::translate("LabelDialog", "Select a label", Q_NULLPTR));
        label->setText(QApplication::translate("LabelDialog", "Label:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LabelDialog: public Ui_LabelDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LABELDIALOG_H
