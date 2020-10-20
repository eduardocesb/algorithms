#include<bits/stdc++.h>
using namespace std;

// Template 1
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld; 

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

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
#define MAXN 200010

ll T,N,M;

struct KMP{
    int m;
    string q;
    vector<int> lps;
    
    KMP(string &_q) : q{_q} {
        m = q.size();
        pre_process();
    }

    void pre_process(){
        lps.assign(m+1,-1);

        for(int i=0, j=-1; i<m ; ){
            while(j>=0 && q[i] != q[j]) j = lps[j];
            lps[++i] = ++j; 
        }
    }

    int match(string &p){
        ll n = p.size();

        int maior = -INF;

        for(int i=0,j=0; i<n;){
            while( j>=0 && p[i] != q[j]) j = lps[j];
            i++; j++;

            maior = j;

            if(j == m)  j = lps[j];
        }
        return maior;
    }

};

int main(){

	string s;

    while(cin >> s){
        
        string aux = s;

        reverse(all(aux));

        KMP kmp(aux);

        int ans = kmp.match(s);

        for(int i = s.size()-ans-1;i>=0;i--){
            s += s[i];
        }
        cout << s << endl;
    }

	return 0;
}