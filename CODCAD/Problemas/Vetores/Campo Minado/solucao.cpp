#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	int nums[N+2];
	nums[0] = nums[N+1] = 0;
	for (int i = 1; i <= N; ++i)
	{
		cin >> nums[i];
	}

	for (int i = 1; i <= N; ++i)
	{
		cout << nums[i-1] + nums[i] + nums[i+1] << endl;
	}
	return 0;
}