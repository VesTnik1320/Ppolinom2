#pragma once
#include "../Ppolinom/Polinom.h"
#include <vector>

class Model {
	vector<Polinom> polinoms;
	int count;
public:
	Model();
	void Run();
	void Update(string message = "");
};
