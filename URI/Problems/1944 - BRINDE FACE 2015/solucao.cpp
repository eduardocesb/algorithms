#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define ll long long
#define MAXN 100010


using namespace std;

int main(int argc, char** argv)
{
	optimize;

	stack<char> pilha, aux;
	vector<char> aux1(4);

	pilha.push('F');
	pilha.push('A');
	pilha.push('C');
	pilha.push('E');

	char x;

	int N;

	cin >> N;

	int r = 0;


	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < 4; j++)
			cin >> aux1[j];

		bool ok = true;

		for(int j = 0; j < 4; j++)
		{
			if(aux1[j] == pilha.top())
			{
				aux.push(pilha.top());
				pilha.pop();
			}
			else
			{
				ok = false;
				break;
			}
		}

		if(pilha.empty())
		{
			pilha.push('F');
			pilha.push('A');
			pilha.push('C');
			pilha.push('E');
		}

		if(ok) r++;
		else
		{
			while(!aux.empty())
			{
				pilha.push(aux.top());
				aux.pop();
			}

			pilha.push(aux1[0]);
			pilha.push(aux1[1]);
			pilha.push(aux1[2]);
			pilha.push(aux1[3]);
		}

	}

	cout << r << endl;
	
	return 0;
}
