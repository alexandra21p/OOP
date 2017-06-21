#pragma once
#include "Tutorial.h"
#include <vector>
#include <algorithm>
#include <iterator>


// exception class for repository
class RepositoryException : public AppException {
public:
	RepositoryException(const std::string& msg) :
		AppException(msg) {
	}
};


class Repository
{

private:
	std::vector<Tutorial> tutorials;
	std::string filename;

	double nrLikes;
	int current;


public:
	/*
	Constructor with parameters.
	Initializes an object of type repository, by reading data from the given file.
	Throws: FileException - if the file cannot be opened.
	*/
	Repository(const std::string& filename);


	double totalLikes() {
		double total = 0;
		for (auto t : this->tutorials) {
			total += t.getNrLikes();
		}
		return total;
	}

	double getNrLikes() {
		double total = 0;
		total = totalLikes();
		return this->nrLikes + total;
	}
	void setNrLikes(double l) { nrLikes = l; }

	

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
	void deleteTutorial(Tutorial t);

	/*
	Update a tutorial from the database
	- finds the tutorial based on the title & presenter (unique identifier)
	Input: title, presenter, likes
	Output: the fields of the corresp. Tutorial are modified
	*/

	void updateTutorial(Tutorial t, double likes);

	/*
	Finds a tutorial, by presenter
	Input: presenter - string
	Output: the tutorial that was found, or all the existing tutorials, if the input string is empty.
	*/
	std::vector<Tutorial> findByPresenter(std::string presenter);

	// returns all the tutorials from the repository
	std::vector<Tutorial> getTutorials() const { return tutorials; }
	~Repository();

	// increase the number of likes in the repository for tutorials by 1
	void incrLikes();

	void playTutorials(std::string presenter);
	void next(std::string presenter);
	Tutorial getCurrentTut(std::string presenter);

private:
	void readFromFile();
	void writeToFile();
};

