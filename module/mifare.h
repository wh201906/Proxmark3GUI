#ifndef MIFARE_H
#define MIFARE_H

#include "common/util.h"
#include "ui_mainwindow.h"
#include "ui/mf_attack_hardnesteddialog.h"
#include <QObject>
#include <QString>

class Mifare : public QObject
{
    Q_OBJECT
public:
    explicit Mifare(Ui::MainWindow *ui, Util *addr, QObject *parent = nullptr);

    bool isKeyValid(const QString key);
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
public slots:
signals:

private:
    Ui::MainWindow *ui;
    Util* util;
};

#endif // MIFARE_H
