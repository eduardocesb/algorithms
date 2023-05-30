#include <bits/stdc++.h> // UVA - 10038
#define N 3010
using namespace std;

int n,past,atual,v[N];
bool jolly = true;
bool mark[N];

void clear(int n)
{
	for(int i=1;i<n;++i)
		mark[i] = true;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin>>n)
	{	
		if(atual) cout<<"\n";
		jolly = true; clear(n);


		for(int i=0;i<n;++i)
			cin>>v[i];

		for(int i=0;i<n-1;++i)
		{
			int x = abs(v[i]-v[i+1]);
			if(x<n) mark[x] = false;			
		}

		for(int i=1;i<n;++i)
			if(mark[i])
			{
				cout<<"Not jolly\n"; jolly = false;
				break;
			}
		if(jolly) cout<<"Jolly\n";
	}
}