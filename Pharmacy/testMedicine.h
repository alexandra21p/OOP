/*
 * testMedicine.h
 *
 *  Created on: 16 Apr 2015
 *      Author: Alexandra
 */

#ifndef TESTMEDICINE_H_
#define TESTMEDICINE_H_

#include <assert.h>
#include "MedicineValidator.h"
#include "Medicine.h"

void testCreateMedicine() {
	Medicine m(1, "nume", "abc", 50);
	assert(m.getId() == 1);
	assert(m.getName() == "nume");
	assert(m.getSubst() == "abc");
	assert(m.getQuantity() == 50);
}

void testValidateMedicine() {
	Medicine m(1, "nume", "abc", 50);
	MedicineValidator val;
	val.validate(m);

    Medicine m1(-1, "nume", "abc", 50);
	try {
		val.validate(m1);
		assert(false);
	} catch (ValidatorException& e) {
		assert(true);
	}

	Medicine m2(1, "", "abc", 50);
	try {
		val.validate(m2);
		assert(false);
	} catch (ValidatorException& e) {
		assert(true);
	}

	Medicine m3(1, "nume", "", 50);
	try {
		val.validate(m3);
		assert(false);
	} catch (ValidatorException& e) {
		assert(true);
	}

	Medicine m4(1, "nume", "abc", 0);
		try {
			val.validate(m4);
			assert(false);
		} catch (ValidatorException& e) {
			assert(true);
		}
}


#endif /* TESTMEDICINE_H_ */
