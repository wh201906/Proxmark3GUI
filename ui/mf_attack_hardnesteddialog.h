#ifndef MF_ATTACK_HARDNESTEDDIALOG_H
#define MF_ATTACK_HARDNESTEDDIALOG_H

#include <QDialog>

namespace Ui
{
class MF_Attack_hardnestedDialog;
}

class MF_Attack_hardnestedDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MF_Attack_hardnestedDialog(int blocks, QWidget *parent = nullptr);
    ~MF_Attack_hardnestedDialog();


private:
    Ui::MF_Attack_hardnestedDialog *ui;
signals:
    void sendCMD(const QString& cmd);
private slots:
    void on_buttonBox_accepted();
};

#endif // MF_ATTACK_HARDNESTEDDIALOG_H
