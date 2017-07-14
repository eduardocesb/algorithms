#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
	int N_C, N_N, x ,y;
	cin >> N_C >> N_N;
	map<long long, long long> C, R;
	for (int i = 0; i < N_C; ++i)
	{
		cin >> x >> y;
		C[x] = y;
	}

	for (int i = 0; i < N_N; ++i)
	{
		cin >> x >> y;
		if((C.find(x) == C.end() || C[x] < y) && (R.find(x) == R.end() || R[x] < y))
			R[x] = y;
	}

	for(map<long long, long long>::iterator it = R.begin(); it != R.end(); it++)
		cout << it->first << ' ' << it->second << endl;
	return 0;
}