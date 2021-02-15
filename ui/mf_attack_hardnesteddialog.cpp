#include "mf_attack_hardnesteddialog.h"
#include "ui_mf_attack_hardnesteddialog.h"

MF_Attack_hardnestedDialog::MF_Attack_hardnestedDialog(int blocks, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MF_Attack_hardnestedDialog)
{
    ui->setupUi(this);
    for(int i = 0; i < blocks; i++)
    {
        ui->knownKeySectorBox->addItem(QString::number(i));
        ui->targetKeySectorBox->addItem(QString::number(i));
    }

}

MF_Attack_hardnestedDialog::~MF_Attack_hardnestedDialog()
{
    delete ui;
}

void MF_Attack_hardnestedDialog::on_buttonBox_accepted()
{
    if(Util::getClientType() == Util::CLIENTTYPE_OFFICIAL)
        emit sendCMD("hf mf hardnested "
                     + ui->knownKeySectorBox->currentText()
                     + " "
                     + ui->knownKeyTypeBox->currentText()
                     + " "
                     + ui->knownKeyBox->text()
                     + " "
                     + ui->targetKeySectorBox->currentText()
                     + " "
                     + ui->targetKeyTypeBox->currentText());
    else if(Util::getClientType() == Util::CLIENTTYPE_ICEMAN) // same format in v4.9237
        emit sendCMD("hf mf hardnested "
                     + ui->knownKeySectorBox->currentText()
                     + " "
                     + ui->knownKeyTypeBox->currentText()
                     + " "
                     + ui->knownKeyBox->text()
                     + " "
                     + ui->targetKeySectorBox->currentText()
                     + " "
                     + ui->targetKeyTypeBox->currentText());
}
