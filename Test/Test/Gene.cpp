#include "stdafx.h"
#include "Gene.h"


Gene::Gene() : name(""), organism(""), sequence("") {}


Gene::Gene(std::string n, std::string o, std::string s) : name(n), organism(o), sequence(s) {}
