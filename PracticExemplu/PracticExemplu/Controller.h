#pragma once
#include "Repository.h"
#include "Exception.h"
#include <string>

class Controller {
private:
	Repository *repo;
public:
	Controller(Repository *r);
	~Controller();

	Repository* getRepo() { return repo; }
	void sortF(vector<Question> v) {
		repo->sortById(v);
	}
	vector<Question> getQuestions() { return repo->getQuestions(); }

	void addQ(int i, std::string t, std::string c, int s, Participant p) {
		if (p.getName() == "Presenter") {
			Question q{ i, t, c, s };
			repo->addQuestion(q);
		}
		else throw Exception("Only the presenter can add a question!");
	}

	void removeQ(Question q, Participant p) {
		if (p.getName() == "Presenter") {
			repo->removeQuestion(q);
		}
		else throw Exception("Only the presenter can remove a question!");
	}

	int answerQuest(Question q, Participant p, string ans) {
		if (q.getCorrAns() == ans) {
			int newScore = 0;
			newScore = p.getScore() + q.getScore();
			p.setScore(newScore);
			return p.getScore();
		}
		else return p.getScore();
	}
};

