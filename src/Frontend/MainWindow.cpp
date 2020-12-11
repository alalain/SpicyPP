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
  connect(ui->CalculateButton, &QPushButton::clicked, this,
          &MainWindow::onCalculate);
  ui->Node1->setValidator(node1Validator);
  ui->Node2->setValidator(node2Validator);
  ui->Value->setValidator(valueValidator);
  ui->Component->setValidator(componentValidator);
  ui->ErrorLabel->setText("ProTipp: Node 0 (GND) has to be in Network.");
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::onReset()
{
  network = Network();
  ui->CompList->clear();
  ui->SolList->clear();
  ui->CompList->show();
  ui->SolList->hide();
  ui->ErrorLabel->setText("ProTipp: Node 0 (GND) has to be in Network.");
}

void MainWindow::onCalculate()
{
  ui->SolList->clear();
  std::vector<MeasureVal> solutions;
  network.GetNewestSolution(solutions);
  ui->CompList->hide();
  ui->SolList->show();
  QString text = "";
  for (std::vector<int>::size_type i = 0; i < solutions.size(); i++)
  {
    text = "";
    text.append(QString::fromStdString(solutions[i].name))
        .append(": ")
        .append(QString::number(solutions[i].value))
        .append(QString::fromStdString(solutions[i].unit));
    ui->SolList->addItem(text);
  }
}

void MainWindow::onAdd()
{
  ui->SolList->hide();
  ui->CompList->show();
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
  ui->ErrorLabel->setText("");
  double value = valueString.toDouble();
  int node1 = node1String.toInt();
  int node2 = node2String.toInt();
  std::string name = nameString.toStdString();
  QString ListText = "";
  if (componentIndex == 0)
  {
    ListText.append(nameString)
        .append(": ")
        .append(valueString)
        .append("Ohm ")
        .append(node1String)
        .append(" ")
        .append(node2String);
    QListWidgetItem item(ListText);
    ui->CompList->addItem(ListText);
    network.AddResistor(name, node1, node2, value);
  }
  else if (componentIndex == 1)
  {
    ListText.append(nameString)
        .append(": ")
        .append(valueString)
        .append("Volt ")
        .append(node1String)
        .append(" ")
        .append(node2String);
    QListWidgetItem item(ListText);
    ui->CompList->addItem(ListText);
    network.AddVoltageSource(name, node1, node2, value);
  }
}
