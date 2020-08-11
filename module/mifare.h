#ifndef MIFARE_H
#define MIFARE_H

#include "common/util.h"
#include "ui_mainwindow.h"
#include "ui/mf_attack_hardnesteddialog.h"
#include "ui/mf_uid_parameterdialog.h"
#include "ui/mf_sim_simdialog.h"
#include <QObject>
#include <QString>
#include <QStringList>
#include <QRegularExpression>
#include <QMessageBox>
class Mifare : public QObject
{
    Q_OBJECT
public:
    explicit Mifare(Ui::MainWindow *ui, Util *addr, QWidget *parent = nullptr);

    enum KeyType
    {
        KEY_A = 'A',
        KEY_B = 'B',
    };

    enum DataType
    {
        DATA_INVALID,
        DATA_WITHSPACE,
        DATA_NOSPACE,
    };

    struct CardType
    {
        quint8 type;
        quint8 sector_size;
        quint16 block_size;
        quint8 blk[40];
        quint8 blks[40];
    };

    enum AccessType
    {
        ACC_NEVER = 0,
        ACC_KEY_A = 1,
        ACC_KEY_B = 2,
        ACC_KEY_AB = 3,
    };

    enum TargetType
    {
        TARGET_MIFARE,
        TARGET_UID,
        TARGET_EMULATOR,
    };

    static const CardType card_mini;
    static const CardType card_1k;
    static const CardType card_2k;
    static const CardType card_4k;

    static const AccessType dataCondition[8][4];
    static const AccessType trailerReadCondition[8][3];
    static const AccessType trailerWriteCondition[8][3];

    QString info(bool isRequiringOutput = false);
    void chk();
    void nested();
    void hardnested();
    void sniff();
    void snoop();
    void list();
    void readOne(TargetType targetType = TARGET_MIFARE);
    void readSelected(TargetType targetType = TARGET_MIFARE);
    void writeOne(TargetType targetType = TARGET_MIFARE);
    void writeSelected(TargetType targetType = TARGET_MIFARE);
    void dump();
    void restore();

    void data_clearData(bool clearAll = true);
    void data_clearKey(bool clearAll = true);
    static bool data_isKeyValid(const QString& key);
    static Mifare::DataType data_isDataValid(const QString& data);
    void data_syncWithDataWidget(bool syncAll = true, int block = 0);
    void data_syncWithKeyWidget(bool syncAll = true, int sector = 0, KeyType keyType = KEY_A);

    CardType cardType;
    Mifare::CardType getCardType();
    void setCardType(int type);
    void wipeC();
    void setParameterC();

    bool data_loadDataFile(const QString& filename);
    bool data_loadKeyFile(const QString& filename);
    bool data_saveDataFile(const QString& filename, bool isBin);
    bool data_saveKeyFile(const QString& filename, bool isBin);
    void data_key2Data();
    void data_data2Key();

    void data_setData(int block, const QString& data);
    void data_setKey(int sector, KeyType keyType, const QString& key);
    void lockC();
    void wipeE();
    void simulate();
    void loadSniff(const QString& file);
    void saveSniff(const QString& file);
    void data_fillKeys();

    static QList<quint8> data_getACBits(const QString &text);
    static int data_b2s(int block);
    static bool data_isACBitsValid(const QString &text, QList<quint8> *returnHalfBytes = nullptr);
public slots:
signals:

private:
    QWidget* parent;
    Ui::MainWindow *ui;
    Util* util;

    QStringList* keyAList;
    QStringList* keyBList;
    QStringList* dataList;
    QRegularExpression* dataPattern;
    QRegularExpression* keyPattern_res;
    QRegularExpression* keyPattern;
    QString bin2text(const QByteArray& buff, int start, int length);

    QString _readblk(int blockId, KeyType keyType, const QString &key, TargetType targetType = TARGET_MIFARE, int waitTime = 300);
    QStringList _readsec(int sectorId, KeyType keyType, const QString &key, TargetType targetType = TARGET_MIFARE, int waitTime = 300);
    bool _writeblk(int blockId, KeyType keyType, const QString &key, const QString &data, TargetType targetType = TARGET_MIFARE, int waitTime = 300);
};

#endif // MIFARE_H
