#pragma once
#include "Controller.h"

class UI
{

private:
	Controller ctrl;
	void uiAdd();
	void uiDelete();
	void uiShow();

public:
	UI(Controller c) : ctrl(c) {}
	void run();
	~UI();
};

