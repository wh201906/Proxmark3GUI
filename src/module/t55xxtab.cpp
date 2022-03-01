#include "t55xxtab.h"
#include "ui_t55xxtab.h"

T55xxTab::T55xxTab(Util *addr, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::T55xxTab)
{
    ui->setupUi(this);
    util = addr;
}

T55xxTab::~T55xxTab()
{
    delete ui;
}

void T55xxTab::setConfigMap(const QVariantMap &configMap)
{
    this->configMap = configMap;
}

void T55xxTab::setGUIState(bool st)
{
    ui->cloneGroupBox->setEnabled(st);
    emit setParentGUIState(st);
}

void T55xxTab::on_Clone_EM410xReadButton_clicked()
{
    setGUIState(false);

    QVariantMap config = configMap["clone em410x"].toMap();
    QString result;
    QRegularExpressionMatch reMatch;

    result = util->execCMDWithOutput(
                 config["read"].toString(),
                 Util::ReturnTrigger(6000, {config["successful read flag"].toString()}));
    if(result.isEmpty())
    {
        setGUIState(true);
        return;
    }
    reMatch = QRegularExpression(config["pattern"].toString()).match(result);
    ui->Clone_EM410xIDEdit->setText(reMatch.captured());

    setGUIState(true);
}

void T55xxTab::on_Clone_EM410xCloneButton_clicked()
{
    if(ui->Clone_EM410xIDEdit->text().isEmpty())
        return;
    setGUIState(false);

    QVariantMap config = configMap["clone em410x"].toMap();
    QString cmd = config["clone cmd"].toString();
    cmd.replace("<id>", ui->Clone_EM410xIDEdit->text());
    if(ui->Clone_T5555Button->isChecked())
        cmd.replace("<type>", config["t5555 flag"].toString());
    else
        cmd.replace("<type>", config["t55x7 flag"].toString());
    util->execCMD(cmd);
    Util::gotoRawTab();

    setGUIState(true);
}

