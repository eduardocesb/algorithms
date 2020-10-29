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

vector< array<int,3> > v;

void init()
{
	int n = 1e4 + 64;

	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;j+=i)
			for(int k=j;k<=n;k+=j)
				v.pb({i,j,k});
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	init();
	int t,a,b,c;
	cin>>t;

	while(t--)
	{
		cin>>a>>b>>c;
		array<int,4> best;
		best = {INF,a,b,c};
		for(auto e : v)
		{
			array<int,4> now;
			now = { abs(a-e[0]) + abs(b-e[1]) + abs(c-e[2]),e[0],e[1],e[2]};
			best = min(best,now);
		}
		cout<<best[0]<<"\n";
		cout<<best[1]<<" "<<best[2]<<" "<<best[3]<<"\n";
	}
}