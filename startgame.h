#ifndef STARTGAME_H
#define STARTGAME_H

#include "player.h"
#include <QGraphicsScene>
#include <QWidget>
#include <QGraphicsView>
#include <QJsonObject>


class StartGame: public QGraphicsView
{
public:
  StartGame(QWidget * parent=0);
  QStringList getArguments();

  QGraphicsScene * scene;
  Player * player;
};

#endif // STARTGAME_H
