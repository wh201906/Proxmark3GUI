#ifndef MIFARE_H
#define MIFARE_H

#include "common/util.h"
#include "ui_mainwindow.h"
#include "ui/mf_attack_hardnesteddialog.h"
#include <QObject>
#include <QString>
#include <QStringList>
#include <QRegExp>
class Mifare : public QObject
{
    Q_OBJECT
public:
    explicit Mifare(Ui::MainWindow *ui, Util *addr, QObject *parent = nullptr);

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

    void data_clearData();
    void data_clearKey();
    bool data_isKeyValid(const QString &key);
    Mifare::DataType data_isDataValid(QString data);
    void data_syncWithDataWidget(bool syncAll = true, int block = 0);
    void data_syncWithKeyWidget(bool syncAll = true, int sector = 0, bool isKeyA = true);
public slots:
signals:

private:
    Ui::MainWindow *ui;
    Util* util;

    QStringList* keyAList;
    QStringList* keyBList;
    QStringList*  dataList;
    QRegExp* dataPattern;

    int sectors = 16;
    int blocks = 64;
};

#endif // MIFARE_H
