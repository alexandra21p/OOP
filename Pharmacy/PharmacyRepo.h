/*
 * PharmacyRepo.h
 *
 *  Created on: 24 Apr 2015
 *      Author: Alexandra
 */

#ifndef PHARMACYREPO_H_
#define PHARMACYREPO_H_

#include <vector>
#include "Medicine.h"
#include "MedicineValidator.h"
#include <memory>

class RepositoryException: public PharmacyException {
public:
	RepositoryException(string msg) :
			PharmacyException(msg) {
	}
};


/*
 * Repository for medicines
 * Abstract base class for repository (memory, file)
 */
class PharmacyRepo {
public:
    virtual vector<Medicine> undoL()=0;

    virtual void backupList()=0;


	/**
	 * Add an element at the end of the array
	 *
	 */
    virtual void store(Medicine m)=0;


	/*
	 * get the element from the list, using id
	 */
    virtual Medicine getElement(size_t id)=0;


	/**
	 * Delete the element from the list
	 */
    virtual void deleteMedicine(size_t id)=0;



	/**
	 * modify the element based on its id
	 */
    virtual void modifyMedicine(Medicine m)=0;


	/*
	 * returns number of added medicines
	 */
    virtual int getNrMedicines()=0;

	/**
	 * All the medicines from the repository
	 */
    virtual vector<Medicine> getAll()=0;


    virtual ~PharmacyRepo(){
    }

    virtual std::string toStringRepo()=0;

};

#endif /* PHARMACYREPO_H_ */
