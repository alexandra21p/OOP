#pragma once
#include "Controller.h"

class UI
{

private:
	Controller ctrl;
public:
	UI(Controller c) : ctrl(c) {}
	void run();
	~UI() {}

private:
	static void printMenu();
	static void printRepositoryMenu();
	static void printWatchListMenu();

	void uiAdd();
	void uiDelete();
	void uiUpdate();
	void displayAllRepo();
	//void uiAddToWatchList();
	void showWatchlist();
	void uiDeleteFromWatchlist();


};

