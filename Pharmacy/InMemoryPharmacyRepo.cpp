/*
 * InMemoryPharmacyRepo.cpp
 *
 *  Created on: 4 Apr 2015
 *      Author: Alexandra
 */

#include "InMemoryPharmacyRepo.h"
#include <string>
#include <algorithm>
#include <memory>

using namespace std;

// creates a new dynamic array, MedList and a list of lists, UndoList
InMemoryPharmacyRepo::InMemoryPharmacyRepo() {
    vector<Medicine> MedList;
    //MedList = new vector<Medicine>();
    //UndoList = new vector<vector<Medicine>* >();
}

// destructor for MedList and UndoList
InMemoryPharmacyRepo::~InMemoryPharmacyRepo() {
    //delete MedList;
    //delete UndoList;
}




class MyClass {
public:
	MyClass(int nr) {
		n = nr;
    }

	MyClass(const MyClass &m){

		this->n=m.n;

    }

	virtual ~MyClass() {
    }
	bool operator()(Medicine m) {
		return n == m.getId();
	}
private:
	int n;
};

/*
 * implementation of the multiple undo function
 */
vector<Medicine> InMemoryPharmacyRepo::undoL() {
    if (UndoList.size() > 0) {
		int nr;
        nr = UndoList.size()-1;
        vector<Medicine> undo = UndoList.at(nr);
        UndoList.pop_back();
        MedList.clear();
        MedList.resize(undo.size());
        copy(undo.begin(), undo.end(), MedList.begin());

        //delete undo;
	}
	return MedList;

    /*vector<Medicine> undo = UndoList.at(UndoList.size()-1);
    MedList.clear();
    for_each(undo.begin(), undo.end(), [&](Medicine m){
        MedList.push_back(m);
     });

    int n;
    n = UndoList.size()-1;
    UndoList.erase(UndoList.begin() + n);
    */
}


/*
 * undo function - saves the list before the undo operation
*/
void InMemoryPharmacyRepo::backupList() {
	/*
	for(size_t i=0; i < MedList->size(); i++)
	{
		Medicine m = MedList->at(i);
		int id;
		int quantity;
		std::string name, activ_subst;
		id = m.getId();
		name = m.getName();
		activ_subst = m.getSubst();
		quantity = m.getQuantity();
		Medicine med = Medicine(id,name,activ_subst,quantity);

		undo.push_back(med);
	}

	UndoList->push_back(undo);
    */

    vector<Medicine> undo = vector<Medicine>(MedList.size());
    copy(MedList.begin(), MedList.end(), undo.begin());
    UndoList.push_back(undo);

    //vector<Medicine> undo = getAll();
    //UndoList.push_back(undo);
}


/**
 * Add an element at the end of the array
 * throw RepositoryException if a medicine with the same id already exists
 */
void InMemoryPharmacyRepo::store(Medicine m){
	//verify if we have a medicine with the same id - NO duplicates allowed !

	/*
	for (size_t i = 0; i < MedList->size(); i++) {
		if (MedList->at(i).getId() == m.getId()) {
			throw RepositoryException(
					"Medicine with the same ID already exists !");
		}
	}
	MedList->push_back(m);
}
	 */
    int id;
    auto it = find_if(MedList.begin(), MedList.end(), [&](const Medicine& m){
        return m.getId()==id;
    });

    if (it == MedList.end()) {
        MedList.push_back(m);
	}
	else
		throw RepositoryException(
							"Medicine with the same ID already exists !");
}

/*
 * get the element from the list, using id
 */
Medicine InMemoryPharmacyRepo::getElement(size_t id){
    return MedList.at(id);
}


/*
 * Count the number of medicines in the repository
 */
int InMemoryPharmacyRepo::getNrMedicines() {
    return MedList.size();
}

 // get all medicines from the repository
vector<Medicine> InMemoryPharmacyRepo::getAll() {
	return MedList;
}


/**
 * Delete the element from the list
*/
void InMemoryPharmacyRepo::deleteMedicine(size_t id) {
	//all->erase(all->begin()+ id);
	//return MedList->erase(MedList->begin() + id);
    vector<Medicine>::iterator it = find_if(MedList.begin(), MedList.end(), [&](const Medicine& m){
        return m.getId()==id;
    });
    if (it != MedList.end()) {
        MedList.erase(it);
	}

}


/**
 * modify the element based on its id
 */
void InMemoryPharmacyRepo::modifyMedicine(Medicine m) {
	//MedList->at(id) = m;
	//MedList->insert(m, poz);
    vector<Medicine>::iterator it = find_if(MedList.begin(), MedList.end(), MyClass(m.getId()));
    if (it != MedList.end()) {
		//all->at(id) = m;
        MedList.erase(it);
        MedList.insert(it, m);
	}
	else
		throw RepositoryException("Medicine not found !");
}



/**
 * returns a string (used for printing)
 */
std::string InMemoryPharmacyRepo::toStringRepo() {
	string rez = "";
	Medicine p;
	Medicine m;
    for (size_t i = 0; i < MedList.size(); i++) {
        p = MedList.at(i);
        //m = p;
		rez += m.toString();
		rez += "\n";
	}
	return rez;
}
