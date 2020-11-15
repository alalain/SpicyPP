#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::onReset);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::onReset()
{
  ui->label->setText("De Marius cheggt nüüt");
}
