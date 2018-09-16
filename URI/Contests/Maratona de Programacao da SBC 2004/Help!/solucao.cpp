#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(0); cin.tie(0)

using namespace std;

int main(int argc, char** argv)
{
	optimize;
	int N;
	while((cin >> N) && N)
	{
		unordered_map<string, int> idx;
		int t, r = 0, q = 0;
		string x, y;
		while(N--)
		{
			cin >> x >> t >> y;
			if(y == "correct")
				r += t + idx[x], q++;
			else
				idx[x] += 20;
		}
		cout << q << " " << r << endl;
	}
	return 0;
}
