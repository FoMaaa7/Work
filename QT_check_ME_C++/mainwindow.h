#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QIcon>
#include <QDir>
#include <QScrollArea>
#include <QTextEdit>
#include <QPushButton>
#include <QMessageBox>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTextEdit *info;
    QPushButton *test;
    QPushButton *test1;
    QPushButton *toFile;
    QMessageBox *eicar;
    QPushButton *eic;
    QPushButton *eic1;
    QMessageBox *exe;
    QPushButton *e;
    QPushButton *e1;
    int a;
    QDir *formdir;
    void Testing();
    void Eicar_Yes();
    void Eicar_No();
    void Exe_Yes();
    void Exe_No();
    void INFile();
    void qaw();
    void qwr();
    bool DelDir(const QString &);
    void RemoveAllFiles( const QString& , bool  );
    void SetFilePermissions( const QString &, QFile::Permission );
   void RemoveFilesInDir( const QString & );
    bool qCopyDirectory(const QDir& , const  QDir& , bool);
    int removeFolder(QDir &);
    //QPushButton *klik;
private:
    Ui::MainWindow *ui;
private slots:

};
#endif // MAINWINDOW_H
