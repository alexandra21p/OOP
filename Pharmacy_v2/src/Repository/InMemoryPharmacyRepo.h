
/*
 * InMemoryPharmacyRepo.h
 *
 *  Created on: 4 Apr 2015
 *      Author: Alexandra
 */

#ifndef INMEMORYPHARMACYREPO_H_
#define INMEMORYPHARMACYREPO_H_

#include <string>
#include <vector>
//#include "../DynamicArray/DynamicArray.h"
#include "PharmacyRepo.h"
//#include "../DynamicArray/Template.h"
#include "../Domain/Medicine.h"
#include "../Domain/MedicineValidator.h"


class InMemoryPharmacyRepo: public PharmacyRepo {
public:
	/**
	 * Default constructor
	 */
	InMemoryPharmacyRepo();

	/**
	 * destructor
	 */
	virtual ~InMemoryPharmacyRepo();


	vector<Medicine>* undoL();

	void backupList();


	/**
	 * Add an element at the end of the array
	 *
	 */
	void store(Medicine m);


	/*
	 * get the element from the list, using id
	 */
	Medicine getElement(size_t id);


	/**
	 * Delete the element from the list
	 */
	void deleteMedicine(Medicine m);



	/**
	 * modify the element based on its id
	 */
	void modifyMedicine(Medicine m);

	/*
	 * returns number of added medicines
	 */
	int getNrMedicines();

	/**
	 * All the medicines from the repository
	 */
	vector<Medicine>* getAll();

	/**
	 * returns a string (used for printing)
	 */
	std::string toStringRepo();


private:
	vector<Medicine>* MedList;
	vector<vector<Medicine>* >* UndoList;
};


#endif /* INMEMORYPHARMACYREPO_H_ */
