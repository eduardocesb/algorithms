#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

int lis(vector<int> nums){
	vector<int> pilha;
	int r = 0;
	for (int i = 0; i < N; ++i)
	{
		vector<int>::iterator it = upper_bound(pilha.begin(), pilha.end(), nums[i]);
		if(it == pilha.end()) pilha.push_back(nums[i]), r++;
		else *it = nums[i];
	}

	return r;
}

int main(int argc, char const *argv[])
{
	cin >> N;
	vector<int> nums(N);
	for (int i = 0; i < N; ++i) cin >> nums[i];

	cout << lis(nums) << endl;
	return 0;
}