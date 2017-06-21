#include "stdafx.h"
#include "UI.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;




int selectCommand() {
	cout << endl;
	cout << "1 - add" << endl;
	cout << "2 - delete" << endl;
	cout << "3 - show all" << endl;
	cout << "0 - exit" << endl;
	cout << "\tSelect option: " << endl;

	int cmd = 0;
	cin >> cmd;
	cin.ignore();
	return cmd;
}
void UI::uiAdd() {
	std::string name;
	cout << "Enter name: " << endl;
	getline(cin, name);

	std::string org;
	cout << "Enter organism: " << endl;
	getline(cin, org);

	std::string seq;
	cout << "Enter sequence: " << endl;
	getline(cin, seq);

	this->ctrl.add_gene(name, org, seq);

}

void UI::uiDelete() {
	std::string name;
	cout << "Enter name: " << endl;
	getline(cin, name);

	std::string org;
	cout << "Enter organism: " << endl;
	getline(cin, org);

	this->ctrl.delete_gene(name, org);


}

void printGene(Gene g) {
	cout << "Name: " << g.getName() << " | " << "Organism: " << g.getOrganism() << " | " << "Sequence: " << g.getSequence() << endl;
}

void printGenes(DynamicVector2 v) {
	for (int i = 0; i < v.getSize(); i++) {
		Gene g = v.get(i);
		cout << "Name: " << g.getName() << " | " << "Organism: " << g.getOrganism() << " | " << "Sequence: " << g.getSequence() << endl;
	}
}

void UI::uiShow() {
	DynamicVector2 v = ctrl.getRepo();
	printGenes(v);
}
void UI::run() {
	while (true) {

		int cmd = selectCommand();
		if (cmd == 0) {
			break;
		}
		if (cmd == 1) {
			this->uiAdd();
		}
		if (cmd == 2) {
			this->uiDelete();
		}
		if (cmd == 3) {
			uiShow();
		}
		else {
			cout << "Invalid option!" << endl;
		}
	}
}

UI::~UI() {
}
