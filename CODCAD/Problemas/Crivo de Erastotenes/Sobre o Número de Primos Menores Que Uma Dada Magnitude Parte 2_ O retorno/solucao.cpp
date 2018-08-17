#include <iostream>

using namespace std;

bool nums[10000001];

void e_primo(long long int N){
	nums[0] = nums[1] = true;
	for (long long int i = 2; i <= N; ++i)
	{
		if(!nums[i]){
			for (long long int j = 2 * i; j <= N; j += i)
			{
				nums[j] = true;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	long long int N;
	cin >> N;
	if(N < 2)
		return 0;
	e_primo(N);
	for (long long int i = 0; i <= N; ++i)
	{
		if(!nums[i])
			cout << i << ' ';
	}
	cout << endl;
	return 0;
}