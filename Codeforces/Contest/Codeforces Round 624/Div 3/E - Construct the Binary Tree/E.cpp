#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
const int N = 5010;
const int INF = 1e9;
const int MOD = 1e9 + 7;
using namespace std;
typedef pair<int,int> ii;
typedef long long int ll;


int n,d;
int pai[N],cnt[N];
vector<int> nivel[N];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>d;
		int sum = (n*(n-1))/2;

		if(d > sum)
		{
			cout<<"NO\n";
			continue;
		}

		for(int i=0;i<n;++i)
		{
			pai[i] = i-1;
			cnt[i] = 1;
			nivel[i].clear();
			nivel[i].pb(i);	
		}

		int now = n - 1;
		int pos;

		while(sum > d)
		{			
			cnt[now] = 0;

			for(pos = 0;pos<now-1;++pos)
				if(nivel[pos].size())
					break;							

			if(pos == now - 1) break;

			int dif = sum - d;
			if(dif < now - pos - 1)
			{
				pai[now] = now - 1 - sum + d;
				sum = d;
				break;
			}
						
			int x = nivel[pos].back();
			pai[now] = x;
			cnt[x]++;
			if(cnt[x] >= 2) nivel[pos].pop_back();

			nivel[pos+1].pb(now);
			sum-= now - pos - 1;
			now--;
		}

		if(sum > d)
			cout<<"NO\n";
		
		else
		{
			cout<<"YES\n";
			for(int i=1;i<n;++i)
			{
				cout<<pai[i]+1;
				if(i+1<n) cout<<" ";
			}
			cout<<"\n";
		}
	}
}
