#include <iostream>
#include <algorithm>
#define MAXN 1001

using namespace std;

int main(int argc, char const *argv[])
{
	int M, N;
	cin >> M >> N;
	int X[MAXN], Y[MAXN], R[MAXN];
	for (int i = 0; i < M; ++i)
	{
		cin >> X[i];
	}

	for (int i = 0; i < N; ++i)
	{
		cin >> Y[i];
	}

	int tam = max(M, N), vai = 0;
	bool achou = false;
	for (int i = tam - 1; i >= 0; i--)
	{
		int x = X[i] + Y[i] + vai;
		if(x == 2){
			x = 0;
			vai = 1;
		}else if(x == 3){
			x = 1;
			vai = 1;
		}else{
			vai = 0;
		}
		R[i] = x;

		//Desconsiderar os 0's do final...
		if(R[i] == 1){
			achou = true;
		}
		if(!achou){
			tam--;
		}
	}

	for (int i = 0; i < tam; ++i)
	{
		cout << R[i] << ' ';
	}
	cout << endl;
	return 0;
}