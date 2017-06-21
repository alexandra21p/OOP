#pragma once
#include "Tutorial.h"
#include <vector>
using namespace std;


// exception class for watchlist
class WatchListException : public AppException {
public:
	WatchListException(const std::string& msg) :
		AppException(msg) {
	}
};
class WatchList
{

protected:
	vector<Tutorial> tutorials;
	int current;

public:
	WatchList();

	// Adds a tutorial to the watchlist.
	void add(const Tutorial& tut);

	// Returns the tutorial that is currently playing.
	Tutorial getCurrentTutorial();

	vector<Tutorial> getTuts() const { return tutorials; }

	// Starts the watchlist - plays the first tutorial.
	void play();

	// Plays the next tutorial in the watchlist
	void next();

	// Checks if the watchlist is empty.
	bool isEmpty();

	void deleteFromWatchlist(Tutorial t);


};
