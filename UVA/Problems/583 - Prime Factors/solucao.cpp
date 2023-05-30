#include <bits/stdc++.h> // 583 - Prime Factors
using namespace std;
typedef long long int ll;

const long long int N = 56345;

ll n;
vector<ll> primos;
bool seen[N],flag;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	primos.push_back(2);
	for(ll i=3;i<N;i+=2)
	{
		if(!seen[i])
		{
			for(int j=2*i;j<N;j+=i)
				seen[j] = true;	
			primos.push_back(i);
		}
	}
	
	int cnt = primos.size();
	while(cin>>n && n)
	{
		cout<<n<<" = ";

		if(n < 0LL) 
		{
			cout<<"-1 x "; 
			n*=-1;
		}
		
		for(int pos=0;pos<cnt;++pos)
		{
			while(n%primos[pos] == 0)
			{
				cout<<primos[pos];
				n/=primos[pos];
				if(n == 1) break;
				cout<<" x ";
			}
			if(n == 1) break;
		}

		if(n > 1) cout<<n;
		cout<<"\n";		
	}
}