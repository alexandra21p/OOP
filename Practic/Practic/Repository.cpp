#include "Repository.h"
#include <algorithm>



Repository::Repository(string filename) {
	filename = "files.in";
	readFromFile(filename);
}


Repository::~Repository() {
	writeToFile();
}

void Repository::readFromFile(string filename) {
	ifstream fin("programmers.in");
	Programmer p;
	while (fin >> p) {
		progs.push_back(p);
	}
	fin.close();

	fin.open(filename);
	SourceCodeFile s;
	while (fin >> s) {
		files.push_back(s);
	}
	sortByName();
}

void Repository::writeToFile() {
	ofstream fout("resfiles_.in");
	for (auto it : files) {
		fout << it;
	}
}


/* Adds a new SourceCodeFile object in the repository file vector
	Input: s - SourceCodeFile
	Output: the element has been added into the repository, and the list has been sorted
	Throws: Exception if the name field is empty or there already exists a file with that name
*/
void Repository::add(SourceCodeFile s) {
	if (s.getName() == "")
		throw Exception("Invalid input! Name field is empty.");
	auto it = find(files.begin(), files.end(), s);
	if (it == files.end()) {
		files.push_back(s);
	}
	else throw Exception("There already is a file with that name!");
	sortByName();
	notify();
}

/* Removes a SourceCodeFile object from the repository file vector
	Input: s - SourceCodeFile
	Output: the element is removed from the list of files, and sorts the list
*/
void Repository::remove(SourceCodeFile s) {
	auto it = find(files.begin(), files.end(), s);
	if (it != files.end()) {
		files.erase(it);
	}
	sortByName();
	notify();
}


/*	Updates a SourceCodeFile object from the repository file vector
	Finds the elem by name, removes it and then replaces it with the given object s
	Input: s - SourceCodeFile
	Output: the elem with the corresponding name is replaced with the given SourceCodeObject s
*/
void Repository::update(SourceCodeFile s) {
	auto it = find(files.begin(), files.end(), s);
	if (it != files.end()) {
		files.erase(it);
		files.push_back(s);
	}
}

void Repository::updateProgrammer(Programmer p) {
	auto it = find(progs.begin(), progs.end(), p);
	if (it != progs.end()) {
		progs.erase(it);
		progs.push_back(p);
	}
}

void Repository::sortByName() {
	sort(files.begin(), files.end(), [](const SourceCodeFile &a, const SourceCodeFile &b) {
		return a.getName() < b.getName();
	});
}