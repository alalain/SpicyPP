#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow),
      node1Validator(new QIntValidator(0, 100, this)),
      node2Validator(new QIntValidator(0, 100, this)),
      valueValidator(new QDoubleValidator(0, 400000000000, 6, this)),
      componentValidator(new QIntValidator(0, 1, this))
{
  ui->setupUi(this);

  connect(ui->ResetButton, &QPushButton::clicked, this, &MainWindow::onReset);
  connect(ui->AddButton, &QPushButton::clicked, this, &MainWindow::onAdd);
  ui->Node1->setValidator(new QIntValidator(0, 100, this));
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::onReset()
{
}

void MainWindow::onAdd()
{
  // Resistor = 0 VoltageSource = 1
  int componentIndex = ui->Component->currentIndex();

  QString errorMessage = "";
  if (componentIndex == 0)
  {
  }
  else if (componentIndex == 1)
  {
  }
  else
  {
    // ERROOORRRR
  }
}
