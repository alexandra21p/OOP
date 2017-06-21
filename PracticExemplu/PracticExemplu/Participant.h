#pragma once
#include <string>
#include <iostream>
class Participant
{
private:
	std::string name;
	int score;
public:
	Participant() : name(""), score(0) {}
	Participant(std::string n, int s) : name(n), score(s) {}
	~Participant();

	std::string getName() const { return name; }
	int getScore() { return score; }
	void setScore(int s) { score = s; }

	friend std::ostream &operator<<(std::ostream &output,
		Participant &p)
	{
		output << p.getName() << ',' << p.getScore() << '\n';
		return output;
	}

	//inline bool operator==(const Question& rhs) { return rhs.id == this->id; }

	friend std::istream &operator>>(std::istream  &input, Participant &p)
	{
		std::string st;
		getline(input, st, ',');
		p.name = st;
		getline(input, st, '\n');
		p.score = atoi(st.c_str());
		return input;
	}
};

