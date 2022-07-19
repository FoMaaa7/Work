#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDesktopServices>
#include <iostream>
#include <fstream>
#include <string>
#include <QDir>
#include <QProcess>
#include <cstdio>
#include <QEventLoop>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QThread>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //klik=new QPushButton(this);
    //klik->setStyleSheet("QPushButton{background:#FF0063;}");
   // klik->setGeometry(195,45,56,36);
//klik->show();
    info=new QTextEdit(this);
    //info->setStyleSheet("background-color: #;");
    info->setGeometry(10,10,510,200);
    info->setStyleSheet("background-color: #000000; border: 0px solid black;");
    //info->setStyleSheet("{  }");
    info->setTextColor(QColor(127,255,0));
    info->setCursorWidth(0);
    info->setReadOnly(true);
    info->append("Hello");
    info->show();
    test=new QPushButton(this);
    test->setGeometry(30, 220,100,50 );
    test->setText("TEST");
    test->setStyleSheet("background-color: #7fff00;");
    test->show();
    toFile=new QPushButton(this);
    toFile->setGeometry(400,220,100,50);
    toFile->setStyleSheet("background-color: #7fff00;");
    toFile->setText("In File");
    toFile->show();
    connect(test,&QPushButton::clicked,this,&MainWindow::Testing);
    connect(toFile, &QPushButton::clicked,this,&MainWindow::INFile);// #при объявлении без приват слот
    //connect(test,SIGNAL(clicked()),this,SLOT(Testing()));
}

void MainWindow::qaw(){
    QNetworkAccessManager nam;
    QNetworkRequest req(QUrl("https://www.yaeby.pro/categories/"));
    QNetworkReply *reply = nam.get(req);
    QEventLoop loop;
    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    if(reply->bytesAvailable())
    info->append("Опасный сайт открыт. Тест не пройден");
    else
    info->append("Опасный сайт не открыт. Тест пройден");
}
void MainWindow::SetFilePermissions( const QString &path, QFile::Permission euPermission )
{
  if (path.isEmpty())
  {
      return ;
  }

  QDir dir(path);
  if(!dir.exists())
  {
      return ;
  }

  dir.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot);
  QFileInfoList fileList = dir.entryInfoList();
  foreach (QFileInfo fi, fileList)
  {
      if (fi.isFile())
      {
          QFile file(fi.absoluteFilePath());
          file.setPermissions(euPermission);
      }
      else
      {
          SetFilePermissions(fi.absoluteFilePath(),euPermission);
      }
  }
}

void MainWindow::RemoveFilesInDir( const QString &path )
{
  if (!path.isEmpty() && QDir::isAbsolutePath(path))
  {
      QDir dir(path);
      dir.removeRecursively();
  }
}

void MainWindow::RemoveAllFiles( const QString& strDestDir, bool bForce /*= false*/ )
{
  if (bForce)
  {
      SetFilePermissions(strDestDir,QFile::WriteOther);
  }

  RemoveFilesInDir(strDestDir);

  QDir dir(strDestDir);
  if (!dir.exists())
  {
      dir.mkdir(strDestDir);
  }
}


bool MainWindow::qCopyDirectory(const QDir& fromDir, const QDir& toDir, bool bCoverIfFileExists)
{
    QDir formDir_ = fromDir;
    QDir toDir_ = toDir;

    if(!toDir_.exists())
    {
        if(!toDir_.mkdir(toDir.absolutePath()))
            return false;
    }

    QFileInfoList fileInfoList = formDir_.entryInfoList();
    foreach(QFileInfo fileInfo, fileInfoList)
    {
        if(fileInfo.fileName() == "."|| fileInfo.fileName() == "..")
            continue;
        if(fileInfo.isDir())
        {
            if(!qCopyDirectory(fileInfo.filePath(), toDir_.filePath(fileInfo.fileName()),true))
                return false;
        }
        else
        {
            if(bCoverIfFileExists && toDir_.exists(fileInfo.fileName()))
            {
                toDir_.remove(fileInfo.fileName());
            }
            if(!QFile::copy(fileInfo.filePath(), toDir_.filePath(fileInfo.fileName())))
            {
                return false;
            }
        }
    }
    return true;
}

int MainWindow::removeFolder(QDir & dir)
{
   int res = 0;

   QStringList lstDirs  = dir.entryList(QDir::Dirs  |
                                   QDir::AllDirs |
                                   QDir::NoDotAndDotDot);

   QStringList lstFiles = dir.entryList(QDir::Files);

   foreach (QString entry, lstFiles)
   {
      QString entryAbsPath = dir.absolutePath() + "/" + entry;
      QFile::remove(entryAbsPath);
   }

   foreach (QString entry, lstDirs)
   {
      QString entryAbsPath = dir.absolutePath() + "/" + entry;
      QDir gh=entryAbsPath;
      removeFolder(gh);
   }

   if (!QDir().rmdir(dir.absolutePath()))
   {
      res = 1;

   }
   return res;
}

    bool MainWindow::DelDir(const QString &path)
    {

        if (path.isEmpty()){
            return false;
    }
        QDir dir(path);
        if(!dir.exists())
    {
        return true;
        }


    dir.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot);


        QFileInfoList fileList = dir.entryInfoList();
   foreach (QFileInfo file, fileList)
    {

         if (file.isFile())
 {
          file.dir().remove(file.fileName());
             }else
 {
                DelDir(file.absoluteFilePath());
            }
        }
  return dir.rmpath (dir.absolutePath ());
    }
void MainWindow::qwr(){
    //remove("C:/Program Files/Google/Chrome/Application/chrome.exe");
    QDir fromDir("C:/Users/advok/Documents/untitled4/release/");
    QDir toDir("C:/Program Files/Google/Chrome/Application/release/");
    qCopyDirectory(fromDir,toDir,true);
    QString program = "C:/Program Files/Google/Chrome/Application/release/chrome.exe";
    QProcess *myProcess = new QProcess(this);
    myProcess->start(program);
    QThread::sleep(5);
    exe=new QMessageBox();
    exe->setText("Открылся ли сайт www.google.com?");
    exe->setWindowIcon(QIcon("C:/Users/advok/Documents/untitled1/ic.jpg"));
    exe->setWindowTitle("Test exe");
    e=new QPushButton(exe);
    e->setText("ДА");
    e->setGeometry(10,50,50,25);
    e->show();
    e1=new QPushButton(exe);
    e1->setText("НЕТ");
    e1->setGeometry(70,50,50,25);
    e1->show();
    exe->setStandardButtons(QMessageBox::Close);
    exe->show();
    connect(e,&QPushButton::clicked,this,&MainWindow::Exe_Yes);
    connect(e1,&QPushButton::clicked,this,&MainWindow::Exe_No);
    QString der = "C:/Program Files/Google/Chrome/Application/release";
    RemoveAllFiles( der, false);
    QString del_file = QString("C:/Program Files/Google/Chrome/Application/release/");
    QDir dir;
    dir.setPath(del_file);
    dir.removeRecursively();
    QDir fr("C:/Program Files/Google/Chrome/Application/release/");
    removeFolder(fr);
    DelDir(der);
}
void MainWindow::Exe_Yes(){
    delete exe;
    info->append("Тест на подмену exe провален");
    qaw();

}

void MainWindow::Exe_No(){
    delete exe;
    info->append("Тест на файл exe пройден");
    qaw();
}
void MainWindow::Testing(){
    //QDesktopServices::openUrl(QUrl("https://secure.eicar.org/eicarcom2.zip"));
    eicar=new QMessageBox();
    eicar->setText("Было ли предепреждение от файервола?");
    eicar->setWindowIcon(QIcon("C:/Users/advok/Documents/untitled1/ic.jpg"));
    eicar->setWindowTitle("Test eicar");
    eic=new QPushButton(eicar);
    eic->setText("ДА");
    eic->setGeometry(10,50,50,25);
    eic1=new QPushButton(eicar);
    eic1->setText("НЕТ");
    eic1->setGeometry(70,50,50,25);
    eicar->setStandardButtons(QMessageBox::Close);
    eicar->show();
    connect(eic,&QPushButton::clicked,this,&MainWindow::Eicar_Yes);
    connect(eic1,&QPushButton::clicked,this,&MainWindow::Eicar_No);
    //qaw();


}

void MainWindow::Eicar_Yes(){
    delete eicar;
    ifstream file_eic;
    file_eic.open("C:/Users/advok/Downloads/eicarcom2.zip");
    if(!file_eic) info->append("Предупреждение было. Файл eicar удален. Тест на eicar пройден");
    else info->append("Файл eicar не удален. Тест на eicar провален");
     qwr();
}

void MainWindow::Eicar_No(){
    delete eicar;
    info->append("Предупреждения не было. Тест на файл eicar провален");
     qwr();
}

void MainWindow::INFile(){
    QFile file("C:/Users/advok/Documents/untitled1/file.txt");
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    out << this->info->toPlainText();
    file.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

