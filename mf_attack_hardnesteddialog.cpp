#include "mf_attack_hardnesteddialog.h"
#include "ui_mf_attack_hardnesteddialog.h"

MF_Attack_hardnestedDialog::MF_Attack_hardnestedDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MF_Attack_hardnestedDialog)
{
    ui->setupUi(this);
    for(int i=0;i<64;i++)
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
    emit sendCMD("hf mf hardnested "
                 +ui->knownKeySectorBox->currentText()
                 +" "
                 +ui->knownKeyTypeBox->currentText()
                 +" "
                 +ui->knownKeyBox->text()
                 +" "
                 +ui->targetKeySectorBox->currentText()
                 +" "
                 +ui->targetKeyTypeBox->currentText());
}
