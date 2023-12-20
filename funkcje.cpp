#include <iostream>
#include "funkcje.h"
#include <cmath>
#include <math.h> 
#include <algorithm>

using namespace std;


double Logarytm(int liczba)
{
	return log(liczba);
}

double Exponent(int liczba)
{
	return exp(liczba);
}

float Odchylenie(float tab[])
{
	float sum=0;
	for (int i = 0; i < 10; i++)
	{
		sum = sum + tab[i];
	}
	float odchylenie = sqrt(sum / 10);

	return odchylenie;
}


float mediana(float* tab, int n)
{
    sort(tab, tab + 10);
    float mediana;
    if (n % 2 == 0)
    {
        mediana = tab[(n - 1) / 2] + tab[n / 2];
        mediana = mediana / 2;
    }
    else
    {
        mediana = tab[n / 2];
    }
    return mediana;
}