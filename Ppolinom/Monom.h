#pragma once
#include <iostream>
using namespace std;
struct Monom {
	double coeff;
	int x, y, z;
public:
	Monom(int c = 0, int xp = 0, int yp = 0, int zp = 0) : coeff(c), x(xp), y(yp), z(zp) {}
	bool operator <(const Monom& m);
	bool operator ==(const Monom& m) { return ((x == m.x) && (y == m.y) && (z == m.z)); };
	bool operator !=(const Monom& m) { return !(*this == m); };
	friend ostream& operator <<(ostream& out, const Monom& m);
	friend istream& operator >>(istream& in, Monom& m);
};
