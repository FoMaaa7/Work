#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>
#include <QTime>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QTime midnight (0,0,0);
    qsrand (midnight.secsTo(QTime::currentTime()));
    ui->setupUi(this);
    this->resize(1600,900);
    this->setWindowTitle("Покер");
    image=new QLabel(this);
    i=new QImage("C:/Users/Anton Vodichenkov/Documents/untitled5/Без имени.png");
    QImage podng=i->scaled(1600,900,Qt::IgnoreAspectRatio);
    image->show();
    image->resize(1600,900);
    image->setPixmap(QPixmap::fromImage(podng,Qt::AutoColor));
    music= new QSound("C:/Users/Anton Vodichenkov/Documents/untitled5/W.wav");
    a= new QCheckBox (this);
    b= new QCheckBox (this);
    c= new QCheckBox (this);
    d= new QCheckBox (this);
    e= new QCheckBox (this);
    a->setText("Уровень 1");
    b->setText("Уровень 2");
    c->setText("Уровень 3");
    d->setText("Уровень 4");
    e->setText("Уровень 5");
    a->setGeometry(10,10,300,100);
    b->setGeometry(10,50,300,100);
    c->setGeometry(10,90,300,100);
    d->setGeometry(10,130,300,100);
    e->setGeometry(10,170,300,100);
    a->show();
    b->show();
    c->show();
    d->show();
    e->show();
    a->setChecked(true);
    connect (a, SIGNAL(clicked()), this, SLOT (A()));
    connect (b, SIGNAL(clicked()), this, SLOT (B()));
    connect (c, SIGNAL(clicked()), this, SLOT (C()));
    connect (d, SIGNAL(clicked()), this, SLOT (D()));
    connect (e, SIGNAL(clicked()), this, SLOT (E()));
    klikforstart=new QPushButton (this);
    klikforstart->setText("Играть");
    klikforstart->setGeometry(800,450,100,50);
    klikforstart->show();
    size_set=new QTimer();
    size_set->start(1000);
    connect(size_set,SIGNAL(timeout()),this,SLOT (s_set()));
    connect(klikforstart, SIGNAL(clicked()), this, SLOT(Start()));

}
MainWindow::~MainWindow()
{
    delete ui;
}
void  MainWindow::Start()
{
    anim=new QPropertyAnimation(klikforstart,"geometry");
    anim->setDuration(1000);
    anim->setEasingCurve(QEasingCurve::Linear);
    anim->setStartValue(QRect(800,450,100,50));
    anim->setEndValue(QRect(800,750,100,50));
    anim->start();
    klikforstart->setText("Раздать");
    connect(klikforstart,SIGNAL(clicked()),this, SLOT (Razdacha()));
    connect(klikforstart, SIGNAL(clicked()),this, SLOT (Delete()));

}
void MainWindow::Delete()
{
    klikforstart->hide();
    delete klikforstart;
    connect (klikforstart,SIGNAL(clicked()), this, SLOT (Razdacha()));
}
void MainWindow::s_set()
{
    this->resize(1600,900);
}
void MainWindow::PlayMusic()
{
    formusic->start(30000);
}
void MainWindow::Razdacha(){
    image00= new QLabel(this);
    i00= new QImage("C:/Users/Anton Vodichenkov/Documents/untitled5/рубашка.jpg");
    image00->setGeometry(1400,150,150,250);
    QImage podng00=i00->scaled(150,250,Qt::IgnoreAspectRatio);
    image00->show();
    image00->resize(150,250);
    image00->setPixmap(QPixmap::fromImage(podng00, Qt::AutoColor));
    image1= new QLabel(this);
    l5=qrand() % 52;
    lol=arr[l5];
    i1= new QImage(lol);
    image1->setGeometry(700,650,150,250);
    QImage podng1=i1->scaled(150,250,Qt::IgnoreAspectRatio);
    image1->show();
    image1->resize(150,250);
    image1->setPixmap(QPixmap::fromImage(podng1, Qt::AutoColor));
    anim1=new QPropertyAnimation(image1,"geometry");
    anim1->setDuration(1000);
    anim1->setEasingCurve(QEasingCurve::Linear);
    anim1->setStartValue(QRect(1400,150,150,250));
    anim1->setEndValue(QRect(700,650,150,250));
    anim1->start();
    image2= new QLabel(this);
    l6=qrand() % 52;
    while (l6==l5)
    {
      l6=qrand() % 52;
    }
    lol1=arr[l6];
    i2= new QImage(lol1);
    image2->setGeometry(780,650,150,250);
    QImage podng2=i2->scaled(150,250,Qt::IgnoreAspectRatio);
    image2->show();
    image2->resize(150,250);
    image2->setPixmap(QPixmap::fromImage(podng2, Qt::AutoColor));
    anim2=new QPropertyAnimation(image2,"geometry");
    anim2->setDuration(1000);
    anim2->setEasingCurve(QEasingCurve::Linear);
    anim2->setStartValue(QRect(1400,150,150,250));
    anim2->setEndValue(QRect(780,650,150,250));
    anim2->start();
    image3= new QLabel(this);
    i3= new QImage("C:/Users/Anton Vodichenkov/Documents/untitled5/рубашка.jpg");
    image3->setGeometry(300,500,250,150);
    QImage podng3=i3->scaled(250,150,Qt::IgnoreAspectRatio);
    image3->show();
    image3->resize(250,150);
    image3->setPixmap(QPixmap::fromImage(podng3, Qt::AutoColor));
    anim3=new QPropertyAnimation(image3,"geometry");
    anim3->setDuration(1000);
    anim3->setEasingCurve(QEasingCurve::Linear);
    anim3->setStartValue(QRect(1400,150,250,150));
    anim3->setEndValue(QRect(300,500,250,150));
    anim3->start();
    image4= new QLabel(this);
    i4= new QImage("C:/Users/Anton Vodichenkov/Documents/untitled5/рубашка.jpg");
    image4->setGeometry(300,550,250,150);
    QImage podng4=i4->scaled(250,150,Qt::IgnoreAspectRatio);
    image4->show();
    image4->resize(250,150);
    image4->setPixmap(QPixmap::fromImage(podng4, Qt::AutoColor));
    anim4=new QPropertyAnimation(image4,"geometry");
    anim4->setDuration(1000);
    anim4->setEasingCurve(QEasingCurve::Linear);
    anim4->setStartValue(QRect(1400,150,250,150));
    anim4->setEndValue(QRect(300,550,250,150));
    anim4->start();
    image5= new QLabel(this);
    i5= new QImage("C:/Users/Anton Vodichenkov/Documents/untitled5/рубашка.jpg");
    image5->setGeometry(1100,500,250,150);
    QImage podng5=i5->scaled(250,150,Qt::IgnoreAspectRatio);
    image5->show();
    image5->resize(250,150);
    image5->setPixmap(QPixmap::fromImage(podng5, Qt::AutoColor));
    anim5=new QPropertyAnimation(image5,"geometry");
    anim5->setDuration(1000);
    anim5->setEasingCurve(QEasingCurve::Linear);
    anim5->setStartValue(QRect(1400,150,250,150));
    anim5->setEndValue(QRect(1100,500,250,150));
    anim5->start();
    image6= new QLabel(this);
    i6= new QImage("C:/Users/Anton Vodichenkov/Documents/untitled5/рубашка.jpg");
    image6->setGeometry(1100,550,250,150);
    QImage podng6=i6->scaled(250,150,Qt::IgnoreAspectRatio);
    image6->show();
    image6->resize(250,150);
    image6->setPixmap(QPixmap::fromImage(podng6, Qt::AutoColor));
    anim6=new QPropertyAnimation(image6,"geometry");
    anim6->setDuration(1000);
    anim6->setEasingCurve(QEasingCurve::Linear);
    anim6->setStartValue(QRect(1400,150,250,150));
    anim6->setEndValue(QRect(1100,550,250,150));
    anim6->start();
    image0= new QLabel(this);
    i0= new QImage("C:/Users/Anton Vodichenkov/Documents/untitled5/фишка.jpg");
    image0->setGeometry(1500,800,75,75);
    QImage podng0=i0->scaled(75,75,Qt::IgnoreAspectRatio);
    image0->show();
    image0->resize(75,75);
    image0->setPixmap(QPixmap::fromImage(podng0, Qt::AutoColor));
    fishki= new QLineEdit(this);
    fishki->setGeometry(1500,775,75,30);
    fishki->setText("1150");
    fishki->show();
    set_fishki= new QTimer();
    set_fishki->start(1000);
    connect (set_fishki,SIGNAL(timeout()),this,SLOT (Chek()));
    music->play();
    razdat= new QPushButton (this);
    razdat->setText("Разложить");
    razdat->setGeometry(800,100,150,50);
    razdat->show();
    connect(razdat, SIGNAL(clicked()), this, SLOT(Razdat()));
}
void MainWindow::Razdat()
{
    delete razdat;
    image7= new QLabel(this);
    l7=qrand() % 52;
    while ((l7==l5)||(l7==l6))
    {
       l7=qrand() % 52;
    }
    lol2=arr[l7];
    i7= new QImage(lol2);
    image7->setGeometry(450,100,150,250);
    QImage podng7=i7->scaled(150,250,Qt::IgnoreAspectRatio);
    image7->show();
    image7->resize(150,250);
    image7->setPixmap(QPixmap::fromImage(podng7, Qt::AutoColor));
    anim7=new QPropertyAnimation(image7,"geometry");
    anim7->setDuration(800);
    anim7->setEasingCurve(QEasingCurve::Linear);
    anim7->setStartValue(QRect(1400,150,150,250));
    anim7->setEndValue(QRect(450,100,150,250));
    anim7->start();
    image8= new QLabel(this);
    l8=qrand() % 52;
    while ((l8==l5)||(l8==l6)||(l8==l7))
    {
        l8=qrand() % 52;
    }
     lol3=arr[l8];
    i8= new QImage(lol3);
    image8->setGeometry(610,100,150,250);
    QImage podng8=i8->scaled(150,250,Qt::IgnoreAspectRatio);
    image8->show();
    image8->resize(150,250);
    image8->setPixmap(QPixmap::fromImage(podng8, Qt::AutoColor));
    anim8=new QPropertyAnimation(image8,"geometry");
    anim8->setDuration(800);
    anim8->setEasingCurve(QEasingCurve::Linear);
    anim8->setStartValue(QRect(1400,150,150,250));
    anim8->setEndValue(QRect(610,100,150,250));
    anim8->start();
    image9= new QLabel(this);
    l9=qrand() % 52;
    while ((l9==l5)||(l9==l6)||(l9==l7)||(l9==l8))
    {
        l9=qrand() % 52;
    }
    lol4=arr[l9];
    i9= new QImage(lol4);
    image9->setGeometry(770,100,150,250);
    QImage podng9=i9->scaled(150,250,Qt::IgnoreAspectRatio);
    image9->show();
    image9->resize(150,250);
    image9->setPixmap(QPixmap::fromImage(podng9, Qt::AutoColor));
    anim9=new QPropertyAnimation(image9,"geometry");
    anim9->setDuration(800);
    anim9->setEasingCurve(QEasingCurve::Linear);
    anim9->setStartValue(QRect(1400,150,150,250));
    anim9->setEndValue(QRect(770,100,150,250));
    anim9->start();
    stavka=new QPushButton(this);
    chek=new QPushButton (this);
    stavka->setGeometry(100,800,100,50);
    stavka->show();
    stavka->setText("Ставка");
    chek->setGeometry(100,850,100,50);
    chek->setText("Чек");
    chek->show();
    connect(stavka,SIGNAL(clicked()),this, SLOT(Stavki()));
    connect (chek, SIGNAL(clicked()),this, SLOT (Check()));
    pass1=new QPushButton(this);
    pass1->setGeometry(100,750,100,50);
    pass1->setText("Пас");
    pass1->show();
    connect(pass1,SIGNAL(clicked()),this, SLOT(Pass1()));
}
void MainWindow::Stavki()
{
    delete stavka;
    stav= new QLineEdit(this);
    stav->setGeometry(800,600,75,30);
    stav->show();
    st10= new QPushButton(this);
    st20= new QPushButton(this);
    st50= new QPushButton(this);
    st100= new QPushButton(this);
    st500= new QPushButton(this);
    st10->setGeometry(25,800,50,50);
    st10->setText("10");
    st20->setGeometry(75,800,50,50);
    st20->setText("20");
    st50->setGeometry(125,800,50,50);
    st50->setText("50");
    st100->setGeometry(175,800,50,50);
    st100->setText("100");
    st500->setGeometry(225,800,50,50);
    st500->setText("500");
    st10->show();
    st20->show();
    st50->show();
    st100->show();
    st500->show();
    connect(st10,SIGNAL(clicked()), this, SLOT(St10()));
    connect(st20,SIGNAL(clicked()), this, SLOT(St20()));
    connect(st50,SIGNAL(clicked()), this, SLOT(St50()));
    connect(st100,SIGNAL(clicked()), this, SLOT(St100()));
    connect(st500,SIGNAL(clicked()), this, SLOT(St500()));
}
void MainWindow::St10()
{
    k=k+10;
    QString str = QString::number(k);
    stav->setText(str);
    bool ok;
  k1=str.toInt(&ok,10);
}
void MainWindow::St20()
{
     k=k+20;
     QString str = QString::number(k);
     stav->setText(str);
     bool ok;
   k1=str.toInt(&ok,10);
}
void MainWindow::St50()
{
    k=k+50;
    QString str = QString::number(k);
    stav->setText(str);
    bool ok;
  k1=str.toInt(&ok,10);
}
void MainWindow::St100()
{
    k=k+100;
    QString str = QString::number(k);
    stav->setText(str);
    bool ok;
  k1=str.toInt(&ok,10);
}
void MainWindow::St500()
{
    k=k+500;
    QString str = QString::number(k);
    stav->setText(str);
     bool ok;
   k1=str.toInt(&ok,10);
}
void MainWindow::Chek()
{
    inform=1150;
    inform=inform-k1;
    QString str1 = QString::number(inform);
    fishki->setText(str1);
}
void MainWindow::Check()
{
   delete st10;
   delete st20;
    delete st50;
    delete st100;
    delete st500;
    delete chek;
     delete pass1;
    l1=qrand() % 52;
    while ((l1==l5)||(l1==l6)||(l1==l7)||(l1==l8)||(l1==l9))
    {
        l1=qrand() % 52;
    }
    l2=qrand() % 52;
    while ((l2==l5)||(l2==l6)||(l2==l7)||(l2==l8)||(l2==l9)||(l2==l1))
    {
        l2=qrand() % 52;
    }
    l3=qrand() % 52;
    while ((l3==l5)||(l3==l6)||(l3==l7)||(l3==l8)||(l3==l9)||(l3==l1)||(l3==l2))
    {
        l3=qrand() % 52;
    }
    l4=qrand() % 52;
    while ((l4==l5)||(l4==l6)||(l4==l7)||(l4==l8)||(l4==l9)||(l4==l1)||(l4==l2)||(l4==l3))
    {
        l4=qrand() % 52;
    }
    if (((((l1>l7)&&(l1>l8)&&(l1>l9))||((l2>l7)&&(l2>l8)&&(l2>l9))))&&(k1<15))
    {
      k2=10;
    }
    if((((((abs(l1-l7)<4)||(abs(l1-l8)<4)||(abs(l1-l9)<4))||((abs(l2-l7)<4)||(abs(l2-l8)<4)||(abs(l2-l9)<4)||(abs(l1-l2)<4))))))
    {
        k2=20;
    }
    if ((((abs(l1-l7)<4)||(abs(l1-l8)<4)||(abs(l1-l9)<4))&&((abs(l2-l7)<4)||(abs(l2-l8)<4)||(abs(l2-l9)<4)))|| ((abs(l1-l2)<4)&&((abs(l7-l8)<4)||(abs(l7-l9)<4)||(abs(l8-l9)<4))))
    {
        k2=40;
    }
    if ( ((abs(l1-l7)<4)&&(abs(l1-l8)<4)) || ((abs(l1-l8)<4)&&(abs(l1-l9)<4)) || ((abs(l1-l7)<4)&&(abs(l1-l9)<4)) || ((abs(l2-l7)<4)&&(abs(l2-l8)<4)) || ((abs(l2-l8)<4)&&(abs(l2-l9)<4)) || ((abs(l2-l7)<4)&&(abs(l2-l9)<4)) ||( (abs(l1-l2)<4)&&((abs(l1-l8)<4)||(abs(l1-l7)<4)||(abs(l1-l9)<4))) )
    {
        k2=50;
    }
    if (((abs(l1/4-l2/4)==1)&& ((abs(l2/4-l7/4)==1)||(abs(l2/4-l8/4)==1)||(abs(l2/4-l9/4)==1))) || ((abs(l1/4-l7/4)==1)&& ((abs(l7/4-l2/4)==1)||(abs(l7/4-l8/4)==1)||(abs(l7/4-l9/4)==1))) || ((abs(l1/4-l8/4)==1)&& ((abs(l8/4-l2/4)==1)||(abs(l8/4-l7/4)==1)||(abs(l8/4-l9/4)==1))) || ((abs(l1/4-l9/4)==1)&& ((abs(l9/4-l2/4)==1)||(abs(l9/4-l8/4)==1)||(abs(l9/4-l7/4)==1))))
    {
        k2=30; //3cart
    }
    if (((abs(l1-l2)%4==0) && ((abs(l1-l7)%4==0)||(abs(l1-l8)%4==0)||(abs(l1-l9)%4==0))) || ((abs(l1-l7)%4==0)&&((abs(l1-l8)%4==0)||(abs(l1-l9)%4==0))) || ((abs(l2-l7)%4==0)&&((abs(l2-l8)%4==0)||(abs(l2-l9)%4==0))))
    {
       k2=60;     //3
    }
    if (((((l3>l7)&&(l3>l8)&&(l3>l9))||((l4>l7)&&(l4>l8)&&(l4>l9))))&&(k1<15))
    {
      k3=10;
    }
    if((((((abs(l3-l7)<4)||(abs(l3-l8)<4)||(abs(l3-l9)<4))||((abs(l4-l7)<4)||(abs(l4-l8)<4)||(abs(l4-l9)<4)||(abs(l3-l2)<4))))))
    {
        k3=20;
    }
    if ((((abs(l3-l7)<4)||(abs(l3-l8)<4)||(abs(l3-l9)<4))&&((abs(l4-l7)<4)||(abs(l4-l8)<4)||(abs(l4-l9)<4)))|| ((abs(l3-l4)<4)&&((abs(l7-l8)<4)||(abs(l7-l9)<4)||(abs(l8-l9)<4))))
    {
        k3=40;
    }
    if ( ((abs(l3-l7)<4)&&(abs(l3-l8)<4)) || ((abs(l3-l8)<4)&&(abs(l3-l9)<4)) || ((abs(l3-l7)<4)&&(abs(l3-l9)<4)) || ((abs(l4-l7)<4)&&(abs(l4-l8)<4)) || ((abs(l4-l8)<4)&&(abs(l4-l9)<4)) || ((abs(l4-l7)<4)&&(abs(l4-l9)<4)) ||( (abs(l3-l4)<4)&&((abs(l3-l8)<4)||(abs(l3-l7)<4)||(abs(l3-l9)<4))) )
    {
        k3=50;
    }
    if (((abs(l3/4-l4/4)==1)&& ((abs(l4/4-l7/4)==1)||(abs(l4/4-l8/4)==1)||(abs(l4/4-l9/4)==1))) || ((abs(l3/4-l7/4)==1)&& ((abs(l7/4-l4/4)==1)||(abs(l7/4-l8/4)==1)||(abs(l7/4-l9/4)==1))) || ((abs(l3/4-l8/4)==1)&& ((abs(l8/4-l4/4)==1)||(abs(l8/4-l7/4)==1)||(abs(l8/4-l9/4)==1))) || ((abs(l3/4-l9/4)==1)&& ((abs(l9/4-l4/4)==1)||(abs(l9/4-l8/4)==1)||(abs(l9/4-l7/4)==1))))
    {
        k3=30; //3cart
    }
    if (((abs(l3-l4)%4==0) && ((abs(l3-l7)%4==0)||(abs(l3-l8)%4==0)||(abs(l3-l9)%4==0))) || ((abs(l3-l7)%4==0)&&((abs(l3-l8)%4==0)||(abs(l3-l9)%4==0))) || ((abs(l4-l7)%4==0)&&((abs(l4-l8)%4==0)||(abs(l4-l9)%4==0))))
    {
       k3=60;     //3
    }
    if(((k1<k2)||(k1<k3)))
    {
        podnat=new QPushButton(this);
        pass=new QPushButton (this);
        podnat->setGeometry(100,800,140,50);
        pass->setGeometry(100,850,140,50);
        podnat->setText("Уравнять");
        pass->setText("Пас");
        podnat->show();
        pass->show();
        connect(podnat,SIGNAL(clicked()),this, SLOT(Podnat()));
        connect(pass,SIGNAL(clicked()),this, SLOT(Pass()));
    }

     if((k2<k1)||(k3<k1)) {
    if((k2!=k1)&&(k2>10)&&(k1>k2)&&(k2!=0)&&(k1<110))
    {
        k2=k1;
    }
    else
    {
        k2=0;

    }
    if((k3!=k1)&&(k3>10)&&(k1>k3)&&(k3!=0)&&(k1<2000))
    {
        k3=k1;
     }
    else
    {
        k3=0;

    }
    }
  /*  if ((k2!=k3)&&(k2!=0))
    {
        k2=k3;
    }
    if ((k3!=k2)&&(k3!=0))
    {
        k3=k2;
    } */
    if ((k2!=k3)&&(k2!=0)&&(k2>20))
    {
        k2=k3;
    }
    if ((k3!=k2)&&(k3!=0)&&(k3>20))
    {
        k3=k2;
    }
    stav1= new QLineEdit(this);
    stav1->setGeometry(450,450,75,30);
    stav1->show();
    stav2= new QLineEdit(this);
    stav2->setGeometry(1100,450,75,30);
    stav2->show();
    QString str15=QString::number(k2);
    stav1->setText(str15);
    QString str16=QString::number(k3);
    stav2->setText(str16);
    if (k2==0)
    {
        stav1->setText("Пас");
    }
    if (k3==0)
    {
        stav2->setText("Пас");
    }


    if ((k2==0)&&(k3==0)&&(k1!=0))
    {
        win= new QLineEdit(this);
        win->setGeometry(500,25,150,50);
        win->setText("Победа");
        win->show();
        inform=inform+(k2+k3+k1);
    }
    else
    {
    razdat1=new QPushButton(this);
    razdat1->setGeometry(800,25,150,50);
    razdat1->setText("Раздать");
    razdat1->show();
    connect(razdat1,SIGNAL(clicked()),this,SLOT(Razdat1()));
    }
}
void MainWindow::A()
{
    b->setChecked(false);
    c->setChecked(false);
    d->setChecked(false);
    e->setChecked(false);
    uroven=1;
}
void MainWindow::B()
{
    a->setChecked(false);
    c->setChecked(false);
    d->setChecked(false);
    e->setChecked(false);
    uroven=2;
}
void MainWindow::C()
{
    a->setChecked(false);
    b->setChecked(false);
    d->setChecked(false);
    e->setChecked(false);
    uroven=3;
}
void MainWindow::D()
{
    a->setChecked(false);
    b->setChecked(false);
    c->setChecked(false);
    e->setChecked(false);
    uroven=4;
}
void MainWindow::E()
{
    a->setChecked(false);
    b->setChecked(false);
    d->setChecked(false);
    c->setChecked(false);
    uroven=5;
}

void MainWindow::Podnat()
{
    delete podnat;
    delete pass;
    if (k1<k3)
    {
        k1=k3;
    }
    if (k1<k2)
    {
        k1=k2;
    }
    QString str17=QString::number(k1);
    stav->setText(str17);
}
void MainWindow::Pass()
{
    delete podnat;
    delete pass;
    stav->setText("Пас");
}
void MainWindow::Razdat1()
{

    delete razdat1;
    l10=qrand() % 52;
    while ((l10==l5)||(l10==l6)||(l10==l7)||(l10==l8)||(l10==l9)||(l10==l1)||(l10==l2)||(l10==l3))
    {
        l10=qrand() % 52;
    }
    lol5=arr[l10];
    image01=new QLabel(this);
    i01= new QImage(lol5);
    image01->setGeometry(930,100,150,250);
    QImage podng00=i01->scaled(150,250,Qt::IgnoreAspectRatio);
    image01->show();
    image01->resize(150,250);
    image01->setPixmap(QPixmap::fromImage(podng00, Qt::AutoColor));
    anim10=new QPropertyAnimation(image01,"geometry");
    anim10->setDuration(800);
    anim10->setEasingCurve(QEasingCurve::Linear);
    anim10->setStartValue(QRect(1400,150,150,250));
    anim10->setEndValue(QRect(930,100,150,250));
    anim10->start();
    if (k1!=0)
    {
    stava= new QPushButton(this);
    cek= new QPushButton(this); 
    stava->setText("Ставка");
    cek->setText("Чек");
    stava->setGeometry(100,800,100,50);
    stava->show();
    cek->setGeometry(100,850,100,50);
    cek->show();
    connect(stava,SIGNAL(clicked()),this,SLOT(Stava()));
    connect(cek,SIGNAL(clicked()),this,SLOT(Cek()));  
    }
    passs= new QPushButton(this);
    passs->setText("Пас");
    passs->setGeometry(100,750,100,50);
    passs->show();
    connect(passs,SIGNAL(clicked()),this,SLOT(Passs()));
}
void MainWindow::Pass1()
{
    k1=0;
    stav= new QLineEdit(this);
    stav->setGeometry(800,600,75,30);
    stav->setText("Пас");
    stav->show();
    win= new QLineEdit(this);
    win->setGeometry(500,25,150,50);
    win->setText("Поражение");
    win->show();
   delete pass1;
    delete chek;
    delete stavka;
    l1=qrand() % 52;
    while ((l1==l5)||(l1==l6)||(l1==l7)||(l1==l8)||(l1==l9))
    {
        l1=qrand() % 52;
    }
    l2=qrand() % 52;
    while ((l2==l5)||(l2==l6)||(l2==l7)||(l2==l8)||(l2==l9)||(l2==l1))
    {
        l2=qrand() % 52;
    }
    l3=qrand() % 52;
    while ((l3==l5)||(l3==l6)||(l3==l7)||(l3==l8)||(l3==l9)||(l3==l1)||(l3==l2))
    {
        l3=qrand() % 52;
    }
    l4=qrand() % 52;
    while ((l4==l5)||(l4==l6)||(l4==l7)||(l4==l8)||(l4==l9)||(l4==l1)||(l4==l2)||(l4==l3))
    {
        l4=qrand() % 52;
    }
    if (((((l1>l7)&&(l1>l8)&&(l1>l9))||((l2>l7)&&(l2>l8)&&(l2>l9))))&&(k1<15))
    {
      k2=10;
    }
    if((((((abs(l1-l7)<4)||(abs(l1-l8)<4)||(abs(l1-l9)<4))||((abs(l2-l7)<4)||(abs(l2-l8)<4)||(abs(l2-l9)<4)||(abs(l1-l2)<4))))))
    {
        k2=20;
    }
    if ((((abs(l1-l7)<4)||(abs(l1-l8)<4)||(abs(l1-l9)<4))&&((abs(l2-l7)<4)||(abs(l2-l8)<4)||(abs(l2-l9)<4)))|| ((abs(l1-l2)<4)&&((abs(l7-l8)<4)||(abs(l7-l9)<4)||(abs(l8-l9)<4))))
    {
        k2=40;
    }
    if ( ((abs(l1-l7)<4)&&(abs(l1-l8)<4)) || ((abs(l1-l8)<4)&&(abs(l1-l9)<4)) || ((abs(l1-l7)<4)&&(abs(l1-l9)<4)) || ((abs(l2-l7)<4)&&(abs(l2-l8)<4)) || ((abs(l2-l8)<4)&&(abs(l2-l9)<4)) || ((abs(l2-l7)<4)&&(abs(l2-l9)<4)) ||( (abs(l1-l2)<4)&&((abs(l1-l8)<4)||(abs(l1-l7)<4)||(abs(l1-l9)<4))) )
    {
        k2=50;
    }
    if (((abs(l1/4-l2/4)==1)&& ((abs(l2/4-l7/4)==1)||(abs(l2/4-l8/4)==1)||(abs(l2/4-l9/4)==1))) || ((abs(l1/4-l7/4)==1)&& ((abs(l7/4-l2/4)==1)||(abs(l7/4-l8/4)==1)||(abs(l7/4-l9/4)==1))) || ((abs(l1/4-l8/4)==1)&& ((abs(l8/4-l2/4)==1)||(abs(l8/4-l7/4)==1)||(abs(l8/4-l9/4)==1))) || ((abs(l1/4-l9/4)==1)&& ((abs(l9/4-l2/4)==1)||(abs(l9/4-l8/4)==1)||(abs(l9/4-l7/4)==1))))
    {
        k2=30; //3cart
    }
    if (((abs(l1-l2)%4==0) && ((abs(l1-l7)%4==0)||(abs(l1-l8)%4==0)||(abs(l1-l9)%4==0))) || ((abs(l1-l7)%4==0)&&((abs(l1-l8)%4==0)||(abs(l1-l9)%4==0))) || ((abs(l2-l7)%4==0)&&((abs(l2-l8)%4==0)||(abs(l2-l9)%4==0))))
    {
       k2=60;     //3
    }
    if (((((l3>l7)&&(l3>l8)&&(l3>l9))||((l4>l7)&&(l4>l8)&&(l4>l9))))&&(k1<15))
    {
      k3=10;
    }
    if((((((abs(l3-l7)<4)||(abs(l3-l8)<4)||(abs(l3-l9)<4))||((abs(l4-l7)<4)||(abs(l4-l8)<4)||(abs(l4-l9)<4)||(abs(l3-l2)<4))))))
    {
        k3=20;
    }
    if ((((((abs(l3-l7)<4)||(abs(l3-l8)<4)||(abs(l3-l9)<4))&&((abs(l4-l7)<4)||(abs(l4-l8)<4)||(abs(l4-l9)<4)))|| ((abs(l3-l4)<4)&&((abs(l7-l8)<4)||(abs(l7-l9)<4)||(abs(l8-l9)<4))))))
    {
        k3=40;
    }
    if (( ((abs(l3-l7)<4)&&(abs(l3-l8)<4)) || ((abs(l3-l8)<4)&&(abs(l3-l9)<4)) || ((abs(l3-l7)<4)&&(abs(l3-l9)<4)) || ((abs(l4-l7)<4)&&(abs(l4-l8)<4)) || ((abs(l4-l8)<4)&&(abs(l4-l9)<4)) || ((abs(l4-l7)<4)&&(abs(l4-l9)<4)) ||( (abs(l3-l4)<4)&&((abs(l3-l8)<4)||(abs(l3-l7)<4)||(abs(l3-l9)<4))) ))
    {
        k3=50;
    }
    if ((((abs(l3/4-l4/4)==1)&& ((abs(l4/4-l7/4)==1)||(abs(l4/4-l8/4)==1)||(abs(l4/4-l9/4)==1))) || ((abs(l3/4-l7/4)==1)&& ((abs(l7/4-l4/4)==1)||(abs(l7/4-l8/4)==1)||(abs(l7/4-l9/4)==1))) || ((abs(l3/4-l8/4)==1)&& ((abs(l8/4-l4/4)==1)||(abs(l8/4-l7/4)==1)||(abs(l8/4-l9/4)==1))) || ((abs(l3/4-l9/4)==1)&& ((abs(l9/4-l4/4)==1)||(abs(l9/4-l8/4)==1)||(abs(l9/4-l7/4)==1)))))
    {
        k3=30; //3cart
    }
    if ((((abs(l3-l4)%4==0) && ((abs(l3-l7)%4==0)||(abs(l3-l8)%4==0)||(abs(l3-l9)%4==0))) || ((abs(l3-l7)%4==0)&&((abs(l3-l8)%4==0)||(abs(l3-l9)%4==0))) || ((abs(l4-l7)%4==0)&&((abs(l4-l8)%4==0)||(abs(l4-l9)%4==0)))))
    {
       k3=60;     //3
    }
   /* else {
        if(k1!=0)
        {
    if((k2!=k1)&&(k2>10)&&(k1>k2)&&(k2!=0)&&(k1<110))
    {
        k2=k1;
    }
    else
    {
        k2=0;

    }
    if((k3!=k1)&&(k3>10)&&(k1>k3)&&(k3!=0)&&(k1<2000))
    {
        k3=k1;
     }
    else
    {
        k3=0;

    }
    }
    } */
    if ((k2!=k3)&&(k2!=0)&&(k2>20))
        //&&((uroven==1)||(uroven==2)||(uroven==3)||(uroven==4)))
    {
        k2=k3;
    }
    if ((k3!=k2)&&(k3!=0)&&(k3>20))
            //&&((uroven==1)||(uroven==2)||(uroven==3)||(uroven==4)))
    {
        k3=k2;
    }

    stav1= new QLineEdit(this);
    stav1->setGeometry(450,450,75,30);
    stav1->show();
    stav2= new QLineEdit(this);
    stav2->setGeometry(1100,450,75,30);
    stav2->show();
    QString str15=QString::number(k2);
    stav1->setText(str15);
    QString str16=QString::number(k3);
    stav2->setText(str16);
    if (k2==0)
    {
        stav1->setText("Пас");
    }
    if (k3==0)
    {
        stav2->setText("Пас");
    }
    if ((k2==0)&&(k3==0)&&(k1==0))
    {
        win= new QLineEdit(this);
        win->setGeometry(500,25,150,50);
        win->setText("Ничья");
        win->show();
        inform=inform+k1;
    }
    else {
    razdat1=new QPushButton(this);
    razdat1->setGeometry(800,25,150,50);
    razdat1->setText("Раздать");
    razdat1->show();
    connect(razdat1,SIGNAL(clicked()),this,SLOT(Razdat1()));
    }
    inform=inform-(k2+k3+k1);
}
void MainWindow::Stava()
{
    delete stava;
    st10= new QPushButton(this);
    st20= new QPushButton(this);
    st50= new QPushButton(this);
    st100= new QPushButton(this);
    st500= new QPushButton(this);
    st10->setGeometry(25,800,50,50);
    st10->setText("10");
    st20->setGeometry(75,800,50,50);
    st20->setText("20");
    st50->setGeometry(125,800,50,50);
    st50->setText("50");
    st100->setGeometry(175,800,50,50);
    st100->setText("100");
    st500->setGeometry(225,800,50,50);
    st500->setText("500");
    st10->show();
    st20->show();
    st50->show();
    st100->show();
    st500->show();
    connect(st10,SIGNAL(clicked()), this, SLOT(St10()));
    connect(st20,SIGNAL(clicked()), this, SLOT(St20()));
    connect(st50,SIGNAL(clicked()), this, SLOT(St50()));
    connect(st100,SIGNAL(clicked()), this, SLOT(St100()));
    connect(st500,SIGNAL(clicked()), this, SLOT(St500()));
}
void MainWindow::Cek()
{
    delete st10;
    delete st20;
     delete st50;
     delete st100;
     delete st500;
     delete cek;
      delete passs;
    if ((abs(l1-l10)<4)||(abs(l2-l10)<4))
    {
        k2=k2+20;
    }
    if (((abs(l1/4-l2/4)==1)&& ((abs(l2/4-l7/4)==1)||(abs(l2/4-l8/4)==1)||(abs(l2/4-l9/4)==1))) || ((abs(l1/4-l7/4)==1)&& ((abs(l7/4-l2/4)==1)||(abs(l7/4-l8/4)==1)||(abs(l7/4-l9/4)==1))) || ((abs(l1/4-l8/4)==1)&& ((abs(l8/4-l2/4)==1)||(abs(l8/4-l7/4)==1)||(abs(l8/4-l9/4)==1))) || ((abs(l1/4-l9/4)==1)&& ((abs(l9/4-l2/4)==1)||(abs(l9/4-l8/4)==1)||(abs(l9/4-l7/4)==1))))
    {
        if((abs(l1/4-l10/4)==1)||(abs(l2/4-l10/4)==1)||(abs(l7/4-l10/4)==1)||(abs(l8/4-l10/4)==1)||(abs(l9/4-l10/4)==1))
            {
            k2=k2+50;
            }
        //4cart
    }
    if (((abs(l1-l2)%4==0) && ((abs(l1-l7)%4==0)||(abs(l1-l8)%4==0)||(abs(l1-l9)%4==0))) || ((abs(l1-l7)%4==0)&&((abs(l1-l8)%4==0)||(abs(l1-l9)%4==0))) || ((abs(l2-l7)%4==0)&&((abs(l2-l8)%4==0)||(abs(l2-l9)%4==0))))
    {
       if ((abs(l10-l1)%4==0)||(abs(l10-l2)%4==0)||(abs(l10-l7)%4==0)||(abs(l10-l8)%4==0)||(abs(l10-l9)%4==0))
       {
           k2=k2+70; //4
       }
    }
    if((((((abs(l1-l7)<4)||(abs(l1-l8)<4)||(abs(l1-l9)<4))||((abs(l2-l7)<4)||(abs(l2-l8)<4)||(abs(l2-l9)<4)||(abs(l1-l2)<4))))))
    {
       if ((abs(l1-l10)<4)||(abs(l2-l10)<4))
       {
           k2=k2+40;
       }
    }
    if (((((abs(l1-l7)<4)||(abs(l1-l8)<4)||(abs(l1-l9)<4))&&((abs(l2-l7)<4)||(abs(l2-l8)<4)||(abs(l2-l9)<4)))|| ((abs(l1-l2)<4)&&((abs(l7-l8)<4)||(abs(l7-l9)<4)||(abs(l8-l9)<4)))))
    {
        if((abs(l1-l10)<4)||(abs(l2-l10)<4))
        {
            k2=k2+100;
        }
    }
    //dddddddddddddddddddddddddddddddddddddddddddddd
    if ((abs(l3-l10)<4)||(abs(l4-l10)<4))
    {
        k2=k2+20;
    }
    if (((abs(l3/4-l4/4)==1)&& ((abs(l4/4-l7/4)==1)||(abs(l4/4-l8/4)==1)||(abs(l4/4-l9/4)==1))) || ((abs(l3/4-l7/4)==1)&& ((abs(l7/4-l4/4)==1)||(abs(l7/4-l8/4)==1)||(abs(l7/4-l9/4)==1))) || ((abs(l3/4-l8/4)==1)&& ((abs(l8/4-l4/4)==1)||(abs(l8/4-l7/4)==1)||(abs(l8/4-l9/4)==1))) || ((abs(l3/4-l9/4)==1)&& ((abs(l9/4-l4/4)==1)||(abs(l9/4-l8/4)==1)||(abs(l9/4-l7/4)==1))))
    {
        if((abs(l3/4-l10/4)==1)||(abs(l4/4-l10/4)==1)||(abs(l7/4-l10/4)==1)||(abs(l8/4-l10/4)==1)||(abs(l9/4-l10/4)==1))
            {
            k2=k2+50;
            }
        //4cart
    }
    if (((abs(l3-l4)%4==0) && ((abs(l3-l7)%4==0)||(abs(l3-l8)%4==0)||(abs(l3-l9)%4==0))) || ((abs(l3-l7)%4==0)&&((abs(l3-l8)%4==0)||(abs(l3-l9)%4==0))) || ((abs(l4-l7)%4==0)&&((abs(l4-l8)%4==0)||(abs(l4-l9)%4==0))))
    {
       if ((abs(l10-l3)%4==0)||(abs(l10-l4)%4==0)||(abs(l10-l7)%4==0)||(abs(l10-l8)%4==0)||(abs(l10-l9)%4==0))
       {
           k2=k2+70; //4
       }
    }
    if((((((abs(l3-l7)<4)||(abs(l3-l8)<4)||(abs(l3-l9)<4))||((abs(l4-l7)<4)||(abs(l4-l8)<4)||(abs(l4-l9)<4)||(abs(l3-l4)<4))))))
    {
       if ((abs(l3-l10)<4)||(abs(l4-l10)<4))
       {
           k2=k2+40;
       }
    }
    if (((((abs(l3-l7)<4)||(abs(l3-l8)<4)||(abs(l3-l9)<4))&&((abs(l4-l7)<4)||(abs(l4-l8)<4)||(abs(l4-l9)<4)))|| ((abs(l3-l4)<4)&&((abs(l7-l8)<4)||(abs(l7-l9)<4)||(abs(l8-l9)<4)))))
    {
        if((abs(l3-l10)<4)||(abs(l4-l10)<4))
        {
            k2=k2+100;
        }
    }
    if(((k1<k2)||(k1<k3)))
    {
        podnat=new QPushButton(this);
        pass=new QPushButton (this);
        podnat->setGeometry(100,800,140,50);
        pass->setGeometry(100,850,140,50);
        podnat->setText("Уравнять");
        pass->setText("Пас");
        podnat->show();
        pass->show();
        connect(podnat,SIGNAL(clicked()),this, SLOT(Podnat()));
        connect(pass,SIGNAL(clicked()),this, SLOT(Pass()));
    }
    if((k2<k1)||(k3<k1))
{
    if((k2!=k1)&&(k2>10)&&(k1>k2)&&(k2!=0)&&(k1<110))
    {
        k2=k1;
    }
    else
    {
        k2=0;

    }
    if((k3!=k1)&&(k3>10)&&(k1>k3)&&(k3!=0)&&(k1<2000))
    {
        k3=k1;
     }
    else
    {
        k3=0;

    }
    }

    if ((k2!=k3)&&(k2!=0)&&(k2>60))
        //&&((uroven==1)||(uroven==2)||(uroven==3)||(uroven==4)))
    {
        k2=k3;
    }
    if ((k3!=k2)&&(k3!=0)&&(k3>60))
            //&&((uroven==1)||(uroven==2)||(uroven==3)||(uroven==4)))
    {
        k3=k2;
    }
    stav1= new QLineEdit(this);
    stav1->setGeometry(450,450,75,30);
    stav1->show();
    stav2= new QLineEdit(this);
    stav2->setGeometry(1100,450,75,30);
    stav2->show();
    QString str15=QString::number(k2);
    stav1->setText(str15);
    QString str16=QString::number(k3);
    stav2->setText(str16);
    if (k2==0)
    {
        stav1->setText("Пас");
    }
    if (k3==0)
    {
        stav2->setText("Пас");
    }


    if ((k2==0)&&(k3==0))
    {
        win= new QLineEdit(this);
        win->setGeometry(500,25,150,50);
        win->setText("Победа");
        win->show();
        inform=inform+(k2+k3+k1);
    }
    else
    {
        razdat1=new QPushButton(this);
        razdat1->setGeometry(800,25,150,50);
        razdat1->setText("Раздать");
        razdat1->show();
        connect(razdat1,SIGNAL(clicked()),this,SLOT(Razdat2()));
    }

}
void MainWindow::Passs()
{
    k1=0;
    stav= new QLineEdit(this);
    stav->setGeometry(800,600,75,30);
    stav->setText("Пас");
    stav->show();
    win= new QLineEdit(this);
    win->setGeometry(500,25,150,50);
    win->setText("Поражение");
    win->show();
   delete passs;
    if ((abs(l1-l10)<4)||(abs(l2-l10)<4))
    {
        k2=k2+20;
    }
    if (((abs(l1/4-l2/4)==1)&& ((abs(l2/4-l7/4)==1)||(abs(l2/4-l8/4)==1)||(abs(l2/4-l9/4)==1))) || ((abs(l1/4-l7/4)==1)&& ((abs(l7/4-l2/4)==1)||(abs(l7/4-l8/4)==1)||(abs(l7/4-l9/4)==1))) || ((abs(l1/4-l8/4)==1)&& ((abs(l8/4-l2/4)==1)||(abs(l8/4-l7/4)==1)||(abs(l8/4-l9/4)==1))) || ((abs(l1/4-l9/4)==1)&& ((abs(l9/4-l2/4)==1)||(abs(l9/4-l8/4)==1)||(abs(l9/4-l7/4)==1))))
    {
        if((abs(l1/4-l10/4)==1)||(abs(l2/4-l10/4)==1)||(abs(l7/4-l10/4)==1)||(abs(l8/4-l10/4)==1)||(abs(l9/4-l10/4)==1))
            {
            k2=k2+50;
            }
        //4cart
    }
    if (((abs(l1-l2)%4==0) && ((abs(l1-l7)%4==0)||(abs(l1-l8)%4==0)||(abs(l1-l9)%4==0))) || ((abs(l1-l7)%4==0)&&((abs(l1-l8)%4==0)||(abs(l1-l9)%4==0))) || ((abs(l2-l7)%4==0)&&((abs(l2-l8)%4==0)||(abs(l2-l9)%4==0))))
    {
       if ((abs(l10-l1)%4==0)||(abs(l10-l2)%4==0)||(abs(l10-l7)%4==0)||(abs(l10-l8)%4==0)||(abs(l10-l9)%4==0))
       {
           k2=k2+70; //4
       }
    }
    if((((((abs(l1-l7)<4)||(abs(l1-l8)<4)||(abs(l1-l9)<4))||((abs(l2-l7)<4)||(abs(l2-l8)<4)||(abs(l2-l9)<4)||(abs(l1-l2)<4))))))
    {
       if ((abs(l1-l10)<4)||(abs(l2-l10)<4))
       {
           k2=k2+40;
       }
    }
    if (((((abs(l1-l7)<4)||(abs(l1-l8)<4)||(abs(l1-l9)<4))&&((abs(l2-l7)<4)||(abs(l2-l8)<4)||(abs(l2-l9)<4)))|| ((abs(l1-l2)<4)&&((abs(l7-l8)<4)||(abs(l7-l9)<4)||(abs(l8-l9)<4)))))
    {
        if((abs(l1-l10)<4)||(abs(l2-l10)<4))
        {
            k2=k2+100;
        }
    }
    if ((abs(l3-l10)<4)||(abs(l4-l10)<4))
    {
        k2=k2+20;
    }
    if (((abs(l3/4-l4/4)==1)&& ((abs(l4/4-l7/4)==1)||(abs(l4/4-l8/4)==1)||(abs(l4/4-l9/4)==1))) || ((abs(l3/4-l7/4)==1)&& ((abs(l7/4-l4/4)==1)||(abs(l7/4-l8/4)==1)||(abs(l7/4-l9/4)==1))) || ((abs(l3/4-l8/4)==1)&& ((abs(l8/4-l4/4)==1)||(abs(l8/4-l7/4)==1)||(abs(l8/4-l9/4)==1))) || ((abs(l3/4-l9/4)==1)&& ((abs(l9/4-l4/4)==1)||(abs(l9/4-l8/4)==1)||(abs(l9/4-l7/4)==1))))
    {
        if((abs(l3/4-l10/4)==1)||(abs(l4/4-l10/4)==1)||(abs(l7/4-l10/4)==1)||(abs(l8/4-l10/4)==1)||(abs(l9/4-l10/4)==1))
            {
            k2=k2+50;
            }
        //4cart
    }
    if (((abs(l3-l4)%4==0) && ((abs(l3-l7)%4==0)||(abs(l3-l8)%4==0)||(abs(l3-l9)%4==0))) || ((abs(l3-l7)%4==0)&&((abs(l3-l8)%4==0)||(abs(l3-l9)%4==0))) || ((abs(l4-l7)%4==0)&&((abs(l4-l8)%4==0)||(abs(l4-l9)%4==0))))
    {
       if ((abs(l10-l3)%4==0)||(abs(l10-l4)%4==0)||(abs(l10-l7)%4==0)||(abs(l10-l8)%4==0)||(abs(l10-l9)%4==0))
       {
           k2=k2+70; //4
       }
    }
    if((((((abs(l3-l7)<4)||(abs(l3-l8)<4)||(abs(l3-l9)<4))||((abs(l4-l7)<4)||(abs(l4-l8)<4)||(abs(l4-l9)<4)||(abs(l3-l4)<4))))))
    {
       if ((abs(l3-l10)<4)||(abs(l4-l10)<4))
       {
           k2=k2+40;
       }
    }
    if (((((abs(l3-l7)<4)||(abs(l3-l8)<4)||(abs(l3-l9)<4))&&((abs(l4-l7)<4)||(abs(l4-l8)<4)||(abs(l4-l9)<4)))|| ((abs(l3-l4)<4)&&((abs(l7-l8)<4)||(abs(l7-l9)<4)||(abs(l8-l9)<4)))))
    {
        if((abs(l3-l10)<4)||(abs(l4-l10)<4))
        {
            k2=k2+100;
        }
    }
    /*else {
        if(k1!=0)
        {
    if((k2!=k1)&&(k2>10)&&(k1>k2)&&(k2!=0)&&(k1<110))
    {
        k2=k1;
    }
    else
    {
        k2=0;

    }
    if((k3!=k1)&&(k3>10)&&(k1>k3)&&(k3!=0)&&(k1<2000))
    {
        k3=k1;
     }
    else
    {
        k3=0;

    }
    }
    } */
    if ((k2!=k3)&&(k2!=0)&&(k2>20))
        //&&((uroven==1)||(uroven==2)||(uroven==3)||(uroven==4)))
        //without level
    {
        k2=k3;
    }
    if ((k3!=k2)&&(k3!=0)&&(k3>20))
            //&&((uroven==1)||(uroven==2)||(uroven==3)||(uroven==4)))
        //without level
    {
        k3=k2;
    }

    stav1= new QLineEdit(this);
    stav1->setGeometry(450,450,75,30);
    stav1->show();
    stav2= new QLineEdit(this);
    stav2->setGeometry(1100,450,75,30);
    stav2->show();
    QString str15=QString::number(k2);
    stav1->setText(str15);
    QString str16=QString::number(k3);
    stav2->setText(str16);
    if (k2==0)
    {
        stav1->setText("Пас");
    }
    if (k3==0)
    {
        stav2->setText("Пас");
    }
    if ((k2==0)&&(k3==0)&&(k1==0))
    {
        win= new QLineEdit(this);
        win->setGeometry(500,25,150,50);
        win->setText("Ничья");
        win->show();
        inform=inform+k1;
    }
    else
    {
        razdat1=new QPushButton(this);
        razdat1->setGeometry(800,25,150,50);
        razdat1->setText("Раздать");
        razdat1->show();
        connect(razdat1,SIGNAL(clicked()),this,SLOT(Razdat2()));
    }
    inform=inform-(k2+k3+k1);
}
void MainWindow::Razdat2()
{
    delete razdat1;
    l11=qrand() % 52;
    while ((l11==l5)||(l11==l6)||(l11==l7)||(l11==l8)||(l11==l9)||(l11==l1)||(l11==l2)||(l11==l3)||(l11==l10))
    {
        l11=qrand() % 52;
    }
    lol6=arr[l11];
    image010=new QLabel(this);
    i010= new QImage(lol6);
    image010->setGeometry(1090,100,150,250);
    QImage podng010=i010->scaled(150,250,Qt::IgnoreAspectRatio);
    image010->show();
    image010->resize(150,250);
    image010->setPixmap(QPixmap::fromImage(podng010, Qt::AutoColor));
    anim101=new QPropertyAnimation(image010,"geometry");
    anim101->setDuration(800);
    anim101->setEasingCurve(QEasingCurve::Linear);
    anim101->setStartValue(QRect(1400,150,150,250));
    anim101->setEndValue(QRect(1090,100,150,250));
    anim101->start();
    if (k1!=0)
    {
    stava= new QPushButton(this);
    cek= new QPushButton(this);
    stava->setText("Ставка");
    cek->setText("Чек");
    stava->setGeometry(100,800,100,50);
    stava->show();
    cek->setGeometry(100,850,100,50);
    cek->show();
    connect(stava,SIGNAL(clicked()),this,SLOT(Stava1()));
    connect(cek,SIGNAL(clicked()),this,SLOT(Cek1()));
    }
    passs= new QPushButton(this);
    passs->setText("Пас");
    passs->setGeometry(100,750,100,50);
    passs->show();
    connect(passs,SIGNAL(clicked()),this,SLOT(Passs1()));
}
void MainWindow::Stava1()
{
    delete stava;
    st10= new QPushButton(this);
    st20= new QPushButton(this);
    st50= new QPushButton(this);
    st100= new QPushButton(this);
    st500= new QPushButton(this);
    st10->setGeometry(25,800,50,50);
    st10->setText("10");
    st20->setGeometry(75,800,50,50);
    st20->setText("20");
    st50->setGeometry(125,800,50,50);
    st50->setText("50");
    st100->setGeometry(175,800,50,50);
    st100->setText("100");
    st500->setGeometry(225,800,50,50);
    st500->setText("500");
    st10->show();
    st20->show();
    st50->show();
    st100->show();
    st500->show();
    connect(st10,SIGNAL(clicked()), this, SLOT(St10()));
    connect(st20,SIGNAL(clicked()), this, SLOT(St20()));
    connect(st50,SIGNAL(clicked()), this, SLOT(St50()));
    connect(st100,SIGNAL(clicked()), this, SLOT(St100()));
    connect(st500,SIGNAL(clicked()), this, SLOT(St500()));
}
void MainWindow::Passs1()
{
    k1=0;
    stav= new QLineEdit(this);
    stav->setGeometry(800,600,75,30);
    stav->setText("Пас");
    stav->show();
    win= new QLineEdit(this);
    win->setGeometry(500,25,150,50);
    win->setText("Поражение");
    win->show();

   delete passs;
    if ((abs(l1-l11)<4)||(abs(l2-l11)<4))
    {
        k2=k2+20;
    }
    if (((abs(l1/4-l2/4)==1)&& ((abs(l2/4-l7/4)==1)||(abs(l2/4-l8/4)==1)||(abs(l2/4-l9/4)==1))) || ((abs(l1/4-l7/4)==1)&& ((abs(l7/4-l2/4)==1)||(abs(l7/4-l8/4)==1)||(abs(l7/4-l9/4)==1))) || ((abs(l1/4-l8/4)==1)&& ((abs(l8/4-l2/4)==1)||(abs(l8/4-l7/4)==1)||(abs(l8/4-l9/4)==1))) || ((abs(l1/4-l9/4)==1)&& ((abs(l9/4-l2/4)==1)||(abs(l9/4-l8/4)==1)||(abs(l9/4-l7/4)==1))))
    {
        if((abs(l1/4-l10/4)==1)||(abs(l2/4-l10/4)==1)||(abs(l7/4-l10/4)==1)||(abs(l8/4-l10/4)==1)||(abs(l9/4-l10/4)==1))
            {
            if ((abs(l1/4-l11/4)==1)||(abs(l2/4-l11/4)==1)||(abs(l7/4-l11/4)==1)||(abs(l8/4-l11/4)==1)||(abs(l9/4-l11/4)==1)||(abs(l10/4-l11/4)==1))
            {
                k2=k2+100;
            }
            }
        //5cart
    }
    if (((abs(l1-l2)%4==0) && ((abs(l1-l7)%4==0)||(abs(l1-l8)%4==0)||(abs(l1-l9)%4==0))) || ((abs(l1-l7)%4==0)&&((abs(l1-l8)%4==0)||(abs(l1-l9)%4==0))) || ((abs(l2-l7)%4==0)&&((abs(l2-l8)%4==0)||(abs(l2-l9)%4==0))))
    {
       if ((abs(l10-l1)%4==0)||(abs(l10-l2)%4==0)||(abs(l10-l7)%4==0)||(abs(l10-l8)%4==0)||(abs(l10-l9)%4==0))
       {
           if ((abs(l11-l1)%4==0)||(abs(l11-l2)%4==0)||(abs(l11-l7)%4==0)||(abs(l11-l8)%4==0)||(abs(l11-l9)%4==0)||(abs(l11-l10)%4==0))
           {
               k2=k2+80;
               //5
           }
       }
    }
       if((((((abs(l1-l7)<4)||(abs(l1-l8)<4)||(abs(l1-l9)<4))||((abs(l2-l7)<4)||(abs(l2-l8)<4)||(abs(l2-l9)<4)||(abs(l1-l2)<4))))))
       {
          if ((abs(l1-l11)<4)||(abs(l2-l11)<4))
          {
              k2=k2+40;
          }
       }
          if((((((abs(l1-l7)<4)||(abs(l1-l8)<4)||(abs(l1-l9)<4))||((abs(l2-l7)<4)||(abs(l2-l8)<4)||(abs(l2-l9)<4)||(abs(l1-l2)<4))))))
          {
             if ((abs(l1-l10)<4)||(abs(l2-l10)<4))
             {
                 if ((abs(l1-l11)<4)||(abs(l2-l11)<4))
                 {
                     k2=k2+200;
                 }
             }
          }
          //aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
          if ((abs(l3-l11)<4)||(abs(l4-l11)<4))
          {
              k2=k2+20;
          }
          if (((abs(l3/4-l4/4)==1)&& ((abs(l4/4-l7/4)==1)||(abs(l4/4-l8/4)==1)||(abs(l4/4-l9/4)==1))) || ((abs(l3/4-l7/4)==1)&& ((abs(l7/4-l4/4)==1)||(abs(l7/4-l8/4)==1)||(abs(l7/4-l9/4)==1))) || ((abs(l3/4-l8/4)==1)&& ((abs(l8/4-l4/4)==1)||(abs(l8/4-l7/4)==1)||(abs(l8/4-l9/4)==1))) || ((abs(l3/4-l9/4)==1)&& ((abs(l9/4-l4/4)==1)||(abs(l9/4-l8/4)==1)||(abs(l9/4-l7/4)==1))))
          {
              if((abs(l3/4-l10/4)==1)||(abs(l4/4-l10/4)==1)||(abs(l7/4-l10/4)==1)||(abs(l8/4-l10/4)==1)||(abs(l9/4-l10/4)==1))
                  {
                  if ((abs(l3/4-l11/4)==1)||(abs(l4/4-l11/4)==1)||(abs(l7/4-l11/4)==1)||(abs(l8/4-l11/4)==1)||(abs(l9/4-l11/4)==1)||(abs(l10/4-l11/4)==1))
                  {
                      k2=k2+100;
                  }
                  }
              //5cart
          }
          if (((abs(l3-l4)%4==0) && ((abs(l3-l7)%4==0)||(abs(l3-l8)%4==0)||(abs(l3-l9)%4==0))) || ((abs(l3-l7)%4==0)&&((abs(l3-l8)%4==0)||(abs(l3-l9)%4==0))) || ((abs(l4-l7)%4==0)&&((abs(l4-l8)%4==0)||(abs(l4-l9)%4==0))))
          {
             if ((abs(l10-l3)%4==0)||(abs(l10-l4)%4==0)||(abs(l10-l7)%4==0)||(abs(l10-l8)%4==0)||(abs(l10-l9)%4==0))
             {
                 if ((abs(l11-l3)%4==0)||(abs(l11-l4)%4==0)||(abs(l11-l7)%4==0)||(abs(l11-l8)%4==0)||(abs(l11-l9)%4==0)||(abs(l11-l10)%4==0))
                 {
                     k2=k2+80;
                     //5
                 }
             }
          }
             if((((((abs(l3-l7)<4)||(abs(l3-l8)<4)||(abs(l3-l9)<4))||((abs(l4-l7)<4)||(abs(l4-l8)<4)||(abs(l4-l9)<4)||(abs(l3-l4)<4))))))
             {
                if ((abs(l3-l11)<4)||(abs(l4-l11)<4))
                {
                    k2=k2+40;
                }
             }
                if((((((abs(l3-l7)<4)||(abs(l3-l8)<4)||(abs(l3-l9)<4))||((abs(l4-l7)<4)||(abs(l4-l8)<4)||(abs(l4-l9)<4)||(abs(l3-l4)<4))))))
                {
                   if ((abs(l3-l10)<4)||(abs(l4-l10)<4))
                   {
                       if ((abs(l3-l11)<4)||(abs(l4-l11)<4))
                       {
                           k2=k2+200;
                       }
                   }
                }
    if ((k2!=k3)&&(k2!=0)&&(k2>20))
        //&&((uroven==1)||(uroven==2)||(uroven==3)||(uroven==4)))
    {
        k2=k3;
    }
    if ((k3!=k2)&&(k3!=0)&&(k3>20))
            //&&((uroven==1)||(uroven==2)||(uroven==3)||(uroven==4)))
    {
        k3=k2;
    }

    stav1= new QLineEdit(this);
    stav1->setGeometry(450,450,75,30);
    stav1->show();
    stav2= new QLineEdit(this);
    stav2->setGeometry(1100,450,75,30);
    stav2->show();
    QString str15=QString::number(k2);
    stav1->setText(str15);
    QString str16=QString::number(k3);
    stav2->setText(str16);
    if (k2==0)
    {
        stav1->setText("Пас");
    }
    if (k3==0)
    {
        stav2->setText("Пас");
    }
    if ((k2==0)&&(k3==0)&&(k1==0))
    {
        win= new QLineEdit(this);
        win->setGeometry(500,25,150,50);
        win->setText("Ничья");
        win->show();
        inform=inform+k1;
    }
    inform=inform-(k2+k3+k1);
}
void MainWindow::Cek1()
{
    delete st10;
    delete st20;
     delete st50;
     delete st100;
     delete st500;
     delete cek;
      delete passs;
    if ((abs(l1-l11)<4)||(abs(l2-l11)<4))
    {
        k2=k2+20;
        K=1;
    }
    if (((abs(l1/4-l2/4)==1)&& ((abs(l2/4-l7/4)==1)||(abs(l2/4-l8/4)==1)||(abs(l2/4-l9/4)==1))) || ((abs(l1/4-l7/4)==1)&& ((abs(l7/4-l2/4)==1)||(abs(l7/4-l8/4)==1)||(abs(l7/4-l9/4)==1))) || ((abs(l1/4-l8/4)==1)&& ((abs(l8/4-l2/4)==1)||(abs(l8/4-l7/4)==1)||(abs(l8/4-l9/4)==1))) || ((abs(l1/4-l9/4)==1)&& ((abs(l9/4-l2/4)==1)||(abs(l9/4-l8/4)==1)||(abs(l9/4-l7/4)==1))))
    {
        if((abs(l1/4-l10/4)==1)||(abs(l2/4-l10/4)==1)||(abs(l7/4-l10/4)==1)||(abs(l8/4-l10/4)==1)||(abs(l9/4-l10/4)==1))
            {
            if ((abs(l1/4-l11/4)==1)||(abs(l2/4-l11/4)==1)||(abs(l7/4-l11/4)==1)||(abs(l8/4-l11/4)==1)||(abs(l9/4-l11/4)==1)||(abs(l10/4-l11/4)==1))
            {
                k2=k2+100;
                K=2;
            }
            }
        //5cart
    }
    if (((abs(l1-l2)%4==0) && ((abs(l1-l7)%4==0)||(abs(l1-l8)%4==0)||(abs(l1-l9)%4==0))) || ((abs(l1-l7)%4==0)&&((abs(l1-l8)%4==0)||(abs(l1-l9)%4==0))) || ((abs(l2-l7)%4==0)&&((abs(l2-l8)%4==0)||(abs(l2-l9)%4==0))))
    {
       if ((abs(l10-l1)%4==0)||(abs(l10-l2)%4==0)||(abs(l10-l7)%4==0)||(abs(l10-l8)%4==0)||(abs(l10-l9)%4==0))
       {
           if ((abs(l11-l1)%4==0)||(abs(l11-l2)%4==0)||(abs(l11-l7)%4==0)||(abs(l11-l8)%4==0)||(abs(l11-l9)%4==0)||(abs(l11-l10)%4==0))
           {
               k2=k2+80;
               K=3;
               //5
           }
       }
    }
       if((((((abs(l1-l7)<4)||(abs(l1-l8)<4)||(abs(l1-l9)<4))||((abs(l2-l7)<4)||(abs(l2-l8)<4)||(abs(l2-l9)<4)||(abs(l1-l2)<4))))))
       {
          if ((abs(l1-l11)<4)||(abs(l2-l11)<4))
          {
              k2=k2+40;
              K=4;
          }
       }
          if((((((abs(l1-l7)<4)||(abs(l1-l8)<4)||(abs(l1-l9)<4))||((abs(l2-l7)<4)||(abs(l2-l8)<4)||(abs(l2-l9)<4)||(abs(l1-l2)<4))))))
          {
             if ((abs(l1-l10)<4)||(abs(l2-l10)<4))
             {
                 if ((abs(l1-l11)<4)||(abs(l2-l11)<4))
                 {
                     k2=k2+200;
                 }
             }
          }
          if ((abs(l3-l11)<4)||(abs(l4-l11)<4))
          {
              k2=k2+20;
          }
          if (((abs(l3/4-l4/4)==1)&& ((abs(l4/4-l7/4)==1)||(abs(l4/4-l8/4)==1)||(abs(l4/4-l9/4)==1))) || ((abs(l3/4-l7/4)==1)&& ((abs(l7/4-l4/4)==1)||(abs(l7/4-l8/4)==1)||(abs(l7/4-l9/4)==1))) || ((abs(l3/4-l8/4)==1)&& ((abs(l8/4-l4/4)==1)||(abs(l8/4-l7/4)==1)||(abs(l8/4-l9/4)==1))) || ((abs(l3/4-l9/4)==1)&& ((abs(l9/4-l4/4)==1)||(abs(l9/4-l8/4)==1)||(abs(l9/4-l7/4)==1))))
          {
              if((abs(l3/4-l10/4)==1)||(abs(l4/4-l10/4)==1)||(abs(l7/4-l10/4)==1)||(abs(l8/4-l10/4)==1)||(abs(l9/4-l10/4)==1))
                  {
                  if ((abs(l3/4-l11/4)==1)||(abs(l4/4-l11/4)==1)||(abs(l7/4-l11/4)==1)||(abs(l8/4-l11/4)==1)||(abs(l9/4-l11/4)==1)||(abs(l10/4-l11/4)==1))
                  {
                      k2=k2+100;
                  }
                  }
              //5cart
          }
          if (((abs(l3-l4)%4==0) && ((abs(l3-l7)%4==0)||(abs(l3-l8)%4==0)||(abs(l3-l9)%4==0))) || ((abs(l3-l7)%4==0)&&((abs(l3-l8)%4==0)||(abs(l3-l9)%4==0))) || ((abs(l4-l7)%4==0)&&((abs(l4-l8)%4==0)||(abs(l4-l9)%4==0))))
          {
             if ((abs(l10-l3)%4==0)||(abs(l10-l4)%4==0)||(abs(l10-l7)%4==0)||(abs(l10-l8)%4==0)||(abs(l10-l9)%4==0))
             {
                 if ((abs(l11-l3)%4==0)||(abs(l11-l4)%4==0)||(abs(l11-l7)%4==0)||(abs(l11-l8)%4==0)||(abs(l11-l9)%4==0)||(abs(l11-l10)%4==0))
                 {
                     k2=k2+80;
                     //5
                 }
             }
          }
             if((((((abs(l3-l7)<4)||(abs(l3-l8)<4)||(abs(l3-l9)<4))||((abs(l4-l7)<4)||(abs(l4-l8)<4)||(abs(l4-l9)<4)||(abs(l3-l4)<4))))))
             {
                if ((abs(l3-l11)<4)||(abs(l4-l11)<4))
                {
                    k2=k2+40;
                }
             }
                if((((((abs(l3-l7)<4)||(abs(l3-l8)<4)||(abs(l3-l9)<4))||((abs(l4-l7)<4)||(abs(l4-l8)<4)||(abs(l4-l9)<4)||(abs(l3-l4)<4))))))
                {
                   if ((abs(l3-l10)<4)||(abs(l4-l10)<4))
                   {
                       if ((abs(l3-l11)<4)||(abs(l4-l11)<4))
                       {
                           k2=k2+200;
                       }
                   }
                }
    if(((k1<k2)||(k1<k3)))
    {
        podnat=new QPushButton(this);
        pass=new QPushButton (this);
        podnat->setGeometry(100,800,140,50);
        pass->setGeometry(100,850,140,50);
        podnat->setText("Уравнять");
        pass->setText("Пас");
        podnat->show();
        pass->show();
        connect(podnat,SIGNAL(clicked()),this, SLOT(Podnat()));
        connect(pass,SIGNAL(clicked()),this, SLOT(Pass()));
    }
     if((k2<k1)||(k3<k1)) {

    if((k2!=k1)&&(k2>10)&&(k1>k2)&&(k2!=0)&&(k1<110))
    {
        k2=k1;
    }
    else
    {
        k2=0;

    }
    if((k3!=k1)&&(k3>10)&&(k1>k3)&&(k3!=0)&&(k1<2000))
    {
        k3=k1;
     }
    else
    {
        k3=0;

    }
    }
    if ((k2!=k3)&&(k2!=0)&&(k2>60))
        //&&((uroven==1)||(uroven==2)||(uroven==3)||(uroven==4)))
    {
        k2=k3;
    }
    if ((k3!=k2)&&(k3!=0)&&(k3>60))
            //&&((uroven==1)||(uroven==2)||(uroven==3)||(uroven==4)))
    {
        k3=k2;
    }
    stav1= new QLineEdit(this);
    stav1->setGeometry(450,450,75,30);
    stav1->show();
    stav2= new QLineEdit(this);
    stav2->setGeometry(1100,450,75,30);
    stav2->show();
    QString str15=QString::number(k2);
    stav1->setText(str15);
    QString str16=QString::number(k3);
    stav2->setText(str16);
    if (k2==0)
    {
        stav1->setText("Пас");
    }
    if (k3==0)
    {
        stav2->setText("Пас");
    }
    if ((k2==0)&&(k3==0))
    {
        win= new QLineEdit(this);
        win->setGeometry(500,25,150,50);
        win->setText("Победа");
        win->show();
       inform=inform+(k2+k3+k1);
    }
}
