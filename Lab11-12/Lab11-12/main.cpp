#include "myclass.h"
#include <QtWidgets/QApplication>
#include <QMessageBox>
#include "CSVWatchList.h"
#include "HTMLFileWatchList.h"

int main(int argc, char *argv[])
{


	QApplication a(argc, argv);

	Repository repo("tutorials.txt");
	Validator val;
	FileWatchList* w = nullptr;
	QMessageBox msgBox;
	msgBox.setText("What type of file do you choose to work with?");
	QAbstractButton* pButtonYes = msgBox.addButton("CSV File", QMessageBox::YesRole);
	msgBox.addButton("HTML File", QMessageBox::NoRole);

	msgBox.exec();

	if (msgBox.clickedButton() == pButtonYes) {
		w = new CSVWatchList{};
	}
	else {
		w = new HTMLFileWatchList{};
	}

	Controller ctrl(repo, w, val);

	MyClass gui{ctrl};
	gui.show();
	return a.exec();
	//delete w;

}
