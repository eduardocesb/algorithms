#include <bits/stdc++.h>
#define LIM 100000000
#define MAXN 110

using namespace std;

int B, Z;
struct Animal
{
	int atual;
	int proximo[MAXN];
} animais[11];

bool ok()
{
	for(int i = 1; i < B; i++)
		if(animais[i].atual != animais[i - 1].atual) return false;
	return true;
}

void muda()
{
	for(int i = 0; i < B; i++)
		animais[i].atual = animais[i].proximo[animais[i].atual];
}

int main()
{
	cin >> B >> Z;
	
	for(int i = 0; i < B; i++)
	{
		cin >> animais[i].atual;
		for(int j = 1; j <= Z; j++)
			cin >> animais[i].proximo[j];
	}

	int cont = 0;

	while(cont < LIM)
	{
		if(ok()) break;
		muda();
		cont++;
	}
	
	if(cont == LIM)
		cout << "*" << endl;
	else
		cout << animais[0].atual << " " << cont << endl;
}
