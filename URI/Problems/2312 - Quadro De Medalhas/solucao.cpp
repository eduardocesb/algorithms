#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define ll long long
#define MAXN 100010


using namespace std;

struct Pais
{
	string nome;
	int o, p, b;

	bool operator < (const Pais &a) const
	{
		if(o != a.o) return o > a.o;
		if(p != a.p) return p > a.p;
		if(b != a.b) return b > a.b;
		return nome < a.nome;
	}
};

int main(int argc, char** argv)
{
	optimize;

	int N;

	cin >> N;

	Pais paises[N];

	for(int i = 0; i < N; i++)
		cin >> paises[i].nome >> paises[i].o >> paises[i].p >> paises[i].b;

	sort(paises, paises + N);

	for(int i = 0; i < N; i++)
		cout << paises[i].nome << " " << paises[i].o << " " << paises[i].p << " " << paises[i].b << endl;
	
	return 0;
}
