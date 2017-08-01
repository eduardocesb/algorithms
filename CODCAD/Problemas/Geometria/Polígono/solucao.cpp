#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	deque<int> palitos(N);
	for (int i = 0; i < N; ++i)
		cin >> palitos[i];
	sort(palitos.begin(), palitos.end());
	int r = 0, soma = 0;
	for (int i = 0; i < N; ++i)
	{
		if(palitos[i] < soma)
			r = i + 1;
		soma += palitos[i];
	}

	cout << r << endl;
	return 0;
}