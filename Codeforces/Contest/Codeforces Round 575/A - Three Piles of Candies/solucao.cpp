#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)

using namespace std;


int main(int argc, char** argv)
{
	// optimize;
	
	int N;
	
	long long a, b, c;
	
	cin >> N;
	
	while(N--)
	{
		cin >> a >> b >> c;
		
		cout << ((a + b + c) / 2) << endl;
	}
	return 0;
}