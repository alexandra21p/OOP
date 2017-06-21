#pragma once
#include <string>
#include <iostream>

class Programmer {
private:
	std::string name;
	int nrFiles;
public:
	Programmer();
	Programmer(std::string n, int f) : name(n), nrFiles(f) {}
	~Programmer();
	std::string getName() const { return name; }
	int getNrFiles() { return nrFiles; }
	void setName(std::string n) { name = n; }
	void setNrFiles(int f) { nrFiles = f; }

	friend std::ostream &operator<<(std::ostream &output, Programmer &p) {
		output << p.getName() << ',' << p.getNrFiles() << '\n';
		return output;
	}
	friend std::istream &operator>>(std::istream &input, Programmer &p) {
		std::string st;
		getline(input, st, ',');
		p.name = st;
		getline(input, st, '\n');
		p.nrFiles = atoi(st.c_str());
		return input;
	}
	inline bool operator==(const Programmer &rhs) { return rhs.name == this->name; }
};

