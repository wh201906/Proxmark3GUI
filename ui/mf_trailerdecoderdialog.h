#ifndef MF_TRAILERDECODERDIALOG_H
#define MF_TRAILERDECODERDIALOG_H

#include <QDialog>
#include <QValidator>
#include <QDebug>
#include <QButtonGroup>
#include <QTableWidget>

namespace Ui
{
class MF_trailerDecoderDialog;
}

class MF_trailerDecoderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MF_trailerDecoderDialog(QWidget *parent = nullptr);
    ~MF_trailerDecoderDialog();
    enum AccessType
    {
        ACC_NEVER = 0,
        ACC_KEY_A = 1,
        ACC_KEY_B = 2,
        ACC_KEY_AB = 3,
    };

private slots:

    void on_accessBitsEdit_textEdited(const QString &arg1);

    void on_blockSizeChanged(int id, bool st);
private:
    Ui::MF_trailerDecoderDialog *ui;
    QRegularExpressionValidator* validator;
    QButtonGroup* sizeGroup;
    void setTableItem(QTableWidget *widget, int row, int column, AccessType accessType);

    // If I don't make them static, the app will crash(these arrays might take too much space)
    static AccessType dataCondition[8][4];
    static AccessType trailerReadCondition[8][3];
    static AccessType trailerWriteCondition[8][3];

};

#endif // MF_TRAILERDECODERDIALOG_H
