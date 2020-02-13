#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 2000000000
#define pii pair<int, int>
#define ll long long
#define ld long double
#define MAXN 500
#define MAXL 23

using namespace std;

int teclado[MAXN];
int pos[30];


void solve(string S)
{
	for(int i = 0; i < MAXN; i++) teclado[i] = -1;
	for(int i = 0; i < 30; i++) pos[i] = -1;

	bool deu_merda = false;

	for(int i = 0; i < (int)S.length(); i++)
	{
		int x = S[i]  - 'a';

		if(!i)
		{
			pos[x] = 220;
			teclado[220] = x;
			continue;
		}

		if(pos[x] != -1)
		{
			int y = pos[S[i - 1] - 'a'];

			if(teclado[y + 1] != x && teclado[y - 1] != x)
			{
			//	cout << "AQUI: " << x << " " << i << " " << y << endl;
				deu_merda = true;
			}
		}
		else
		{
			int y = pos[S[i - 1] - 'a'];

			if(teclado[y - 1] == -1)
			{
				pos[x] = y - 1;
				teclado[y - 1] = x;
			}
			else if(teclado[y + 1] == -1)
			{
				pos[x] = y + 1;
				teclado[y + 1] = x;
			}
			else
			{
			//	cout << "NAO ERA PRA ENTRAR AQUI\n\n";
			//	cout << x << " " << i << " " << y << endl;
				deu_merda = true;
			}
		}
	}

	if(deu_merda)
	{
		cout << "NO" << endl;
		return;
	}

	vector<char> r;

	cout << "YES" << endl;

	for(int i = 0; i < 26; i++) if(pos[i] == -1) r.push_back('a' + i);

	for(int i = 0; i < MAXN; i++)
		if(teclado[i] != -1)
			cout << (char)('a' + teclado[i]);

	for(auto t : r)
		cout << t;
	cout << endl;

}

int main(int argc, char const *argv[])
{
	optimize;

	int N;
	string S;

	cin >> N;

	while(N--)
	{
		cin >> S;

		solve(S);
	}

	return 0;
}