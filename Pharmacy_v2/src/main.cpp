/*
 * main.cpp
 *
 *  Created on: 17 Apr 2015
 *      Author: Alexandra
 */

#include <iostream>
#include "Domain/testMedicine.h"
#include "Repository/testRepo.h"
#include "UI/PharmacyUI.h"
#include "Repository/FileRepo.h"
#include "Repository/InMemoryPharmacyRepo.h"
#include "Controller/testController.h"
//#include "cppMemDbg.h"
using namespace std;

void testApp() {
	//Functionality - add a product
	testCreateMedicine();
	testValidateMedicine();
	testRepo();
	testRepoException();
	testAdd();
	testDelete();
	testModify();
	testFilterByName();
	//testFilterByQuantity();

}

void startApp() {
	//create validator
	MedicineValidator* val = new MedicineValidator();

	//create repository
	//PharmacyRepo* repo = new InMemoryPharmacyRepo();
	PharmacyRepo* repo = new FileRepo();

	//create controller
	PharmacyController ph(repo, val);


	/*
	 * add 3 elements to the list when the application starts
	 * when using FileRepo, throw PharmacyException if the elements already exist
	*/
	try {
		ph.add_medicine(4,"ibuprofen","abcxx",15);
		ph.add_medicine(10,"medication","bbxx",100);
		ph.add_medicine(5,"med3","ccxx",35);
	} catch (PharmacyException& ex) {
			cout << "ERROR: " << ex.getMsg() << endl;
	} catch (...) {
			cout << "unknown exception";
	}

	//create ui
	ConsoleUI ui(&ph);

	//start ui
	ui.showUI();
}
int main() {
	testApp();
	startApp();
	//PrintMemoryLeakInfo();
	return 0;
}
