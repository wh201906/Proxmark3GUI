#ifndef LF_H
#define LF_H

#include <QObject>

#include "common/util.h"
#include "ui_mainwindow.h"

class LF : public QObject
{
    Q_OBJECT
public:
    explicit LF(Ui::MainWindow *ui, Util *addr, QWidget *parent = nullptr);

    struct LFConfig
    {
        uint8_t divisor;
        uint8_t bitsPerSample;
        uint8_t decimation;
        bool averaging;
        uint8_t triggerThreshold;
        uint16_t samplesToSkip;
    };

    static constexpr LFConfig defaultLFConfig =
    {
        95,
        8,
        1,
        true,
        0,
        0
    };

    void read();
    void sniff();
    void search();
    void tune();
    void getLFConfig();
    void setLFConfig(LF::LFConfig lfconfig);
    void resetLFConfig();
    static float divisor2Freq(uint8_t divisor);
    static uint8_t freq2Divisor(float freq);

    void setConfigMap(const QVariantMap &configMap);
private:
    QWidget* parent;
    Ui::MainWindow *ui;
    Util* util;
    LFConfig currLFConfig;
    QRegularExpression* LFconfigPattern;
    QVariantMap configMap;
    void syncWithUI();
    bool getLFConfig_helper(const QVariantMap& map, QString& str, int* result);
signals:
    void LFfreqConfChanged(int divisor, bool isCustomized);
};

#endif // LF_H
