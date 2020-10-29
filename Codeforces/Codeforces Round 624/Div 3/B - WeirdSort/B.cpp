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

vector<int> a,b,p;

int t,n,m;
bool comp(ii x,ii y)
{
	return x.f < y.f; 
}

bool check(vector<int> v)
{
	for(int i=0;i<v.size()-1;++i)
		if(v[i] > v[i+1]) return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>t;
	while(t--)
	{
		cin>>n>>m;

		a.resize(n);
		b.resize(n);
		// p.resize(m);

		for(int i=0;i<n;++i)
		{
			cin>>a[i];
			b[i] = a[i];
		}

		sort(all(b));

		bool seen[n + 100];

		for(int i=0;i<=n;++i)
			seen[i] = false;

		for(int i=0;i<m;++i)
		{
			int x;
			cin>>x;
			seen[x-1] = true;
		}

		if(check(a))
		{
			cout<<"YES\n";
			continue;
		}

		while(1)
		{
			bool change = false;
			for(int i=1;i<a.size();++i)
				if(a[i-1] > a[i] && seen[i-1])
				{
					change = true;
					swap(a[i-1],a[i]);
				}

			if(!change) break;
		}

		for(int i=0;i<n;++i)
		{
			int next = b[i];
			int pos = 0;

			for(int j=0;j<n;++j)
				if(next == a[j])
				{
					pos = j;
					break;
				}

			while(1)
			{
				if(a[pos] == b[i]) break;
				if(pos > 0 && seen[pos-1] && a[pos-1] > a[pos])
				{
					swap(a[pos],a[pos-1]);
					seen[pos-1] = false;
				}
				else break;
			}
		}


		if(check(a)) cout<<"YES\n";
		else cout<<"NO\n";

	}

}
