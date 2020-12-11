/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *ResetButton;
    QPushButton *AddButton;
    QPushButton *CalculateButton;
    QLabel *Title;
    QComboBox *Component;
    QLabel *CompLabel;
    QLabel *Node1Label;
    QLabel *Node2Label;
    QLabel *NodeValue;
    QLineEdit *Node1;
    QLineEdit *Node2;
    QLineEdit *Value;
    QLineEdit *Name;
    QLabel *NameLabel;
    QLabel *ErrorLabel;
    QListWidget *CompList;
    QListWidget *SolList;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        ResetButton = new QPushButton(centralwidget);
        ResetButton->setObjectName(QString::fromUtf8("ResetButton"));
        ResetButton->setGeometry(QRect(10, 510, 121, 41));
        AddButton = new QPushButton(centralwidget);
        AddButton->setObjectName(QString::fromUtf8("AddButton"));
        AddButton->setGeometry(QRect(330, 510, 121, 41));
        CalculateButton = new QPushButton(centralwidget);
        CalculateButton->setObjectName(QString::fromUtf8("CalculateButton"));
        CalculateButton->setGeometry(QRect(670, 510, 121, 41));
        Title = new QLabel(centralwidget);
        Title->setObjectName(QString::fromUtf8("Title"));
        Title->setGeometry(QRect(10, 10, 311, 51));
        QFont font;
        font.setPointSize(29);
        Title->setFont(font);
        Title->setAlignment(Qt::AlignCenter);
        Component = new QComboBox(centralwidget);
        Component->addItem(QString());
        Component->addItem(QString());
        Component->setObjectName(QString::fromUtf8("Component"));
        Component->setGeometry(QRect(150, 60, 141, 31));
        CompLabel = new QLabel(centralwidget);
        CompLabel->setObjectName(QString::fromUtf8("CompLabel"));
        CompLabel->setGeometry(QRect(10, 66, 151, 21));
        Node1Label = new QLabel(centralwidget);
        Node1Label->setObjectName(QString::fromUtf8("Node1Label"));
        Node1Label->setGeometry(QRect(10, 130, 61, 21));
        Node2Label = new QLabel(centralwidget);
        Node2Label->setObjectName(QString::fromUtf8("Node2Label"));
        Node2Label->setGeometry(QRect(10, 160, 61, 21));
        NodeValue = new QLabel(centralwidget);
        NodeValue->setObjectName(QString::fromUtf8("NodeValue"));
        NodeValue->setGeometry(QRect(10, 190, 61, 21));
        Node1 = new QLineEdit(centralwidget);
        Node1->setObjectName(QString::fromUtf8("Node1"));
        Node1->setGeometry(QRect(70, 130, 113, 21));
        Node2 = new QLineEdit(centralwidget);
        Node2->setObjectName(QString::fromUtf8("Node2"));
        Node2->setGeometry(QRect(70, 160, 113, 21));
        Value = new QLineEdit(centralwidget);
        Value->setObjectName(QString::fromUtf8("Value"));
        Value->setGeometry(QRect(70, 190, 113, 21));
        Name = new QLineEdit(centralwidget);
        Name->setObjectName(QString::fromUtf8("Name"));
        Name->setGeometry(QRect(70, 100, 113, 21));
        NameLabel = new QLabel(centralwidget);
        NameLabel->setObjectName(QString::fromUtf8("NameLabel"));
        NameLabel->setGeometry(QRect(10, 100, 61, 21));
        ErrorLabel = new QLabel(centralwidget);
        ErrorLabel->setObjectName(QString::fromUtf8("ErrorLabel"));
        ErrorLabel->setGeometry(QRect(10, 240, 311, 241));
        ErrorLabel->setAutoFillBackground(true);
        CompList = new QListWidget(centralwidget);
        CompList->setObjectName(QString::fromUtf8("CompList"));
        CompList->setGeometry(QRect(355, 21, 421, 451));
        CompList->setAutoFillBackground(true);
        SolList = new QListWidget(centralwidget);
        SolList->setObjectName(QString::fromUtf8("SolList"));
        SolList->setGeometry(QRect(350, 20, 421, 451));
        SolList->setAutoFillBackground(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        ResetButton->setText(QApplication::translate("MainWindow", "Reset", nullptr));
        AddButton->setText(QApplication::translate("MainWindow", "Add", nullptr));
        CalculateButton->setText(QApplication::translate("MainWindow", "Calculate", nullptr));
        Title->setText(QApplication::translate("MainWindow", "Spicy ++", nullptr));
        Component->setItemText(0, QApplication::translate("MainWindow", "Resistance", nullptr));
        Component->setItemText(1, QApplication::translate("MainWindow", "Source", nullptr));

        CompLabel->setText(QApplication::translate("MainWindow", "Choose component:", nullptr));
        Node1Label->setText(QApplication::translate("MainWindow", "Node 1", nullptr));
        Node2Label->setText(QApplication::translate("MainWindow", "Node 2", nullptr));
        NodeValue->setText(QApplication::translate("MainWindow", "Value", nullptr));
        NameLabel->setText(QApplication::translate("MainWindow", "Name", nullptr));
        ErrorLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
