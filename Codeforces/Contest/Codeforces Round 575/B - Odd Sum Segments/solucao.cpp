#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)

using namespace std;


int main(int argc, char** argv)
{
	// optimize;
	
	int Q, N, K;
	
	cin >> Q;
	
	while(Q--)
	{
		cin >> N >> K;
		
		int sum = 0, x;
		
		vector<int> r;
		
		for(int i = 1; i <= N; i++)
		{
			cin >> x;
			
			sum += x;
			
			if(K <= 1) continue;
			
			if(sum & 1)
			{
				r.push_back(i);
				K--;
				sum = 0;
			}
		}
		
		if(sum & 1)
		{
			cout << "YES" << endl;
			r.push_back(N);
			for(auto i : r)
				cout << i << " ";
			cout << endl;
		}
		else
			cout << "NO" << endl;
	}
	
	return 0;
}