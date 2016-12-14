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
	int inf = 0;
	int sup = C-1;
	int meio;
	while(inf <= sup)
	{
		meio = (inf + sup)/2;
		if(raio[meio] >= distancia && (meio == 0 || raio[meio-1] < distancia)){
			return C - meio;
		}
		if(distancia < raio[meio]){
			sup = meio-1;
		}else{
			inf = meio+1;
		}
	 }
	return 0;
}

int main(int argc, char const *argv[])
{
	cin >> C >> N;
	for (int i = 0; i < C; ++i)
	{
		int x;
		cin >> x;
		raio.push_back(x);
	}

	unsigned long long total = 0;
	for (int i = 0; i < N; ++i)
	{
		int x, y;
		cin >> x >> y;
		double distancia = calcula_distancia(x,y);
		total += pontos(distancia);
		//cout << "pontos para a distancia " << distancia << ": " << pontos(distancia) << endl;
	}
	cout << total << endl;
	return 0;
}