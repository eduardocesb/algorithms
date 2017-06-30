#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, B, x;
	cin >> N >> B;
	while(N != 0 || B != 0){
		bool nums[181];
		memset(nums, false, sizeof(bool) * 181);
		for (int i = 0; i < B; ++i)
		{
			cin >> x;
			nums[x] = true;
		}

		bool deu_certo = true;

		//Para todo número...
		for (int i = 0; i <= N; ++i)
		{
			//Verificar se posso formar ele...
			for (int j = 0; j <= N ; ++j)
			{
				if(nums[j] && nums[j + i]){
					break;
				}
				if(j == N){
					deu_certo = false;
				}
			}
		}

		if(deu_certo){
			cout << 'Y' << endl;
		}else{
			cout << 'N' << endl;
		}
		cin >> N >> B;
	}
	return 0;
}