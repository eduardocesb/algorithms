#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(0); cin.tie(0)
#define pii pair<int, int>
#define MAXN 100100

using namespace std;

int main(int argc, char** argv)
{
	optimize;
	
	int N;
	
	cin >> N;
	
	map<char, int> idx;
	string x;
	
	for(int i = 0; i < N; i++)
	{
		cin >> x;
		idx[x[0]]++;
	}
	
	int r = 0;
	
	for(auto s : idx)
	{
		int k = s.second;
		int y = k / 2;
		k -= y;
		// cout << k << endl;
		
		r += (k * (k - 1)) / 2;
		r += (y * (y - 1)) / 2;
	}
	
	cout << r << endl;
	
	return 0;
} 