/*
 * FileRepo.cpp
 *
 *  Created on: 24 Apr 2015
 *      Author: Alexandra
 */

#include "FileRepo.h"
#include "../Domain/Medicine.h"
#include <string>
#include <fstream>
#include <algorithm>


FileRepo::FileRepo() {
	fname = "data.txt";
	UndoList = new vector<vector<Medicine>* >();
}


class MyClass {
public:
	MyClass(int nr) {
		n = nr;
	};

	MyClass(const MyClass &m){

		this->n=m.n;

	};

	virtual ~MyClass() {
	}	;
	bool operator()(Medicine m) {
		return n == m.getId();
	}
private:
	int n;
};


void FileRepo::store(Medicine m) {
	vector<Medicine>* all = getAll();

	//verify if we have a medicine with the same id
	vector<Medicine>::iterator it = find_if(all->begin(), all->end(), MyClass(m.getId()));
	if (it == all->end()) {
		all->push_back(m);
	}
	else
		throw RepositoryException(
				"Medicine with the same ID already exists!");

	//store to file
	ofstream out(fname.c_str());
	if (!out.is_open()) {  // verify if the stream is opened
		std::string msg("Unable to open file: ");
		throw PharmacyException(msg);
	}

	// iterate medicines
	vector<Medicine>::iterator iter = all->begin();
	while (iter != all->end()) {
		Medicine m = *iter;
		out << m.getId();
		out << endl;
		out << m.getName();
		out << endl;
		out << m.getSubst();
		out << endl;
		out << m.getQuantity();
		out << endl;
		iter++;
	}
	out.close();
	delete all;
}


// writes to file
void FileRepo::writeToFile(vector<Medicine>* all) {
	ofstream out(fname.c_str());
	if (!out.is_open()) {  // verify if the stream is opened
		std::string msg("Unable to open file: ");
		throw PharmacyException(msg);
	}

	// iterate medicines
	vector<Medicine>::iterator it = all->begin();
	while (it != all->end()) {
		Medicine m = *it;
		out << m.getId();
		out << endl;
		out << m.getName();
		out << endl;
		out << m.getSubst();
		out << endl;
		out << m.getQuantity();
		out << endl;
		it++;
	}
	out.close();
}

/**
 * Count the number of medicines in the repository
 */
int FileRepo::getNrMedicines() {
	vector<Medicine>* all = getAll();
	int rez = all->size();
	delete all;
	return rez;
}

/**
 * reads from file
 * All the medicines from the repository
 */
vector<Medicine>* FileRepo::getAll() {
	ifstream in(fname.c_str());
	if (!in.is_open()) { //verify if the stream is opened
		std::string msg("Unable to open file: data.txt");
		throw PharmacyException(msg);
	}
	vector<Medicine>* rez = new vector<Medicine>;
	while (!in.eof()) {
		int id;
		string name;
		string activ_subst;
		int quantity;
		in >> id;
		if (in.eof()) {
			// did not manage to read the number
			break;
		}
		in >> name;
		in >> activ_subst;
		in >> quantity;
		Medicine m(id, name, activ_subst, quantity);
		rez->push_back(m);
	}
	in.close();
	return rez;
}




/**
 * Delete the element from the file
*/
void FileRepo::deleteMedicine(Medicine m) {
	vector<Medicine>* all = getAll();
	//all->erase(all->begin() + id);
	vector<Medicine>::iterator it = find_if(all->begin(), all->end(), MyClass(m.getId()));
	if (it != all->end()) {
		all->erase(it);
	}
	writeToFile(all);
	delete all;
}


/**
 * modify the element based on its id
*/
void FileRepo::modifyMedicine(Medicine m) {
	vector<Medicine>* all = getAll();
	vector<Medicine>::iterator it = find_if(all->begin(), all->end(), MyClass(m.getId()));
	if (it != all->end()) {
		//all->at(id) = m;
		all->erase(it);
		all->insert(it, m);
	}
	writeToFile(all);
	delete all;
}


/**
 * returns a string (used for printing)
 */
std::string FileRepo::toStringRepo() {
	string rez = "";
	Medicine p;
	Medicine m;
	vector<Medicine>* all = getAll();
	for (size_t i = 0; i < all->size(); i++) {
		p = all->at(i);
		m = p;
		rez += m.toString();
		rez += "\n";
	}
	return rez;
}

/*
 * get the element from the list index
 */
Medicine FileRepo::getElement(size_t index){
	vector<Medicine>* all = getAll();
	return all->at(index);
}



/*
 * undo function - saves the list before the undo operation
*/
void FileRepo::backupList() {
	/*
	vector<Medicine>::iterator it = all->begin();
	while (it != all->end()) {
		Medicine m = *it;
		int id;
		int quantity;
		string name, activ_subst;
		id = m.getId();
		name = m.getName();
		activ_subst = m.getSubst();
		quantity = m.getQuantity();
		Medicine med = Medicine(id,name,activ_subst,quantity);

		undo.push_back(med);
		it++;
	}

	UndoList->push_back(undo);
	*/
	vector<Medicine>* all = getAll();
	vector<Medicine>* undo = new vector<Medicine>(all->size());
	copy(all->begin(), all->end(), undo->begin());

	UndoList->push_back(undo);
}



/*
 * implementation of the multiple undo function
 */
vector<Medicine>* FileRepo::undoL() {
	/*
	vector<Medicine>* all = getAll();

	if (UndoList->size() > 0) {
		int nr = UndoList->size() - 1;
		vector<Medicine> undo = UndoList->at(nr);
		UndoList->pop_back();
		all->clear();
		for (size_t i=0; i<undo.size(); i++) {
			all->push_back(undo.at(i));
		}
	}
	writeToFile(all);
	return all;
	*/
	vector<Medicine>* all = getAll();
	if (UndoList->size() > 0) {
		int nr;
		nr = UndoList->size()-1;
		vector<Medicine>* undo = UndoList->at(nr);
		UndoList->pop_back();
		all->clear();
		all->resize(undo->size());
		copy(undo->begin(), undo->end(), all->begin());

		delete undo;
		}
	return all;
}

