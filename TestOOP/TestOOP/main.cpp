#include "testoop.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository repo("fruits.txt");
	Controller ctrl(repo);
	TestOOP w{ctrl};
	QSize s(600, 400);
	w.setFixedSize(s);
	w.show();
	return a.exec();
}
