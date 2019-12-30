//https://www.urionlinejudge.com.br/judge/pt/problems/view/1900
//O(N * log N)

#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pii pair<int, int>
#define ll long long
#define INF 2000000000
#define MAXN 200020

using namespace std;

int nums[MAXN], N;

ll suffix[MAXN];

int main(int argc, char const *argv[])
{
	optimize;

	cin >> N;

	for(int i = 0; i < N; i++) cin >> nums[i];

	for(int i = N - 1; i >= 0; i--) suffix[i] = suffix[i + 1] + nums[i];

	ll ans = 0LL;

	map<ll, int> mapa;

	for(int i = 0; i < N; i++)
	{
		mapa[suffix[i]]++;;

		ans += mapa[suffix[i] - nums[i]];
	}

	cout << ans << endl;

	return 0;
}