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
#define MAXN 1010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

ll dp[MAXN][MAXN];
ll cb[2 * MAXN][2 * MAXN];

// CB: cb[i][j] -> Quantas possibilidades tenho com i bolinhas pretas em j espaços 
// Dp: dp[i][j] -> Quantas possibilidades tenho com uma grade de tamanho i sendo que j posições já foram coloridas

void preCalc(){
	
	cb[0][0] = 0;

	for(int i=1;i<2 * MAXN;i++) cb[i][0] = 0, cb[0][i] = 1; 

	vector<ll> sum(2 * MAXN);
	iota(all(sum), 0);

	for(int i=1;i < 2 * MAXN;i++){
		vector<ll> aux;
		ll acum = 0;

		for(int j=0;j < 2 * MAXN;j++){
			cb[i][j] = sum[j];

			acum += cb[i][j];
			acum %= mod;
			aux.pb(acum);
		}

		sum = aux;
	}
}

ll solve(int i, int j){

	if(i < 0) 			return 1LL;
	if(!i && !j) 		return 2LL;
	if(!i && j == 1) 	return 1LL;

	if(~dp[i][j]) return dp[i][j];

	ll ans = 0;

	if(j){
		ans = 2LL * ( ( solve(i-1,1) * solve(0,1) ) % mod ) * cb[2 * i -1][2];
		ans += solve(i-1, 0); 
		ans %= mod;
	}
	else{
		ans = 2LL * solve(i,1);
		ans %= mod;
	}

	return dp[i][j] = ans;
}

void solve(){
	
	ll ans = 0;

	for(int i=0;i<N;i++) {
		ans += ( ( (solve(i,1) * solve(N-i-2,0) * 2LL) % mod) * cb[ 2 * (i+1) - 1 ][ 2 * (N-i-1) + 1 ]) % mod;
		ans %= mod;
	}

	cout << ans << endl;
}

int main(){

	optimize;
	
	preCalc();
	ms(dp, -1);

    while(cin >> N && N){
		solve();
    }

	return 0;
}