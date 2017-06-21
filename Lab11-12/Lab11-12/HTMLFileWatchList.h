#pragma once
#include "FileWatchList.h"
class HTMLFileWatchList :
	public FileWatchList
{
public:
	void writeToFile() override;

	/*
	Displays the watch list using notepad++.
	*/
	void displayWatchList() const override;

};