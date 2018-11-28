#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(int argc, char** argv)
{
	int N;
	
	cin >> N;
	int nums[N];
	
	ll S = 0LL;
	unordered_map<ll, bool> idx;
	
	for(int i = 0; i < N; i++)
	{
		cin >> nums[i];
		S += nums[i];
		
		idx[S] = true;
	}
	
	if(S & 1LL) 
	{
		cout << "N" << endl;
		return 0;
	}
	
	ll meio = S >> 1LL;
	ll s = 0LL;
	int r = 0;
	
	for(int i = 0; i < N; i++)
	{
		s += nums[i];
		if(s > meio) break;
		
		r += idx[s + meio];
	}
	
	cout << (r > 1 ? "Y" : "N") << endl;
	
	return 0;
}