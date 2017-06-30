#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	int nums[N];
	int soma = 0;

	for (int i = 0; i < N; ++i)
	{
		cin >> nums[i];
		soma += nums[i];
	}

	int s = 0;
	for (int i = 0; i < N; ++i)
	{
		s += nums[i];
		if(s*2 == soma){
			cout << i + 1 << endl;
			break;
		}
	}
	return 0;
}