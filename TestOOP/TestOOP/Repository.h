#pragma once
#include <vector>
#include <algorithm>
#include "Fruit.h"


class Repository {
private:
	std::vector<Fruit> fruits;
	std::vector<Fruit> sortedList;
	std::string fileName;
	std::vector<Fruit> filterList;

public:
	Repository(const std::string& fileName);
	~Repository();
	std::vector<Fruit> const getFruits() { return fruits; }
	std::vector<Fruit> const getSortedList() { return sortedList; }
	std::vector<Fruit> const getFilteredList() { return filterList; }
	/*
		function that sorts the list
	- uses a comparator predicate which compares 2 Fruit objects based on their nutrition benefits (string)
	- takes the initial list fruits and adds in the sortedList the elements then sorts them
	Result: sortedList
	*/
	void sortList();
	/*
	function that computes the total quantity of fruits with a given benefit
	filters the initial list
	Input: benefit (string)
	Result: totalQuant (double)
	*/
	double filterListFunc(std::string nutr);

private:
	void readFromFile();
};

