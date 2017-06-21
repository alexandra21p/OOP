#include "Controller.h"

Controller::~Controller()
{
}

double Controller::filter(std::string nutr) {
	return this->repo.filterListFunc(nutr);
}
void Controller::sort() {
	this->repo.sortList();
}