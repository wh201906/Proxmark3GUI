#include "mf_trailerdecoderdialog.h"
#include "ui_mf_trailerdecoderdialog.h"

MF_trailerDecoderDialog::MF_trailerDecoderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MF_trailerDecoderDialog)
{
    ui->setupUi(this);
    QRegularExpression re("(([0-9a-fA-F]{2} ){0,4})|([0-9a-fA-F]{0,8})");
    validator = new QRegularExpressionValidator(this);
    validator->setRegularExpression(re);
    ui->accessBitsEdit->setValidator(validator);

    sizeGroup = new QButtonGroup(this);
    sizeGroup->addButton(ui->size4Button, 4);
    sizeGroup->addButton(ui->size16Button, 16);
    connect(sizeGroup, QOverload<int, bool>::of(&QButtonGroup::buttonToggled), this, &MF_trailerDecoderDialog::on_blockSizeChanged);
    connect(ui->C0Box, QOverload<int>::of(&QSpinBox::valueChanged), this, &MF_trailerDecoderDialog::on_boxChanged);
    connect(ui->C1Box, QOverload<int>::of(&QSpinBox::valueChanged), this, &MF_trailerDecoderDialog::on_boxChanged);
    connect(ui->C2Box, QOverload<int>::of(&QSpinBox::valueChanged), this, &MF_trailerDecoderDialog::on_boxChanged);
    connect(ui->C3Box, QOverload<int>::of(&QSpinBox::valueChanged), this, &MF_trailerDecoderDialog::on_boxChanged);

    ui->dataBlockWidget->setRowCount(3);
    ui->dataBlockWidget->setColumnCount(4);
    ui->trailerBlockWidget->setRowCount(2);
    ui->trailerBlockWidget->setColumnCount(3);
}

MF_trailerDecoderDialog::~MF_trailerDecoderDialog()
{
    delete ui;
}
void MF_trailerDecoderDialog::on_accessBitsEdit_textChanged(const QString &arg1)
{
    ui->C0Box->blockSignals(true);
    ui->C1Box->blockSignals(true);
    ui->C2Box->blockSignals(true);
    ui->C3Box->blockSignals(true);
    QList<quint8> ACBits = Mifare::data_getACBits(arg1);
    if(ACBits.size() == 0)
    {
        ui->isAccessBitsValidLabel->setStyleSheet("color:rgb(200, 0, 0)");
        ui->isAccessBitsValidLabel->setText(tr("Invalid!\nIt could make the whole sector blocked irreversibly!"));
    }
    else
    {
        ui->C0Box->setValue(ACBits[0]);
        ui->C1Box->setValue(ACBits[1]);
        ui->C2Box->setValue(ACBits[2]);
        ui->C3Box->setValue(ACBits[3]);
        ui->isAccessBitsValidLabel->setStyleSheet("color:rgb(0, 200, 0)");
        ui->isAccessBitsValidLabel->setText(tr("Valid"));
        bool isKeyBReadable = ACBits[3] == 0 || ACBits[3] == 1 || ACBits[3] == 4;
        for(int j = 0; j < 3; j++)
        {
            setTableItem(ui->trailerBlockWidget, 0, j, Mifare::trailerReadCondition[ACBits[3]][j]);
            setTableItem(ui->trailerBlockWidget, 1, j, Mifare::trailerWriteCondition[ACBits[3]][j]);
        }
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                Mifare::AccessType type = Mifare::dataCondition[ACBits[i]][j];
                if(type == Mifare::ACC_KEY_B && isKeyBReadable)
                {
                    type = Mifare::ACC_NEVER;
                }
                else if(type == Mifare::ACC_KEY_AB && isKeyBReadable)
                {
                    type = Mifare::ACC_KEY_A;
                }
                setTableItem(ui->dataBlockWidget, i, j, type);
            }
        }
    }
    ui->C0Box->blockSignals(false);
    ui->C1Box->blockSignals(false);
    ui->C2Box->blockSignals(false);
    ui->C3Box->blockSignals(false);
}

void MF_trailerDecoderDialog::on_blockSizeChanged(int id, bool st)
{
    if(st)
    {
        if(id == 4)
        {
            ui->dataBlockWidget->verticalHeaderItem(0)->setText(tr("Block") + "0");
            ui->dataBlockWidget->verticalHeaderItem(1)->setText(tr("Block") + "1");
            ui->dataBlockWidget->verticalHeaderItem(2)->setText(tr("Block") + "2");
        }
        else if(id == 16)
        {
            ui->dataBlockWidget->verticalHeaderItem(0)->setText(tr("Block") + "0~4");
            ui->dataBlockWidget->verticalHeaderItem(1)->setText(tr("Block") + "5~9");
            ui->dataBlockWidget->verticalHeaderItem(2)->setText(tr("Block") + "10~14");
        }

    }
}

void MF_trailerDecoderDialog::setTableItem(QTableWidget* widget, int row, int column, Mifare::AccessType accessType)
{
    if(widget->item(row, column) == nullptr)
        widget->setItem(row, column, new QTableWidgetItem());
    QString text;
    if(accessType == Mifare::ACC_NEVER)
    {
        text = "X";
    }
    else if(accessType == Mifare::ACC_KEY_A)
    {
        text = tr("KeyA");
    }
    else if(accessType == Mifare::ACC_KEY_B)
    {
        text = tr("KeyB");
    }
    else if(accessType == Mifare::ACC_KEY_AB)
    {
        text = tr("KeyA+B");
    }
    widget->item(row, column)->setText(text);
}

void MF_trailerDecoderDialog::on_boxChanged()
{
    quint8 ACBits[4];
    ACBits[0] = ui->C0Box->value();
    ACBits[1] = ui->C1Box->value();
    ACBits[2] = ui->C2Box->value();
    ACBits[3] = ui->C3Box->value();
    quint8 halfBytes[6] = {0, 0, 0, 0, 0, 0};
    for(int i = 0; i < 4; i++)
    {
        halfBytes[2] |= (((ACBits[i] >> 0) & 1) << i);
        halfBytes[5] |= (((ACBits[i] >> 1) & 1) << i);
        halfBytes[4] |= (((ACBits[i] >> 2) & 1) << i);
    }
    halfBytes[0] = (~halfBytes[5]) & 0xf;
    halfBytes[1] = (~halfBytes[2]) & 0xf;
    halfBytes[3] = (~halfBytes[4]) & 0xf;

    QString result;
    for(int i = 0; i < 3; i++)
    {
        result += QString::number(halfBytes[i * 2], 16);
        result += QString::number(halfBytes[i * 2 + 1], 16);
        result += " ";
    }
    result = result.toUpper();
    ui->accessBitsEdit->setText(result);

}
