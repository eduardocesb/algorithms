#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 2000000000
#define pii pair<int, int>
#define ll long long
#define MAXN 100100
#define MAXL 23

using namespace std;

string S;

void solve()
{
	vector<pii> passos;

	for(int i = 0; i < (int)S.length(); i++)
	{
		char menor = S[i];
		int pos = i;
		for(int j = i + 1; j < (int)S.length(); j++)
		{
			if(menor > S[j])
			{
				pos = j;
				menor = S[j];
			}
		}

		swap(S[i], S[pos]);

		if(i != pos)
			passos.push_back(pii(i + 1, pos + 1));
	}

	reverse(passos.begin(), passos.end());

	for(auto p : passos)
		cout << p.second << " " << p.first << endl;
}

int main(int argc, char const *argv[])
{
	optimize;

	cin >> S;

	solve();
	
	return 0;
}