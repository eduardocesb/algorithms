#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define fi first 
#define se second 
#define pb push_back

#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
vector<vector<pii>> adj;
vector<int> ex;

ll dijkstra(){

    vector<pii> dist(N,pii(INFLL,INFLL));
    
    bool v[N] = {0};
    set<pii> s;
    
	FOR(i,0,sz(ex)){
		dist[ ex[i] ] = pii(0,0);
    	s.insert(pii(0,ex[i]));
	}
	
    while(!s.empty()){
		ll u = s.begin()->second;
		s.erase(s.begin());
		
		v[u] = true;

        if(dist[u].se == INFLL) break;
		
        for(int i=0;i<adj[u].size();i++){
            ll w = adj[u][i].first;
            ll p = adj[u][i].second;
		
		    if(v[w]) continue;
            else{

                if(dist[w].fi > dist[u].se + p ){
                    
                    ll aux = dist[u].se + p;
                    
					s.erase(pii(dist[w].se , w));
					
					dist[w].se = dist[w].fi;
                    dist[w].fi = aux;
					
					s.insert(pii(dist[w].se , w));

                }else if(dist[w].se > dist[u].se + p ){
                    
                    ll aux = dist[u].se + p;
                    
					s.erase(pii(dist[w].se , w));
                    
                    dist[w].se = aux;
					
					s.insert(pii(dist[w].se , w));
                }
            }
        }
    }

    return dist[0].se;
}

void solve(){
	cout << dijkstra() << endl;
}

int main(){

	optimize;
	cin >> N >> M >> K;

	adj.resize(N);
	ex.resize(K);

	FOR(i,0,M){
		ll a,b,c;
		cin >> a >> b >> c;

		adj[a].pb(pii(b,c));
		adj[b].pb(pii(a,c));
	}

	FOR(i,0,K) cin >> ex[i];

	solve();
    
	return 0;
}