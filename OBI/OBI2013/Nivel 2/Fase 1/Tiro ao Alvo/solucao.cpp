#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int C, N;
vector<int>raio;

double calcula_distancia(int x, int y){
	double distancia = sqrt((pow(x, 2) + pow(y, 2)));
	return distancia;
}

int pontos(double distancia){
	//Implementar busca binaria...
	return 1;
}

int main(int argc, char const *argv[])
{
	cin >> C >> N;
	for (int i = 0; i < C; ++i)
	{
		int x;
		cin >> x;
		raio.push_back(i);
	}

	int total = 0;
	for (int i = 0; i < N; ++i)
	{
		int x, y;
		cin >> x >> y;
		double distancia = calcula_distancia(x,y);
		total += pontos(distancia);
	}
	cout << total << endl;
	return 0;
}