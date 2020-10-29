#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
const int N = 2e5 + 7;
const int INF = 1e9;
const int MOD = 1e9 + 7;
using namespace std;
typedef pair<int,int> ii;
typedef long long int ll;

ll poww(ll x,ll y)
{
	ll z = 1;
	while(y > 0)
	{
		if(y%2 == 1) z = (z*x)%MOD;
		x = (x*x)%MOD;
		y/=2;
	}
	return z%MOD;
}

int n,ans;
int t;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


	cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		if(a == b)
		{
			cout<<"0\n";
			continue;			
		}

		if(a < b)
		{
			int dif = b - a;
			if(dif%2 == 1) ans = 1;
			else ans = 2;
		}
		else
		{
			int dif = a - b;
			if(dif%2 == 0) ans = 1;
			else ans = 2;
		}
		cout<<ans<<"\n";
	}

}