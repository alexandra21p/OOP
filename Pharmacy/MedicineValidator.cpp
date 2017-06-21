/*
 * MedicineValidator.cpp
 *
 *  Created on: 16 Apr 2015
 *      Author: Alexandra
 */

#include "MedicineValidator.h"

// validators for each field of a medicine

void MedicineValidator::validate(const Medicine& m)  {
	if (m.getId() < 0) {
		throw ValidatorException("ID is a negative number !");
	}
	if (m.getName().length() == 0) {
		throw ValidatorException("Name is empty !");
	}
	if (m.getSubst().length() == 0) {
			throw ValidatorException("Active substance is empty !");
		}
	if (m.getQuantity() <= 0) {
		throw ValidatorException("Price is negative !");
	}
}
