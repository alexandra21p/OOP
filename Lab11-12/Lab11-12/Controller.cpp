#include "Controller.h"
#include "FileWatchList.h"

using namespace std;

void Controller::addToRepo(std::string title, std::string presenter, double minutes, double seconds, double likes, std::string link) {
	Tutorial t{ title, presenter, Duration{ minutes, seconds }, likes, link };
	// validate the tutorial before adding
	this->validator.validate(t);
	this->repo.addTutorial(t);

}

// delets a tutorial with the given title & presenter
void Controller::deleteFromRepo(std::string title, std::string presenter) {
	Tutorial t{ title, presenter, Duration{ 0,0 }, 0, "" };
	this->repo.deleteTutorial(t);
}

void Controller::updateFromRepo(std::string title, std::string presenter, double likes) {
	Tutorial t{ title, presenter, Duration{ 0, 0 }, 0, "" };
	this->repo.updateTutorial(t, likes);
}


void Controller::increaseLikes() {
	this->repo.incrLikes();
}

vector<Tutorial> Controller::filterByPres(std::string presenter) {
	vector<Tutorial> res = this->repo.filterByPresenter(presenter);
	return res;
}

void Controller::playTutsFromRepo() {
	this->repo.playTutorials();
}

void Controller::nextTutorialRepo() {
	this->repo.next();
}


void Controller::addTutToWatchlist(const Tutorial& T) {
	if (this->watchlist == nullptr)
		return;
	this->watchlist->add(T);
}

void Controller::deleteTutFromWatchlist(std::string title, std::string pres) {
	Tutorial t{ title, pres, Duration{ 0,0 }, 0, "" };
	this->watchlist->deleteFromWatchlist(t);
}

void Controller::playTutWatchList() {
	if (this->watchlist == nullptr)
		return;
	this->watchlist->play();
}

void Controller::nextTutWatchlist() {
	if (this->watchlist == nullptr)
		return;
	this->watchlist->next();
}

void Controller::saveWatchList(const std::string& filename) {
	if (this->watchlist == nullptr)
		return;
	this->watchlist->setFilename(filename);
	this->watchlist->writeToFile();
}

void Controller::openWatchList() const {
	if (this->watchlist == nullptr)
		return;
	this->watchlist->displayWatchList();
}

Controller::~Controller() {}
