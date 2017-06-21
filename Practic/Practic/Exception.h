#pragma once
#include <exception>
#include <string>
using namespace std;

class Exception : public exception
{
private:
	std::string st;
public:
	Exception(std::string s) : st(s) {}
	~Exception();
	const char* what() { return st.c_str(); }
};

