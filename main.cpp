#include "mainwindow.h"
#include <QApplication>
#include "player.h"
#include "startGame.h"
#include <QFile>
#include <QString>
#include <string>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  StartGame * game;
  game = new StartGame();
  game->show();

  return a.exec();
}
