/*
 * Medicine.h
 *
 *  Created on: 31 Mar 2015
 *      Author: Alexandra
 */

#ifndef MEDICINE_H_
#define MEDICINE_H_


#include <string>
#include <iostream>
#include <sstream>
using namespace std;

// template for string printing, converts int to string
namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
    	//create an output string stream
        std::ostringstream stm ;
        //throw the value into the string stream
        stm << n ;
        //convert the string stream into a string and return
        return stm.str() ;
    }
}



class Medicine {
public:

	Medicine(const Medicine& ot) :
				id(ot.id), name(ot.name), activ_subst(ot.activ_subst), quantity(ot.quantity) {
		}


	/**
	 * Constructor, initialise the medicine
	 * i - unique id
	 * n - name of the medicine
	 * s - active substance of the medicine
	 * q - quantity of the medicine
	 */
	Medicine(int i, string n, string s, int q);
	Medicine();

	/* Medicine(int id, string name, string activ_subst, int quantity) {
		this->id = id;
		this->name = name;
		this->activ_subst = activ_subst;
		this->quantity = quantity;
	}
	 */

	// destructor
	~Medicine(){
	}

/*
 * getters for id, name, active substance and quantity
 */
	int getId() const {
		return id;
	}
	string getName() const {
		return name;
	}
	string getSubst() const {
		return activ_subst;
	}
	int getQuantity() const {
		return quantity;
	}

/*
 * setters for id, name, active substance and quantity - DON'T NEED THEM ANYMORE
 */
	void setId(int id) {
		this->id = id;
	}
	void setName(string name) {
			this->name = name;
		}
	void SetSubstance(string activ_subst) {
		this->activ_subst = activ_subst;
	}
	void SetQuantity(int quantity) {
		this->quantity = quantity;
	}


//virtual string toString();
//string Medicine::toString(){
//	return "ID: " + id + "Name: " + name + "Active Substance: " + activ_subst + "Quantity: " + quantity; }


	// function to print the string
	std::string toString(){
		std::string rez;
		rez+="ID: ";
		std::string ID = patch::to_string(this->getId());

		rez+=ID;
		rez+="   ";
		rez+="Name: ";
		rez+=this->getName();
		rez+="   ";
		rez+="Active Substance: ";
		rez+=this->getSubst();
		rez+="   ";

		rez+="Quantity: ";
		std::string am = patch::to_string(this->getQuantity());
		rez+=am;
		rez+="   ";
		return rez;
	}

	// declaration of class elements
private:
	int id;
	string name;
	string activ_subst;
	int quantity;
};


/**
 * Generic exception used in the application
 * We will derive specialised exceptions from this class
 */
class PharmacyException {
public:
	PharmacyException(string& msg) {
		this->msg = msg;
	}
	const string& getMsg() const {
		return msg;
	}

private:
	string msg;
};


#endif /* MEDICINE_H_ */
