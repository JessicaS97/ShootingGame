#ifndef PLAYER_H
#define PLAYER_H

#include <QString>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>
#include <QJsonObject>
#include <iostream>

using namespace std;

/**
 * Player is part of the builder pattern. It builds a complex object through
 * the builder.
 *
 */

class Player:public QObject, public QGraphicsPixmapItem{
  Q_OBJECT
public:
  Player(QGraphicsItem * parent=0);
  Player(int m_posx, QString m_size, int m_speed);
  ~Player();

  int getSpeed();
  void setSpeed(int m_speed);

  QString getSize();
  void changeSize(QString size);

  int getPosX();
  void setPosX(int x);

  void keyPressEvent(QKeyEvent * event);    //trigger event when a keyboard is pressed
private:
  QMediaPlayer * fireSound;
  QMediaPlayer * jumpSound;
  int m_speed;
  QString m_size;
  int m_posx;
};


#endif // PLAYER_H
