#include "Repository.h"



Repository::Repository(string filename) {
	filename = "questions.in";
	readFromFile(filename);
}


Repository::~Repository() {
	writeToFile();
}

void Repository::addQuestion(Question q) {
	if (q.getText() == "") 
		throw Exception("Invalid input! Text is empty.");
	else {
		auto it = find(this->questions.begin(), this->questions.end(), q);
		if (it == this->questions.end()) {
			questions.push_back(q);
	}
	else throw Exception("There already is a question with that id!");
	//sortById();
	notify();
	}
}

void Repository::removeQuestion(Question q) {
	auto it = find(this->questions.begin(), this->questions.end(), q);
	if (it != questions.end()) {
		this->questions.erase(it);
	}
	//sortById();
	notify();
}

void Repository::readFromFile(string filename) {
	ifstream fin("participants.in");

	Participant p;
	while (fin >> p) {
		part.push_back(p);
	}
	fin.close();
	
	// read the questions
	fin.open(filename);
	Question q;
	while (fin >> q) {
		questions.push_back(q);
	}
	//for (auto it : part) {
		//if (it.getName() == "Presenter") {
			//sortById(questions);
		//}
	sortByScore();
	
}

void Repository::writeToFile() {
	ofstream fout("quest_.in");
	for (auto it : questions)
		fout << it;

	fout.close();
	fout.open("participants.in");
	for (auto it : part)
		fout << it;
}

void Repository::sortById(vector<Question> v) {
	sort(v.begin(), v.end(), [](const Question &a, const Question &b) {
		return a.getId() < b.getId();
	});
}

void Repository::sortByScore() {
	sort(questions.begin(), questions.end(), [](const Question &a, const Question &b) {
		return a.getScore() > b.getScore();
	});
}