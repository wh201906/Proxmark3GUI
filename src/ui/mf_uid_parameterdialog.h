#ifndef MF_UID_PARAMETERDIALOG_H
#define MF_UID_PARAMETERDIALOG_H

#include <QDialog>
#include "common/util.h"

namespace Ui
{
class MF_UID_parameterDialog;
}

class MF_UID_parameterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MF_UID_parameterDialog(const QString& uid, const QString& atqa, const QString& sak, const QVariantMap& config, QWidget *parent = nullptr);
    ~MF_UID_parameterDialog();

private:
    Ui::MF_UID_parameterDialog *ui;
    QVariantMap config;
signals:
    void sendCMD(const QString& cmd);
private slots:
    void on_buttonBox_accepted();
};

#endif // MF_UID_PARAMETERDIALOG_H
