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

int n, m, q, k, v[N];
pii w[N];

vector<ll>caras;
void gen(deque<char> s){
	if(sz(s) >= 36) return;
	ll mask = 0;
	if(s[0] != '0'){
		for(int i=0;i<sz(s);i++){
			if(s[i] == '1') mask += (1LL<<(i));
		}
		if(mask > 0)caras.pb(mask);
	}
	auto ss = s;
	s.push_front('0');
	s.push_back('0');
	gen(s);
	ss.push_front('1');
	ss.push_back('1');
	gen(ss);
	
}

void solve_case(){
	int A, B;
	cin>>A>>B;
	int qtd = upper_bound(all(caras),B)-lower_bound(all(caras),A);
	cout<<max(0LL, qtd)<<"\n";
}

int32_t main(){
	ios::sync_with_stdio(false); cin.tie(0);
	deque<char>v;
	gen(v);
	v.pb('0');
	gen(v);
	v.pop_back();
	v.pb('1');
	gen(v);

	sort(all(caras));
	caras.erase(unique(all(caras)),caras.end());

	int test_case=1;
	cin>>test_case;
	while(test_case--){
		solve_case();
	}
}
