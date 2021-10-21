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

#define all(x) x.begin(),x.end()
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 50010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
int A[MAXN], B[MAXN], menor[MAXN];
bool vis[MAXN];
vector<pii> edge;

void dijkstra(int s, vector<ll> &dist){

	priority_queue< pii, vector<pii>, greater<pii>  > pq;

	pq.push(pii(s,0));
	dist[s] = 0;

	while(!pq.empty()){
		int u = pq.top().se;
		pq.pop();

		if(vis[u]) continue;
		vis[u] = true;

		for(auto i : edge){
			int v = (u + i.fi)%A[0];

			if(dist[v] > dist[u] + i.se){
				dist[v] = dist[u] + i.se;
				pq.push(pii(dist[u] + i.se, v));
			}
		}
	}
}

void solve(){

	for(int i=0;i<N;i++) {
		int aux = A[i]%A[0];

		if(!menor[aux]) {
			menor[aux] = A[i];
			edge.pb(pii(aux, A[i]));
		}
	}

	vector<ll> dist(A[0], INFLL);

	dijkstra(0, dist);

	dist[0] = menor[0];
	
	for(int i=0;i<M;i++){
		int aux = B[i]%A[0];

		if(dist[aux] <= B[i] || !B[i]) 	cout << "TAK\n";
		else 	  						cout << "NIE\n";
	}
}

int main(){

	optimize;
	
	cin >> N;

	for(int i=0;i<N;i++) cin >> A[i];

	cin >> M;

	for(int i=0;i<M;i++) cin >> B[i];

	solve();
    
	return 0;
}