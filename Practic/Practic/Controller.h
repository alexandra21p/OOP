#pragma once
#include "Repository.h"

class Controller
{
private:
	Repository* repo;
public:
	Controller(Repository* r) : repo(r) {}
	~Controller();
	vector<SourceCodeFile> getSourceFiles() { return repo->getFiles(); }
	
	
	void add_file(SourceCodeFile s) {
		repo->add(s);
	}

	vector<Programmer> getProgrammers() { return repo->getProgrammers(); }

	Programmer getProg(Programmer p) {
		return repo->getProgrammer(p);
	}

	void removeFile(SourceCodeFile f) {
		//SourceCodeFile f{ name, "", "", "" };
		repo->remove(f);
	}

	int updateFile(SourceCodeFile f, Programmer p) {
		if (f.getStatus() == "revised")
			throw Exception("This file has already been revised!");
		if (f.getReviewer() == p.getName()) {
			throw Exception("This programmer has already reviewed this file!");
		}
		else {
			f.setReviewer(p.getName());
			repo->update(f);

			int count = 0;
			count = p.getNrFiles() + 1;
			p.setNrFiles(count);
			repo->updateProgrammer(p);
		}
		Programmer pr = repo->getProgrammer(p);
		return pr.getNrFiles();
		
	}

};

