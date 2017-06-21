#include "Repository.h"
#include <fstream>
#include <string>
#include <exception>



Repository::Repository(const std::string& fileName) {
	this->fileName = fileName;
	readFromFile();
}

Repository::~Repository() {}

void Repository::readFromFile() {
	std::ifstream file(fileName);

	//if (!file.is_open())
		//throw exception("The file could not be opened!");

	Fruit f;
	while (file >> f)
		this->fruits.push_back(f);

	file.close();
}

bool comp(const Fruit& f1, const Fruit& f2) {
	return f1.getNutr() < f2.getNutr();
}
void Repository::sortList() {
	if (sortedList.size() > 0) {
	sortedList.erase(sortedList.begin(), sortedList.end());

	}
	for (auto elem : fruits) {
		sortedList.push_back(elem);
	}
	std::sort(sortedList.begin(), sortedList.end(), comp);
}

double Repository::filterListFunc(std::string nutr) {
	double res = 0;
	if (filterList.size() > 0) {
		filterList.erase(filterList.begin(), filterList.end());
	}
	for (auto elems : fruits) {
		if (elems.getNutr() == nutr) {
			filterList.push_back(elems);
		}
	}
	for (auto el : filterList) {
		res += el.getQuantity();
	}
	return res;

}
