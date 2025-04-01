#pragma once
#include "../Ppolinom/Polinom.h"
#include <vector>

class Model {
	vector<Polinom> polynomes;
	int count;
public:
	m1();
	void Run();
	void Update(string message = "");
};
