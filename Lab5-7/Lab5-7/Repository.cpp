#include "stdafx.h"
#include <iostream>
#include "Repository.h"
#include "Validator.h"
#include <string>

using namespace std;

Repository::Repository() {
	this->current = 0;
	this->nrLikes = 0; // totalLikes();

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
	for (int i = 0; i < this->tutorials.getSize(); i++) {
		if (tutorials.get(i).getTitle() == t.getTitle() && tutorials.get(i).getPresenter() == t.getPresenter()) {
			throw RepositoryException(
				"This tutorial already exists!");
		}
	}
	this->tutorials.addE(t);
}



void Repository::deleteTutorial(std::string title, std::string pres) {
	Tutorial t;
	int ok = 0;
	for (int i = 0; i < this->tutorials.getSize(); i++) {
		t = this->tutorials.get(i);
		//cout << t.getTitle() << " and " << title << endl;
		//cout << t.getPresenter() << " and " << pres << endl;
		if (t.getTitle() == title && t.getPresenter() == pres) {
			this->tutorials.deleteElem(i);
			ok = 1;
		}
	}
	if (ok == 0) {
		throw RepositoryException(
			"This tutorial doesn't exist!");
	}
}


void Repository::updateTutorial(std::string title, std::string presenter, double likes) {
	Tutorial t;
	int ok = 0;
	//DynamicVector res = this->tutorials;
	for (int i = 0; i < this->tutorials.getSize(); i++) {
		t = this->tutorials.get(i);
		if (t.getTitle() == title && t.getPresenter() == presenter) {
			Tutorial tut = Tutorial(t.getTitle(), t.getPresenter(), t.getDuration(), likes, t.getLink());
			this->tutorials.set(i, tut);
			//t.setNrLikes(likes);
			ok = 1;
		}
	}
	if (ok == 0) {
		throw RepositoryException(
			"This tutorial doesn't exist!");
	}
	//return res;
}


TemplateArray<Tutorial> Repository::findByPresenter(std::string presenter) {
	TemplateArray<Tutorial> res;
	if (presenter == "") {
		return this->tutorials;
	}
	else {
		for (int i = 0; i < this->tutorials.getSize(); i++) {
			Tutorial t = tutorials.get(i);
			if (t.getPresenter() == presenter) {
				res.addE(t);
			}
		}
		return res;
	}

}

Tutorial Repository::getCurrentTut(std::string presenter) {
	TemplateArray<Tutorial> res = this->findByPresenter(presenter);
	if (this->current == res.getSize())
		this->current = 0;
	Tutorial* elems = res.getAllElems();
	if (elems != NULL)
		return elems[this->current];
	return Tutorial{};

}


void Repository::playTutorials(std::string presenter) {
	TemplateArray<Tutorial> res = this->findByPresenter(presenter);
	if (res.getSize() == 0)
		return;
	this->current = 0;
	Tutorial currentTut = this->getCurrentTut(presenter);
	currentTut.play();

}

void Repository::next(std::string presenter) {
	TemplateArray<Tutorial> res = this->findByPresenter(presenter);
	if (res.getSize() == 0)
		return;
	this->current++;
	Tutorial currentTut = this->getCurrentTut(presenter);
	currentTut.play();

}