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
ld l, alfa;
const int t = 3;

struct Matriz{
	ld m[t][t];

    Matriz() {
        for(int i=0;i<t;i++)
			for(int j=0;j<t;j++)
				m[i][j] = 0;
    }

    Matriz(ld nums[]){
        for(int i=0;i<t;i++)
			for(int j=0;j<t;j++)
				m[i][j] = nums[i*t + j];
    }

    Matriz(int i){
        for(int i=0;i<t;i++)
			for(int j=0;j<t;j++)
				m[i][j] = (i==j);
    }

	Matriz operator* (const Matriz &p){
		Matriz ans;

		for(int i=0;i<t;i++)
			for(int j=0;j<t;j++)
				for(int k = ans.m[i][j] = 0;k<t;k++)
					ans.m[i][j] = (ans.m[i][j] + m[i][k] * p.m[k][j]);

		return ans;
	} 
};

Matriz fastExpoM(Matriz A, ll n) {
	
	Matriz ret(1);
	Matriz b = A;
  	
  	while (n) {
    	if (n & 1)
     	 	ret = (ret * b);
    	b = (b * b);
    	n >>= 1;
  	}
  	return ret;
}

void solve(){

    ld nums[9];

    //  cos(alfa) -sin(alfa) l 
    //  sin(alfa)  cos(alfa) 0
    //          0          0 1

    alfa = alfa * acos(-1) / 180.0L;

    nums[0] =  cos(alfa);
    nums[1] = -sin(alfa);
    nums[2] =  l;

    nums[3] =  sin(alfa);
    nums[4] =  cos(alfa);
    nums[5] =  0;

    nums[6] = 0;
    nums[7] = 0;
    nums[8] = 1;

    Matriz m(nums);

    m = fastExpoM(m, N);

    ld x = m.m[0][2];
    ld y = m.m[1][2];

    cout << fixed << setprecision(8) << x;
    cout << " " << fixed << setprecision(8) << y << endl;
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> alfa >> l >> N;
		
		solve();
    }

	return 0;
}