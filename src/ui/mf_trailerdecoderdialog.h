#ifndef MF_TRAILERDECODERDIALOG_H
#define MF_TRAILERDECODERDIALOG_H

#include <QDialog>
#include <QValidator>
#include <QDebug>
#include <QButtonGroup>
#include <QTableWidget>
#include "../module/mifare.h"

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

private slots:

    void on_accessBitsEdit_textChanged(const QString& arg1);

    void on_blockSizeChanged(int id, bool st);

    void on_boxChanged();
private:
    Ui::MF_trailerDecoderDialog *ui;
    QRegularExpressionValidator* validator;
    QButtonGroup* sizeGroup;
    void setTableItem(QTableWidget *widget, int row, int column, Mifare::AccessType accessType);
    void showCBits();
};

#endif // MF_TRAILERDECODERDIALOG_H
