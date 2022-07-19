#include "mainwindow.h"

#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowIcon(QIcon("C:/Users/advok/Documents/untitled1/ic.jpg"));
    w.setStyleSheet("background-color: #56Bfe4;");
    w.setGeometry(50,50,530,280);
    w.setMinimumHeight(280);
    w.setMaximumHeight(280);
    w.setMinimumWidth(530);
    w.setMaximumWidth(530);
    w.setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
    w.show();
    return a.exec();
}
