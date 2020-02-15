#include "startgame.h"
#include <QTimer>
#include <QGraphicsSimpleTextItem>
#include "movingBg.h"
#include <QPixmap>
#include <stdio.h>
#include <string.h>

StartGame::StartGame(QWidget *parent)
{

    QString myFileName = "C:/Users/jessi/Documents/cow/config.txt";
    QFile myFile(myFileName);

        // Return error message if cannot open file
        if(!myFile.open(QFile::ReadOnly | QFile::Text))
        {
            qDebug() << "Error opening file";

        }

    QTextStream in(&myFile);
    QString text = in.readAll();

    //Store input data in list
    QStringList myList = text.split(" ");

    int posx = myList[0].toInt();
    int speed = myList[2].toInt();


    // Initialize player with given arguments from config file
    Player *player = new Player(posx, myList[1], speed);

    // Create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1000,800); // make the scene 800x600 instead of infinity by infinity (default)

    // Add background elements
    setBackgroundBrush(QBrush(QImage(":/images/images/background.png")));
    QGraphicsPixmapItem *ground = scene->addPixmap(QPixmap(":/images/images/ground.png"));


    // Set currently created scene to the one to visualize
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1000,800);

    // Create the player
    player = new Player();
    player->setPos(100,500);
    // Make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // Add the player to the scene
    scene->addItem(player);

    // Play background music
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/sounds/bg.mp3"));
    music->play();


    // Add moving background
    MovingBg * bg = new MovingBg();
    scene->addItem(bg);

    show();
}
