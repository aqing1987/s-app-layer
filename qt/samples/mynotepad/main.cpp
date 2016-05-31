#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>
#include <QPixmap>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));

    // add start screen
    QPixmap pixmap("bin_images/splash.png");
    QSplashScreen splash(pixmap);
    splash.show();

    // simulate process sth
    for (int i = 0; i < 100000000; i++) {
        ;
    }

    MainWindow w;
    w.show();
    splash.finish(&w);

    return a.exec();
}
