#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld; 

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define space " " 

#define pii pair<int,int>
#define fi first 
#define se second 
#define pb push_back

#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define PI 3.141592653589793238462643383279502884
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007
#define MAXM 302

ll T,N,M;
int v[MAXM][MAXM];
int hor[MAXM][MAXM];
int ver[MAXM][MAXM];

#define MAXN 90010

vector<int> adjU[MAXN];
int pairU[MAXN], pairV[MAXN];
bool vis[MAXN];
int m, n;

bool dfs(int u) {
    vis[u] = true;
    if (u == 0) return true;
    for (int i = 0; i < (int)adjU[u].size(); i++) {
        int v = adjU[u][i];
        if (!vis[pairV[v]] && dfs(pairV[v])) {
            pairV[v] = u; pairU[u] = v;
            return true;
        }
    }
    return false;
}

int kuhn() {
    memset(&pairU, 0, sizeof pairU);
    memset(&pairV, 0, sizeof pairV);
    int result = 0;
    for (int u = 1; u <= m; u++) {
        memset(&vis, false, sizeof vis);
        if (pairU[u]==0 && dfs(u)) result++;
    }
    return result;
}

void preenche(){

	int cont = 1;
		
	bool last;
	bool fir;

	FOR(i,0,N){
		last = false;
		fir = true;

		FOR(j,0,M){
			if(v[i][j] == 1){
			
				if(last) cont ++;
				hor[i][j] = cont;
				last = false;
				fir = false;
			
			}else if(v[i][j] == 2){
				
				hor[i][j] = 0;
				if(!fir) last = true;

			}else if(v[i][j] == 3){
			
				hor[i][j] = 0;
			
			}
		}
		cont++;
	}

	m = cont-1;

	cont = 1;

	FOR(i,0,M){
		last = false;
		fir = true;
		FOR(j,0,N){
			if(v[j][i] == 1){
				
				if(last) cont++;
				ver[j][i] = cont;
				last = false;
				fir = false;
			
			}else if(v[j][i] == 2){
				
				ver[j][i] = 0;
				if(!fir) last = true;

			}else if(v[j][i] == 3){
			
				ver[j][i] = 0;
			
			}
		}
		cont++;
	}
	n = cont-1;
}

void solve(){

	preenche();

	FOR(i,1,m+1)	adjU[i].clear();
	
	FOR(i,0,N){
		FOR(j,0,M){
			if(v[i][j] == 1)
				adjU[ hor[i][j] ].pb( ver[i][j] );
		}
	}

	int ans = kuhn();

	cout << ans << endl;
}

int main(){

	cin >> T;

    while(T--){
		cin >> N >> M;

		char a;

		FOR(i,0,N){
			FOR(j,0,M){
				cin >> a;
				if(a == 'H'){
					v[i][j] = 1;
				}else if(a == 'A'){
					v[i][j] = 2;
				}else if(a == 'D'){
					v[i][j] = 3;
				}
			}
		}
		solve();
    }

	return 0;
}	