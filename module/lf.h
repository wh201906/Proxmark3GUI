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

    struct Config
    {
        uint8_t divisor;
        uint8_t bitPerSample;
        uint8_t decimation;
        bool averaging;
        uint8_t triggerThreshold;
        uint16_t samplesToSkip;
    };

    static constexpr Config defaultConfig =
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
    void getConfig();
    void setConfig(LF::Config config);
    void resetConfig();
    static float divisor2Freq(uint8_t divisor);
    static uint8_t freq2Divisor(float freq);

private:
    QWidget* parent;
    Ui::MainWindow *ui;
    Util* util;
    Config currConfig;
    QRegularExpression* configPattern;
    void syncWithUI();
signals:

};

#endif // LF_H
