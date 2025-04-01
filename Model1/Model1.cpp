#include "Model1.h"
#include "../Ppolinom/Monom.h"
#include "../pPolinom/Polinom.cpp"
#include "../pPolinom/Monom.cpp"
Model::Model()
{
	count = 0;
	Polinom a, b, c;
	a.AddMonom(Monom(1, 3, 1, 1));
	a.AddMonom(Monom(3, 2, 3, 0));
	a.AddMonom(Monom(5, 2, 0, 0));

	b.AddMonom(Monom(1, 0, 1, 0));
	b.AddMonom(Monom(2, 0, 0, 1));
	b.AddMonom(Monom(10, 2, 0, 1));

	c.AddMonom(Monom(-1, 1, 1, 0));
	polinoms.push_back(a);
	polinoms.push_back(b);
	polinoms.push_back(c);

}

void Model::Run()
{
	Update();
	char key = 'a';
	while (key != 'q') {
		cin >> key;
		Polinom res;
		int number1, number2;
		switch (key)
		{
		case '1':
			cin >> number1 >> number2;
			if (number1 >= polinoms.size() || number2 >= polinoms.size()) Update("Try again");
			else
			{
				try {
					res = polinoms[number1] + polinoms[number2];
					polinoms.push_back(res);
					Update();
				}
				catch (...) {
					Update("Try again");
				}
			}
			break;
		case '2':
			cin >> number1 >> number2;
			if (number1 >= polinoms.size() || number2 >= polinoms.size()) Update("Try again");
			else
			{
				try {
					res = polinoms[number1] - polinoms[number2];
					polinoms.push_back(res);
					Update();
				}
				catch (...) {
					Update("Try again");
				}
			}
			break;
		case '3':
			cin >> number1 >> number2;
			if (number1 >= polinoms.size() || number2 >= polinoms.size()) Update("Try again");
			else {
				try {
					res = polinoms[number1] * polinoms[number2];
					polinoms.push_back(res);
					Update();
				}
				catch (...) {
					Update("Try again");
				}
			}
			break;
		case '4':
			int number, c;
			cin >> number >> c;
			if (number >= polinoms.size()) Update("Try again");
			else
			{
				try {
					res = polinoms[number] * c;
					polinoms.push_back(res);
					Update();
				}
				catch (...) {
					Update("Try again");
				}
			}
			break;
		case '5':
			try {
				cin >> res;
				polinoms.push_back(res);
				Update();
			}
			catch (...) {
				Update("Try again");
			}
			break;
		default:
			Update("Try again");
			break;
		}
		count++;
	}
	Update("Its all over...");
	cin >> key;
}

void Model::Update(string message)
{
	system("cls");
	cout << "polinoms count: " << polinoms.size() << endl;
	cout << "Operations are done: " << count << endl;
	for (int i = 0; i < polinoms.size(); i++) {
		cout << i << ") " << polinoms[i] << endl;
	}
	cout << "Choose operation:" << endl;
	cout << "1: Polinoms add" << endl;
	cout << "2: Polinoms dis" << endl;
	cout << "3: Polinoms mult" << endl;
	cout << "4: Polinoms mult on int" << endl;
	cout << "5: Polinoms input (coeff x y z until coeff == 0" << endl;
	cout << "q: Quit" << endl;
	if (message != "") {
		cout << "\033[31m" << message << "\033[0m" << endl;
	}
}
