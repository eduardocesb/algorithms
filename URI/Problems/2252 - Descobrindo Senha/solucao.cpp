#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	int teste = 1;
	while(!(cin >> N).eof()){
		vector<double> nums;
		vector<int>posicao;
		for (int i = 0; i < 10; ++i)
		{
			double x;
			cin >> x;
			posicao.push_back(i);
			nums.push_back(x);
		}

		for(int i = 9; i >= 0; i--){
			for(int j = 0; j < i; j++){
				if(nums[i] > nums[j]){
					double aux = nums[i];
					nums[i] = nums[j];
					nums[j] = aux;
					int aux_posicao = posicao[i];
					posicao[i] = posicao[j];
					posicao[j] = aux_posicao;
				}else if(nums[i] == nums[j]){
					if(posicao[i] < posicao[j]){
						int aux_posicao = posicao[i];
						posicao[i] = posicao[j];
						posicao[j] = aux_posicao;
					}
				}
			}
		}
		cout << "Caso " << teste << ": ";
		for (int i = 0; i < N; ++i)
		{
			cout << posicao[i];
		}
		cout << endl;
		teste++;
	}
	return 0;
}