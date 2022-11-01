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
#define MAXN 200100

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int T,N,M,K;
const int t = 450;
stack<tuple<int,int,int,int,int,int>> pilha;

class UnionFind{
    private:
        vector<int> parent;
        vector<int> rank;
    public:
        void init(int n){
        	parent.assign(n+1,0);
            rank.assign(n+1,0);

            for(int i=0;i<n;i++){
                parent[i] = i;
            }	
        }
        void reset(int n){
            for(int i=0;i<n;i++){
                parent[i] = i;
                rank[i] = 0;
            }
        }

        void resetParcial(){
            while(!pilha.empty()){
            	auto i = pilha.top();
            	pilha.pop();
            
            	int p = get<0>(i);
            	int q = get<1>(i);

            	parent[p] = get<2>(i);
            	parent[q] = get<3>(i);
            	rank[p] = get<4>(i);
            	rank[q] = get<5>(i);
            } 
        }

        int find(int i, int k){
            if(parent[i] == i) return i;
            
            if(k) return find(parent[i], k);
            else return  parent[i] = find(parent[i], k);
        }

        bool sameSet(int i, int j, int k){
            return find(i,k)==find(j,k);
        }

        void unir(int i, int j, int k){
    		i = find(i,k);
            j = find(j,k);
    	    
            if(i != j){
				if(k) pilha.push(make_tuple(i,j,parent[i],parent[j],rank[i],rank[j]));	

                if(rank[i] < rank[j]) swap(i,j);
                parent[j] = i;
                if(rank[i] == rank[j]) rank[i]++;
            }
        }
};

struct Query{
	int l, r, id;

    Query() {}
    Query(int _l, int _r, int _id) : l{_l}, r{_r}, id{_id} {}

    bool operator<(const Query &a) const{
	    if (l/t != a.l/t){
	    	return l < a.l; 
	    }
	    return r < a.r;
	}
};

pii edge[MAXN];
int v[MAXN], ans[MAXN], cc, cc2;
Query Q[MAXN];
UnionFind UF;

void add(int p, int k, int &c){

	int u = edge[p].fi, v = edge[p].se;

	bool r = UF.sameSet(u,v,k);

	if(!r){
		UF.unir(u,v,k);
		c--;
	}
}

void MO(){
	sort(Q, Q+K);

	UF.init(N);

	int lMO=0, rMO=-1, l, r, id, last = -1;
	
	for(int i=0; i<K; i++){

		l = Q[i].l;
		r = Q[i].r;
		id = Q[i].id;

		//Resetando quando o l troca de bloco
		if(l/t != last) {
			if(i) UF.reset(N);
			last = l/t;
			cc = N;

			rMO = min(M , (l/t) * t + t -1);
		}
	
		if(l/t == r/t){
			cc2 = N;
	
			rMO = l-1;
			lMO = l;

			while(rMO < r) add(++rMO, 1 , cc2);

			rMO = min(M , (l/t) * t + t -1);
		}
		else{
			lMO = min(M , (l/t) * t + t);

			//To adicionando do r anterior até r o r atual
			while(rMO < r) add(++rMO, 0, cc);
			
			cc2 = cc;
			
			//To adicionando da l até SQRT
			while(lMO > l) add(--lMO, 1, cc2);
		}

		//Reseto a todo momento o UF2 por causa do l
		UF.resetParcial();
		
		ans[id] = cc2;
	}

	for(int i=0;i<K;i++) cout << ans[i] << endl;
}

int main(){

	optimize;

	cin >> T;

    while(T--){
    	cin >> N >> M >> K;

		FOR(i,0,M) {
			int a,b;
			cin >> a >> b; 

			a--, b--;
			
			edge[i].fi = a;
			edge[i].se = b;
		}
		
		FOR(i,0,K){
			int a,b;
			cin >> a >> b;

			a--, b--;

			Q[i].l = a, Q[i].r = b;
			Q[i].id = i;
		}

		MO();
    }

	return 0;
}