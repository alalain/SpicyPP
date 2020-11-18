#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow),
      node1Validator(new QIntValidator(0, 100, this)),
      node2Validator(new QIntValidator(0, 100, this)),
      valueValidator(new QDoubleValidator(0, 400000000000, 6, this)),
      componentValidator(new QIntValidator(0, 1, this)), network()
{
  ui->setupUi(this);

  connect(ui->ResetButton, &QPushButton::clicked, this, &MainWindow::onReset);
  connect(ui->AddButton, &QPushButton::clicked, this, &MainWindow::onAdd);
  ui->Node1->setValidator(node1Validator);
  ui->Node2->setValidator(node2Validator);
  ui->Value->setValidator(valueValidator);
  ui->Component->setValidator(componentValidator);
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
  int pos = 0;
  bool errorDetected = false;
  QString nameString = ui->Name->text();
  QString node1String = ui->Node1->text();
  QString node2String = ui->Node2->text();
  QString valueString = ui->Value->text();
  int componentIndex = ui->Component->currentIndex();
  QString errorMessage = "";

  if ((ui->Node1->validator()->validate(node1String, pos)) != 2)
  {
    errorDetected = true;
    errorMessage.append("Node1 muss zwischen 0 und 100 liegen \n");
  }

  if ((ui->Node2->validator()->validate(node2String, pos)) != 2)
  {
    errorDetected = true;
    errorMessage.append("Node2 muss zwischen 0 und 100 liegen \n");
  }

  if ((ui->Value->validator()->validate(valueString, pos)) != 2)
  {
    errorDetected = true;
    errorMessage.append("Wert bitte anderst wählen \n");
  }
  if (errorDetected)
  {
    ui->ErrorLabel->show();
    ui->ErrorLabel->setText(errorMessage);
    return;
  }
  ui->ErrorLabel->hide();
  double value = valueString.toDouble();
  int node1 = node1String.toInt();
  int node2 = node2String.toInt();
  std::string name = nameString.toStdString();

  if (componentIndex == 0)
  {
    network.AddResistor(name, node1, node2, value);
  }
  else if (componentIndex == 1)
  {
    network.AddVoltageSource(name, node1, node2, value);
  }
}
