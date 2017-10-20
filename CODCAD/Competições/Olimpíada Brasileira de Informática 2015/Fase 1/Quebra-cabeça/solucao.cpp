#include <bits/stdc++.h>
#define optimize std::ios::sync_with_stdio(0); cin.tie(0)
#define ci pair<char, int>

using namespace std;

int main(int argc, char const *argv[])
{
	optimize;
	int N, a, c; 
	char b;

	unordered_map<int, ci> peca;

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> a >> b >> c;

		peca[a] = ci(b, c);
	}

	string r = "";

	int esquerda = 0;

	for (int i = 0; i < N; ++i)
	{
		r += peca[esquerda].first;
		esquerda = peca[esquerda].second;
	}

	cout << r << endl;
	return 0;
}