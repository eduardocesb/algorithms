#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

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
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

struct UF{
    vector<int> parent, sz;

    UF(int n){
        parent.resize(n);
        sz.assign(n, 1);

        iota(all(parent), 0);
    }

    int find(int u) {
        if(u == parent[u])  return u;
        else                return find(parent[u]);
    }

    void unir(int u, int v) {
        u = find(u);
        v = find(v);

        if(u == v) return;

        if(sz[u] > sz[v]) {
            parent[v] = u;
            sz[u] += sz[v];
        }
        else {
            parent[u] = v;
            sz[v] += sz[u];
        }
    }

    int getSize(int u) { return sz[u]; }
};

void solve() {

    cin >> N >> M;
    
    UF uf(N);

    for(int i = 0, u, v; i < M; i++) {
        cin >> u >> v;

        u--, v--;

        uf.unir(u,v);
    }

    ll grupos = 0, ans = 1;

    for(int i = 0; i < N; i++){
        if(i == uf.find(i)) {
            grupos++;
            ans *= uf.getSize(i);
            ans %= mod; 
        }
    }

    cout << grupos << " " << ans << endl;
}

int main() {

	optimize;
	
	cin >> T;

    while(T--) {
		solve();
    }

	return 0;
}