/*
 * PharmacyController.cpp
 *
 *  Created on: 4 Apr 2015
 *      Author: Alexandra
 */

#include "PharmacyController.h"
#include <algorithm>

//constructor
PharmacyController::PharmacyController(PharmacyRepo* repo, MedicineValidator* val) {
	this->repo = repo;
	validator = val;
}

// destructor
PharmacyController::~PharmacyController() {
	delete repo;
	delete validator;
}



/*
 * controller function for multiple undo operations
 */
vector<Medicine>* PharmacyController::undoController(){
	return repo->undoL();
}


/**
 * Add a medicine
 * prec: element: int id, string name, string activ_subst, int quantity
 * post: the element is added
 * Throw ValidatorException if the medicine is invalid
 * throw RepositoryExcepiton if a medicine with the given id already exists
 */
Medicine PharmacyController::add_medicine(int id, string name, string activ_subst, int quantity){
	// make a copy of the list
	repo->backupList();
	//create medicine
	Medicine m(id, name, activ_subst, quantity);
	//validate medicine
	validator->validate(m);
	//store medicine
	repo->store(m);
	return m;
}


/**
 * Delete the element from the list, based on its ID
 * return the deleted element
*/
void PharmacyController::delete_medicine(int id){
	/*repo->backupList();
	Medicine m;
	for (size_t i=0; i < repo->getNrMedicines(); i++) {
		m = repo->getElement(i);
	    if (m.getId() == id)
	    	repo->deleteMedicine(i);
	}
	*/
	repo->backupList();
	Medicine m(id, "", "", 0);
	repo->deleteMedicine(m);
}

/**
 * modify the element by its id
 * prec: int id
 * post: element is modified(name, active substance, quantity)
 */
void PharmacyController::modify_medicine(int id, string name, string activ_subst, int quantity){
	repo->backupList();
	Medicine m;
	/*
	for (i=0; i < repo->getNrMedicines(); i++){
		m = repo->getElement(i);
		if (m.getId() == id) {
			Medicine med = Medicine(id, name, activ_subst, quantity);
			repo->modifyMedicine(med, i);
		}
	}
	*/
	Medicine med = Medicine(id, name, activ_subst, quantity);
	repo->modifyMedicine(med);

}

/*
 * filter by name
 * prec: string name
 * post: returns a new list containing only the filtered elements
 */
vector<Medicine>* PharmacyController::filterByName(string name) {
	vector<Medicine>* all = repo->getAll();
	vector<Medicine>* rez = new vector<Medicine>(all->size());
	//std::vector<Medicine>::iterator it = remove_copy_if(all->begin(), all->end(), rez->begin(), FName(name));
	//rez->erase(it, rez->end());
	rez->erase(remove_copy_if(all->begin(), all->end(), rez->begin(), FName(name)), rez->end());

	return rez;
	/*
	for (size_t i = 0; i < all->size(); i++) {
		Medicine m = all->at(i);
		if (m.getName().compare(name) == 0) {
			//make a copy of the medicine
			rez->push_back(m);
		}
	}
	*/
}


/*
 * Filter by quantity
 * returns a new list containing only the filtered elements
 */

vector<Medicine>* PharmacyController::filterByQuantity(int quant) {
	/*
	vector<Medicine>* rez = new vector<Medicine>();
	vector<Medicine>* all = repo->getAll();


	for (size_t i = 0; i < all->size(); i++) {
		Medicine m = all->at(i);
		if (m.getQuantity() > quant) {
			//make a copy of the medicine
			rez->push_back(m);
		}
	}
	return rez;
	*/
	vector<Medicine>* rez = new vector<Medicine>();
	vector<Medicine>* all = repo->getAll();
	rez->resize(all->size());
	std::vector<Medicine>::iterator it = std::remove_copy_if(all->begin(), all->end(), rez->begin(), FQuant(quant));
	rez->erase(it, rez->end());
	return rez;
}

vector<Medicine>* PharmacyController::getAllMeds() {
	vector<Medicine>* rez = repo->getAll();
	return rez;
}

/**
 * comp is a parameter of type function
 * sort medicine in any order, order given by the comp param
 * return sorted medicines
 */
vector<Medicine>* PharmacyController::sortBy(bool comp(Medicine, Medicine)) {
	vector<Medicine>* all = repo->getAll();
	vector<Medicine>* rez = new vector<Medicine>(all->size());
	//make a copy so the repository is not affected
	copy(all->begin(), all->end(), rez->begin());
	//sort by price
	sort(rez->begin(), rez->end(), comp);
	return rez;
}

bool byQuantity(Medicine m1, Medicine m2) {
	return m1.getQuantity() < m2.getQuantity();
}

vector<Medicine>* PharmacyController::sortByQuantity() {
	return sortBy(byQuantity);
}

// prints the string
std::string PharmacyController::printController() {
return repo->toStringRepo();
}


