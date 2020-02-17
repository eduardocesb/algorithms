//https://codeforces.com/contest/1157/problem/C1
#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pii pair<int, int>
#define ll long long
#define INF 1000000000
#define MAXN 200020
#define MAXL 22

using namespace std;

int nums[MAXN];

int main(int argc, char const *argv[])
{
	optimize;

	int N;

	cin >> N;

	for(int i = 0; i < N; i++) cin >> nums[i];

	int i = 0, j = N -1;

	int ans = 0, last = -1;
	string resp = "";

	while(i <= j)
	{
		if(nums[i] < nums[j])
		{
			if(last < nums[i])
			{
				resp += 'L';
				last = nums[i];
				i++;
			}
			else if(last < nums[j])
			{
				resp += 'R';
				last = nums[j];
				j--;
			}
			else break;
		}
		else if(nums[i] > nums[j])
		{
			if(last < nums[j])
			{
				resp += 'R';
				last = nums[j];
				j--;
			}
			else if(last < nums[i])
			{
				resp += 'L';
				last = nums[i];
				i++;
			}
			else break;
		}
		else
		{
			int a = i, b = j, l = last, c = 0, d = 0;

			string x = "", y = "";
			while(nums[a] > l)
			{
				x += 'L';
				c++;
				l = nums[a];
				a++;
			}

			l = last;

			while(nums[b] > l)
			{
				y += 'R';
				d++;
				l = nums[b];
				b--;
			}

			if(c > d)
			{
				ans += c;
				resp += x;
			}
			else
			{
				ans += d;
				resp += y;
			}
			break;
		}

		ans++;
	}

	cout << ans << endl << resp << endl;

	return 0;
}