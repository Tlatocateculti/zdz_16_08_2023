#pragma once

#include <string>

using namespace std;


class A {

	int a,
		b;
public:

	A() : a(5), b(3) {};

	bool operator>(const A& a) {
		return this->a > a.a && this->b > a.b;
	}

	bool operator==(const A& a) {
		return this->a == a.a && this->b == a.b;
	}
};

class B {
	double a,
		b;
};

template<class T, typename U = bool, class Z = string, class DF = char>
class Operacje
{
public:
	
	inline bool static wieksze(T a, T b) { return a > b;  };
	//bool static wieksze(char, char);
	//bool static wieksze(string, string);

	bool static rowne(Z a, Z b) { return a == b;  };
	bool static mniejsze(T a, T b) { return a < b; };

};

