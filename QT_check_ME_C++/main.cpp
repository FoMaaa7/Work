#include "mainwindow.h"

#include <QApplication>
#include <QDesktopServices>
#include <QUrl>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QDesktopServices::openUrl(QUrl("https://www.google.ru/"));
    qApp->exit();
    //delete w;
    return 0;

}
