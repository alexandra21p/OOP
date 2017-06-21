/*
================================================================================
	Name        : PharmacyUI.cpp
	Author      : Alexandra
	Description :

	~ P5. Pharmacy management

Create an application to manage the stock of medicines (id, name,active substance,
quantity in stock) in a pharmacy.
1. Add a new medicine.
2. Modify medicine.
3. Remove medicine
4. Filter.
 	- by name
 	- by quantity
5. Undo the last operation.
- undo – the last operation that has modified the list of medicines is cancelled

================================================================================
*/

#include <iostream>
#include <string>
#include "PharmacyUI.h"
#include <algorithm>

using namespace std;

/*
 * initialises the console
 */
ConsoleUI::ConsoleUI(PharmacyController *con) {
	ph = con;
}


/**
 * Prints the menu and reads the user command
 * returns the selected menu index
 */
int ConsoleUI::readUserCommand(){

	cout<<"\n- PHARMACY MANAGEMENT-\n"<<endl;

	cout<<" Welcome ! "<<endl;

	cout<<"0 to EXIT."<<endl;

	cout<<"1. Add a medicine."<<endl;

	cout<<"2. Remove a medicine."<<endl;

	cout<<"3. Modify a medicine."<<endl;

	cout<<"4. Show all medicines."<<endl;

	cout<<"5. Filter by name."<<endl;

	cout<<"6. Filter by quantity."<<endl;

	cout<<"7. Undo the last operation."<<endl;

	cout<<"8. Sort by quantity."<<endl;

	cout<<" ~ Choose an option: "<<endl;

	int cmd;
	cin>>cmd;
	return cmd;

}

/*
 * UI function for adding a medicine
 * prec: int id, string name, string activ_subst, int quantity
 * post: medicine is added
 */
void ConsoleUI::uiAdd(){
	int id;
	string name;
	string activ_subst;
	int quantity;
	cout<<"Enter ID: ";
	cin>>id;
	cout<<"Enter name: ";
	cin>>name;
	cout<<"Enter the active substance: ";
	cin>>activ_subst;
	cout<<"Enter a new quantity: ";
	cin>>quantity;
	try {
		Medicine m = ph->add_medicine(id, name, activ_subst, quantity);
		cout<<"The medicine has been added! "<<endl;
	} catch (PharmacyException& ex) {
		cout << "ERROR: " << ex.getMsg() << endl;
	} catch (...) {
		cout << "unknown exception";
	}
}

/*
 * UI function for deleting a medicine based on its ID
 * prec: int id given by the user
 * post: element with given ID is deleted
 */
void ConsoleUI::uiDelete(){
	int id;
	cout<<"Enter ID for the element you want to delete: ";
	cin>>id;
	ph->delete_medicine(id);
	cout<<"The medicine has been deleted! "<<endl;
}


/*
 * UI function for modifying a medicine; searches for the element with the given id and updates
 * its characteristics: name, active substance, quantity
 * prec: int id given by the user
 * post: the element is updated
 */
void ConsoleUI::uiModify(){
	int id, quantity;
	string name,activ_subst;
	cout<<"Input the ID for the medicine that will be modified: ";
	cin>>id;
	cout<<"Input the new name: ";
	cin>>name;
	cout<<"Enter new substance: ";
	cin>>activ_subst;
	cout<<"Enter new quantity: ";
	cin>>quantity;
	ph->modify_medicine(id, name, activ_subst, quantity);

}


/*
 * to print them as a table 'n shit
 *
void print() {
	cout.width(10);
	cout <<"ID: ";
	cout.width(20);
	cout << "Name: ";
	cout.width(20);
	cout << "Active Substance: ";
	cout.width(10);
	cout << "Quantity: ";
	cout << endl;
}


void printMedicine(Medicine m) {
	cout.width(10);
	cout << m.getId();
	cout.width(20);
	cout << m.getName();
	cout.width(20);
	cout << m.getSubst();
	cout.width(10);
	cout << m.getQuantity();
	cout << endl;
}

*/

void printMed(Medicine m) {
	cout <<"ID: " << m.getId() << "   ";
	cout << "Name: " << m.getName() << "   ";
	cout << "Active Substance: " << m.getSubst() << "   ";
	cout << "Quantity: " << m.getQuantity();
	cout << endl;
}

void  printMedicines(vector<Medicine>* rez) {
	//print();
	for_each(rez->begin(), rez->end(), printMed);
}



/*
 * ui function that filters based on the name input by the user
 */
void ConsoleUI::uiFilterName() {
	cout << "Enter the name: ";
	string name;
	cin >> name;
	vector<Medicine>* rez = ph->filterByName(name);
	for_each(rez->begin(), rez->end(), printMed);
	delete rez;
}

/*
 * ui function that filters based on the quantity input by the user
 * returns a new list containing only the corresponding filtered elements
 */
void ConsoleUI::uiFilterQuantity() {
	cout << "Enter the quantity: ";
	int q;
	cin >> q;
	vector<Medicine>* rez = ph->filterByQuantity(q);
	for_each(rez->begin(), rez->end(), printMed);
	delete rez;
}

/*
 * ui function to sort products by quantity
 */
void ConsoleUI::uiSort() {
	vector<Medicine>* rez = ph->sortByQuantity();
	for_each(rez->begin(), rez->end(), printMed);
	delete rez;
}


void ConsoleUI::uiPrintAll() {
	vector<Medicine>* rez = ph->getAllMeds();
	printMedicines(rez);
}

void ConsoleUI::uiUndo() {
	printMedicines(ph->undoController());
}


/**
 * Start the UI
 * verifies the command from the user input and calls it
 * - if the command is not a valid one, the program gives an error message
 */
void ConsoleUI::showUI() {


	while(1){
		int opt = readUserCommand();

		if(opt == 0) {
			cout<<"Program terminated.";
			break;
		} else if (opt == 1) {
			uiAdd();
		} else if (opt == 2) {
			uiDelete();
		} else if (opt == 3) {
			uiModify();
		} else if (opt == 4) {
			uiPrintAll();
			//cout << ph->printController();
		} else if (opt == 5) {
			uiFilterName();
		} else if (opt == 6) {
			uiFilterQuantity();
		} else if (opt == 7) {
			uiUndo();
		} else if (opt == 8) {
			uiSort();
		} else {
			cout << "Unknown command. Try again. "<<endl;
		}

	}
}

