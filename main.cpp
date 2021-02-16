#include "ui/mainwindow.h"

#include <QApplication>
#include <QSettings>
#include <QTranslator>
#include <QMessageBox>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QApplication a(argc, argv);
    MainWindow w;

    QSettings* settings = new QSettings("GUIsettings.ini", QSettings::IniFormat);
    settings->setIniCodec("UTF-8");
    settings->beginGroup("lang");
    QString currLang = settings->value("language", "").toString();
    settings->endGroup();
    if(currLang == "")
    {
        if(Util::chooseLanguage(settings, &w))
        {
            settings->beginGroup("lang");
            currLang = settings->value("language", "").toString();
            settings->endGroup();
        }
        else
            currLang = "en_US";
    }
    currLang = "lang/" + currLang;
#ifdef Q_OS_WIN
    currLang += ".qm";
#else
    currLang += ".ts";;
#endif
    QTranslator* translator = new QTranslator(&w);
    if(translator->load(currLang))
    {
        a.installTranslator(translator);
    }
    else
    {
        QMessageBox::information(&w, "Error", "Can't load " + currLang + " as translation file.");
    }
    delete settings;
    w.initUI();
    w.show();
    return a.exec();
}


