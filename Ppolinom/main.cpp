#include "TList.h"
#include "Polinom.h"
#include <iostream>
using namespace std;
void main() {

	Monom m[3] = { Monom(1, 2, 1, 1), Monom(-3, 1, 0, 0), Monom(4, 0, 2, 1) };
	Polinom p1(m, 3);
	cout << p1 << endl;
	Monom test1(-4, 0, 2, 1);
	p1.AddMonom(test1);
	cout << p1 << " DelLast " << endl;
	/*Polinom p1, p2;
	p1.AddMonom(Monom(1, 1, 1, 1));
	Monom m1(3, 2, 0, 0);
	p2.AddMonom(Monom(3, 3, 1, 1));
	Polinom pRes = p1 * m1;
	cout << pRes << endl;
	cout << p2 << endl;*/
}