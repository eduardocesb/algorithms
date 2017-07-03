#include <iostream>
#include <algorithm>

using namespace std;
int N, M;

bool compara(int i, int j){
	//Valor que cada deputado vai receber...
	int valor_i = i / M;
	int valor_j = j / M;
	//Lucro que o presidento vai receber
	int lucro_i = i % M;
	int lucro_j = j % M;
	if(lucro_i > lucro_j){
		return true;
	}else if(lucro_i == lucro_j && (valor_i > valor_j)){
		return true;
	}else{
		return false;
	}
}

int main(int argc, char const *argv[])
{
	cin >> N >> M;
	int nums[N];
	for (int i = 0; i < N; ++i)
	{
		cin >> nums[i];
	}

	sort(nums, nums + N, compara);

	for (int i = 0; i < N; ++i)
	{
		cout << nums[i] << ' ';
	}

	cout << endl;
	return 0;
}