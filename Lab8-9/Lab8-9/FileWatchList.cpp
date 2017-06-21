#include "stdafx.h"
#include "FileWatchList.h"


FileWatchList::FileWatchList() : WatchList{}, filename{""} {}


void FileWatchList::setFilename(const std::string& filename)
{
	this->filename = filename;
}
