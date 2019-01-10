#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(0); cin.tie(0)
#define INFINITO 1000000001
#define MAXN 1000100

using namespace std;

int pilha[MAXN], TAM;

int top()
{
	return (TAM ? pilha[TAM - 1] : INFINITO);
}

void push(int x)
{
	pilha[TAM] = min(top(), x);
	TAM++;
}

void pop()
{
	if(TAM)
		TAM--;
	else
		cout << "EMPTY" << endl;
}

void MIN()
{
	if(TAM)
		cout << top() << endl;
	else
		cout << "EMPTY" << endl;
}

int main(int argc, char** argv)
{
	optimize;

	int N, x;

	cin >> N;

	string op;

	while(N--)
	{
		cin >> op;

		if(op == "PUSH")
		{
			cin >> x;
			push(x);
		}
		else if(op == "POP")
			pop();
		else
			MIN();
	}

	return 0;
}
