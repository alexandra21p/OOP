#include "HTMLFileWatchList.h"

#include <fstream>
#include <Windows.h>


void HTMLFileWatchList::writeToFile() {
	ofstream file;
	file.open(filename);
	file << "<!DOCTYPE html>\n<html>\n<head>\n<title>WatchList</title>\n</head>\n<body>\n<table border = '1'>";
	file << "<tr>";

	file << "<td>Title</td>";
	file << "<td>Presenter</td>";
	file << "<td>Duration</td>";
	file << "<td>Likes</td>";
	file << "<td>Link</td>";

	file << "</ tr>";
	for (auto elem : tutorials) {
		file << "<tr>";

		file << "<td>" << elem.getTitle() << "</td>";
		file << "<td>" << elem.getPresenter() << "</td>";
		file << "<td>" << elem.getDuration() << "</td>";
		file << "<td>" << elem.getNrLikes() << "</td>";
		file << "<td>" << elem.getLink() << "</td>";


		file << "</tr>";

	}
	file << "</table>\n</body>\n</html>";
}

void HTMLFileWatchList::displayWatchList() const {
	std::string aux = "\"" + this->filename + "\""; // if the path contains spaces, we must put it inside quotations

	ShellExecuteA(NULL, NULL, "chrome.exe", filename.c_str(), NULL, SW_SHOWMAXIMIZED);
}
