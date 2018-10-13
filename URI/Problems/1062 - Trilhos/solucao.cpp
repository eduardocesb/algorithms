#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	int N, x;
	bool ok, imprime = false;

	scanf("%d", &N);

	while(N)
	{
		imprime = false;
		int prox = 1;
		stack<int> pilha;
		ok = true;

		for(int i = 0; i < N; i++)
		{
			scanf("%d", &x);
			if(!x)
			{
				scanf("%d", &N);
				
				if(!N) return 0;
				
				imprime = true;
				break;
			}

			while(pilha.empty() || pilha.top() < x)
				pilha.push(prox++);

			if(pilha.top() != x)
				ok = false;
			else
				pilha.pop();
		}

		if(imprime)
			puts("");
		else
			printf("%s\n", (ok ? "Yes" : "No"));
	}

	return 0;
}
