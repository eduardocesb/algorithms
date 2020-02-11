#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 2000000000
#define pii pair<int, int>
#define ll long long
#define MAXN 1000100
#define MAXL 23

using namespace std;

int LIS(vector<pii> nums)
{
	vector<int> p;

	for(int i = 0; i < (int)nums.size(); i++)
	{
		auto it = lower_bound(p.begin(), p.end(), nums[i].second);
		if(it == p.end())
			p.push_back(nums[i].second);
		else *it = nums[i].second;
	}

	return (int)p.size();
}

int MDC(int a, int b)
{
	return b ? MDC(b, a % b) : a;
}

pii vetor_direcional(pii v)
{
	int mdc = MDC(abs(v.first), abs(v.second));

	return pii(v.first / mdc, v.second / mdc);
}

map<pii, vector<pii>> retas;

int main(int argc, char const *argv[])
{
	optimize;

	int N, ans = 0, H, Tx, Ty;
	pii p;

	cin >> Tx >> Ty >> N;

	for(int i = 0; i < N; i++)
	{
		cin >> p.first >> p.second >> H;

		p.first -= Tx;
		p.second -= Ty;

		retas[vetor_direcional(p)].push_back(pii(MDC(abs(p.first), abs(p.second)), H));
	}

	for(auto r : retas)
	{
		sort(r.second.begin(), r.second.end());
		ans += LIS(r.second);
	}
	
	cout << ans << endl;

	return 0;
}