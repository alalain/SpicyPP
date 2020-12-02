#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDoubleValidator>
#include <QIntValidator>
#include <QMainWindow>
#include <string>
#include "./../Backend/Network.h"
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

 private:
  Ui::MainWindow* ui;
  QIntValidator* node1Validator;
  QIntValidator* node2Validator;
  QDoubleValidator* valueValidator;
  QIntValidator* componentValidator;

  Network network;
  void onReset();
  void onAdd();
  void UpdateCompList();
};

#endif  // MAINWINDOW_H
