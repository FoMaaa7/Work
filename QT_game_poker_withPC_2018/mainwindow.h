#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QImage>
#include <QLabel>
#include <QtMultimedia/QSound>
#include <QTimer>
#include <QPropertyAnimation>
#include <QCheckBox>
#include <QLineEdit>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
   QPushButton *klikforstart;
   QPushButton *razdat;
    QPushButton *razdat1;
    QPushButton *razdat2;
    QPushButton *razdat3;
   QPushButton *chek;
   QPushButton *stavka;
   QPushButton *st10;
   QPushButton *st20;
   QPushButton *st50;
   QPushButton *st100;
   QPushButton *st500;
   QPushButton *podnat;
   QPushButton *pass;
   QPushButton *pass1;
   QPushButton *passs;
   QPushButton *stava;
   QPushButton *cek;
   QImage *i;
   QImage *i1;
   QImage *i2;
   QImage *i3;
   QImage *i4;
   QImage *i5;
   QImage *i6;
   QImage *i7;
   QImage *i8;
   QImage *i9;
   QImage *i10;
   QImage *i11;
   QImage *i0;
   QImage *i00;
   QImage *i01;
   QImage *i010;
   QLabel *image;
   QLabel *image1;
   QLabel *image2;
   QLabel *image3;
   QLabel *image4;
   QLabel *image5;
   QLabel *image6;
   QLabel *image7;
   QLabel *image8;
   QLabel *image9;
   QLabel *image10;
   QLabel *image11;
   QLabel *image01;
   QLabel *image0;
   QLabel *image00;
   QLabel *image010;
   QTimer *size_set;
   QTimer *formusic;
   QTimer *set_fishki;
   QTimer *stt10;
   QPropertyAnimation *anim;
   QPropertyAnimation *anim1;
   QPropertyAnimation *anim2;
   QPropertyAnimation *anim3;
   QPropertyAnimation *anim4;
   QPropertyAnimation *anim5;
   QPropertyAnimation *anim6;
   QPropertyAnimation *anim7;
   QPropertyAnimation *anim8;
   QPropertyAnimation *anim9;
   QPropertyAnimation *anim10;
    QPropertyAnimation *anim101;
   QSound *music;
   QCheckBox *a;
   QCheckBox *b;
   QCheckBox *c;
   QCheckBox *d;
   QCheckBox *e;
   QTimer *time;
   QLineEdit *fishki;
   QLineEdit *stav;
   QLineEdit *stav1;
   QLineEdit *stav2;
   QLineEdit *win;
   int k=0;
   int k1=0;
   int k2=0;
   int k3=0;
   int k4=0;
   int inform;
   int uroven=0;
   QString lol;
   QString lol1;
   QString lol2;
   QString lol3;
   QString lol4;
   QString lol5;
   QString lol6;
   //QString lol7;
  // QString lol8;
  // QString lol9;
  // QString lol10;
   int l1=0;
   int l2=0;
   int l3=0;
   int l4=0;
   int l5=0;
   int l6=0;
   int l7=0;
   int l8=0;
   int l9=0;
   int l10=0;
   int l11=0;
   int K=0;
   char arr[52][200]={"C:/Users/Anton Vodichenkov/Documents/untitled5/1.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/2.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/3.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/4.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/5.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/6.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/7.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/8.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/9.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/10.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/11.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/12.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/13.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/14.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/15.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/16.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/17.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/18.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/19.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/20.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/21.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/22.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/23.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/24.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/25.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/26.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/27.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/28.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/29.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/30.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/31.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/32.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/33.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/34.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/35.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/36.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/37.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/38.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/39.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/40.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/41.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/42.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/43.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/44.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/45.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/46.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/47.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/48.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/49.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/50.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/51.JPG","C:/Users/Anton Vodichenkov/Documents/untitled5/52.JPG"};
private:
    Ui::MainWindow *ui;
private slots:
    void Start();
    void s_set();
    void Delete();
    void PlayMusic();
    void Razdacha();
    void Razdat();
    void Stavki();
    void St10();
    void St20();
    void St50();
    void St100();
    void St500();
    void Chek();
    void Check();
    void A();
    void B();
    void C();
    void D();
    void E();
    void Podnat();
    void Pass();
    void Razdat1();
    void Pass1();
    void Stava();
    void Passs();
    void Cek();
    void Razdat2();
    void Stava1();
    void Passs1();
    void Cek1();
};

#endif // MAINWINDOW_H
