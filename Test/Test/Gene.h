#pragma once
#include <string>

class Gene
{
private:
	std::string name;
	std::string organism;
	std::string sequence;
public:
	// empty constructor
	Gene();
	// constructor with paramters
	Gene(std::string n, std::string o, std::string s);
	~Gene() {}

	// getters
	std::string getName() const {
		return name;
	}
	std::string getOrganism() const {
		return organism;
	}
	std::string getSequence() const {
		return sequence;
	}

};

