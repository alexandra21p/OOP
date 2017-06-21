/*
 * MedicineValidator.h
 *
 *  Created on: 16 Apr 2015
 *      Author: Alexandra
 */

#ifndef MEDICINEVALIDATOR_H_
#define MEDICINEVALIDATOR_H_

#include "Medicine.h"
#include <string>

class ValidatorException: public PharmacyException {
public:
	ValidatorException(string msg) :
		PharmacyException(msg) {
	}

};

class MedicineValidator {
public:
	/**
	 * validate a medicine
	 * a medicine is valid if the ID >= 0, quantity is >0
	 * the name and active substance fields are not empty
	 * throw ValidateException if the medicine is invalid
	 */
	void validate(const Medicine& m) ;
};


#endif /* MEDICINEVALIDATOR_H_ */
