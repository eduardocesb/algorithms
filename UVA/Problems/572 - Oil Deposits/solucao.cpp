#include <bits/stdc++.h> // 572 - Oil Deposits
#define N 110
using namespace std;

int dx[] = {1,-1,1,-1,0,0,1,-1};
int dy[] = {1,-1,0,0,1,-1,-1,1};

int n,m;
char mapa[N][N];
bool marked[N][N];

bool check(int i,int j)
{
	if(i<0 || i>n || j<0 || j>m || marked[i][j]) return false;
	return true;
}

void dfs(int x,int y)
{
	marked[x][y] = true;
	for(int i=0;i<8;++i)
	{
		int xx = x+dx[i];
		int yy = y+dy[i];
		if(check(xx,yy) && mapa[xx][yy] == '@')
			dfs(xx,yy);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	while(cin>>n>>m && (n+m))
	{
		int ans = 0;

		for(int i=0;i<=n;++i)
			for(int j=0;j<=m;++j)
				marked[i][j] = false;

		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				cin>>mapa[i][j];

		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
			{
				if(mapa[i][j] == '@' && !marked[i][j])
				{
					dfs(i,j);
					ans++;
				}
			}

		cout<<ans<<"\n";
	}
}