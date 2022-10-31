#include <bits/stdc++.h> // UVA - 657 - The die is cast
#define N 70			// Leonardo Su
using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};

bool visited[N][N];
char board[N][N];
int n,m;

bool check(int i,int j)
{
	if(i<0 || i>=n || j<0 || j>=m || visited[i][j] || board[i][j] == '.') return false;
	return true;
}

void dfs_dot(int i,int j)
{
	visited[i][j] = true;
	board[i][j] = '*';
	int xx,yy;
	
	for(int z=0;z<4;++z)
	{
		xx = i + dx[z] , yy = j + dy[z];
		if(check(xx,yy) && board[xx][yy] == 'X')
			dfs_dot(xx,yy);
	}	
}

int dfs_dice(int i,int j)
{
	visited[i][j] = true;
	int xx,yy;
	int ans = 0;
	for(int z=0;z<4;++z)
	{
		xx = i + dx[z] , yy = j + dy[z];
		if(check(xx,yy) && board[xx][yy] != '.')
		{
			if(board[xx][yy] == 'X')
				ans++,dfs_dot(xx,yy);
			if(board[xx][yy] == '*')
				ans += dfs_dice(xx,yy);
		}
	}
	return ans;
}

vector<int> ans;
int caso = 1,x;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	bool pega = false;

	while(cin>>m>>n && (n+m))
	{

		cout<<"Throw "<<caso<<"\n";
		caso++;
		ans.clear();

		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
			{
				cin>>board[i][j];
				visited[i][j] = false;
			}

		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				if(!visited[i][j])
				{
					if(board[i][j] == '*')
					{
						x = dfs_dice(i,j);
						if(x != 0)
							ans.push_back(x);						
					}
				}

		sort(ans.begin(),ans.end());

		for(int i=0;i<ans.size()-1;++i)
			cout<<ans[i]<<" ";
		cout<<ans[ans.size()-1]<<"\n";		
		cout<<"\n";
	}
}