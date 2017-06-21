// Lab5-7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "UI.h"
using namespace std;

int main()
{
	Repository repo;
	Validator val;
	Controller ctrl(repo, val);
	
	// adding sample tutorials
	ctrl.addToRepo("homemade pizza recipe", "Divas Can Cook", 5, 31, 15, "https://www.youtube.com/watch?v=cxB4ACaaR4I");
	ctrl.addToRepo("nutella french toast", "BuzzFeedFood", 0, 47, 23, "https://www.youtube.com/watch?v=f4kE9jkhRR0");
	ctrl.addToRepo("chicken recipe", "POPSUGAR Food", 2, 57, 2, "https://www.youtube.com/watch?v=39CWvJTpOgE");
	ctrl.addToRepo("potatoes", "SORTEDfood", 8, 48, 35, "https://www.youtube.com/watch?v=McK34UW42zI");
	ctrl.addToRepo("simple sushi", "Jamie Oliver", 5, 31, 15, "https://www.youtube.com/watch?v=5w6tenYZ9Y8");

	UI ui(ctrl);
	ui.run();

    return 0;
}

