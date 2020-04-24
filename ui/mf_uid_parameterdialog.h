#ifndef MF_UID_PARAMETERDIALOG_H
#define MF_UID_PARAMETERDIALOG_H

#include <QDialog>

namespace Ui {
class MF_UID_parameterDialog;
}

class MF_UID_parameterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MF_UID_parameterDialog(QWidget *parent = nullptr);
    ~MF_UID_parameterDialog();

private:
    Ui::MF_UID_parameterDialog *ui;
};

#endif // MF_UID_PARAMETERDIALOG_H
