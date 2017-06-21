#pragma once
#include "Observable.h"
#include "Programmer.h"
#include "SourceCodeFile.h"
#include "Exception.h"
#include <vector>
#include <string>
#include <fstream>

class Repository : public Observable {
private:
	void readFromFile(string);
	void writeToFile();
	std::vector<Programmer> progs;
	std::vector<SourceCodeFile> files;
	void sortByName();

public:
	Repository(string filename);
	~Repository();
	std::vector<Programmer> getProgrammers() { return progs; }
	std::vector<SourceCodeFile> getFiles() { return files; }

	void add(SourceCodeFile s);
	void remove(SourceCodeFile s);
	void update(SourceCodeFile s);
	void updateProgrammer(Programmer p);

	Programmer getProgrammer(Programmer p) {
		auto it = find(progs.begin(), progs.end(), p);
		if (it != progs.end())
			return *it;
		return{ "", 0 };
	}

};

