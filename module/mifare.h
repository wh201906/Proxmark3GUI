#ifndef MIFARE_H
#define MIFARE_H

#include "common/util.h"
#include "ui_mainwindow.h"
#include "ui/mf_attack_hardnesteddialog.h"
#include <QObject>
#include <QString>
#include <QStringList>
#include <QRegExp>
#include <QMessageBox>
class Mifare : public QObject
{
    Q_OBJECT
public:
    explicit Mifare(Ui::MainWindow *ui, Util *addr, QWidget *parent = nullptr);

    void info();
    void chk();
    void nested();
    void hardnested();
    void sniff();
    void list();
    void read();
    void readAll();
    void write();
    void writeAll();
    void dump();
    void restore();

    enum DataType
    {
        DATA_INVALID,
        DATA_WITHSPACE,
        DATA_NOSPACE,
    };

    struct CardType
    {
        int type;
        int sectors;
        int blocks;
        int blk[40];
        int blks[40];
    };

    const CardType card_mini =
    {
        0,
        5,
        20,
        {4, 4, 4, 4, 4},
        {0, 4, 8, 12, 16}
    };
    const CardType card_1k =
    {
        1,
        16,
        64,
        {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
        {0, 4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60}
    };
    const CardType card_2k =
    {
        2,
        32,
        128,
        {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
        {0, 4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60, 64, 68, 72, 76, 80, 84, 88, 92, 96, 100, 104, 108, 112, 116, 120, 124}
    };
    const CardType card_4k =
    {
        4,
        40,
        256,
        {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 16, 16, 16, 16, 16, 16, 16, 16},
        {0, 4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60, 64, 68, 72, 76, 80, 84, 88, 92, 96, 100, 104, 108, 112, 116, 120, 124, 128, 144, 160, 176, 192, 208, 224, 240}
    };

    void data_clearData();
    void data_clearKey();
    bool data_isKeyValid(const QString &key);
    Mifare::DataType data_isDataValid(QString data);
    void data_syncWithDataWidget(bool syncAll = true, int block = 0);
    void data_syncWithKeyWidget(bool syncAll = true, int sector = 0, bool isKeyA = true);

    CardType cardType;
    Mifare::CardType getCardType();
    void setCardType(int type);
    void writeAllC();
    void writeC();
    void readAllC();
    void readC();
    void wipeC();
    void setParameterC();

    bool data_loadDataFile(const QString &filename);
    bool data_loadKeyFile(const QString &filename);
    bool data_saveDataFile(const QString& filename, bool isBin);
    bool data_saveKeyFile(const QString &filename, bool isBin);
    void data_key2Data();
    void data_data2Key();

public slots:
signals:

private:
    QWidget* parent;
    Ui::MainWindow *ui;
    Util* util;

    QStringList* keyAList;
    QStringList* keyBList;
    QStringList* dataList;
    QRegExp* dataPattern;
    QRegExp* chkKeyPattern;
    QRegExp* nestedKeyPattern;
};

#endif // MIFARE_H
