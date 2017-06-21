#include "stdafx.h"
#include "Controller.h"



void Controller::addToRepo(std::string title, std::string presenter, double minutes, double seconds, double likes, std::string link) {
	Tutorial t{ title, presenter, Duration{minutes, seconds}, likes, link };
	// validate the tutorial before adding
	this->validator.validate(t);
	this->repo.addTutorial(t);

}

// delets a tutorial with the given title & presenter
void Controller::deleteFromRepo(std::string title, std::string presenter) {
	this->repo.deleteTutorial(title, presenter);
}

void Controller::updateFromRepo(std::string title, std::string presenter, double likes) {
	//Tutorial t{ title, presenter, Duration{ minutes, seconds }, likes, link };
	this->repo.updateTutorial(title, presenter, likes);
}


void Controller::increaseLikes() {
	this->repo.incrLikes();
}

void Controller::playTutsFromRepo(std::string presenter) {
	this->repo.playTutorials(presenter);
}

void Controller::nextTutorialRepo(std::string presenter) {
	this->repo.next(presenter);
}


void Controller::addTutToWatchlist(const Tutorial& T) {
	this->watchlist.add(T);
}

void Controller::deleteTutFromWatchlist(std::string title, std::string pres) {
	this->watchlist.deleteFromWatchlist(title, pres);
}

void Controller::playTutWatchList() {
	this->watchlist.play();
}

void Controller::nextTutWatchlist() {
	this->watchlist.next();
}

Controller::~Controller() {}
