#include <iostream>
#include <vector>

using namespace std;

int josephus(int n, int k){
	int posicao = 0;
	vector<int> nums;
	for (int j = 1; j <= n; j++)
		nums.push_back(j);
	nums.erase(nums.begin());
	while(nums.size() > 1){
		posicao += k-1;
		posicao = posicao % nums.size();
		nums.erase(nums.begin()+posicao);
	}
	return nums[0];
}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	while(N != 0){
		int i = 1;
		int m = josephus(N, i);
		while(m != 13){
			i++;
			m = josephus(N, i);
		}
		cout << i << endl;
		cin >> N;
	}
	return 0;
}