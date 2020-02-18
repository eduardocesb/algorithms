//https://codeforces.com/contest/1304/problem/B
#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define pii pair<int,int>
#define INF 2000000020
#define MAXN 220

using namespace std;

int N, M;
string S[MAXN];

string f(string s)
{
	string ans = "";

	for(int i = (int)s.length() - 1; i >= 0; i--)
		ans += s[i];

	return ans;
}

string solve()
{
	string ans = "";

	map<string, bool> mapa;
	for(int i = 0; i < N; i++)
	{
		if(mapa[S[i]])
		{
			ans = S[i] + ans;
			ans += f(S[i]);
			mapa.erase(S[i]);
		}
		else mapa[f(S[i])] = true;
	}


	for(auto y : mapa)
	{
		auto x = y.first;
		if((int)ans.size() % 2) return ans;

		// cout << x << " -- " << endl;

		if(x == f(x))
		{
			string aux = "";

			for(int i = 0; i < (int)ans.length() / 2; i++)
				aux += ans[i];

			aux += x;

			for(int i = (int)ans.length() / 2; i < (int)ans.length(); i++)
				aux += ans[i];

			ans = aux;
			return ans;
		}
	}

	return ans;
}

int main(int argc, char const *argv[])
{
	optimize;


	cin >> N >> M;

	for(int i = 0; i < N; i++)
		cin >> S[i];

	string ans = solve();

	cout << (int)ans.length() << endl << ans << endl;

	return 0;
}