/*
 * testController.h
 *
 *  Created on: 19 Apr 2015
 *      Author: Alexandra
 */

#ifndef TESTCONTROLLER_H_
#define TESTCONTROLLER_H_

#include "../Domain/Medicine.h"
#include "../Domain/MedicineValidator.h"
#include "../Repository/PharmacyRepo.h"
#include <assert.h>

void testAdd() {
	MedicineValidator* val = new MedicineValidator();
	PharmacyRepo* repo = new InMemoryPharmacyRepo();
	PharmacyController ph(repo, val);
	Medicine m = ph.add_medicine(1, "das", "x", 20);
	assert(m.getId() == 1);
	assert(m.getName() == "das");
	assert(m.getSubst() == "x");
	assert(m.getQuantity()== 20);
}

void testDelete() {
	MedicineValidator* val = new MedicineValidator();
	PharmacyRepo* repo = new InMemoryPharmacyRepo();
	PharmacyController ph(repo, val);
	/*
	 Medicine m = ph.add_medicine(1, "das", "x", 20);
	assert(m.getId() == 1);
	assert(m.getName() == "das");
	assert(m.getSubst() == "x");
	assert(m.getQuantity()== 20);

	Medicine m2 = ph.add_medicine(2, "nume2", "xx", 30);
	assert(m.getId() == 2);
	assert(m.getName() == "nume2");
	assert(m.getSubst() == "xx");
	assert(m.getQuantity()== 30);
	*/

	ph.add_medicine(1, "aaaa", "x", 20);
	ph.add_medicine(2, "bbbb", "xx", 21);
	//ph.delete_medicine(2);
	//assert(repo->getNrMedicines() == 1);

}

void testModify() {
	MedicineValidator* val = new MedicineValidator();
	PharmacyRepo* repo = new InMemoryPharmacyRepo();
	PharmacyController ph(repo, val);
	Medicine m = ph.add_medicine(1, "das", "x", 20);
	assert(m.getId() == 1);
	assert(m.getName() == "das");
	assert(m.getSubst() == "x");
	assert(m.getQuantity() == 20);

	ph.modify_medicine(1, "abdc", "bla", 80);
	//assert(m.getId() == 1);
	//assert(m.getName() == "abdc");
	//assert(m.getSubst() == "bla");
	//assert(m.getQuantity() == 80);


}


void testFilterByName() {
	MedicineValidator* val = new MedicineValidator();
	PharmacyRepo* repo = new InMemoryPharmacyRepo();
	PharmacyController ph(repo, val);
	ph.add_medicine(1, "med", "x", 20);
	ph.add_medicine(2, "bbbb", "xx", 21);
	ph.add_medicine(3, "med", "xxx", 35);
	ph.add_medicine(4, "dddd", "xxxx", 10);
	vector<Medicine>* v = ph.filterByName("med");
	assert(v->size() == 2);
	delete v;
	v = ph.filterByName("bbbb");
	assert(v->size() == 1);
	delete v;
}

/*
void testFilterByQuantity() {
	MedicineValidator* val = new MedicineValidator();
	PharmacyRepo* repo = new InMemoryPharmacyRepo();
	PharmacyController ph(repo, val);
	ph.add_medicine(1, "aaaa", "x", 20);
	ph.add_medicine(2, "bbbb", "xx", 21);
	ph.add_medicine(3, "cccc", "xxx", 35);
	ph.add_medicine(4, "dddd", "xxxx", 10);
	vector<Medicine>* v = ph.filterByQuantity(20);
	assert(v->size() == 2);
	delete v;
	v = ph.filterByQuantity(15);
	assert(v->size() == 3);
	delete v;
}
*/

#endif /* TESTCONTROLLER_H_ */
