#include "bits/stdc++.h" //https://www.spoj.com/problems/POLYMUL/
using namespace std;	// Leonardo
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef complex<long double> C;
typedef vector<long double> vd;
void fft(vector<C>& a) 
{
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vector<complex<long double>> R(2, 1);
	static vector<C> rt(2, 1);
	for (static int k = 2; k < n; k *= 2) 
	{
		R.resize(n); rt.resize(n);
		auto x = polar(1.0L, acos(-1.0L) / k);
		rep(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
	}
	vi rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) 
		{
			C z = rt[j+k] * a[i+j+k];
			a[i + j + k] = a[i + j] - z;
			a[i + j] += z;
		}
}

vd conv(const vd& a, const vd& b) 
{
	if (a.empty() || b.empty()) return {};
	vd res(sz(a) + sz(b) - 1);
	ll L = 32 - __builtin_clz(sz(res)), n = 1 << L;
	vector<C> in(n), out(n);	copy(all(a), begin(in));
	rep(i,0,sz(b)) in[i].imag(b[i]);
	fft(in);
	for (C& x : in) x *= x;
	rep(i,0,n) out[i] = in[-i & (n - 1)] - conj(in[i]);
	fft(out);
	rep(i,0,sz(res)) res[i] = imag(out[i]) / (4 * n);
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int TT = 1;
	cin>>TT;
	for(int T=0;T<TT;++T)
	{
		if(T) cout<<"\n";

		int n;
		cin>>n;
		n++;

		vd a(n),b(n),c;
		for(auto &x : a)
			cin>>x;
		for(auto &x : b)
			cin>>x;

		
		c = conv(a,b);				
		rep(i,0,sz(c))	
		{
			cout<<(long long) (c[i]+0.500);
			if(i+1<sz(c)) cout<<" ";
		}		
	}	
}