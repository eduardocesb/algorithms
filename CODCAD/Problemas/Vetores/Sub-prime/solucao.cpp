#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int B, N;
	cin >> B >> N;
	while(B != 0 || N != 0){
		int nums[B+1];
		for (int i = 1; i <= B; ++i)
		{
			cin >> nums[i];
		}
		int D, C, V;
		for (int i = 0; i < N; ++i)
		{
			cin >> D >> C >> V;
			nums[D] -= V;
			nums[C] += V;
		}

		bool achou = false;
		for (int i = 1; i <= B; ++i)
		{
			if(nums[i] < 0){
				achou = true;
				cout << "N\n";
				break;
			}
		}
		if(!achou){
			cout << "S\n";
		}
		cin >> B >> N;
	}
	return 0;
}