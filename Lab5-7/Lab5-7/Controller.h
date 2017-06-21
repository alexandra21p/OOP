#pragma once
#include "Repository.h"
#include "WatchList.h"
#include "Validator.h"

class Controller
{

private:
	Repository repo;
	WatchList watchlist;
	Validator validator;

public:
	Controller(const Repository& r, Validator v) : repo(r), validator(v) {}

	Repository getRepo() const { return repo; }

	WatchList getWatchList() const { return watchlist; }

	// Adds a tutorial with the given data to the repository.
	void addToRepo(std::string title, std::string presenter, double minutes, double seconds, double likes, std::string link);

	// delets a tutorial with the given title & presenter
	void deleteFromRepo(std::string title, std::string presenter);

	void updateFromRepo(std::string title, std::string presenter, double likes);

	void playTutsFromRepo(std::string presenter);
	void nextTutorialRepo(std::string presenter);

	void increaseLikes();
	/*
	Adds a given tutorial to the current watchlist.
	Input: t - Tutorial, the tutorial must belong to the repository.
	Output: the tutorial is added to the watchlist.
	*/
	void addTutToWatchlist(const Tutorial& T);

	void deleteTutFromWatchlist(std::string title, std::string pres);

	void playTutWatchList();

	void nextTutWatchlist();


	~Controller();
};

