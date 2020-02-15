#include "Fire.h"
#include <QTimer>
#include <QGraphicsScene>
#include "startgame.h"

extern StartGame * game;


// Create a fire object for player to shoot
Fire::Fire(QGraphicsItem * parent):QObject(), QGraphicsPixmapItem(parent)
{
  setPixmap(QPixmap(":/images/images/clip.png"));

  QTimer * timer = new QTimer();
  connect(timer,SIGNAL(timeout()),this,SLOT(action()));

  timer->start(40);   // set timer to 50ms, every 50ms a fire moves
}

Fire::~Fire(){};


// Make fire object move to the left by incrementing its x position
void Fire::action()
{
  // Fire to left
  setPos(x()+10, y());
}
