#pragma once
#include "Monom.h"
#include "TList.h"
#include <string>
class Polinom : public TList<Monom> {
public:
	Polinom() : TList<Monom>() {}
	Polinom(const Polinom& p) : TList<Monom>(p) {}
	Polinom(Monom* p, int sz);

	bool operator==(const Polinom& p) const;
	bool operator!=(const Polinom& p) const { return !(*this == p); };
	Polinom& operator=(const Polinom& p);
	Polinom operator+(Polinom& p);
	Polinom operator-(Polinom& p);
	Polinom operator*(double coef);
	Polinom operator*(Polinom p);
	Polinom operator*(Monom m);
	

	void AddMonom(Monom m);
	friend ostream& operator <<(ostream& out, Polinom& p);
	friend istream& operator >>(istream& in, Polinom& p);
};
