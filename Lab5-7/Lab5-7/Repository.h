#pragma once
#include "Tutorial.h"
//#include "DynamicVector.h"
#include "Template.h"

class Repository
{

private:
	TemplateArray<Tutorial> tutorials;
	double nrLikes;
	int current;

public:

	double totalLikes() { 
		double total = 0;
		for (int i = 0; i < this->tutorials.getSize(); i++) {
			total += tutorials.get(i).getNrLikes();
		}
		return total; 
	}

	double getNrLikes() { 
		double total = 0;
		total = totalLikes();
		return this->nrLikes + total;
	}
	void setNrLikes(double l) { nrLikes = l; }

	Repository();

	/*
	Adds a tutorial to the repository (database).
	Input: t - Tutorial.
	Output: the tutorial is added to the repository.
	*/
	void addTutorial(Tutorial t);

	/*
	Remove a tutorial
	Input: title, pres - string
	Output: the tutorial is deleted from the repository (database)
	*/
	void deleteTutorial(std::string title, std::string pres);

	/*
	Update a tutorial from the database
	- finds the tutorial based on the title & presenter (unique identifier)
	Input: title, presenter, likes
	Output: the fields of the corresp. Tutorial are modified 
	*/

	void updateTutorial(std::string title, std::string presenter, double likes);

	/*
	Finds a tutorial, by presenter
	Input: presenter - string
	Output: the tutorial that was found, or all the existing tutorials, if the input string is empty.
	*/
	TemplateArray<Tutorial> findByPresenter(std::string presenter);

	// returns all the tutorials from the repository
	TemplateArray<Tutorial> getTutorials() const { return tutorials; }
	~Repository();

	// increase the number of likes in the repository for tutorials by 1
	void incrLikes();

	void playTutorials(std::string presenter);
	void next(std::string presenter);
	Tutorial getCurrentTut(std::string presenter);
};

// exception class for repository
class RepositoryException : public AppException {
public:
	RepositoryException(const std::string& msg) :
		AppException(msg) {
	}
};