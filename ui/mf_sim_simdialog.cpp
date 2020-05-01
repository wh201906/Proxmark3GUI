#include "mf_sim_simdialog.h"
#include "ui_mf_sim_simdialog.h"

MF_Sim_simDialog::MF_Sim_simDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MF_Sim_simDialog)
{
    ui->setupUi(this);
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
