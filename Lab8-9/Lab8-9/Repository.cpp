#include "stdafx.h"
#include <string>
#include <fstream>
#include "Repository.h"
#include "Validator.h"
#include <string>

using namespace std;

Repository::Repository(const std::string& filename) {
	this->filename = filename;
	this->readFromFile();

	this->current = 0;
	this->nrLikes = 0;
}


Repository::~Repository() {
	//delete tutorials;
}

void Repository::incrLikes()
{
	//double total = this->getNrLikes();
	double res = this->nrLikes + 1;
	this->setNrLikes(res);
	cout << "The number of likes from the repository was updated to: " << this->getNrLikes() << endl;;
}

void Repository::addTutorial(Tutorial t) {
	// make sure there are no duplicates!
	auto it = find(this->tutorials.begin(), this->tutorials.end(), t);
	if (it == this->tutorials.end()) {
		this->tutorials.push_back(t);
		this->writeToFile();
	}
	else throw RepositoryException("This tutorial already exists!");
	
}



void Repository::deleteTutorial(Tutorial t) {
	auto it = find(this->tutorials.begin(), this->tutorials.end(), t);
	if (it == this->tutorials.end()) {
		throw RepositoryException(
			"This tutorial doesn't exist!");
	}
	else this->tutorials.erase(it);
	this->writeToFile();
	
}


void Repository::updateTutorial(Tutorial t, double likes) {
	Tutorial t1;
	for (auto tut : this->tutorials)
	{
		if (tut.getTitle() == t.getTitle() && tut.getPresenter() == t.getPresenter())
			t1 = tut;
	}
	auto it = find(this->tutorials.begin(), this->tutorials.end(), t);
	if (it != this->tutorials.end()) {
		Tutorial tutt = Tutorial(t1.getTitle(), t1.getPresenter(), t1.getDuration(), likes, t1.getLink());
		this->tutorials.erase(it);
		this->tutorials.push_back(tutt);
		this->writeToFile();
	}
	else throw RepositoryException(
		"This tutorial doesn't exist!");
}


vector<Tutorial> Repository::findByPresenter(std::string presenter) {
	std::vector<Tutorial> res;
	if (presenter == "") {
		return this->tutorials;
	}
	else {
		for (auto t : this->tutorials) {
			if (t.getPresenter() == presenter) {
				res.push_back(t);
			}
		}
		return res;
	}

}

Tutorial Repository::getCurrentTut(std::string presenter) {
	std::vector<Tutorial> res = this->findByPresenter(presenter);
	if (this->current == res.size())
		this->current = 0;
	
	return this->tutorials[this->current];
	return Tutorial{};

}


void Repository::playTutorials(std::string presenter) {
	std::vector<Tutorial> res = this->findByPresenter(presenter);
	if (res.size() == 0)
		return;
	this->current = 0;
	Tutorial currentTut = this->getCurrentTut(presenter);
	currentTut.play();

}

void Repository::next(std::string presenter) {
	std::vector<Tutorial> res = this->findByPresenter(presenter);
	if (res.size() == 0)
		return;
	this->current++;
	Tutorial currentTut = this->getCurrentTut(presenter);
	currentTut.play();

}

void Repository::readFromFile() {
	ifstream file(filename);
	if (!file.is_open()) { 
		throw AppException("Unable to open file!");
	}
	Tutorial t;

	while (file >> t) {
		tutorials.push_back(t);
	}
	file.close();
}

void Repository::writeToFile() {
	ofstream file(filename);
	if (!file.is_open()) { 
		throw AppException("Unable to open file!");
	}

	for (auto elem : this->tutorials) {
		file << elem;
	}
	file.close();
}