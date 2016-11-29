#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	while(N != 0){
		int qtd_gols_alemanha = ((N+12)/12.857142857);
		int qtd_gols_brasil = N/90;
		cout << "Brasil " << qtd_gols_brasil << " x Alemanha " << qtd_gols_alemanha << endl;
		cin >> N;
	}
	return 0;
}