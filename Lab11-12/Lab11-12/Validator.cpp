#include "Validator.h"


Validator::Validator() {}
Validator::~Validator() {}

// validators for each field of a tutorial

void Validator::validate(const Tutorial& m) {
	if (m.getTitle().length() == 0) {
		throw ValidatorException("Title field is empty !");
	}
	if (m.getPresenter().length() == 0) {
		throw ValidatorException("Presenter field is empty !");
	}
	if (m.getNrLikes() < 0) {
		throw ValidatorException("Number of likes field is negative !");
	}
	if (m.getLink().length() == 0) {
		throw ValidatorException("Link field is empty !");
	}
}
