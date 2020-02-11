#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 2000000000
#define pii pair<int, int>
#define ll long long
#define ld long double
#define MAXN 100100
#define MAXL 23
#define EPS 0.000001

using namespace std;

struct Ponto
{
	int X, Y;

	Ponto(int x = 0, int y = 0) : X(x), Y(y) {}

	bool operator < (const Ponto &a) const {return X != a.X ? X < a.X : Y < a.Y;}
	Ponto operator - (const Ponto &a) const {return Ponto(X - a.X, Y - a.Y);}
};

ll cross(Ponto a, Ponto b)
{
	return ((ll)a.X * b.Y) - ((ll)a.Y * b.X);
}


ll dot (Ponto a, Ponto b)
{
	return ((ll)a.X * b.X) + ((ll)a.Y * b.Y);
}


vector<Ponto> ConvexHull(vector<Ponto> p)
{
	sort(p.begin(), p.end());

	vector<Ponto> r(MAXN);
	int tam = 0;

	for(int i = 0; i < (int)p.size(); i++)
	{
		while(tam > 1 && cross(r[tam - 1] - r[tam - 2], p[i] - r[tam - 2]) > 0LL) tam--;
		r[tam++] = p[i];
	}

	for(int i = (int)p.size() - 2; i >= 0; i--)
	{
		while(tam > 1 && cross(r[tam - 1] - r[tam - 2], p[i] - r[tam - 2]) > 0LL) tam--;
		r[tam++] = p[i];
	}

	r.resize(tam);

	return r;
}

ld calc(Ponto a, Ponto b, Ponto c)
{
	return abs(cross(a - b, a - c)) / sqrt(((a.X - b.X) * (a.X - b.X)) + ((a.Y - b.Y) * (a.Y - b.Y)));
}

ld solve(vector<Ponto> pontos)
{
	int N = pontos.size();

	ld ans = INF;

	for(int i = 1; i < N; i++)
	{
		ld curr = 0;
		for(int j = 0; j < N; j++)
			curr = max(curr, calc(pontos[i - 1], pontos[i], pontos[j]));
		ans = min(ans, curr);
	}

	return ans;
}

int main(int argc, char const *argv[])
{
	optimize;

	int N;

	cin >> N;

	vector<Ponto> pontos(N);

	for(int i = 0; i < N; i++)
		cin >> pontos[i].X >> pontos[i].Y;

	cout << setprecision(15) << fixed << solve(ConvexHull(pontos)) << endl;

	return 0;
}