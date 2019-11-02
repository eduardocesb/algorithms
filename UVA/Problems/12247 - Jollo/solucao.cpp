#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pii pair<int, int>
#define ll long long
#define INF 1000000000
#define MAXN 220

using namespace std;

vector<int> a(3), b(2);

bool ok[53];

bool ganha(int i)
{
	vector<int> c;
	c.push_back(i);
	c.push_back(b[0]);
	c.push_back(b[1]);
	sort(c.begin(), c.end());

	int j = 0;
	for(int i = 0; i < 2; i++)
	{
		while(j < 3 && a[j] < c[i]) j++;

		if(j < 3) j++;
		else return true;
	}

	return false;
}

int solve()
{
	sort(a.begin(), a.end());

	for(int i = 1; i < 53; i++)
		if(!ok[i] && ganha(i)) return i;
	return -1;
}

int main(int argc, char const *argv[])
{
	while(true)
	{
		for(int i = 0; i < 3; i++) cin >> a[i];
		for(int i = 0; i < 2; i++) cin >> b[i];

		if(!a[0]) break;

		ok[a[0]] = ok[a[1]] = ok[a[2]] = ok[b[0]] = ok[b[1]] = true;

		cout << solve() << endl;

		ok[a[0]] = ok[a[1]] = ok[a[2]] = ok[b[0]] = ok[b[1]] = false;
	}


	return 0;
}