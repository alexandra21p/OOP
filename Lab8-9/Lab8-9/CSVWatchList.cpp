#include "stdafx.h"
#include "CSVWatchList.h"
#include <fstream>
#include <Windows.h>

using namespace std;

void CSVWatchList::writeToFile()
{
	ofstream f(this->filename);

	if (!f.is_open())
		throw AppException("The file could not be opened!");

	for (auto t : this->tutorials)
		f << t;

	f.close();
}

void CSVWatchList::displayWatchList() const
{
	std::string aux = "\"" + this->filename + "\""; // if the path contains spaces, we must put it inside quotations
											   //ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\OpenOffice 4\\program\\scalc.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
	//ShellExecuteA(NULL, NULL, "c:\\Program Files\\Microsoft Office\\Office15\\EXCEL.EXE", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
	ShellExecuteA(NULL, NULL, "C:\\Program Files\\Notepad++\\notepad++.exe", aux.c_str(), NULL, SW_DENORMAL);
}


