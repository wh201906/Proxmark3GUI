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
    QApplication a(argc, argv);

    QSettings* settings = new QSettings("GUIsettings.ini", QSettings::IniFormat);
    settings->setIniCodec("UTF-8");
    settings->beginGroup("language");
    QString languageFile = settings->value("extPath").toString();
    QString languageName = settings->value("name").toString();
    settings->endGroup();
    settings->beginGroup("UI");
    QString theme = settings->value("Theme_Name").toString();
    settings->endGroup();
    if(languageName == "")
    {
        if(Util::chooseLanguage(settings))
        {
            settings->beginGroup("language");
            languageName = settings->value("name").toString();
            settings->endGroup();
        }
        else
            languageName = "en_US";
    }
    if(languageName == "(ext)")
    {
        settings->beginGroup("language");
        languageFile = settings->value("extPath").toString();
        settings->endGroup();
    }
    else
        languageFile = ":/i18n/" + languageName + ".qm";

    // Note that the translator must be created before the application's widgets.
    QTranslator* translator = new QTranslator();
    if(translator->load(languageFile))
        a.installTranslator(translator);
    else
        QMessageBox::information(nullptr, "Error", "Can't load " + languageFile + " as translation file.");

    QFile* themeFile = new QFile();
    QTextStream* themeStream = new QTextStream();
    QString qssString = a.styleSheet(); // default behavior
    if(theme == "(none)")
        ;
    else if(theme == "qdss_dark")
    {
        themeFile->setFileName(":/qdarkstyle/dark/darkstyle.qss");
        themeFile->open(QFile::ReadOnly | QFile::Text);
        themeStream->setDevice(themeFile);
        qssString = themeStream->readAll();
    }
    else if(theme == "qdss_light")
    {
        themeFile->setFileName(":/qdarkstyle/light/lightstyle.qss");
        themeFile->open(QFile::ReadOnly | QFile::Text);
        themeStream->setDevice(themeFile);
        qssString = themeStream->readAll();
    }
    a.setStyleSheet(qssString);
    delete themeFile;
    delete themeStream;
    themeFile = nullptr;
    themeStream = nullptr;

    delete settings;
    settings = nullptr;

    MainWindow w;
    w.initUI();
    w.show();
    return a.exec();
}


