#ifndef TESTOOP_H
#define TESTOOP_H

#include <QtWidgets/QMainWindow>
#include "Controller.h"
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
//#include "ui_testoop.h"


class TestOOP : public QWidget //public QMainWindow
{
	Q_OBJECT

public:
	TestOOP(Controller &c, QWidget *parent = 0);
	~TestOOP();

private:
	//Ui::TestOOPClass ui;
	Controller& ctrl;
	std::vector<Fruit> currentCountriesInRepoList;

	QListWidget* repoList;
	QLineEdit* nameEdit;
	QLineEdit* nutrEdit;
	QLineEdit* quantityEdit;

	// buttons
	QPushButton* sortButton;
	QPushButton* filterButton;
	QPushButton* refreshButton;
	//QPushButton* sortButton;

	void initGUI();
	void populateRepoList();
	int getRepoListSelectedIndex();

	void connectSignalsAndSlots();

	private slots:
	void listItemChanged();
	
	void filterByBenefit();
	void sortByNutr();
	void refresh();
};

#endif // TESTOOP_H
