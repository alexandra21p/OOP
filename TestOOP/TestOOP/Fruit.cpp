#include "Fruit.h"
using namespace std;

Fruit::Fruit() : name(""), nutrBenef(""), quantity(0) {}

Fruit::Fruit(const std::string& n, const std::string& nb, double q) : name(n), nutrBenef(nb), quantity(q) {}
Fruit::~Fruit() {}
