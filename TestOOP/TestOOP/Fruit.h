#pragma once
#include <string>

class Fruit {
private:
	std::string name;
	std::string nutrBenef;
	double quantity;

public:
	Fruit();
	Fruit(const std::string& n, const std::string& nb, double q);
	~Fruit();
	std::string getName() const { return name; }
	std::string getNutr() const { return nutrBenef; }
	double getQuantity() const { return quantity; }
	bool operator==(const Fruit &f) {
		return(this->name == f.name);
	}

	friend std::istream& operator>>(std::istream& input, Fruit& f) {
		std::string st;
		getline(input, st, '|');
		f.name = st;
		getline(input, st, '|');
		f.nutrBenef = st;
		getline(input, st, '\n');
		f.quantity = atoi(st.c_str());
		return input;

	}
	friend std::ostream& operator<<(std::ostream& output, const Fruit& f) {
		output << f.name << "," << f.nutrBenef << "," << f.quantity << "\n";
		return output;
	}
};

