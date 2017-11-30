#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	string S;

	cin >> S;

	int qtd = 0;

	int soma = 0;

	int tam = S.length();

	for (int i = 0; i < tam; ++i)
	{
		if(S[i] == '1' && S[i + 1] == '0')
		{
			soma += 10;
			i++;
		}
		else
		{
			soma += S[i] - '0';
		}

		qtd++;
	}

	printf("%.2lf\n", (double) (soma * 1.0 / qtd));

	return 0;
}