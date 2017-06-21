#include "gui.h"
#include <QtWidgets/QApplication>
#include "Repository.h"
#include "Controller.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository *r = new Repository("questions.in");
	Controller *c = new Controller(r);
	vector<GUI *> windows;
	for (auto it : r->getProgrammers()) {
		GUI * w = new GUI(c, it);
		w->show();
		r->attach((Observer*)w);
		windows.push_back(w);
	}


	int ret = a.exec();
	/// TODO: memory management: delete
	for (auto it : windows) {
		delete it;
	}
	delete c;
	delete r;
	return ret;
}
