#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define MAXN 1000

using namespace std;

vector<string> pre(5);

bool f(int a, char op, int b)
{
	if(op == '<') return a < b;
	return a > b;
}

bool ok(vector<char> x)
{
	int y[5];
	for(int i = 0; i < 5; i++)
		y[x[i] - 'A'] = i;

	for(int i = 0; i < 5; i++)
		if(!f(y[pre[i][0] - 'A'], pre[i][1], y[pre[i][2] - 'A']))
			return false;
	return true;
}

int main(int argc, char const *argv[])
{
	vector<char> x = {'A', 'B', 'C', 'D', 'E'};

	for(int i = 0; i < 5; i++)
		cin >> pre[i];

	int i = 0;

	while(i++ < MAXN)
	{
		random_shuffle(x.begin(), x.end());

		if(ok(x))
		{
			for(int i = 0; i < 5; i++)
				cout << x[i];
			cout << endl;
			return 0;
		}
	}

	cout << "impossible" << endl;
	
	return 0;
}