#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define pii pair<int, int>
#define INF 1000000000
#define MAXN 100100
#define MAXL 22

using namespace std;

int main(int argc, char const *argv[])
{
	optimize;

	int T, N, A, B, C;
	string S;

	cin >> T;

	while(T--)
	{
		cin >> N >> A >> B >> C;

		cin >> S;

		string R = "";

		int v = 0;

		for(int i = 0; i < N; i++)
		{
			if(S[i] == 'R' && B) B--, v++, R += "P";
			else if(S[i] == 'P' && C) C--, v++, R += "S";
			else if(S[i] == 'S' && A) A--, v++, R += "R";
			else R += "*";
		}

		if(v >= ((N + 1) / 2))
		{
			for(int i = 0; i < N; i++)
				if(R[i] == '*' && A) A--, R[i] = 'R';
				else if(R[i] == '*' && B) B--, R[i] = 'P';
				else if(R[i] == '*' && C) C--, R[i] = 'S';
			cout << "YES" << endl << R << endl;
		}
		else
			cout << "NO" << endl;
	}

	return 0;
}