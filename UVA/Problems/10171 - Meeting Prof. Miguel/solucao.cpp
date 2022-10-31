#include <bits/stdc++.h> //10171-UVA 	O(N^3)
#define f first			// 2 Floyd-Warshall
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()

using namespace std;

const int N = 30;
const int INF = 1e8;
typedef pair<int,int> ii;

int y[N][N],o[N][N];
int n,x,sum1,sum2,ans;
char A,B,t,di,age,l,r;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	bool flag;

	while(cin>>n && n)
	{	
		for(int i=0;i<N;++i)
			for(int j=0;j<N;++j)
				o[i][j] = y[i][j] = (i == j) ? 0 : INF;

		ans = INF;

		for(int i=1;i<=n;++i)
		{
			cin>>age>>di>>A>>B>>x;
			int u = A - 'A';
			int v = B - 'A';

			if(age == 'Y')
			{				
				y[u][v] = min(x,y[u][v]);
				if(di == 'B')
					y[v][u] = min(x,y[v][u]);
			}
			else
			{
				o[u][v] = min(x,o[u][v]);
				if(di == 'B')
					o[v][u] = min(x,o[v][u]);
			}
		}

		for(int k=0;k<N;++k)
			for(int i=0;i<N;++i)
				for(int j=0;j<N;++j)
					y[i][j] = min(y[i][j],y[i][k] + y[k][j]);

		for(int k=0;k<N;++k)
			for(int i=0;i<N;++i)
				for(int j=0;j<N;++j)
					o[i][j] = min(o[i][j],o[i][k] + o[k][j]);
		
		cin>>l>>r;
		int u = l - 'A';
		int v = r - 'A';
		vector<int> resp;

		for(int i=0;i<N;++i)
		{
			if(y[u][i] + o[v][i] < ans)
			{
				resp.clear(); resp.pb(i);
				ans = y[u][i] + o[v][i];
			}
			else if(ans == y[u][i] + o[v][i])
			{
				resp.pb(i);
			}
		}

		if(ans == INF)	cout<<"You will never meet.\n";
		else
		{
			cout<<ans<<" ";
			for(int i=0;i<resp.size();++i)
			{
				if(i != 0)
					cout<<" ";
				cout<<char(resp[i]+'A');
			}
			cout<<"\n";
		}

	}
}