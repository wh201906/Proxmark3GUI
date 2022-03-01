#include "t55xxtab.h"
#include "ui_t55xxtab.h"

T55xxTab::T55xxTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::T55xxTab)
{
    ui->setupUi(this);
}

T55xxTab::~T55xxTab()
{
    delete ui;
}
