#include "TList.h"
#include "Polinom.h"
#include <iostream>
using namespace std;
void main() {
	Polinom p1, p2;
	p1.AddMonom(Monom(1, 1, 1, 1));
	Monom m1(3, 2, 0, 0);
	p2.AddMonom(Monom(3, 3, 1, 1));
	Polinom pRes = p1 * m1;
	cout << pRes << endl;
}