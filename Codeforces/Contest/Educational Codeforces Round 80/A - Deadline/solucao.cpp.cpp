//https://codeforces.com/contest/1288/problem/A

#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

using namespace std;

bool solve(int N, int D)
{
	int root = sqrt(D);

	root += 10;

	for(int i = 0; i <= root; i++)
		if(i + ((D + i) / (i + 1)) <= N) return true;

	return false;
}

int main(int argc, char** argv)
{

	int T, N, D;

	cin >> T;

	while(T--)
	{
		cin >> N >> D;

		cout << (solve(N, D) ? "YES" : "NO") << endl;
	}

	return 0;
}
