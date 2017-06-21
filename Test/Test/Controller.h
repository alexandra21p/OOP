#pragma once
#include "Repository.h"
#include <string>
#include <vector>

class Controller
{
private:
	Repository repo;
public:
	// constructor for controller
	Controller(Repository r) : repo(r) {}
	~Controller();

	DynamicVector2 getRepo();

	void add_gene(std::string name, std::string org, std::string seq);
	void delete_gene(std::string name, std::string org);
};

