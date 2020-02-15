#ifndef BACKGROUNDITEM_H
#define BACKGROUNDITEM_H

#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsPixmapItem>

class MovingBg: public QObject,public QGraphicsPixmapItem{
  Q_OBJECT
public:
  MovingBg(QGraphicsItem * parent=0);
  ~MovingBg();
public slots:
  void move();
};

#endif // BACKGROUNDITEM_H
