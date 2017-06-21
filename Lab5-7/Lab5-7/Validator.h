#pragma once
#include "Tutorial.h"
#include <string>

class ValidatorException : public AppException {
public:
	ValidatorException(std::string msg) :
		AppException(msg) {
	}

};

class Validator {
public:
	Validator();

	/**
	* validate a tutorial
	* a medicine is valid if the number of likes is >= 0,
	* the title, presenter and link fields are not empty
	* throw ValidatorException if the tutorial is invalid
	*/
	void validate(const Tutorial& t);

	~Validator();
};
