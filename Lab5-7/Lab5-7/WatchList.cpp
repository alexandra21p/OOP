#include "stdafx.h"
#include "WatchList.h"


WatchList::WatchList() {
	this->current = 0;
}

void WatchList::add(const Tutorial& tut)
{
	this->tutorials.addE(tut);
}

Tutorial WatchList::getCurrentTutorial()
{
	if (this->current == this->tutorials.getSize())
		this->current = 0;

	Tutorial* elems = this->tutorials.getAllElems();
	if (elems != NULL)
		return elems[this->current];
	return Tutorial{};
}

void WatchList::play()
{
	if (this->tutorials.getSize() == 0)
		return;
	this->current = 0;
	Tutorial currentTut = this->getCurrentTutorial();
	currentTut.play();
}

void WatchList::next()
{
	if (this->tutorials.getSize() == 0)
		return;
	this->current++;
	Tutorial currentTut = this->getCurrentTutorial();
	currentTut.play();
}

bool WatchList::isEmpty()
{
	return this->tutorials.getSize() == 0;
}

void WatchList::deleteFromWatchlist(std::string title, std::string pres) {
	Tutorial t;
	for (int i = 0; i < this->tutorials.getSize(); i++) {
		t = this->tutorials.get(i);
		if (t.getTitle() == title && t.getPresenter() == pres) {
			this->tutorials.deleteElem(i);
		}
	}

}
