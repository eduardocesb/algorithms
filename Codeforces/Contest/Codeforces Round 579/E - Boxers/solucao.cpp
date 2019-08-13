#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define ll long long
#define MAXN 150010

using namespace std;

int nums[MAXN];
bool vis[MAXN];

int main(int argc, char const *argv[])
{
	optimize;

	int N, x;

	cin >> N;

	for(int i = 0; i < N; i++)
		cin >> nums[i];

	sort(nums, nums + N);

	int r = 0;

	for(int i = 0; i < N; i++)
	{
		if(nums[i] - 1 > 0 && !vis[nums[i] - 1])
		{
			r++;
			vis[nums[i] - 1] = true;
		}
		else if(!vis[nums[i]])
		{
			r++;
			vis[nums[i]] = true;
		}
		else if(!vis[nums[i] + 1])
		{
			r++;
			vis[nums[i] + 1] = true;
		}
	}

	cout << r << endl;
	
	return 0;
}