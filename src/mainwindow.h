#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

  virtual bool eventFilter(QObject* watched, QEvent* event);

private:
  Ui::MainWindow* ui;
  QMediaPlayer* player_ = nullptr;
};

#endif  // MAINWINDOW_H
