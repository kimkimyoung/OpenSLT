#include "labeldialog.h"
#include "ui_labeldialog.h"
#include <QMessageBox>
#include <QListWidget>
#include <QLabel>
#include <QDialog>

LabelDialog::LabelDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LabelDialog)
{
    ui->setupUi(this);
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(labelAccept()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(labelReject()));
    connect(ui->listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(doubleClickLabel(QListWidgetItem*)));
    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(sigleClickLabel(QListWidgetItem*)));
}

LabelDialog::~LabelDialog()
{
    delete ui;
}

void LabelDialog::dialogShow()
{
    this->show();
}

void LabelDialog::getLabel(QString label)
{
    ui->lineEdit->setText("");
    emit dialoglabelAdded(label);
}

void LabelDialog::getLabelFromManager(QString label)
{
    ui->listWidget->addItem(label);
}

void LabelDialog::deleteLabelFromManager(QString label)
{
    QListWidgetItem* item = ui->listWidget->findItems(label, Qt::MatchExactly)[0];
    ui->listWidget->removeItemWidget(item);
    delete item;
}

void LabelDialog::clearLabelFromManager()
{
    ui->listWidget->clear();
}

void LabelDialog::doubleClickLabel(QListWidgetItem *item)
{
    label_to_Annotation = item->text();
    getLabel(label_to_Annotation);
    this->close();
}

void LabelDialog::sigleClickLabel(QListWidgetItem *item)
{
    ui->lineEdit->setText(item->text());
}

void LabelDialog::labelAccept()
{
    label_to_Annotation = ui->lineEdit->text();

    if (label_to_Annotation == "")
    {
        QMessageBox::about(NULL, "ERROR", "Please select a label name");
        emit dialoglabelCanceled();
        this->close();
        return;
    }
    if (ui->listWidget->findItems(label_to_Annotation, Qt::MatchExactly).empty())
    {
        ui->listWidget->addItem(label_to_Annotation);
    }
    getLabel(label_to_Annotation);

    this->close();
}

void LabelDialog::labelReject()
{
    ui->lineEdit->setText("");
    emit dialoglabelCanceled();
    this->close();
}
