#ifndef FIRE_H
#define FIRE_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Fire: public QObject, public QGraphicsPixmapItem
{
  Q_OBJECT
public:
  Fire(QGraphicsItem * parent = 0);
  ~Fire();

public slots:
  void action();
};

#endif // FIRE_H
