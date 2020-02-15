#include "player.h"
#include "fire.h"


/*
 * Adds initial sounds and player image
 *
 */

Player::Player(QGraphicsItem *parent)
    : QGraphicsPixmapItem (parent)
{
  QPixmap cowImg(":images/images/giant.png");
  //cowImg = cowImg.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation);
  setPixmap(cowImg);
  setOffset(-cowImg.width() / 2, -cowImg.height()/4);

  fireSound = new QMediaPlayer();
  fireSound->setMedia(QUrl("qrc:/sounds/sounds/shoot.wav"));

  jumpSound = new QMediaPlayer();
  jumpSound->setMedia(QUrl("qrc:/sounds/sounds/jump.wav"));


}

Player::Player(int posx, QString size, int speed)
{
  m_posx = posx;
  m_size = size;
  m_speed = speed;

};

Player::~Player()
{
  std::cout << ("Player deleted\n");
}

/*
 * Event triggered when user presses spacebar or up key
 * For every up key pressed, the player fires to the left. This includes a fire sound too
 * For every space bar pressed, a jump sound is played
 *
 * @param event
 */


void Player::keyPressEvent(QKeyEvent * event)
{

  if(event->key() == Qt::Key_Space) {

      // Make player jump

      // Play jump sound
      if (jumpSound->state() == QMediaPlayer::PlayingState) {
          jumpSound->setPosition(0);
      } else if (jumpSound->state() == QMediaPlayer::StoppedState) {
          jumpSound->play();
      }

  } else if (event->key() == Qt::Key_Up) {

      // Create fire
      Fire * fire = new Fire();
      fire->setPos(x(), y());
      scene()->addItem(fire);

      // Play fire sound
      if (fireSound->state() == QMediaPlayer::PlayingState) {
          fireSound->setPosition(0);
      } else if (fireSound->state() == QMediaPlayer::StoppedState) {
            fireSound->play();
      }

  }
}


// Returns the current speed of player
int Player::getSpeed()
{
  return m_speed;
}

// Set the speed of player
void Player::setSpeed(int speed)
{
  m_speed = speed;
}

// Return current size of player
QString Player::getSize()
{
  return m_size;
}

/*
 * Change size of player
 *
 * @param size
 */

void Player::changeSize(QString size)
{
  if (size.compare("tiny") == 0) {
      m_size = size;
      QPixmap cowImg(":images/images/tiny.png");
      setPixmap(cowImg);
  } else if (size.compare("normal") == 0) {
      m_size = size;
      QPixmap cowImg(":images/images/normal.png");
      setPixmap(cowImg);
  } else if (size.compare("large") == 0) {
      m_size = size;
      QPixmap cowImg(":images/images/large.png");
      setPixmap(cowImg);
  } else if (size.compare("giant") == 0) {
      m_size = size;
      QPixmap cowImg(":images/images/giant.png");
      setPixmap(cowImg);
  } else {
      // Diplay invalid size value
      qDebug() << "Invalid size";
  }
}

// Get x position of player
int Player::getPosX()
{
  return m_posx;
}


// Set position x of player
// @param x
void Player::setPosX(int x)
{
  m_posx = x;
}

