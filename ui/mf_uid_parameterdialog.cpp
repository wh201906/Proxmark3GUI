#include "mf_uid_parameterdialog.h"
#include "ui_mf_uid_parameterdialog.h"

MF_UID_parameterDialog::MF_UID_parameterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MF_UID_parameterDialog)
{
    ui->setupUi(this);
}

MF_UID_parameterDialog::~MF_UID_parameterDialog()
{
    delete ui;
}
