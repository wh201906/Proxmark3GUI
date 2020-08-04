#include "mf_trailerdecoderdialog.h"
#include "ui_mf_trailerdecoderdialog.h"

MF_trailerDecoderDialog::AccessType MF_trailerDecoderDialog::dataCondition[8][4] =
{
    {ACC_KEY_AB, ACC_KEY_AB, ACC_KEY_AB, ACC_KEY_AB},
    {ACC_KEY_AB, ACC_NEVER, ACC_NEVER, ACC_NEVER},
    {ACC_KEY_AB, ACC_KEY_B, ACC_NEVER, ACC_NEVER},
    {ACC_KEY_AB, ACC_KEY_B, ACC_KEY_B, ACC_KEY_AB},
    {ACC_KEY_AB, ACC_NEVER, ACC_NEVER, ACC_KEY_AB},
    {ACC_KEY_B, ACC_KEY_B, ACC_NEVER, ACC_NEVER},
    {ACC_KEY_B, ACC_NEVER, ACC_NEVER, ACC_NEVER},
    {ACC_NEVER, ACC_NEVER, ACC_NEVER, ACC_NEVER},
};
MF_trailerDecoderDialog::AccessType MF_trailerDecoderDialog::trailerReadCondition[8][3] =
{
    {ACC_NEVER, ACC_KEY_A, ACC_KEY_A},
    {ACC_NEVER, ACC_KEY_A, ACC_KEY_A},
    {ACC_NEVER, ACC_KEY_AB, ACC_NEVER},
    {ACC_NEVER, ACC_KEY_AB, ACC_NEVER},
    {ACC_NEVER, ACC_KEY_A, ACC_KEY_A},
    {ACC_NEVER, ACC_KEY_AB, ACC_NEVER},
    {ACC_NEVER, ACC_KEY_AB, ACC_NEVER},
    {ACC_NEVER, ACC_KEY_AB, ACC_NEVER},
};
MF_trailerDecoderDialog::AccessType MF_trailerDecoderDialog::trailerWriteCondition[8][3] =
{
    {ACC_KEY_A, ACC_NEVER, ACC_KEY_A},
    {ACC_NEVER, ACC_NEVER, ACC_NEVER},
    {ACC_KEY_B, ACC_NEVER, ACC_KEY_B},
    {ACC_NEVER, ACC_NEVER, ACC_NEVER},
    {ACC_KEY_A, ACC_KEY_A, ACC_KEY_A},
    {ACC_KEY_B, ACC_KEY_B, ACC_KEY_B},
    {ACC_NEVER, ACC_KEY_B, ACC_NEVER},
    {ACC_NEVER, ACC_NEVER, ACC_NEVER},
};

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

    ui->dataBlockWidget->setRowCount(3);
    ui->dataBlockWidget->setColumnCount(4);
    ui->trailerBlockWidget->setRowCount(2);
    ui->trailerBlockWidget->setColumnCount(3);
}

MF_trailerDecoderDialog::~MF_trailerDecoderDialog()
{
    delete ui;
}
void MF_trailerDecoderDialog::on_accessBitsEdit_textEdited(const QString &arg1)
{
    QString input = arg1;
    input.remove(" ");
    if(input.length() < 6)
    {
        ui->isAccessBitsValidLabel->setText("");
        return;
    }
    input = input.left(6);
    quint32 result = input.toUInt(nullptr, 16);
    quint8 halfBytes[6];
    for(int i = 0; i < 6; i++)
    {
        halfBytes[i] = (result >> ((5 - i) * 4)) & 0xf;
    }
    qDebug() << result;
    if((~halfBytes[0] & 0xf) != halfBytes[5] || (~halfBytes[1] & 0xf) != halfBytes[2] || (~halfBytes[3] & 0xf) != halfBytes[4])
    {
        ui->isAccessBitsValidLabel->setStyleSheet("color:rgb(200, 0, 0)");
        ui->isAccessBitsValidLabel->setText(tr("Invalid! It could make the whole sector blocked irreversibly!"));
    }
    else
    {
        ui->isAccessBitsValidLabel->setStyleSheet("color:rgb(0, 200, 0)");
        ui->isAccessBitsValidLabel->setText(tr("Valid"));
        quint8 ACBits[4];
        for(int i = 0; i < 4; i++)
        {
            ACBits[i] = (((halfBytes[4] >> i) & 1) << 2) | (((halfBytes[5] >> i) & 1) << 1) | (((halfBytes[2] >> i) & 1) << 0);
        }
        bool isKeyBReadable = ACBits[3] == 0 || ACBits[3] == 1 || ACBits[3] == 4;
        for(int j = 0; j < 3; j++)
        {
            setTableItem(ui->trailerBlockWidget, 0, j, trailerReadCondition[ACBits[3]][j]);
            setTableItem(ui->trailerBlockWidget, 1, j, trailerWriteCondition[ACBits[3]][j]);
        }
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                AccessType type = dataCondition[ACBits[i]][j];
                if(type == ACC_KEY_B && isKeyBReadable)
                {
                    type = ACC_NEVER;
                }
                else if(type == ACC_KEY_AB && isKeyBReadable)
                {
                    type = ACC_KEY_A;
                }
                setTableItem(ui->dataBlockWidget, i, j, type);
            }
        }
    }
}

void MF_trailerDecoderDialog::on_blockSizeChanged(int id, bool st)
{
    if(st)
    {
        if(id == 4)
        {
            ui->dataBlockWidget->verticalHeaderItem(0)->setText("Block0");
            ui->dataBlockWidget->verticalHeaderItem(1)->setText("Block1");
            ui->dataBlockWidget->verticalHeaderItem(2)->setText("Block2");
        }
        else if(id == 16)
        {
            ui->dataBlockWidget->verticalHeaderItem(0)->setText("Block0~4");
            ui->dataBlockWidget->verticalHeaderItem(1)->setText("Block5~9");
            ui->dataBlockWidget->verticalHeaderItem(2)->setText("Block10~14");
        }

    }
}

void MF_trailerDecoderDialog::setTableItem(QTableWidget* widget, int row, int column, AccessType accessType)
{
    if(widget->item(row, column) == nullptr)
        widget->setItem(row, column, new QTableWidgetItem());
    QString text;
    if(accessType == ACC_NEVER)
    {
        text = "X";
    }
    else if(accessType == ACC_KEY_A)
    {
        text = "KeyA";
    }
    else if(accessType == ACC_KEY_B)
    {
        text = "KeyB";
    }
    else if(accessType == ACC_KEY_AB)
    {
        text = "KeyA+B";
    }
    widget->item(row, column)->setText(text);
}
