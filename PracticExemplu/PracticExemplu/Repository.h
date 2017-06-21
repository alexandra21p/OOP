#pragma once
#include "Observable.h"
#include "Question.h"
#include "Participant.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include "Exception.h"

class Repository : public Observable {
private:
	void readFromFile(string);
	vector<Question> questions;
	vector<Participant> part;
	
public:
	void writeToFile();
	void sortByScore();
	void sortById(vector<Question> v);
	Repository(string filename);
	~Repository();
	vector<Question> getQuestions() { return questions; }
	vector<Participant> getParticipants() { return part; }

	// presenter
	void addQuestion(Question q);
	void removeQuestion(Question q);


};

