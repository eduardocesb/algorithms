#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, C, S, r = 0, sentido, local = 1;

	cin >> N >> C >> S;

	if(local == S) r++;
	
	for (int i = 0; i < C; ++i)
	{
		cin >> sentido;

		local += sentido;

		if(local < 1) local = N;
		if(local > N) local = 1;

		if(local == S) r++;
	}

	cout << r << endl;
	return 0;
}