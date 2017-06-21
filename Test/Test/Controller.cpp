#include "stdafx.h"
#include "Controller.h"

using namespace std;


Controller::~Controller() {}

DynamicVector2 Controller::getRepo()
{
	DynamicVector2 v = repo.getAll();
	return v;

}

void Controller::add_gene(std::string name, std::string org, std::string seq) {
	Gene g{ name, org, seq };
	this->repo.addGene(g);
}

void Controller::delete_gene(std::string name, std::string org) {
	this->repo.deleteGene(name, org);
}
