#ifndef BUILDER_H
#define BUILDER_H

#include <QGraphicsPixmapItem>
#include <QMediaPlayer>

class Builder:public QObject, public QGraphicsPixmapItem{
  Q_OBJECT
public:
  Builder(QGraphicsItem * parent=0);
  Builder(int m_posx, QString m_size, int m_speed);
  ~Builder();

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

#endif // BUILDER_H
