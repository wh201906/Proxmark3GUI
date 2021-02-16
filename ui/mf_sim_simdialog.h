#ifndef MF_SIM_SIMDIALOG_H
#define MF_SIM_SIMDIALOG_H

#include <QDialog>
#include <QDebug>
#include "common/util.h"

namespace Ui
{
class MF_Sim_simDialog;
}

class MF_Sim_simDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MF_Sim_simDialog(int cardType, QString cardTypeText, QWidget *parent = nullptr);
    ~MF_Sim_simDialog();

private slots:
    void on_eBox_clicked(bool checked);

    void on_fBox_clicked(bool checked);

private:
    Ui::MF_Sim_simDialog *ui;
    int cardType;
    QString cardTypeText;
signals:
    void sendCMD(const QString& cmd);
private slots:
    void on_buttonBox_accepted();
};

#endif // MF_SIM_SIMDIALOG_H
