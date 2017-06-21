#pragma once
#include <string>
#include <iostream>
class SourceCodeFile
{
private:
	std::string name;
	std::string status;
	std::string creator;
	std::string reviewer;
public:
	SourceCodeFile();
	SourceCodeFile(std::string n, std::string s, std::string c, std::string r) : name(n), status(s), creator(c), reviewer(r) {}
	~SourceCodeFile();
	std::string getName() const { return name; }
	std::string getStatus() const { return status; }
	std::string getCreator() const { return creator; }
	std::string getReviewer() const { return reviewer; }

	void setName(std::string n) { name = n; }
	void setStatus(std::string s) { status = s; }
	void setReviewer(std::string r) { reviewer = r; }

	friend std::ostream &operator<<(std::ostream &output, SourceCodeFile &s) {
		output << s.getName() << ',' << s.getStatus() << ',' << s.getCreator() << ',' << s.getReviewer() <<'\n';
		return output;
	}
	friend std::istream &operator>>(std::istream &input, SourceCodeFile &s) {
		std::string st;
		getline(input, st, ',');
		s.name = st;
		getline(input, st, ',');
		s.status = st;
		getline(input, st, ',');
		s.creator = st;
		getline(input, st, '\n');
		s.reviewer = st;
		return input;
	}
	inline bool operator==(const SourceCodeFile &rhs) { return rhs.name == this->name; }
};

