#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 2000000000
#define pii pair<int, int>
#define ll long long
#define MAXN 100
#define MAXL 23

using namespace std;

int nums[MAXN];

int main(int argc, char const *argv[])
{
	optimize;

	int N, T, ans, menor = INF;

	cin >> N;

	for(int i = 0; i < N; i++) cin >> nums[i];

	cin >> T;

	for(int i = 0; i < N; i++)
	{
		if(menor > T % nums[i])
		{
			menor = T % nums[i];
			ans = nums[i];
		}
	}
	
	cout << ans << endl;

	return 0;
}