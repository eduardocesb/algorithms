#include <bits/stdc++.h> // UVA 612  - DNA Sorting
#define N 70 			// Solution with BIT
#define all(x) x.begin(),x.end()
#define mp make_pair
using namespace std;

typedef pair<int,int> ii;

int t;
int n,m,limit;
int BIT[N];
string input;
vector<pair<ii,string> > ans;

void upd(int i,int x)
{
	while(i<N)
	{
		BIT[i]+=x;
		i+=(i&-i);
	}
}

int query(int i)
{
	int sum = 0;
	while(i>0)
	{
		sum+=BIT[i];
		i-=(i&-i);
	}
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	limit = int('T' - 'A') + 1; //max value

	cin>>t;
	while(t--)
	{
		cin>>n>>m;	
		ans.clear();	int sum = 0;

		int v[N];

		for(int z=0;z<m;++z)
		{
			for(int i=0;i<N;++i) BIT[i] = 0;  
			sum = 0;

			cin>>input;

			for(int i=0;i<n;++i)
			{
				int x = int(input[i] - 'A') + 1;
				sum+=query(limit) - query(x);
				upd(x,1);
			}

			ans.push_back(mp(mp(sum,z),input));
		}

		sort(all(ans));
		for(int i=0;i<ans.size();++i)
			cout<<ans[i].second<<"\n";
		if(t)
			cout<<"\n";
	}
}