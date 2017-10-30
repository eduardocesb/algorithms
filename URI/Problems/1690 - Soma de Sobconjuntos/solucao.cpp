#include <bits/stdc++.h>
#define optimize std::ios::sync_with_stdio(0); cin.tie(0)
#define ll long long

using namespace std;

int main(int argc, char const *argv[])
{
	optimize;

	int T, N, x;

	cin >> T;

	while(T--){

		cin >> N;

		int nums[N];

		for (int i = 0; i < N; ++i)
			cin >> nums[i];

		//Ordena os valores do menor para o maior...
		sort(nums, nums + N);

		//Último soma que consegui gerar...
		ll r = 0;

		//Para cada novo valor...
		for (int i = 0; i < N; ++i)
			//Se o próximo valor a ser gerado for menor que o próximo valor a ser processado...
			//Significa que eu não conseguirei gerar aquela soma...
			//Logo essa é minha resposta...
			if(r + 1 < nums[i])
				break;
			//Caso contrário, eu consigo gerar todas as somas partindo das que eu já tinha mais o novo valor...
			else
				r += nums[i];

		//No final imprime o primeiro valor que não pode ser gerado...
		cout << r + 1 << endl;
	}
	return 0;
}