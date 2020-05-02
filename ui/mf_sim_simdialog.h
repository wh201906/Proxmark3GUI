#ifndef MF_SIM_SIMDIALOG_H
#define MF_SIM_SIMDIALOG_H

#include <QDialog>
#include <QDebug>

namespace Ui
{
class MF_Sim_simDialog;
}

class MF_Sim_simDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MF_Sim_simDialog(int cardType, QWidget *parent = nullptr);
    ~MF_Sim_simDialog();

private slots:
    void on_eBox_clicked(bool checked);

    void on_fBox_clicked(bool checked);

private:
    Ui::MF_Sim_simDialog *ui;
    int cardType;
signals:
    void sendCMD(QString cmd);
private slots:
    void on_buttonBox_accepted();
};

#endif // MF_SIM_SIMDIALOG_H
