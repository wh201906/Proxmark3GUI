#include "mf_uid_parameterdialog.h"
#include "ui_mf_uid_parameterdialog.h"

MF_UID_parameterDialog::MF_UID_parameterDialog(const QString& uid, const QString& atqa, const QString& sak, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MF_UID_parameterDialog)
{
    ui->setupUi(this);
    ui->UIDLineEdit->setText(uid);
    ui->ATQALineEdit->setText(atqa);
    ui->SAKLineEdit->setText(sak);
}

MF_UID_parameterDialog::~MF_UID_parameterDialog()
{
    delete ui;
}

void MF_UID_parameterDialog::on_buttonBox_accepted()
{
    emit sendCMD("hf mf csetuid "
                 + ui->UIDLineEdit->text()
                 + " "
                 + ui->ATQALineEdit->text()
                 + " "
                 + ui->SAKLineEdit->text());
}
