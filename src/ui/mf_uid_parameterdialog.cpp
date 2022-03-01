#include "mf_uid_parameterdialog.h"
#include "ui_mf_uid_parameterdialog.h"

MF_UID_parameterDialog::MF_UID_parameterDialog(const QString& uid, const QString& atqa, const QString& sak, const QVariantMap& config, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MF_UID_parameterDialog)
{
    ui->setupUi(this);
    ui->UIDLineEdit->setText(uid);
    ui->ATQALineEdit->setText(atqa);
    ui->SAKLineEdit->setText(sak);
    this->config = config;
}

MF_UID_parameterDialog::~MF_UID_parameterDialog()
{
    delete ui;
}

void MF_UID_parameterDialog::on_buttonBox_accepted()
{
    QString cmd = config["cmd"].toString();
    cmd.replace("<uid>", ui->UIDLineEdit->text());
    cmd.replace("<atqa>", ui->ATQALineEdit->text());
    cmd.replace("<sak>", ui->SAKLineEdit->text());
    emit sendCMD(cmd);
}
