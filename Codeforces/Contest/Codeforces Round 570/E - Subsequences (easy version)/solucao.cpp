#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define ll long long

using namespace std;

int N, K;

int solve(string S)
{
	unordered_map<string, bool> vis;
	queue<string> fila;
	
	vis[S] = true;
	fila.push(S);

	int r = 0;

	while(!fila.empty() && (int)vis.size() < K)
	{
		string s = fila.front();
		
		fila.pop();
		
		int tam = s.length();

		for(int i = 0; i < tam; i++)
		{
			string x = s;
			x.erase(i, 1);

			if(vis.find(x) == vis.end() && (int)vis.size() + 1 <= K)
			{
				fila.push(x);
				vis[x] = true;
				r += N - x.size();
			}
		}
	}

	return ((int)vis.size() < K ? -1 : r);


}

int main(int argc, char** argv)
{
	optimize;

	cin >> N >> K;

	string S;

	cin >> S;

	cout << solve(S) << endl;

	return 0;
}
