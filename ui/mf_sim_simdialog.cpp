#include "mf_sim_simdialog.h"
#include "ui_mf_sim_simdialog.h"

MF_Sim_simDialog::MF_Sim_simDialog(int cardType, QString cardTypeText, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MF_Sim_simDialog)
{
    ui->setupUi(this);
    if(Util::getClientType() == Util::CLIENTTYPE_OFFICIAL)
    {
        ui->atqaGroupBox->setVisible(false);
        ui->atqaLine->setVisible(false);
        ui->sakGroupBox->setVisible(false);
        ui->sakLine->setVisible(false);
        ui->vGroupBox->setVisible(false);
        ui->vLine->setVisible(false);
    }
    else if(Util::getClientType() == Util::CLIENTTYPE_ICEMAN)
    {
        ui->fGroupBox->setVisible(false);
        ui->fLine->setVisible(false);
        ui->rGroupBox->setVisible(false);
        ui->rLine->setVisible(false);
        ui->uBox->setText("-u");
        ui->nBox->setText("-n");
        ui->iBox->setText("-i");
        ui->xBox->setText("--crack");
        ui->eBox->setText("-e");
    }
    this->cardType = cardType;
    this->cardTypeText = cardTypeText;
}

MF_Sim_simDialog::~MF_Sim_simDialog()
{
    delete ui;
}

void MF_Sim_simDialog::on_eBox_clicked(bool checked)
{
    if(checked)
    {
        ui->iBox->setChecked(true);
        ui->xBox->setChecked(true);
    }
    if(!ui->eBox->isChecked() && !ui->fBox->isChecked())
    {
        ui->iBox->setEnabled(true);
        ui->xBox->setEnabled(true);
    }
    else
    {
        ui->iBox->setEnabled(false);
        ui->xBox->setEnabled(false);
    }
}

void MF_Sim_simDialog::on_fBox_clicked(bool checked)
{
    if(checked)
    {
        ui->iBox->setChecked(true);
        ui->xBox->setChecked(true);
    }
    if(!ui->eBox->isChecked() && !ui->fBox->isChecked())
    {
        ui->iBox->setEnabled(true);
        ui->xBox->setEnabled(true);
    }
    else
    {
        ui->iBox->setEnabled(false);
        ui->xBox->setEnabled(false);
    }
}

void MF_Sim_simDialog::on_buttonBox_accepted()
{
    QString paras;
    if(Util::getClientType() == Util::CLIENTTYPE_OFFICIAL)
    {
        paras += (ui->uBox->isChecked() ? "u " + ui->uEdit->text() + " " : "");
        paras += (ui->nBox->isChecked() ? "n " + ui->nEdit->text() + " " : "");
        paras += (ui->iBox->isChecked() ? "i " : "");
        paras += (ui->xBox->isChecked() ? "x " : "");
        paras += (ui->eBox->isChecked() ? "e " : "");
        paras += (ui->fBox->isChecked() ? "f " + ui->fEdit->text() + " " : "");
        paras += (ui->rBox->isChecked() ? "r " : "");
        emit sendCMD(QString("hf mf sim ") + "*" + QString::number(cardType) + " " + paras.trimmed());
    }
    else if(Util::getClientType() == Util::CLIENTTYPE_ICEMAN)
    {
        paras += (ui->uBox->isChecked() ? "-u " + ui->uEdit->text() + " " : "");
        paras += (ui->atqaBox->isChecked() ? "--atqa " + ui->atqaEdit->text() + " " : "");
        paras += (ui->sakBox->isChecked() ? "--sak " + ui->sakEdit->text() + " " : "");
        paras += (ui->nBox->isChecked() ? "-n " + ui->nEdit->text() + " " : "");
        paras += (ui->iBox->isChecked() ? "-i " : "");
        paras += (ui->xBox->isChecked() ? "--crack " : "");
        paras += (ui->eBox->isChecked() ? "-e " : "");
        paras += (ui->vBox->isChecked() ? "-v " : "");
        emit sendCMD(QString("hf mf sim --") + cardTypeText + " " + paras.trimmed());
    }
}
