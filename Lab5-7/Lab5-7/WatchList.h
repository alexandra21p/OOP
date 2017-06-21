#pragma once
//#include "DynamicVector.h"
#include "Template.h"
#include "Tutorial.h"


class WatchList
{

private:
	TemplateArray<Tutorial> tutorials;
	int current;

public:
	WatchList();

	// Adds a tutorial to the watchlist.
	void add(const Tutorial& tut);

	// Returns the tutorial that is currently playing.
	Tutorial getCurrentTutorial();

	TemplateArray<Tutorial> getTuts() const { return tutorials; }

	// Starts the watchlist - plays the first tutorial.
	void play();

	// Plays the next tutorial in the watchlist
	void next();

	// Checks if the watchlist is empty.
	bool isEmpty();

	void deleteFromWatchlist(std::string title, std::string pres);


};

