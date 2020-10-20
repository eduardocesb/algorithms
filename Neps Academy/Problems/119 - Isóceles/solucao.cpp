//https://neps.academy/problem/119
#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 2000000020LL
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define POS(n, x) (lower_bound(ALL(n), x) - (n).begin())
#define ll long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101 
#define MAXN 200020
#define MAXL 23
#define endl '\n'

using namespace std;

// (1 + sqrt(5)) / 2
const ld GOLDEN_RATIO = 1.6180339887498949025257388711906969547271728515625;
const ld PI = acos(-1.0);
const int BLOCK = 333;

int N, nums[MAXN], pref[MAXN], suff[MAXN], ans;

int main(int argc, char const *argv[])
{
	optimize;
	
	cin >> N;

	for(int i = 1; i <= N; i++)
		cin >> nums[i];

	for(int i = 1; i <= N; i++)
		pref[i] = min(nums[i], pref[i - 1] + 1);

	for(int i = N; i; i--)
		suff[i] = min(nums[i], suff[i + 1] + 1);

	for(int i = 1; i <= N; i++)
		ans = max(ans, min(pref[i], suff[i]));

	cout << ans << endl;

	return 0;
}