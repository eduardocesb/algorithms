//https://neps.academy/problem/117
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
#define MAXN 505
#define MAXL 23
#define endl '\n'

using namespace std;

// (1 + sqrt(5)) / 2
const ld GOLDEN_RATIO = 1.6180339887498949025257388711906969547271728515625;
const ld PI = acos(-1.0);
const int BLOCK = 333;

int N, P, a[MAXN][MAXN], b[MAXN][MAXN], sum_a[MAXN][MAXN], sum_b[MAXN][MAXN];

void precalc(int nums[MAXN][MAXN], int sum[MAXN][MAXN])
{
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			sum[i][j] = nums[i][j] + (sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1]);
}


int area(int sum[MAXN][MAXN], int i, int j, int l, int r)
{
	return sum[i][j] - sum[l - 1][j] - sum[i][r - 1] + sum[l - 1][r - 1];
}

ll solve(int sum_a[MAXN][MAXN], int sum_b[MAXN][MAXN])
{
	ll ans = 0;

	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
		{
			int l = 0, r = N, m;

			int menor = 0, maior = 0;

			while(l <= r)
			{
				m = (l + r) / 2;

				if(i - m < 1 or j - m < 1)
				{
					r = m - 1;
					continue;
				}


				if(area(sum_b, i, j, i - m, j - m))
				{
					r = m - 1;
					continue;
				}

				if(area(sum_a, i, j, i - m, j - m))
				{
					r = m - 1;
					continue;
				}

				menor = m + 1;
				l = m + 1;
			}

			l = 0, r = N;

			while(l <= r)
			{
				m = (l + r) / 2;

				if(i - m < 1 or j - m < 1)
				{
					r = m - 1;
					continue;
				}

				if(area(sum_b, i, j, i - m, j - m))
				{
					r = m - 1;
					continue;
				}

				maior = m + 1;
				l = m + 1;
			}

			ans += maior - menor;
		}

	return ans;
}

int main(int argc, char const *argv[])
{
	optimize;

	cin >> N >> P;

	int x, y;

	for(int i = 0; i < P; i++)
	{
		cin >> x >> y;

		a[x][y] = 1;
	}

	for(int i = 0; i < P; i++)
	{
		cin >> x >> y;

		b[x][y] = 1;
	}

	precalc(a, sum_a);
	precalc(b, sum_b);

	cout << solve(sum_a, sum_b) << " " << solve(sum_b, sum_a) << endl;
	
	return 0;
}