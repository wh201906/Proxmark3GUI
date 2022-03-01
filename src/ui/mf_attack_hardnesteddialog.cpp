#include "mf_attack_hardnesteddialog.h"
#include "ui_mf_attack_hardnesteddialog.h"

MF_Attack_hardnestedDialog::MF_Attack_hardnestedDialog(int blocks, const QVariantMap& config, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MF_Attack_hardnestedDialog)
{
    ui->setupUi(this);
    for(int i = 0; i < blocks; i++)
    {
        ui->knownKeyBlockBox->addItem(QString::number(i));
        ui->targetKeyBlockBox->addItem(QString::number(i));
    }
    this->config = config;

}

MF_Attack_hardnestedDialog::~MF_Attack_hardnestedDialog()
{
    delete ui;
}

void MF_Attack_hardnestedDialog::on_buttonBox_accepted()
{
    QString cmd = config["cmd"].toString();
    cmd.replace("<known key block>", ui->knownKeyBlockBox->currentText());
    cmd.replace("<known key type>", config["known key type"].toMap()[ui->knownKeyTypeBox->currentText()].toString());
    cmd.replace("<known key>", ui->knownKeyBox->text());
    cmd.replace("<target key block>", ui->targetKeyBlockBox->currentText());
    cmd.replace("<target key type>", config["target key type"].toMap()[ui->targetKeyTypeBox->currentText()].toString());
    emit sendCMD(cmd);
}
