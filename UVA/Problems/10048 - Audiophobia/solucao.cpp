/*
  *********************
  uva 10048 Audiophobia
  Leonardo Su
*/
#include <bits/stdc++.h>
#define MAXN 150
using namespace std;
int dist[MAXN][MAXN],n,m,q,teste=1;
int a,b,w,ttt;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    bool ok=false;
    
    while(true)
    {
        cin>>n>>m>>q;
        if(n==0 && m==0 && q==0) return 0;
        if(ttt!=0) cout<<"\n";
        ttt++;
        memset(dist,9999999,sizeof dist);
        for(int i=1;i<=m;++i)
        {
            cin>>a>>b>>w;
            dist[a][b]=w;
            dist[b][a]=w;
        }

        for(int k=1;k<=n;++k)
            for(int i=1;i<=n;++i)
                for(int j=1;j<=n;++j)
                dist[j][i]=dist[i][j]=min(dist[i][j],max(dist[i][k],dist[k][j])  );
        

        cout<<"Case #"<<teste++<<"\n";
        for(int i=1;i<=q;++i)
        {
            cin>>a>>b;
            if(dist[a][b]<=9999999)
            cout<<dist[a][b]<<"\n";
            else
                cout<<"no path\n";
        }
        
    }

    return 0;
}