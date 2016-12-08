#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int X, Y;
	int N;
	cin >> X >> Y >> N;
	int qtd = 0;
	int r[N];
	for(int i = 1; i <= N; i++)
	{
		int xi, yi, t;
		cin >> xi >> yi >> t;
		double distancia = sqrt(pow(xi - X, 2) + pow(yi - Y, 2));
		if(distancia < t)
		{
			r[qtd] = i;
			qtd++;
		}
	}
	for(int i = 0; i < qtd-1; i++)
	{
		cout << r[i] << " ";
	}
	if(qtd == 0){
		cout << -1 << endl;
	}else{
		cout << r[qtd-1] << endl;
	}
	return 0;
}
