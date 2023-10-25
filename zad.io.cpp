#include <iostream>

using namespace std;

int main() {
	static int AA[10];
	int* BB = new int[10];
	int iloscliczbujemnych = 0;
	cout << "Napisz 10 liczb: " << endl;
	for (int i; i < 10; i++) {
		cin >> AA[i];
		if (AA[i] < 0) {
			BB[iloscliczbujemnych] = AA[i];
			iloscliczbujemnych++;
		}
	}
	cout << "Liczby ujemne to: ";
	for (int i; i < iloscliczbujemnych; i++) {
		cout << BB[i];
	}
	cout << "Ilosc liczb ujemnych to " << iloscliczbujemnych << " a dodatnich to " << 10 - iloscliczbujemnych << endl;
	delete[] BB;
	return 0;
}