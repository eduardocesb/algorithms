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
#define MAXM 110

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

int A[MAXN], preSum[MAXN][MAXM];
vector<int> fat[MAXN];
bool p[MAXM];
vector<int> primos;

void crivo() {

    for(int i = 2; i < MAXM; i++) {
        if(!p[i]) {
            primos.pb(i);
            for(int j = i*i; j < MAXM; j+=i) p[j] = true;
        }   
    }
}

void fatora() {

    for(int i = 1; i <= N; i++) {

        int k = A[i];
        int j = 0;

        while(k > 1) {
            if(k % primos[j] == 0) {
                k /= primos[j];
                fat[i].pb(primos[j]);
            } 
            else    j++;
        }
    }
}

ll fastExp(ll x, ll n, ll m) {

    ll r = 1;

    while(n) {
        if(n & 1) r = (r * x) % m; 
        n >>= 1;
        x = (x * x) % m; 
    }

    return r;
}

void solve() {

	crivo();

    cin >> N;
    
    for(int i = 1; i <= N; i++) cin >> A[i];
    
    fatora();

    for(int i = 1; i <= N; i++) {

        for(int j = 0; j <= 100; j++) preSum[i][j] = preSum[i-1][j];

        for(int j = 0; j < fat[i].size(); j++) preSum[i][fat[i][j]]++; 
    }
    
    cin >> M;
    
    for(ll i = 0, u, v, m; i < M; i++) {
        
        ll ans = 1;
        
        cin >> u >> v >> m;

        for(int j = 1; j <= 100; j++) {
            int k = preSum[v][j] - preSum[u - 1][j];

            ans *= fastExp(j,k,m);
            ans %= m;
        }

        cout << ans << endl;
    }
}

int main() {

	optimize;
	
	//cin >> T;

    T = 1;

    while(T--) {
		solve();
    }

	return 0;
}