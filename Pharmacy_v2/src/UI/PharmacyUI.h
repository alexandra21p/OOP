/*
 * PharmacyUI.h
 *
 *  Created on: 17 Apr 2015
 *      Author: Alexandra
 */

#ifndef PHARMACYUI_H_
#define PHARMACYUI_H_

#include "../Controller/PharmacyController.h"

class ConsoleUI {

public:
	ConsoleUI(PharmacyController *con);
	void showUI();

private:
	PharmacyController* ph;
	int readUserCommand();
	void uiAdd();
	void uiDelete();
	void uiModify();
	void uiFilterName();
	void uiFilterQuantity();
	void uiSort();
	void uiUndo();
	void uiPrintAll();
};

#endif /* PHARMACYUI_H_ */
