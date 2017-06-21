/********************************************************************************
** Form generated from reading UI file 'testoop.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTOOP_H
#define UI_TESTOOP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestOOPClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TestOOPClass)
    {
        if (TestOOPClass->objectName().isEmpty())
            TestOOPClass->setObjectName(QStringLiteral("TestOOPClass"));
        TestOOPClass->resize(600, 400);
        menuBar = new QMenuBar(TestOOPClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        TestOOPClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TestOOPClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TestOOPClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(TestOOPClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        TestOOPClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(TestOOPClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TestOOPClass->setStatusBar(statusBar);

        retranslateUi(TestOOPClass);

        QMetaObject::connectSlotsByName(TestOOPClass);
    } // setupUi

    void retranslateUi(QMainWindow *TestOOPClass)
    {
        TestOOPClass->setWindowTitle(QApplication::translate("TestOOPClass", "TestOOP", 0));
    } // retranslateUi

};

namespace Ui {
    class TestOOPClass: public Ui_TestOOPClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTOOP_H
