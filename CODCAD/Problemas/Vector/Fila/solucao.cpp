#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, M;
	cin >> N;
	vector<int> nums;
	for (int i = 0; i < N; ++i)
	{
		int x;
		cin >> x;
		nums.push_back(x);
	}

	cin >> M;

	for (int i = 0; i < M; ++i)
	{
		int x;
		cin >> x;
		for (int j = 0; j < N; ++j)
		{
			if(nums[j] == x){
				nums.erase(nums.begin() + j);
				break;
			}
		}
		N--;
	}


	for (int i = 0; i < N; ++i)
		cout << nums[i] << ' ';
	cout << endl;
	return 0;
}