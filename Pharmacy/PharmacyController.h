/*
 * PharmacyController.h
 *
 *  Created on: 4 Apr 2015
 *      Author: Alexandra
 */

#ifndef PHARMACYCONTROLLER_H_
#define PHARMACYCONTROLLER_H_

#include <string>
#include <vector>
#include "Medicine.h"
#include "MedicineValidator.h"
#include "PharmacyRepo.h"


class PharmacyController {
public:
	/**
	 * controller constructor, contains repo and validator
	 */
    PharmacyController();

    PharmacyController(unique_ptr<PharmacyRepo> repo, unique_ptr<MedicineValidator> val);
    //PharmacyController(PharmacyRepo* repo, MedicineValidator* val);

	/**
	 * Responsible with de-allocating the repo and the validator
	 */
	virtual ~PharmacyController();


	/*
	 * controller function for multiple undo
	 */
    void undoController();


	/**
	 * Add a medicine
	 * pre: element: int id, string name, string activ_subst, int quantity
	 * post: the element is added
	 * Throw ValidatorException if the medicine is invalid
	 * throw RepositoryExcepiton if a medicine with the given id already exists
	 */
	Medicine add_medicine(int id, string name, string activ_subst, int quantity);


	/**
	 * Delete the element from the list (based on its ID)

	 * return the deleted element
	 */
	void delete_medicine(int id);



	/**
	 * modify the element at the element by its id.
	 * pre: int id
	 * post:  - element is modified(name, active substance, quantity)
	 *        - the id remains unchanged
	 */
	void modify_medicine(int id, string name, string activ_subst, int quantity);
	/*
	 * Filter by name
	 * pre: string name
	 * post: returns a new list containing only the filtered elements
	 */


	/*
	 * return the list of medicines
	 */
    vector<Medicine> getAllMeds();

    vector<Medicine> filterByName(string name);


	/*
	 * Filter by quantity
	 * pre: int quantity
	 * post: returns a new list containing only the filtered elements
	 */
    vector<Medicine> filterByQuantity(int quant);


    vector<Medicine> sortByQuantity();

	/**
	 * returns a string (used for printing)
	 */
	std::string printController();


private:
    //PharmacyRepo* repo;
    //MedicineValidator* validator;
    unique_ptr<PharmacyRepo> repo;
    unique_ptr<MedicineValidator> validator;

	/**
	 * comp is a parameter of type function
	 * sort medicine in any order, order given by the comp param
	 */
    vector<Medicine> sortBy(bool comp(Medicine, Medicine));
};

class FQuant {
public:
	    FQuant(int q){
	    	quantity = q;
        }
        virtual ~FQuant() {
        }
        bool operator()(Medicine m){
                return quantity > m.getQuantity();
        }
private:
        int quantity;
};


class FName {
public:
        FName(string n){
        	name = n;
        }
        virtual ~FName(){
        }
        bool operator()(Medicine m){
                return name !=m.getName();
        }
private:
        string name;
};



#endif /* PHARMACYCONTROLLER_H_ */
