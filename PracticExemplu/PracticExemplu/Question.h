#pragma once
#include <string>
#include <iostream>

class Question {
private:
	int id;
	std::string text;
	std::string correctAns;
	int score;

public:
	Question() : id(0), text(""), correctAns(""), score(0) {}
	Question(int i, std::string t, std::string c, int s) : id(i), text(t), correctAns(c), score(s) {}
	~Question();
	int getId() const { return id; }
	std::string getText() const { return text; }
	std::string getCorrAns() const { return correctAns; }
	int getScore() const { return score; }

	friend std::ostream &operator<<(std::ostream &output,
		Question &q)
	{
		output << q.getId() << ',' << q.getText() << ',' << q.getCorrAns() <<  ',' << q.getScore() << '\n';
		return output;
	}

	inline bool operator==(const Question& rhs) { return rhs.id == this->id; }

	friend std::istream &operator>>(std::istream  &input, Question &q)
	{
		std::string st;
		getline(input, st, ',');
		q.id = atoi(st.c_str());
		getline(input, st, ',');
		q.text = st;
		getline(input, st, ',');
		q.correctAns = st;
		getline(input, st, '\n');
		q.score = atoi(st.c_str());
		return input;
	}

};

