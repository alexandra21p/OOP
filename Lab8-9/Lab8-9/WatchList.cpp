#include "stdafx.h"
#include "WatchList.h"


WatchList::WatchList() {
	this->current = 0;
}

void WatchList::add(const Tutorial& tut)
{
	this->tutorials.push_back(tut);
}

Tutorial WatchList::getCurrentTutorial()
{
	if (this->current == this->tutorials.size())
		this->current = 0;

	this->tutorials[this->current];
	return Tutorial{};
}

void WatchList::play()
{
	if (this->tutorials.size() == 0)
		return;
	this->current = 0;
	Tutorial currentTut = this->getCurrentTutorial();
	currentTut.play();
}

void WatchList::next()
{
	if (this->tutorials.size() == 0)
		return;
	this->current++;
	Tutorial currentTut = this->getCurrentTutorial();
	currentTut.play();
}

bool WatchList::isEmpty()
{
	return this->tutorials.size() == 0;
}

void WatchList::deleteFromWatchlist(Tutorial t) {
	auto it = find(tutorials.begin(), tutorials.end(), t);
	if (it != tutorials.end()) {
		this->tutorials.erase(it);
	}
}