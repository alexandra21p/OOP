#include "stdafx.h"
#include "Repository.h"

#include <string>
#include <iostream>
#include <vector>
using namespace std;


Repository::Repository() {
	//genes = new vector<Gene>();
}


Repository::~Repository() {
	//delete genes;
}

void Repository::addGene(Gene g) {
	for (int i = 0; i < this->genes.getSize(); i++) {
		if (this->genes.get(i).getName() == g.getName() && this->genes.get(i).getOrganism() == g.getOrganism()) {
			cout << "The gene already exists!!" << endl;
			return;
		}
	}
	this->genes.add(g);
	cout << "The gene has been successfully added!" << endl;
}


void Repository::deleteGene(std::string name, std::string org) {
	int ok = 0;
	Gene g;
	for (int i = 0; i <this->genes.getSize(); i++) {
		g = this->genes.get(i);
		if (g.getName() == name && g.getOrganism() == org) {
			this->genes.deleteE(i);
			ok = 1;
			cout << "The gene has been successfully deleted!" << endl;
		}
	}
	if (ok == 0) {
		cout << "The gene does not exist!!" << endl;
	}
	
}




DynamicVector2 Repository::getAll() {
	return genes;
}

