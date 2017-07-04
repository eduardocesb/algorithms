#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, M;
	cin >> N >> M;
	int nums[N];
	unordered_map<int, int> numero;
	for (int i = 0; i < N; ++i)
	{
		nums[i] = 0;
		int x;
		for (int j = 0; j < M; ++j)
		{
			cin >> x;
			nums[i] += x;
		}

		numero[nums[i]] = i + 1;
	}

	sort(nums, nums + N);
	cout << numero[nums[0]] << endl;
	cout << numero[nums[1]] << endl;
	cout << numero[nums[2]] << endl;
	return 0;
}