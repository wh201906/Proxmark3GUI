#include "ui/mainwindow.h"

#include <QApplication>
#include <QSettings>
#include <QTranslator>
#include <QMessageBox>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    MainWindow w;
    QSettings* settings = new QSettings("GUIsettings.ini", QSettings::IniFormat);
    settings->beginGroup("lang");
    QVariant lang = settings->value("language", "null");
    if(lang == "null")
    {
#ifdef Q_OS_WIN
        lang = "lang/en_US.qm";
#else
        lang = "lang/en_US.ts";
#endif
        QStringList langList;
        langList.append("English");
        langList.append("简体中文");
        QString seletedText = QInputDialog::getItem(&w, "", "Choose a language:", langList, 0, false);
        if(seletedText == "English")
        {
#ifdef Q_OS_WIN
            lang = "lang/en_US.qm";
#else
            lang = "lang/en_US.ts";
#endif
        }
        else if(seletedText == "简体中文")
        {
#ifdef Q_OS_WIN
            lang = "lang/zh_CN.qm";
#else
            lang = "lang/zh_CN.ts";
#endif
        }
    }
    QTranslator* translator = new QTranslator(&w);
    if(translator->load(lang.toString()))
    {
        a.installTranslator(translator);
        settings->setValue("language", lang);
    }
    else
    {
        QMessageBox::information(&w, "Error", "Can't load " + lang.toString() + " as translation file.");
    }
    settings->endGroup();
    delete settings;
    w.initUI();
    w.show();
    return a.exec();
}
