// Lab8-9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "CSVWatchList.h"
#include "HTMLFileWatchList.h"
#include "UI.h"
using namespace std;


int main()
{
	try {
		Repository repo("data.txt");
		Validator val;
		FileWatchList* w = nullptr;
		int com{ 0 };
		cout << "Choose the type of file for watchlist: (1) CSV or (2) HTML " << endl;
		cin >> com;
		cin.ignore();
		if (com == 1) {
			w = new CSVWatchList{};
		}
		if (com == 2) {
			w = new HTMLFileWatchList{};
		}
		//FileWatchList* w = new CSVWatchList{};
		//FileWatchList* w = new HTMLFileWatchList{};
		Controller ctrl(repo, w, val);

		// adding sample tutorials
		/*ctrl.addToRepo("homemade pizza recipe", "Divas Can Cook", 5, 31, 15, "https://www.youtube.com/watch?v=cxB4ACaaR4I");
		ctrl.addToRepo("nutella french toast", "BuzzFeedFood", 0, 47, 23, "https://www.youtube.com/watch?v=f4kE9jkhRR0");
		ctrl.addToRepo("chicken recipe", "POPSUGAR Food", 2, 57, 2, "https://www.youtube.com/watch?v=39CWvJTpOgE");
		ctrl.addToRepo("potatoes", "SORTEDfood", 8, 48, 35, "https://www.youtube.com/watch?v=McK34UW42zI");
		ctrl.addToRepo("simple sushi", "Jamie Oliver", 5, 31, 15, "https://www.youtube.com/watch?v=5w6tenYZ9Y8");
		*/
		UI ui(ctrl);
		ui.run();
		delete w;
	}
	catch (AppException& ex) {
		cout << "ERROR: Repository file could not be opened! The application will terminate." << endl;
		return 1;
	}
	catch (...) {
		cout << "unknown exception";
	}
	
    return 0;
}

