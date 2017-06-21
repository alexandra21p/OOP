#pragma once
#include "Gene.h"
#include <string>
#include <vector>
//using namespace std;
#include "DynamicVector2.h"

class Repository
{

private:
	DynamicVector2 genes;

public:
	Repository();
	~Repository();

	/*
	* adds a gene in the repository
	* Input: Gene g
	* Output: the gene is added in the repository
	*/
	void addGene(Gene g);

	/*
	* deletes a gene from the repository based on the name & organism
	* Input: name, org - string
	* Output: the gene is deleted from the repository
	*/
	void deleteGene(std::string name, std::string org);

	// returns the list with all elements
	DynamicVector2 getAll();
};

