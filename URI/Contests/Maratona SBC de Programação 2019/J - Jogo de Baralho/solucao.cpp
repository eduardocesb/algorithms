#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define ll long long

using namespace std;

string CARTAS = "A23456789DQJK";

int pos(char x)
{
	for(int i = 0; i < 13; i++)
		if(CARTAS[i] == x) return i;

	return -1;
}

int coringa, N, K;
bool block;

struct Jogador
{
	int cartas[13], indice;

	Jogador(string c, int i)
	{
		indice = i;

		memset(cartas, 0, sizeof cartas);

		for(auto x : c)
			cartas[pos(x)]++;
	}

	bool ganhou()
	{
		if(coringa == indice) return false;

		for(int i = 0; i < 13; i++)
			if(cartas[i] == 4) return true;
		return false;
	}

	char menor()
	{
		if(coringa == indice && !block) return 'C';

		char resp;
		int menor = 5;

		for(int i = 0; i < 13; i++)
			if(cartas[i] && cartas[i] < menor)
			{
				menor = cartas[i];
				resp = CARTAS[i];
			}

		return resp;
	}
};

vector<Jogador> jogadores;

int ok()
{
	for(int i = 0; i < N; i++)
		if(jogadores[i].ganhou()) return i + 1;

	return 0;
}

void joga()
{
	int prox = (K + 1) % N;

	char carta = jogadores[K].menor();

	block = false;

	if(carta == 'C')
	{
		block = true;
		coringa = prox;
	}
	else
	{
		jogadores[K].cartas[pos(carta)]--;
		jogadores[prox].cartas[pos(carta)]++;
	}

	K = (K + 1) % N;
}

int main(int argc, char const *argv[])
{
	optimize;

	cin >> N >> K;

	string s;

	for(int i = 0; i < N; i++)
	{
		cin >> s;

		jogadores.push_back(Jogador(s, i));
	}
	
	K--;

	int i;

	block = true;
	coringa = K;

	while(!(i = ok())) joga();

	cout << i << endl;

	return 0;
}