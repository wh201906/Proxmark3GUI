#include "ui/mainwindow.h"

#include <QApplication>
#include <QSettings>
#include <QTranslator>
#include <QMessageBox>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QSettings* settings = new QSettings("GUIsettings.ini", QSettings::IniFormat);
    QVariant lang = settings->value("lang", "null");
    if(lang == "null")
    {
        lang = "lang/en_US.qm";
        QStringList langList;
        langList.append("English");
        langList.append("简体中文");
        QString seletedText = QInputDialog::getItem(&w, "", "Choose a language:", langList, 0, false);
        if(seletedText == "English")
        {
            lang = "lang/en_US.qm";
        }
        else if(seletedText == "简体中文")
        {
            lang = "lang/zh_CN.qm";
        }
    }
    QTranslator* translator = new QTranslator(&w);
    if(translator->load(lang.toString()))
    {
        a.installTranslator(translator);
        settings->setValue("lang", lang);
    }
    else
    {
        QMessageBox::information(&w, "Error", "Can't load " + lang.toString() + " as translation file.");
    }
    delete settings;
    w.initUI();
    w.show();
    return a.exec();
}
