#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QEvent>
#include <QMediaPlaylist>
#include <QUrl>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  Q_INIT_RESOURCE(qt_resources);
  ui->setupUi(this);
  ui->pushButton->installEventFilter(this);
  ui->label->setStyleSheet("background-color: red");
}

MainWindow::~MainWindow()
{
  delete ui;
}

bool MainWindow::eventFilter(QObject* watched, QEvent* event)
{
  if (watched == ui->pushButton && event->type() == QEvent::HoverEnter)
  {
    qDebug() << "Start hover";
    ui->label->setStyleSheet("background-color: green");
    if (!player_)
    {
      QMediaPlaylist* playlist = new QMediaPlaylist();
      playlist->addMedia(QUrl("qrc:/push_button.mp3"));
      playlist->setPlaybackMode(QMediaPlaylist::Loop);

      player_ = new QMediaPlayer(this);
      player_->setPlaylist(playlist);
      player_->setVolume(100);
      player_->play();
    }
  }
  else if (watched == ui->pushButton && event->type() == QEvent::HoverLeave)
  {
    qDebug() << "End hover";
    ui->label->setStyleSheet("background-color: red");
    if (player_)
    {
      player_->stop();
      player_->deleteLater();
      player_ = nullptr;
    }
  }
  return QMainWindow::eventFilter(watched, event);
}
