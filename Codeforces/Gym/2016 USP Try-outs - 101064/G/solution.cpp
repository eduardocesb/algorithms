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

int atual = 1, seg[30 * MAXN], ls[30 * MAXN], rs[30 * MAXN], root[30 * MAXN];
pii ptr[MAXN];

int newNode(){
	ls[atual] = rs[atual] = -1;

	atual++;

	return atual-1;
}

void build(int curr, int tl, int tr){

	if(tl != tr){
		int tm = (tl+tr)/2;

		ls[curr] = newNode();
		rs[curr] = newNode();
		
		build(ls[curr],tl,tm);
		build(rs[curr],tm+1,tr);
	}
}

void update(int prev, int curr, int tl , int tr, int a, int x){

	if(a > tr || a < tl) return;
	else if(a <= tl && tr <= a){
        seg[curr] = x;
		return;
	}
	else{
		int tm = (tl+tr)/2;
		
		//Constrói só para o lado do valor que to indo
		if(a <= tm){		
			rs[curr] = rs[prev];

			if(ls[curr] == -1) ls[curr] = newNode();

			update(ls[prev] , ls[curr], tl, tm, a, x);
		}else{
			ls[curr] = ls[prev];

			if(rs[curr] == -1) rs[curr] = newNode();

			update(rs[prev] , rs[curr], tm+1, tr, a, x);
		}
		
		seg[curr] = seg[ls[curr]] + seg[ rs[curr] ];
	}
}

int query(int prev, int curr, int tl , int tr, int a){

    if(a > tr || a < tl) return 0;
	else if(a <= tl && tr <= a){
		return seg[curr];
	}
	else{
		int tm = (tl+tr)/2;
		
		ls[curr] = ls[prev];
		rs[curr] = rs[prev];
		
        return query(ls[prev] , ls[curr], tl, tm, a) + query(rs[prev] , rs[curr], tm+1, tr, a);
	}
}

void solve(){

    build(0,1,N);

    for(int i=0;i<=N;i++) ptr[i] = pii(1,1);

    for(int i=1;i<=N;i++){
        int a,b;
        char k;

        cin >> k;

        root[i] = newNode();

        if(k == 'E'){
            cin >> a >> b;
            
            ptr[i] = ptr[a];
            
            update(root[a], root[i], 1, N, ptr[i].se, b);
            
            ptr[i].se++;
        }
        else{
            cin >> a;

            //Construou versão i e faço a query na versão i
            ptr[i] = ptr[a];

            cout << query(root[a], root[i], 1, N, ptr[i].fi) << endl;
            
            //"Removo" aquela posição
            ptr[i].fi++;
        }
    }
}

int main(){

	optimize;
	
	cin >> N;
		
	solve();
    
	return 0;
}