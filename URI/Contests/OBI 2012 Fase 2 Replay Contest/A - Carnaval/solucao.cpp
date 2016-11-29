#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	vector<double> notas;
	for (int i = 0; i < 5; ++i)
	{
		double x;
		cin >> x;
		notas.push_back(x);
	}
	sort(notas.begin(), notas.end());
	double media = notas[1]+notas[2]+notas[3];
	printf("%.1f\n", media);
	return 0;
}