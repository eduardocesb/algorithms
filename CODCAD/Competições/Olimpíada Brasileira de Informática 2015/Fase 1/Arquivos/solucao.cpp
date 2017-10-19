#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, B, r = 0, menor = 0;

	cin >> N >> B;

	int nums[N];

	for (int i = 0; i < N; ++i)
		cin >> nums[i];

	sort(nums, nums + N);

	//Tenta juntar o menor elemento com o maior não processado...
	//Começo pelo maior de todos...
	//Se não der certo continua tentado juntar o menor com o próximo
	//elemento maior...
	//Para cada laço, foi criada uma pasta...
	//com um ou dois arquivos...
	for (int i = N - 1; i >= menor; r++, --i)
		if(nums[i] + nums[menor] <= B) menor++;

	cout << r << endl;
		
	return 0;
}