#ifndef MYCLASS_H
#define MYCLASS_H

#include <QtWidgets/QWidget>
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
//#include "ui_myclass.h"
#include "Controller.h"

class MyClass : public QWidget
{
	Q_OBJECT

public:
	MyClass(Controller& c, QWidget *parent = 0);
	~MyClass();

private:
	Controller& ctrl;
	//Ui::MyClassClass ui;
	std::vector<Tutorial> currentTutsInRepoList;
	std::vector<Tutorial> currentTutsInWatchList;

	QListWidget* repoList;
	QLineEdit* titleEdit;
	QLineEdit* presenterEdit;
	QLineEdit* durationEdit;
	QLineEdit* likesEdit;
	QLineEdit* linkEdit;

	QLineEdit* fileNameEdit;
	QLineEdit* nrOfLikesEdit;

	// repo buttons
	QPushButton* clearEditsBtn;
	QPushButton* addButton;
	QPushButton* deleteButton;
	QPushButton* updateButton;
	// must choose the presenter (if not, applies to all tutorials)
	QPushButton* filterByPresBtn;
	QPushButton* playTutButton;
	QPushButton* nextTutButton;
	QPushButton* addToWatchListBtn;

	
	QPushButton* playWatchListBtn;
	QPushButton* nextWatchListBtn;
	QPushButton* delFromWatchListBtn;

	QPushButton* saveWatchListToFileBtn;
	QPushButton* openWatchListBtn;

	QListWidget* watchList;

	void initGUI();

	void populateRepoList();
	void populateWatchList();
	int getRepoListSelectedIndex();

	void connectSignalsAndSlots();

	
private slots:
	// When an item in the list is clicked, the text boxes get filled with the item's information
	void listItemChanged();

	void addTutToRepo();
	void deleteTutFromRepo();
	void updateTutFromRepo();
	


	// filters the elements in the list, by the presenter written in the presenter edit box
	void filterRepoTuts();
	
	void playTutFromRepo();
	void nextTutFromRepo();
	void addTutToWatchList();
	
	void deleteFromWatchList();
	void playWatchList();
	void nextWatchList();
	void saveToFile();
	void openWithProgram();
	
	void clearLineEdits();
};

#endif // MYCLASS_H
