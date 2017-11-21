#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(0); cin.tie(0)
#define MAXK 1010
#define INFINITO 10000000

using namespace std;

int frequencia[MAXK];

int main(int argc, char const *argv[])
{
	optimize;

	int N, K, x;

	cin >> K >> N;

	for (int i = 0; i < N; ++i)
		cin >> x, frequencia[x]++;

	int qtd = (N + 1) / K;

	pair<int, int> r(INFINITO, INFINITO);
	bool ok = true;

	for (int i = 1; i <= K; ++i)
		if(frequencia[i] + 1 == qtd)
			if(r.first == INFINITO)
				r.first = i;
			else
				ok = false;
		else if(frequencia[i] - 1 == qtd)
			if(r.second == INFINITO)
				r.second = i;
			else
				ok = false;
		else if(frequencia[i] != qtd)
			ok = false;
	

	if(!ok)
		cout << '*' << endl;
	else if(r.first != INFINITO && r.second == INFINITO)
		cout << '+' << r.first << endl;
	else if(r.first != INFINITO && r.second != INFINITO)
		cout << '-' << r.second << " +" << r.first << endl;
	else
		cout << '-' << r.second << endl;

	return 0;
}