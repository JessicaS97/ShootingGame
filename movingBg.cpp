#include "movingBg.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>

MovingBg::MovingBg(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

  setPixmap(QPixmap(":/images/images/planets.png"));

  // Set a timer to move background
  QTimer * timer = new QTimer(this);
  connect(timer,SIGNAL(timeout()),this,SLOT(move()));

  timer->start(50);

}

MovingBg::~MovingBg(){};

void MovingBg::move(){
  // Move planets to the left, give depth to background
  setPos(x()-10,y());
}
