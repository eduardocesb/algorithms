#include "bits/stdc++.h" //https://www.spoj.com/problems/ADAMATCH/
using namespace std;	// Leonardo
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef complex<double> C;
typedef vector<double> vd;
void fft(vector<C>& a) 
{
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vector<complex<long double>> R(2, 1);
	static vector<C> rt(2, 1); // (^ 10% faster if double)
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
			C z = rt[j+k] * a[i+j+k]; // (25% faster if hand−rolled)
			a[i + j + k] = a[i + j] - z;
			a[i + j] += z;
		}
}

vd conv(const vd& a, const vd& b) 
{
	if (a.empty() || b.empty()) return {};
	vd res(sz(a) + sz(b) - 1);
	int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
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

	string s,rs;
	cin>>s>>rs;
	reverse(all(rs));

	
	array<char,4> letters = {'A','C','T','G'};
	array<vd, 4> c;
	int n = sz(s), m = sz(rs);

	vd a(n),b(m);
	for(int letter=0;letter<4;++letter)
	{
		for(int i=0;i<n;++i)
			a[i] = (s[i] == letters[letter]) ? 1.0 : 0.0;
		for(int i=0;i<m;++i)
			b[i] = (rs[i] == letters[letter]) ? 1.0 : 0.0;

		c[letter] = conv(a,b);
	}


	int best = 0;
	vi ans(n-m+1);
	for(int i=0;i<=n-m;++i)
	{
		for(int letter=0;letter<4;++letter)
			ans[i] += (int)(c[letter][m-1+i] + 0.5);

		best = max(best,ans[i]);
	}

	cout<<m - best<<"\n";
}