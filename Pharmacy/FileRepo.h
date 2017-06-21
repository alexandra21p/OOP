/*
 * FileRepo.h
 *
 *  Created on: 24 Apr 2015
 *      Author: Alexandra
 */

#ifndef FILEREPO_H_
#define FILEREPO_H_

#include "PharmacyRepo.h"
#include <vector>
#include <memory>

class FileRepo: public PharmacyRepo {
public:

	FileRepo();

	FileRepo(string fname) {
		this->fname = fname;
	}
	/*
	 * store a medicine in the repository
	 */
	void store(Medicine m);


	/**
	 * Count the number of medicines in the repository
	 */
	int getNrMedicines();


	/*
	 * write to file
	 */
    void writeToFile(vector<Medicine> all);


	/**
	 * All the medicines from the repository
	 */
    vector<Medicine> getAll();


    vector<Medicine> undoL();

	void backupList();

	/*
	 * get the element from the list, using id
	 */
	Medicine getElement(size_t id);


	/**
	 * Delete the element from the list
	 */
    void deleteMedicine(size_t id);



	/**
	 * modify the element based on its id
	 */
    void modifyMedicine(Medicine m);

	std::string toStringRepo();

	~FileRepo() {
	}

private:
	string fname;
    //vector<vector<Medicine>* >* UndoList;
    vector< vector<Medicine> > UndoList;
};


#endif /* FILEREPO_H_ */
