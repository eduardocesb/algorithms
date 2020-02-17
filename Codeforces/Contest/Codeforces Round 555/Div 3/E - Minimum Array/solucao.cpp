//https://codeforces.com/contest/1157/problem/E
#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pii pair<int, int>
#define ll long long
#define INF 1000000000
#define MAXN 200020
#define MAXL 22

using namespace std;

int main(int argc, char const *argv[])
{
	optimize;

	int N;

	cin >> N;

	int a[N], x;

	map<int, int> mapa;

	for(int i = 0; i < N; i++) cin >> a[i];
	for(int i = 0; i < N; i++)
	{
		cin >> x;
		mapa[x]++;
	} 

	for(int i = 0; i < N; i++)
	{
		int complemento = N - a[i];
		auto it = mapa.find(complemento);
		
		if(it != mapa.end())
			cout << 0 << " ";
		else
		{
			mapa[complemento] = 1;

			it = mapa.find(complemento);
			it++;

			if(it == mapa.end())
				it = mapa.begin();

			cout << (a[i] + it->first) % N << " ";


			mapa.erase(complemento);
		}

		if(it->second == 1) mapa.erase(it->first);
		else mapa[it->first]--;
	}
	return 0;
}