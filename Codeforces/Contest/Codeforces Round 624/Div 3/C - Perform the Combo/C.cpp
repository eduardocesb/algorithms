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


int prefix[30][N];
string combo,aux;
int ans[30];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


	int t;
	int n,m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		cin>>combo;
		string aux;


		for(int i=0;i<27;++i)
		{
			for(int j=0;j<=n+10;++j)
				prefix[i][j] = 0;
			ans[i] = 0;
		}


		for(int i = 0;i<combo.size();++i)
		{
			int pos = int(combo[i] - 'a');
			prefix[pos][i]++;
			ans[pos]++;
		}
		
		for(int i=0;i<27;++i)
			for(int j=1;j<n;++j)
				prefix[i][j] += prefix[i][j-1];

		for(int i=0;i<m;++i)
		{
			int x;
			cin>>x;
			x--;
			for(int j=0;j<27;++j)
				ans[j]+=prefix[j][x];			
		}

		for(int i=0;i<26;++i)
			cout<<ans[i]<<" ";

		cout<<"\n";
	}


}
