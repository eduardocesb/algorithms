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

#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 1000010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

int atual = 1, seg[4 * MAXN], ls[4 * MAXN], rs[4 * MAXN], root[4 * MAXN];

int newNode(){
	ls[atual] = rs[atual] = -1;

	atual++;

	return atual-1;
}

int v[MAXN], v2[MAXN], mapa2[MAXN];
map<int,int> mapa;

void build(int curr, int tl, int tr){

	if(tl != tr){
		int tm = (tl+tr)/2;

		ls[curr] = newNode();
		rs[curr] = newNode();
		
		build(ls[curr],tl,tm);
		build(rs[curr],tm+1,tr);
	}
}

void update(int prev, int curr, int tl , int tr, int a, int b, int x){

	if(a > tr || b < tl) return;
	else if(a <= tl && tr <= b){
		seg[curr] += x;
		return;
	}
	else{
		int tm = (tl+tr)/2;
		
		//Constrói só para o lado do valor que to indo
		if(a <= tm){		
			rs[curr] = rs[prev];

			if(ls[curr] == -1) ls[curr] = newNode();

			update(ls[prev] , ls[curr], tl, tm, a, b, x);
		}else{
			ls[curr] = ls[prev];

			if(rs[curr] == -1) rs[curr] = newNode();

			update(rs[prev] , rs[curr], tm+1, tr, a, b, x);
		}
		
		seg[curr] = seg[ls[curr]] + seg[ rs[curr] ];
	}
}

int query(int prev, int curr, int tl , int tr, int k){

	if (tl == tr) return tl;
	else{
		int tm = (tl+tr)/2;

		//Soma curr e diminui prev
		int vleft =  seg[ls[curr]] - seg[ls[prev]];

		if(k <= vleft)	return query(ls[prev], ls[curr], tl, tm, k);
		else	return query(rs[prev], rs[curr], tm+1, tr, k-vleft);
	}
}

void solve(){

	for(int i=0;i<M;i++){
		int a,b,c;

		cin >> a >> b >> c;

		int aux = query(root[a-1], root[b], 1, N, c);

		cout << mapa2[aux] << endl;
	}
}

int main(){

	optimize;
	
	cin >> N >> M;
		
	build(0,1,N);

	for(int i=0;i<N;i++) cin >> v[i];

	for(int i=0;i<N;i++) v2[i] = v[i];

	sort(v2, v2+N);
	unique(v2, v2+N);

	int cnt = 1;
	for(auto i : v2) {
		mapa[i] = cnt;
		mapa2[cnt++] = i;
	}

	for(int i=0;i<N;i++) {
		root[i+1] = newNode();

		update( root[i], root[i+1], 1, N, mapa[v[i]], mapa[v[i]], 1);
	}

	solve();

	return 0;
}