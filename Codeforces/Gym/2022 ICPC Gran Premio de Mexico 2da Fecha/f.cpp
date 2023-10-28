#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define sz(x) (int)(x).size()
#define ALL(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define int long long

const int N = 150;
struct point {
	ll x, y;
} points[N];

ll valid[N][N];

bool cmp(point a, point b) {
	return a.x < b.x;
}

ll prod(ll a, ll b) {
	ll p = 1;
	for(ll i=a;i<=b;++i)
		p *= i;
	return p;
}

ll comb(ll n, ll k) {
	return (prod(n - k + 1LL, n) / prod(1LL, k));
}

int ccw(point a, point b, point c) {
	ll tetha = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
	if (tetha == 0)
		return 0;
	else if (tetha > 0)
		return 1;
	else 
		return -1;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    for(int i=0;i<n;++i)
    	cin>>points[i].x>>points[i].y;
    sort(points, points + n, cmp);

    ll total = comb(n, 4LL);
    if (n < 4) {
    	cout<<"0\n";
    	return 0;
    }

    ll invalid = 0;
    for(int i=0;i<n;++i)
    	for(int j=i+1;j<n;++j)
    		for(int k=j+1;k<n;++k)
    			for(int l=k+1;l<n;++l) {
    				//i,j,k / j,k,l / k,l,i, l,i,j
	    			if(ccw(points[i], points[j], points[k]) == 0 || 
	    				ccw(points[j], points[k], points[l]) == 0 || 
	    				ccw(points[i], points[j], points[l]) == 0|| 
	    				ccw(points[i], points[k], points[l]) == 0) {
	    				invalid += 1;
	    			}    				
    			}

    cout<<total - invalid<<"\n";
    return 0;
}