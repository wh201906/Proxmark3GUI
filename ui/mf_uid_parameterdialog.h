#ifndef MF_UID_PARAMETERDIALOG_H
#define MF_UID_PARAMETERDIALOG_H

#include <QDialog>

namespace Ui
{
class MF_UID_parameterDialog;
}

class MF_UID_parameterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MF_UID_parameterDialog(const QString& uid, const QString& atqa, const QString& sak, QWidget *parent = nullptr);
    ~MF_UID_parameterDialog();

private:
    Ui::MF_UID_parameterDialog *ui;
signals:
    void sendCMD(const QString& cmd);
private slots:
    void on_buttonBox_accepted();
};

#endif // MF_UID_PARAMETERDIALOG_H
