/*
 * testRepo.h
 *
 *  Created on: 19 Apr 2015
 *      Author: Alexandra
 */

#ifndef TESTREPO_H_
#define TESTREPO_H_

#include "../Domain/Medicine.h"
#include "InMemoryPharmacyRepo.h"
#include <assert.h>

void testRepo() {
	InMemoryPharmacyRepo repo;
	assert(repo.getNrMedicines() == 0);  // test for add
	Medicine m(1, "nume", "abc", 20);
	repo.store(m);
	assert(repo.getNrMedicines() == 1);

	Medicine m2(2, "nume2", "abcd", 50);  // test for remove
	repo.store(m2);
	assert(repo.getNrMedicines() == 2);
	//repo.deleteMedicine(2);
	//assert(repo.getNrMedicines() == 1);

	Medicine m3(1, "nume3", "xx", 40); // test for modify
	repo.modifyMedicine(m3);
	assert(m3.getId() == 1);
	assert(m3.getName() == "nume3");
	assert(m3.getSubst() == "xx");
	assert(m3.getQuantity() == 40);



}

void testRepoException() {
	InMemoryPharmacyRepo repo;
	Medicine m(1, "nume", "abc", 20);
	repo.store(m);
	Medicine m2(1, "xx", "ab", 70);
	try {
		repo.store(m2);
		assert(false);
		//if we get an error here the store method should throw an exception
	} catch (RepositoryException& ex) {
		assert(true);
	}
}

#endif /* TESTREPO_H_ */
