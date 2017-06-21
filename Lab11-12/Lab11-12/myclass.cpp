#include "myclass.h"
#include <QMessageBox>
#include "Utils.h"

MyClass::MyClass(Controller& c, QWidget *parent) : ctrl(c), QWidget(parent)
{
	//ui.setupUi(this);
	this->initGUI();
	this->currentTutsInRepoList = this->ctrl.getRepo().getTutorials();
	this->currentTutsInWatchList = this->ctrl.getWatchList()->getTuts();
	this->populateRepoList();
}

MyClass::~MyClass() {}

void MyClass::initGUI() {
	//General layout of the window
	QHBoxLayout* layout = new QHBoxLayout{ this };

	// Prepare left side components - vertical layout with: 
	// - list
	// - form layout with the tutorial data
	// - grid layout with buttons: add, delete, update, filter
	QWidget* leftWidget = new QWidget{};
	QVBoxLayout* leftSide = new QVBoxLayout{ leftWidget };

	// list
	this->repoList = new QListWidget{};
	// set the selection model
	this->repoList->setSelectionMode(QAbstractItemView::SingleSelection);

	// tutorial data
	QWidget* tutorialDataWidget = new QWidget{};
	QFormLayout* formLayout = new QFormLayout{ tutorialDataWidget };
	this->titleEdit = new QLineEdit{};
	this->presenterEdit = new QLineEdit{};
	this->durationEdit = new QLineEdit{};
	this->likesEdit = new QLineEdit{};
	this->linkEdit = new QLineEdit{};
	formLayout->addRow("&Title", titleEdit);
	formLayout->addRow("&Presenter", presenterEdit);
	formLayout->addRow("&Duration", durationEdit);
	formLayout->addRow("&Likes", likesEdit);
	formLayout->addRow("&Link", linkEdit);

	// buttons
	QWidget* buttonsWidget = new QWidget{};
	QGridLayout* gridLayout = new QGridLayout{ buttonsWidget };
	this->addButton = new QPushButton("Add");
	this->deleteButton = new QPushButton("Delete");
	this->updateButton = new QPushButton("Update");
	this->filterByPresBtn = new QPushButton("Filter");
	this->playTutButton = new QPushButton("Play");
	this->nextTutButton = new QPushButton("Next");
	this->clearEditsBtn = new QPushButton("Clear Line Edits");


	gridLayout->addWidget(addButton, 0, 0);
	gridLayout->addWidget(deleteButton, 0, 1);
	gridLayout->addWidget(updateButton, 0, 2);
	gridLayout->addWidget(filterByPresBtn, 1, 0);
	gridLayout->addWidget(playTutButton, 1, 1);
	gridLayout->addWidget(nextTutButton, 1, 2);
	gridLayout->addWidget(clearEditsBtn, 2, 0, 1, 3);

	// add everything to the left layout
	leftSide->addWidget(new QLabel{ "All tutorials" });
	leftSide->addWidget(repoList);
	leftSide->addWidget(tutorialDataWidget);
	leftSide->addWidget(buttonsWidget);

	// middle component: one button to add a tutorial to the watchlist
	QWidget* middleWidget = new QWidget{};
	QVBoxLayout* vLayoutMiddle = new QVBoxLayout{ middleWidget };
	this->addToWatchListBtn = new QPushButton{ "> Add to watchlist" };
	vLayoutMiddle->addWidget(this->addToWatchListBtn);

	// right component: the watchlist
	QWidget* rightWidget = new QWidget{};
	QVBoxLayout* rightSide = new QVBoxLayout{ rightWidget };

	// watchlist
	this->watchList = new QListWidget{};

	// watchList buttons
	QWidget* watchListButtonsWidget = new QWidget{};
	QGridLayout* wlButtonsLayout = new QGridLayout{ watchListButtonsWidget };

	this->playWatchListBtn = new QPushButton("Play");
	this->nextWatchListBtn = new QPushButton("Next");
	this->delFromWatchListBtn = new QPushButton("Delete");
	this->saveWatchListToFileBtn = new QPushButton("Save To File");
	this->openWatchListBtn = new QPushButton("Open With Program");
	wlButtonsLayout->addWidget(playWatchListBtn, 0, 0);
	wlButtonsLayout->addWidget(nextWatchListBtn, 0, 1);
	wlButtonsLayout->addWidget(delFromWatchListBtn, 0, 2);
	wlButtonsLayout->addWidget(saveWatchListToFileBtn, 1, 0, 1, 3);
	wlButtonsLayout->addWidget(openWatchListBtn, 2, 0, 1, 3);

	
	QWidget* watchlistData = new QWidget{};
	QFormLayout* formLay = new QFormLayout{ watchlistData };
	this->fileNameEdit = new QLineEdit{};
	formLay->addRow("&File Name", fileNameEdit);
	this->nrOfLikesEdit = new QLineEdit{};
	formLay->addRow("&Total no. of likes", nrOfLikesEdit);
	
	// add everything to the right layout
	rightSide->addWidget(new QLabel{ "WatchList" });
	rightSide->addWidget(watchList);
	rightSide->addWidget(watchListButtonsWidget);
	rightSide->addWidget(watchlistData);

	// add the three layouts to the main layout
	layout->addWidget(leftWidget);
	layout->addWidget(middleWidget);
	layout->addWidget(rightWidget);

	// connect the signals and slots
	this->connectSignalsAndSlots();
}


void MyClass::connectSignalsAndSlots()
{
	// add a connection: function listItemChanged() will be called when an item in the list is selected
	QObject::connect(this->repoList, SIGNAL(itemSelectionChanged()), this, SLOT(listItemChanged()));

	QObject::connect(this->addButton, SIGNAL(clicked()), this, SLOT(addTutToRepo()));
	QObject::connect(this->deleteButton, SIGNAL(clicked()), this, SLOT(deleteTutFromRepo()));
	QObject::connect(this->updateButton, SIGNAL(clicked()), this, SLOT(updateTutFromRepo()));
	QObject::connect(this->filterByPresBtn, SIGNAL(clicked()), this, SLOT(filterRepoTuts()));
	QObject::connect(this->clearEditsBtn, SIGNAL(clicked()), this, SLOT(clearLineEdits()));
	QObject::connect(this->playTutButton, SIGNAL(clicked()), this, SLOT(playTutFromRepo()));
	QObject::connect(this->nextTutButton, SIGNAL(clicked()), this, SLOT(nextTutFromRepo()));
	QObject::connect(this->addToWatchListBtn, SIGNAL(clicked()), this, SLOT(addTutToWatchList()));
	// watchlist actions
	QObject::connect(this->playWatchListBtn, SIGNAL(clicked()), this, SLOT(playWatchList()));
	QObject::connect(this->nextWatchListBtn, SIGNAL(clicked()), this, SLOT(nextWatchList()));
	QObject::connect(this->saveWatchListToFileBtn, SIGNAL(clicked()), this, SLOT(saveToFile()));
	QObject::connect(this->openWatchListBtn, SIGNAL(clicked()), this, SLOT(openWithProgram()));
	QObject::connect(this->delFromWatchListBtn, SIGNAL(clicked()), this, SLOT(deleteFromWatchList()));

}

void MyClass::populateRepoList()
{
	// clear the list, if there are elements in it
	if (this->repoList->count() > 0)
		this->repoList->clear();

	for (auto s : this->currentTutsInRepoList)
	{
		QString itemInList = QString::fromStdString(s.getTitle() + " | " + s.getPresenter());
		this->repoList->addItem(itemInList);
	}

	// set the selection on the first item in the list
	if (this->currentTutsInRepoList.size() > 0)
		this->repoList->setCurrentRow(0);
}

void MyClass::populateWatchList()
{
	// clear the list, if there are elements in it
	if (this->watchList->count() > 0)
		this->watchList->clear();

	for (auto s : this->ctrl.getWatchList()->getTuts())
	{
		QString itemInList = QString::fromStdString(s.getTitle() + " | " + s.getPresenter());
		this->watchList->addItem(itemInList);
	}
}

int MyClass::getRepoListSelectedIndex()
{
	if (this->repoList->count() == 0)
		return -1;

	// get selected index
	QModelIndexList index = this->repoList->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
	
		this->titleEdit->clear();
		this->presenterEdit->clear();
		this->durationEdit->clear();
		this->likesEdit->clear();
		this->linkEdit->clear();
		return -1;
	}

	int idx = index.at(0).row();
	return idx;
}

void MyClass::listItemChanged()
{
	int idx = this->getRepoListSelectedIndex();
	if (idx == -1)
		return;

	std::vector<Tutorial> tuts = this->currentTutsInRepoList;

	// get the tutorial at the selected index
	if (idx >= tuts.size())
		return;
	Tutorial t = tuts[idx];

	this->presenterEdit->setText(QString::fromStdString(t.getPresenter()));
	this->titleEdit->setText(QString::fromStdString(t.getTitle()));
	this->durationEdit->setText(QString::fromStdString(t.getDuration().toString()));
	this->likesEdit->setText(QString::number(t.getNrLikes()));
	this->linkEdit->setText(QString::fromStdString(t.getLink()));
	// total nr of likes in the database
	this->nrOfLikesEdit->setText(QString::number(this->ctrl.getRepo().getNrLikes()));
}



void MyClass::addTutToRepo() {
	std::string title = this->titleEdit->text().toStdString();
	std::string pres = this->presenterEdit->text().toStdString();
	std::string duration = this->durationEdit->text().toStdString();
	// get minutes and seconds
	std::vector<std::string> durationTokens = tokenize(duration, ':');
	if (durationTokens.size() != 2)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "The duration must have minutes and seconds, separated by \":\"!");
		return;
	}
	double likes = this->likesEdit->text().toDouble();
	std::string link = this->linkEdit->text().toStdString();

	try
	{
		this->ctrl.addToRepo(title, pres, stod(durationTokens[0]), stod(durationTokens[1]), likes, link);
		// refresh the list
		this->currentTutsInRepoList = this->ctrl.getRepo().getTutorials();
		this->populateRepoList();
	}
	catch (AppException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString(e.getMsg()));
	}
}

void MyClass::deleteTutFromRepo()
{
	std::string title = this->titleEdit->text().toStdString();
	std::string pres = this->presenterEdit->text().toStdString();

	try
	{
		this->ctrl.deleteFromRepo(title, pres);
		// refresh the list
		this->currentTutsInRepoList = this->ctrl.getRepo().getTutorials();
		this->populateRepoList();
	}
	catch (AppException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString(e.getMsg()));
	}
}

void MyClass::updateTutFromRepo() {
	std::string title = this->titleEdit->text().toStdString();
	std::string pres = this->presenterEdit->text().toStdString();
	double likes = this->likesEdit->text().toDouble();

	try {
		ctrl.updateFromRepo(title, pres, likes);
		// refresh the list
		this->currentTutsInRepoList = this->ctrl.getRepo().getTutorials();
		this->populateRepoList();
	}
	catch (AppException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString(e.getMsg()));
	}
}


void MyClass::filterRepoTuts()
{
	std::string pres = this->presenterEdit->text().toStdString();
	this->currentTutsInRepoList = this->ctrl.filterByPres(pres);
	this->populateRepoList();
}

void MyClass::playTutFromRepo() {
	if (this->ctrl.getRepo().getFilteredList().size() == 0)
	{
		QMessageBox msgBox;
		msgBox.setText("There are no tutorials in the database!");
		msgBox.exec();
		return;
	}

	this->ctrl.playTutsFromRepo();
	/*QMessageBox msgBox1;
	msgBox1.setText(QString::fromStdString(this->ctrl.getRepo().getCurrentTut().getLink()));
	msgBox1.exec();
	*/
}

void MyClass::nextTutFromRepo() {
	if (this->ctrl.getRepo().getFilteredList().size() == 0)
	{
		QMessageBox msgBox;
		msgBox.setText("There are no tutorials in the database!");
		msgBox.exec();
		return;
	}
	this->ctrl.nextTutorialRepo();
}

void MyClass::addTutToWatchList() {
	Tutorial t = this->ctrl.getRepo().getCurrentTut();
	this->ctrl.addTutToWatchlist(t);
	this->populateWatchList();
	QMessageBox msgBox1;
	msgBox1.setText(QString::fromStdString(this->ctrl.getWatchList()->getCurrentTutorial().getLink()));
	msgBox1.exec();


}


void MyClass::playWatchList() {
	if (this->ctrl.getWatchList()->isEmpty())
	{
		QMessageBox msgBox;

		msgBox.setText("There are no tutorials in the watchlist!");
		msgBox.exec();
		return;
	}
	this->ctrl.playTutWatchList();
	QMessageBox msgBox1;
	msgBox1.setText(QString::fromStdString(this->ctrl.getWatchList()->getCurrentTutorial().getLink()));
	msgBox1.exec();
}

void MyClass::nextWatchList() {
	if (this->ctrl.getWatchList()->isEmpty())
	{
		QMessageBox msgBox;
		msgBox.setText("There are no tutorials in the watchlist!");
		msgBox.exec();
		return;
	}
	this->ctrl.nextTutWatchlist();
}

void MyClass::deleteFromWatchList() {
	try {
		Tutorial t = this->ctrl.getWatchList()->getCurrentTutorial();
		this->ctrl.deleteTutFromWatchlist(t.getTitle(), t.getPresenter());
		// refresh list
		this->currentTutsInWatchList = this->ctrl.getWatchList()->getTuts();
		this->populateWatchList();

		QMessageBox msgBox;
		msgBox.setText("Do you want to rate the tutorial? (with a like)");
		msgBox.setStandardButtons(QMessageBox::Yes);
		msgBox.addButton(QMessageBox::No);
		msgBox.setDefaultButton(QMessageBox::No);
		if (msgBox.exec() == QMessageBox::Yes) {
			this->ctrl.increaseLikes();
			this->nrOfLikesEdit->clear();
			this->nrOfLikesEdit->setText(QString::number(this->ctrl.getRepo().getNrLikes()));
		}

	}
	catch (AppException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString(e.getMsg()));
	}
	
}

void MyClass::saveToFile() {
	std::string filename = this->fileNameEdit->text().toStdString();
	try
	{
		this->ctrl.saveWatchList(filename);
		this->fileNameEdit->clear();
		QMessageBox msgBox;
		msgBox.setText("Watch List has been successfully saved to file.");
		msgBox.exec();

		if (this->ctrl.getWatchList() == nullptr)
		{
			QMessageBox msgBox;
			msgBox.setText("Watchlist cannot be displayed!");
			msgBox.exec();
			return;
		}
	}
	catch (AppException& ex) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString(ex.getMsg()));
	}
}

void MyClass::openWithProgram() {
	this->ctrl.openWatchList();
}


void MyClass::clearLineEdits() {
	this->titleEdit->clear();
	this->presenterEdit->clear();
	this->durationEdit->clear();
	this->likesEdit->clear();
	this->linkEdit->clear();
}