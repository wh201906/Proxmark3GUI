#ifndef T55XXTAB_H
#define T55XXTAB_H

#include <QWidget>

namespace Ui {
class T55xxTab;
}

class T55xxTab : public QWidget
{
    Q_OBJECT

public:
    explicit T55xxTab(QWidget *parent = nullptr);
    ~T55xxTab();

private:
    Ui::T55xxTab *ui;
};

#endif // T55XXTAB_H
