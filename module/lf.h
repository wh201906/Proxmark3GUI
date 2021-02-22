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

    void read();
    void sniff();
    void search();
    void tune();
private:
    QWidget* parent;
    Ui::MainWindow *ui;
    Util* util;

signals:

};

#endif // LF_H
