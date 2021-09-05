#include "lf.h"

const LF::Config LF::defaultConfig;

LF::LF(Ui::MainWindow *ui, Util *addr, QWidget *parent): QObject(parent)
{
    this->parent = parent;
    util = addr;
    this->ui = ui;

    configPattern = new QRegularExpression("(\\d+)|Yes|No");
    currConfig = defaultConfig;
}

void LF::read()
{
    if(Util::getClientType() == Util::CLIENTTYPE_OFFICIAL)
        util->execCMD("lf read");
    else if(Util::getClientType() == Util::CLIENTTYPE_ICEMAN)
        util->execCMD("lf read -v");
    Util::gotoRawTab();
    util->execCMD("data plot");
}

void LF::sniff()
{
    if(Util::getClientType() == Util::CLIENTTYPE_OFFICIAL)
        util->execCMD("lf snoop");
    else if(Util::getClientType() == Util::CLIENTTYPE_ICEMAN)
        util->execCMD("lf sniff -v");
    Util::gotoRawTab();
    util->execCMD("data plot");
}

void LF::search()
{
    if(Util::getClientType() == Util::CLIENTTYPE_OFFICIAL)
        util->execCMD("lf search u");
    else if(Util::getClientType() == Util::CLIENTTYPE_ICEMAN)
        util->execCMD("lf search -u");
    Util::gotoRawTab();
}

void LF::tune()
{
    if(Util::getClientType() == Util::CLIENTTYPE_OFFICIAL)
        util->execCMD("hw tune l");
    else if(Util::getClientType() == Util::CLIENTTYPE_ICEMAN)
        util->execCMD("lf tune --divisor " + QString::number(currConfig.divisor));
    Util::gotoRawTab();
}

void LF::getConfig()
{
    QRegularExpressionMatch reMatch;
    QString result;
    QStringList resultList;
    QStringList symbolList =
    {
        "divisor",
        "bps",
        "bits per sample",
        "decimation",
        "averaging",
        "trigger threshold",
        "samples to skip"
    };
    int offset;
    QStringList configList = {"", "", "", "", "", "", ""};
    result = util->execCMDWithOutput("hw status", 400); // not all output from "hw status will be processed".
    result = result.right(result.length() - result.indexOf("LF Sampling config"));
    offset = result.indexOf("samples to skip");
    offset = result.indexOf("\n", offset);
    result = result.mid(0, offset + 2);
    qDebug() << "LF CONFIG GET\n" << result;
    resultList = result.split("\n");
    for(int i = 0; i < resultList.length(); i++)
    {
        for(int j = 0; j < symbolList.length(); j++)
        {
            if(!configList[j].isEmpty())
                continue;
            offset = resultList[i].indexOf(symbolList[j]);
            if(offset != -1)
            {
                reMatch = configPattern->match(resultList[i]);
                qDebug() << "finded: " << resultList[i];
                if(!reMatch.hasMatch())
                    continue;
                qDebug() << "captured: " << reMatch.captured();
                configList[j] = reMatch.captured();
                break;
            }
        }
    }
    qDebug() << "configList: " << configList;
    currConfig.divisor = configList[0].toUInt();
    currConfig.decimation = configList[3].toUInt();
    currConfig.triggerThreshold = configList[5].toUInt();
    currConfig.samplesToSkip = configList[6].toUInt();
    if(Util::getClientType() == Util::CLIENTTYPE_OFFICIAL)
    {
        currConfig.bitPerSample = configList[1].toUInt();
        currConfig.averaging = (configList[4] == "1");
    }
    else if(Util::getClientType() == Util::CLIENTTYPE_ICEMAN)
    {
        currConfig.bitPerSample = configList[2].toUInt();
        currConfig.averaging = (configList[4] == "Yes");
    }
    syncWithUI();
}

void LF::setConfig(LF::Config config)
{
    currConfig = config;
    if(Util::getClientType() == Util::CLIENTTYPE_OFFICIAL)
    {
        util->execCMDWithOutput(QString("lf config")
                                + " q " + QString::number(currConfig.divisor)
                                + " b " + QString::number(currConfig.bitPerSample)
                                + " d " + QString::number(currConfig.decimation)
                                + " a " + QString(currConfig.averaging ? "1" : "0")
                                + " t " + QString::number(currConfig.triggerThreshold)
                                + " s " + QString::number(currConfig.samplesToSkip),
                                500);
        util->execCMDWithOutput("hw setlfdivisor " + QString::number(currConfig.divisor), 500);
    }
    else if(Util::getClientType() == Util::CLIENTTYPE_ICEMAN)
    {
        util->execCMDWithOutput(QString("lf config")
                                + " -a " + QString(currConfig.averaging ? "1" : "0")
                                + " -b " + QString::number(currConfig.bitPerSample)
                                + " --dec " + QString::number(currConfig.decimation)
                                + " --divisor " + QString::number(currConfig.divisor)
                                + " -s " + QString::number(currConfig.samplesToSkip)
                                + " -t " + QString::number(currConfig.triggerThreshold),
                                500);
        util->execCMDWithOutput("hw setlfdivisor -d " + QString::number(currConfig.divisor), 500);
    }
}

void LF::resetConfig()
{
    setConfig(defaultConfig);
    getConfig();
}

float LF::divisor2Freq(uint8_t divisor)
{
    return (12000.0 / (divisor + 1.0));
}

uint8_t LF::freq2Divisor(float freq)
{
    return ((uint16_t)(12000.0 / freq + 0.5) - 1); // uint16_t for (divisor + 1) = 256
}

void LF::syncWithUI()
{
    ui->LF_Conf_freqDivisorBox->setValue(currConfig.divisor); // will trigger valueChanged()
    ui->LF_Conf_bitPerSampleBox->setValue(currConfig.bitPerSample);
    ui->LF_Conf_decimationBox->setValue(currConfig.decimation);
    ui->LF_Conf_averagingBox->setChecked(currConfig.averaging);
    ui->LF_Conf_thresholdBox->setValue(currConfig.triggerThreshold);
    ui->LF_Conf_skipsBox->setValue(currConfig.samplesToSkip);
}
