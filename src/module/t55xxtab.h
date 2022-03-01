#ifndef T55XXTAB_H
#define T55XXTAB_H

#include "common/util.h"
#include <QWidget>

namespace Ui
{
class T55xxTab;
}

class T55xxTab : public QWidget
{
    Q_OBJECT

public:
    explicit T55xxTab(Util *addr, QWidget *parent = nullptr);
    ~T55xxTab();

    void setConfigMap(const QVariantMap& configMap);
private slots:
    void on_Clone_EM410xReadButton_clicked();

    void on_Clone_EM410xCloneButton_clicked();

private:
    Ui::T55xxTab *ui;
    Util* util;
    QVariantMap configMap;

    void setGUIState(bool st);
signals:
    void setParentGUIState(bool st);
};

#endif // T55XXTAB_H
