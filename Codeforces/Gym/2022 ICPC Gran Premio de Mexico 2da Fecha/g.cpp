#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
#define int long long

#define dbg_loc() cerr << __PRETTY_FUNCTION__ << " : " << __LINE__ << "\n"
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p){ 
	return os << '(' << p.first << ", " << p.second << ')'; 
}
template<typename T_container,typename T=typename enable_if<!is_same<T_container,string>::value, typename T_container::value_type>::type> 
ostream& operator<<(ostream &os, const T_container &v){ 
	os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; 
}
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ 
	cerr << ' ' << H; 
	dbg_out(T...); 
}
#define LOCAL
#define LOCAL
#ifdef LOCAL 
#define dbg(...) cerr<<"(" << #__VA_ARGS__<<"):" , dbg_out(__VA_ARGS__) , cerr << endl
#else
#define dbg(...)
#endif
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
ll mod = (1000000007LL);
inline ll Mod(ll a, ll b){return (a%b);}
inline ll poww(ll a, ll b){ll res = 1;while (b > 0){if(b & 1) res = (res * a)%mod;a = (a * a)%mod;b >>= 1;}return res;}
ll gcd (ll a, ll b) { while (b) { a %= b,swap(a, b);}return a;}
void read(vector<int> &w, int n){w.resize(n);for(int i = 0; i < n; i++) cin>>w[i];}
void print(vector<int> &w){for(int i =0; i < sz(w); i++){if(i == sz(w) - 1) cout<<w[i]<<"\n";else cout<<w[i]<<" ";}}

///CUIDADO COM MAXN
#define N 1000010 // 1E6

int n, m, q, k, v[N], pos[N], t[N];
pii w[N];
int L[N],R[N];

void solve_case(){
	ll ans = 0;
	cin>>n;
	pos[1] = 1;
	for(int i=2;i<=n;i++){
		cin>>v[i];
		pos[i] = pos[i-1]+v[i];
	}
	int t_ini = 0;
	for(int i=1;i<=n;i++){
		cin>>t[i];
		L[i] = t_ini;
		R[i] = t_ini + t[i];
		t_ini += t[i]+v[i+1];
	}
	int t_fim = 0;
	for(int i = n; i >= 1; i--){
		int ll = t_fim;
		int rr = t_fim+t[i];

		int l = max(L[i],ll);
		int r = min(R[i],rr);
		ans += max(0LL,r-l);

		t_fim += t[i]+v[i];
	}

	cout<<ans<<"\n";
}

int32_t main(){
	ios::sync_with_stdio(false); cin.tie(0);
	
	int test_case=1;
	while(test_case--){
		solve_case();
	}
}
