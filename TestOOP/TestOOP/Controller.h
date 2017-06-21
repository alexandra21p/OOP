#pragma once
#include "Repository.h"
class Controller
{
private: 
	Repository& repo;
public:
	Controller(Repository& r) : repo(r) {}
	~Controller();
	void sort();
	double filter(std::string nutr);
	Repository getRepo() { return repo; }
};

