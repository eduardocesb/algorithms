#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define MAXN 110

using namespace std;

bool m[MAXN][MAXN];

int main(int argc, char** argv)
{
	optimize;

	int N;

	cin >> N;

	for(int i = 1; i < N; i++)
		m[i][0] = !m[i - 1][0];

	for(int i = 0; i < N; i++)
		for(int j = 1; j < N; j++)
			m[i][j] = !m[i][j - 1];

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			cout << (m[i][j] ? 'W' : 'B') << (j == N - 1 ? "\n" : "");	
		
	return 0;
}
