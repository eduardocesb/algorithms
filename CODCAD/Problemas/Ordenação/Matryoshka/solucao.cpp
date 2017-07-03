#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	int nums[N];
	int ordenado[N];
	bool imprimir[N];
	for (int i = 0; i < N; ++i)
	{
		cin >> nums[i];
		ordenado[i] = nums[i];
		imprimir[i] = false;
	}
	//Ordena os números...
	sort(ordenado, ordenado + N);
	int r = 0;
	for (int i = 0; i < N; ++i)
	{
		//Se o número mudou de posição...
		//Marco ele para ser impresso...
		//Aumento a quantidade de números a serem impressos...
		if(ordenado[i] != nums[i]){
			imprimir[i] = true;
			r++;
		}
	}
	//Imprimo a quantidade de números a serem impressos...
	cout << r << endl;
	//Se existir algum número a ser impresso...
	if(r != 0){
		for (int i = 0; i < N; ++i)
		{
			//Se for pra imprimir o número eu imprimo ele...
			if(imprimir[i])
				cout << ordenado[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}