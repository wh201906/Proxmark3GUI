#include "ui/mainwindow.h"

#include <QApplication>
#include <QSettings>
#include <QTranslator>
#include <QMessageBox>
#include <QTextCodec>
#include <QDir>

int main(int argc, char *argv[])
{
    // A trick to handle non-ascii path
    // The application cannot find the plugins when the path contains non ascii characters.
    // However, the plugins will be load after creating MainWindow(or QApplication?).
    // QDir will handle the path correctly.
    QDir* pluginDir = new QDir;
    if(pluginDir->cd("plugins")) // has plugins folder
    {
        qputenv("QT_PLUGIN_PATH", pluginDir->absolutePath().toLocal8Bit());
    }
    delete pluginDir;

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QDir *langPath = new QDir();
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
    currLang += ".qm";
    langPath->cd("lang");
    QTranslator* translator = new QTranslator(&w);
    if(translator->load(currLang, langPath->absolutePath()))
    {
        a.installTranslator(translator);
    }
    else
    {
        QMessageBox::information(&w, "Error", "Can't load " + currLang + " as translation file.");
    }
    delete settings;
    delete langPath;
    w.initUI();
    w.show();
    return a.exec();
}


