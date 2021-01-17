#ifndef LABELDIALOG_H
#define LABELDIALOG_H

#include <QDialog>
#include <QListWidgetItem>
namespace Ui {
class LabelDialog;
}

class LabelDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LabelDialog(QWidget *parent = 0);
    ~LabelDialog();
signals:
    void dialoglabelAdded(QString label);
    void dialoglabelCanceled();
private slots:
    void dialogShow();
    void getLabel(QString label);
    void getLabelFromManager(QString label);
    void deleteLabelFromManager(QString label);
    void clearLabelFromManager();
    void labelAccept();
    void labelReject();
    void doubleClickLabel(QListWidgetItem *item);
    void sigleClickLabel(QListWidgetItem *item);
private:
    Ui::LabelDialog *ui;
    QString label_to_Annotation;
};

#endif // LABELDIALOG_H
