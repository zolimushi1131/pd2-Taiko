#include "setgame.h"
#include <QTimer>
#include "drum.h"
#include <QMediaPlayer>
#include <QMovie>
#include <QGraphicsPixmapItem>
#include <QLabel>
#include <QGraphicsItem>
#include <QFont>
#include <QGraphicsTextItem>
#include <QKeyEvent>
#include <QPushButton>

extern setGame *game;
setGame::setGame(QWidget *parent)
{
    //設置畫面
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setScene(scene);

    setStyleSheet("background:transparent;");

    QLabel *backgnd = new QLabel(this);
    QMovie *bg = new QMovie(":/image/bg.gif");
    backgnd->setMovie(bg);
    bg->start();
    backgnd->lower();

    scene->addWidget(backgnd);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    //設置鼓面
    drum = new Drum();
    drum->setRect(0,0,100,100);
    drum->setPos(0,250);

    scene->addItem(drum);

    drum->setFlag(QGraphicsItem::ItemIsFocusable);
    drum->setFocus();

    //隨機產生音符
    timer = new QTimer();
    int random=rand()%1000+1500;
    QObject::connect(timer,SIGNAL(timeout()),drum,SLOT(creator()));
    timer->start(random);

    //分數
    score = new Score();
    scene->addItem(score);
    score->setPos(score->x(),score->y()+25);

    //計時器
    count = new Counter();
    scene->addItem(count);
    count->setPos(count->x(),count->y());

    //播放bgm
    QMediaPlayer *bgm = new QMediaPlayer();
    bgm->setMedia(QUrl("qrc:/sound/bgm.mp3"));
    bgm->play();

    show();
    alltime = new QTimer;
    QObject::connect(alltime,SIGNAL(timeout()),this,SLOT(Ending()));
    alltime->start(30000);
}


void setGame::GameStart()
{

    //隨機產生音符
    timer = new QTimer();
    int random=rand()%1000+1500;
    connect(timer,SIGNAL(timeout()),drum,SLOT(creator()));
    timer->start(random);

    //分數
    score = new Score();
    scene->addItem(score);
    score->setPos(score->x(),score->y()+25);

    //計時器
    count = new Counter();
    scene->addItem(count);
    count->setPos(count->x(),count->y());

    alltime = new QTimer;
    QObject::connect(alltime,SIGNAL(timeout()),this,SLOT(Ending()));
    alltime->start(30000);

}

void setGame::Ending()
{
    End = new QLabel(this);
    End->setGeometry(0,0,800,600);
    End->setPixmap(QPixmap(":/image/end.png"));
    End->setVisible(true);
    End->raise();

    QString finalScore = QString::number(game->score->score);

    Result = new QLabel(this);
    Result->setGeometry(400,0,800,600);
    QString labelText = "<P><b><i><FONT COLOR='#ff0000' FONT SIZE = 78>";
    labelText .append(finalScore);
    labelText .append("</i></b></P></br>");
    Result->setText(labelText);
    Result->setVisible(true);
    Result->raise();

    exit=new QPushButton("Quit");
    exit->setParent(this);
    exit->setGeometry(200,275,100,50);
    exit->setStyleSheet("background-color: red");
    QObject::connect(exit,SIGNAL(clicked()),this,SLOT(quit()));
    exit->setVisible(true);
    exit->raise();

    restart=new QPushButton("Restart");
    restart->setParent(this);
    restart->setGeometry(520,275,100,50);
    restart->setStyleSheet("background-color: red");
    connect(restart,SIGNAL(clicked()),this,SLOT(reset()));
    restart->setVisible(true);
    restart->raise();
}


void setGame::quit()
{
    qApp->quit();
}


void setGame::reset()
{
    End->setVisible(false);
    Result->setVisible(false);
    exit->setVisible(false);
    restart->setVisible(false);
    delete score;
    delete count;
    delete timer;
    delete alltime;

    GameStart();
}
