#include "stdafx.h"
#include "UI.h"

#include <string>
using namespace std;

void UI::printMenu()
{
	cout << endl;
	cout << "1 - Administrator mode." << endl;
	cout << "2 - User mode." << endl;
	cout << "0 - Exit." << endl;
}

void UI::printRepositoryMenu()
{
	cout << "Possible commands: " << endl;
	cout << "\t 1 - Add tutorial." << endl;
	cout << "\t 2 - Delete tutorial." << endl;
	cout << "\t 3 - Update tutorial." << endl;
	cout << "\t 4 - Display all." << endl;
	cout << "\t 0 - Back." << endl;
}

void UI::printWatchListMenu()
{
	cout << "Possible commands: " << endl;
	cout << "\t 1 - Database options (play, next, add to watch list)" << endl;
	cout << "\t 2 - Watch List options (watch/delete tutorial, show all)" << endl;
	cout << "\t 0 - Back." << endl;
}

void UI::uiAdd()
{
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);
	cout << "Enter the presenter: ";
	std::string pres;
	getline(cin, pres);
	double minutes = 0, seconds = 0;
	cout << "Enter the duration: " << endl;
	cout << "\tMinutes: ";
	cin >> minutes;
	cin.ignore();
	cout << "\tSeconds: ";
	cin >> seconds;
	cin.ignore();
	cout << "Enter number of likes: ";
	double likes = 0;
	cin >> likes;
	cin.ignore();
	cout << "Youtube link: ";
	std::string link;
	getline(cin, link);

	try {
		this->ctrl.addToRepo(title, pres, minutes, seconds, likes, link);
		cout << "Tutorial has been successfully added to the database!" << endl;
	}
	catch (AppException& ex) {
		cout << "ERROR: " << ex.getMsg() << endl;
	}
	catch (...) {
		cout << "unknown exception";
	}


}

void UI::uiDelete() {
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);
	cout << "Enter the presenter: ";
	std::string pres;
	getline(cin, pres);

	try {
		this->ctrl.deleteFromRepo(title, pres);
		cout << "Tutorial has been successfully deleted from the database!" << endl;
	}
	catch (AppException& ex) {
		cout << "ERROR: " << ex.getMsg() << endl;
	}
	catch (...) {
		cout << "unknown exception";
	}


}

void printTutorials(vector<Tutorial> v) {
	for (auto t : v) {
		Duration d = t.getDuration();
		cout << t.getTitle() << " - " << t.getPresenter() << " | " << d.getMinutes() << ":" << d.getSeconds() << " | " << t.getNrLikes() << " likes" << endl;
		cout << endl;
	}

}

void UI::uiUpdate() {
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);
	cout << "Enter the presenter: ";
	std::string pres;
	getline(cin, pres);
	cout << "Enter the new number of likes: ";
	double likes = 0;
	cin >> likes;
	cin.ignore();

	try {
		this->ctrl.updateFromRepo(title, pres, likes);
		cout << "\tTutorial has been successfully updated!" << endl;
	}
	catch (AppException& ex) {
		cout << "ERROR: " << ex.getMsg() << endl;
	}
	catch (...) {
		cout << "unknown exception";
	}


}



void UI::displayAllRepo()
{
	std::vector<Tutorial> v = this->ctrl.getRepo().getTutorials();
	if (v.size() == 0)
	{
		cout << "There are no tutorials in the repository." << endl;
		return;
	}

	for (auto t : v)
	{
		Duration d = t.getDuration();
		cout << t << endl;
	}
}


void UI::showWatchlist()
{
	std::vector<Tutorial> v = this->ctrl.getWatchList()->getTuts();

	if (v.size() == 0)
	{
		cout << "There are no tutorials in the watchlist!" << endl;
		return;
	}

	for (auto t : v)
	{
		Duration d = t.getDuration();
		cout << t;
		//cout << t.getTitle() << " - " << t.getPresenter() << " | " << d.getMinutes() << ":" << d.getSeconds() << " | " << t.getNrLikes() << " likes" << endl;
	}
}


void UI::saveWatchListToFile() {
	std::string filename;
	cout << "Input the file name (absolute path): ";
	getline(cin, filename);

	try
	{
		this->ctrl.saveWatchList(filename);

		if (this->ctrl.getWatchList() == nullptr)
		{
			cout << "Watchlist cannot be displayed!" << endl;
			return;
		}
	}
	catch (AppException& ex) {
		cout << "ERROR: " << ex.getMsg() << endl;
	}
	catch (...) {
		cout << "unknown exception";
	}
}



void UI::run()
{
	while (true)
	{
		UI::printMenu();
		int command{ 0 };
		cout << "Input the command: ";
		cin >> command;
		cin.ignore();
		if (command == 0)
			break;

		// repository management
		if (command == 1)
		{
			while (true)
			{
				UI::printRepositoryMenu();
				int commandRepo{ 0 };
				cout << "Input the command: ";
				cin >> commandRepo;
				cin.ignore();
				if (commandRepo == 0)
					break;
				switch (commandRepo)
				{
				case 1:
					this->uiAdd();
					break;
				case 2:
					this->uiDelete();
					break;
				case 3:
					this->uiUpdate();
					break;
				case 4:
					this->displayAllRepo();
					break;
				default:
					cout << "Invalid command!! Please try again." << endl;
				}
			}
		}

		// watchlist management
		if (command == 2)
		{
			while (true)
			{
				UI::printWatchListMenu();
				int commandWL{ 0 };
				cout << "Input the command: ";
				cin >> commandWL;
				cin.ignore();
				if (commandWL == 0)
					break;

				if (commandWL == 1) {
					cout << "Enter the presenter: ";
					std::string pres;
					getline(cin, pres);

					while (true) {
						cout << "\t 1 - Play the tutorials from the database." << endl;
						cout << "\t 2 - Add tutorial to watch list." << endl;
						cout << "\t 3 - Next." << endl;
						cout << "\t 0 - Back." << endl;

						int com{ 0 };
						cout << "Input the command: ";
						cin >> com;
						cin.ignore();

						if (com == 0)
							break;

						if (com == 1)
						{
							
							if (this->ctrl.getRepo().getTutorials().size() == 0)
							{
								cout << "There are no tutorials in the database." << endl;
								return;
							}

							this->ctrl.playTutsFromRepo(pres);
							Tutorial t = this->ctrl.getRepo().getCurrentTut(pres);
							Duration d = t.getDuration();
							cout << "You are currently playing: " <<
								t.getTitle() << " - " << t.getPresenter() << " | " << d.getMinutes() << ":" << d.getSeconds() << " | " << t.getNrLikes() << " likes" << endl;

						}
						if (com == 2) {
							Tutorial t = this->ctrl.getRepo().getCurrentTut(pres);
							this->ctrl.addTutToWatchlist(t);
							cout << "Tutorial added successfully to the watchlist!" << endl;
						}

						if (com == 3)
						{
							if (this->ctrl.getRepo().getTutorials().size() == 0)
							{
								cout << "There are no tutorials in the database." << endl;
								return;
							}

							this->ctrl.nextTutorialRepo(pres);
							Tutorial t = this->ctrl.getRepo().getCurrentTut(pres);
							Duration d = t.getDuration();
							cout << "You are currently playing: " <<
								t.getTitle() << " - " << t.getPresenter() << " | " << d.getMinutes() << ":" << d.getSeconds() << " | " << t.getNrLikes() << " likes" << endl;
						}
					}

				}

				if (commandWL == 2) {
					while (true) {
						cout << "\t 1 - Watch tutorial from watch list." << endl;
						cout << "\t 2 - DELETE tutorial from watchlist." << endl;
						cout << "\t 3 - Next." << endl;
						cout << "\t 4 - Save watchlist to file." << endl;
						cout << "\t 5 - Open watchlist with a program (NOTEPAD++ or GOOGLE CHROME)." << endl;
						cout << "\t 6 - Show Watch List." << endl;
						cout << "\t 0 - Back." << endl;
						int com{ 0 };
						cout << "Input the command: ";
						cin >> com;
						cin.ignore();

						if (com == 0)
							break;
						if (com == 1) {
							if (this->ctrl.getWatchList()->isEmpty())
							{
								cout << "There are no tutorials in the watchlist!" << endl;
								return;
							}
						

							this->ctrl.playTutWatchList();
							Tutorial t = this->ctrl.getWatchList()->getCurrentTutorial();
							Duration d = t.getDuration();
							cout << "You are currently playing: " <<
								t.getTitle() << " - " << t.getPresenter() << " | " << d.getMinutes() << ":" << d.getSeconds() << " | " << t.getNrLikes() << " likes" << endl;

						}

						if (com == 2) {
							Tutorial t = this->ctrl.getWatchList()->getCurrentTutorial();
							cout << "CURRENT NR OF LIKES: " << ctrl.getRepo().getNrLikes() << endl;

							this->ctrl.deleteTutFromWatchlist(t.getTitle(), t.getPresenter());
							cout << "Would you like to rate this tutorial with a like? (y / n)" << endl;
							std::string opt;
							getline(cin, opt);
							if (opt == "y") {
								this->ctrl.increaseLikes();
								cout << "Tutorial deleted successfully from the watchlist!" << endl;
							}
							if (opt == "n") {
								cout << "Tutorial deleted successfully from the watchlist!" << endl;
							}
						}

						if (com == 3) {
							if (this->ctrl.getWatchList()->isEmpty())
							{
								cout << "There are no tutorials in the watchlist!" << endl;
								return;
							}

							this->ctrl.nextTutWatchlist();
							Tutorial t = this->ctrl.getWatchList()->getCurrentTutorial();
							Duration d = t.getDuration();
							cout << "You are currently playing: " <<
								t.getTitle() << " - " << t.getPresenter() << " | " << d.getMinutes() << ":" << d.getSeconds() << " | " << t.getNrLikes() << " likes" << endl;

						}
						if (com == 4) {
							this->saveWatchListToFile();
						}
						if (com == 5) {
							this->ctrl.openWatchList();
						}
						if (com == 6) {
							showWatchlist();
						}
					}
				}
			}
		}
	}
}