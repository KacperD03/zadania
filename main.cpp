#include <iostream>
#include "funkcje.h"

using namespace std;

int main() 
{
	cout << Logarytm(57)<<endl;

	cout << Exponent(8)<<endl;

	float tab[10] = { 76,88,13,378,2,822,23,8,95,29 };
	cout << Odchylenie(tab)<<endl;

	cout << mediana(tab, 10)<<endl;

	return 0;
}